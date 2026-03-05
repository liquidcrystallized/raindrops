#include "SongSelectionState.hpp"
#include "PlayingState.hpp"
#include "StateMachine.hpp"
#include <raygui-cpp/Utils.h>
#include <filesystem>
#include <iostream>

namespace raindrops
{
    SongSelectionState::SongSelectionState(StateMachine& stateMachine, Renderer& renderer, MidiMonitor& midiMonitor, const bool replace)
    : State { stateMachine, renderer, midiMonitor, replace, "SongSelectionState" }
    {
        m_songListViewText = "Lorem;Ipsum;Dolor;Sit;Amet;Consectetuer";
        m_songListViewScrollIndex = 1;
        m_songListViewActiveSelection = 0;

        m_playButtonText = "Play";
        m_backButtonText = "Back";
        m_refreshButtonText = "Refresh";

        m_songDirectory = "songs";

        refreshSongList();
        positionUIComponents();
    }

    void SongSelectionState::pause()
    {
        //TODO
    }

    void SongSelectionState::resume()
    {
        //TODO
    }

    void SongSelectionState::update()
    {
        if (raylib::Keyboard::IsKeyPressed(KEY_ESCAPE))
        {
            m_stateMachine.lastState();
        }

        m_connectedDeviceLabelText = "Connected device: " + m_midiMonitor.getConnectedDeviceName();
        m_connectedDeviceLabel.SetText(m_connectedDeviceLabelText.c_str());

        m_verticalStackPanel.Update();
        m_songListView.Update();
    }

    void SongSelectionState::draw()
    {
        m_renderer.drawStart();

        RAYGUI_CPP_UNUSED(m_verticalStackPanel.Show(true));
        RAYGUI_CPP_UNUSED(m_songListView.Show(true));
        RAYGUI_CPP_UNUSED(m_connectedDeviceLabel.Show(true));

        m_renderer.drawEnd();
    }

    void SongSelectionState::onWindowResize()
    {
        positionUIComponents();
    }

    //TODO: Temp programmers UI, implement actual design later, throw it into the renderer
    void SongSelectionState::positionUIComponents()
    {
        m_buttonScalingFactor = 1;

        // Sets the bounds/workspace/position limit for other controls.
        // They should all be rendered inside the bounds of the stack panel.
        m_verticalStackPanelSize  = raylib::Rectangle {
            0,
            0,
            static_cast<float>(m_renderer.getWindowWidth()) / 2.0f,
            static_cast<float>(m_renderer.getWindowHeight()) / 1.5f
        };

        const Vector2 verticalStackPanelPosition {
            this->m_windowCentrePosition.getX() - m_verticalStackPanelSize.GetWidth() / 2,
            this->m_windowCentrePosition.getY() - m_verticalStackPanelSize.GetHeight() / 2
        };

        m_verticalStackPanel = VerticalStackPanel(
            rgc::Bounds(
                {
                    verticalStackPanelPosition.getX(),
                    verticalStackPanelPosition.getY()
                },
                {
                    m_verticalStackPanelSize.GetWidth(),
                    m_verticalStackPanelSize.GetHeight()
                }
            ),
            "song selection (temporary look/ui)"
        );

        const Vector2 songListViewSize {
            m_verticalStackPanelSize.GetWidth() / 1.1f,
            m_verticalStackPanelSize.GetHeight() / 1.5f
        };

        const Vector2 songListViewPosition {
            m_verticalStackPanelSize.GetWidth() - songListViewSize.getX(),
            m_verticalStackPanelSize.GetHeight() - songListViewSize.getY()
        };

        // List view for all connected midi devices.
        m_songListViewBounds = rgc::Bounds {
                {
                    verticalStackPanelPosition.getX() + (songListViewPosition.getX() / 2),
                    verticalStackPanelPosition.getY() + (songListViewPosition.getY() / 12)
                },
                {
                    songListViewSize.getX(),
                    songListViewSize.getY()
                }
        };
        m_songListView = rgc::ListView(m_songListViewBounds, m_songListViewText, &m_songListViewScrollIndex, m_songListViewActiveSelection);
        m_songListView.SetStyle(rgc::Style(rgc::Style::Position::CENTER, { 0, -m_verticalStackPanelSize.GetHeight() / 10.0f }));

        // Size and position the button relative to the stack panel.
        m_buttonSize = raylib::Rectangle {
            0,
            0,
            m_verticalStackPanelSize.GetWidth() / 1.1f,
            m_verticalStackPanelSize.GetHeight() / 8.0f
        };

        // Back button positioning and callback.
        m_backButton = rgc::Button(rgc::Bounds::WithText(
            m_backButtonText,
            m_buttonScalingFactor,
            { m_buttonSize.GetWidth() / 4, m_buttonSize.GetHeight() }),
            m_backButtonText);
        m_backButton.SetStyle(rgc::Style(rgc::Style::Position::BOTTOM_CENTER, { -m_buttonSize.GetWidth() / 5.0f, -m_verticalStackPanelSize.GetHeight() / 12.0f }));
        m_backButton.OnClick([this]
        {
            m_stateMachine.lastState();
        });
        m_verticalStackPanel.AddChild(rgc::ToComponent(&m_backButton));

        // Play button positioning and callback.
        m_playButton = rgc::Button(rgc::Bounds::WithText(
            m_playButtonText,
            m_buttonScalingFactor,
            { m_buttonSize.GetWidth() / 4, m_buttonSize.GetHeight() }),
            m_playButtonText);
        m_playButton.SetStyle(rgc::Style(rgc::Style::Position::BOTTOM_CENTER, { m_buttonSize.GetWidth() / 5.0f, -m_verticalStackPanelSize.GetHeight() / 12.0f }));
        m_playButton.OnClick([this]
        {
            //TODO: Pass loaded song details to play screen for sheet rendering.
            m_next = StateMachine::build<PlayingState>(m_stateMachine, m_renderer, m_midiMonitor, false);
        });
        m_verticalStackPanel.AddChild(rgc::ToComponent(&m_playButton));

        // Show currently connected device.
        m_connectedDeviceLabel = rgc::Label{ rgc::Bounds
            { 10, static_cast<float>(m_renderer.getWindowHeight()) - 20.0f, static_cast<float>(m_renderer.getWindowWidth()), 10 },
            m_connectedDeviceLabelText.c_str() };
        m_connectedDeviceLabel.SetStyle(rgc::Style(rgc::Style::Position::CENTER, { 0, 0 }));
    }

    void SongSelectionState::refreshSongList()
    {
        m_songList.clear();

        //TODO: Create the songs folder in correct standard directories per os. (e.g, appdata, .local/share, etc)
        //TODO: or grant the user the ability to specify a custom song directory.
        if (!std::filesystem::exists(m_songDirectory))
        {
            std::cout << "The songs folder does not exist. Creating.";
            std::filesystem::create_directory(m_songDirectory);
        }

        for (std::filesystem::directory_entry const& entry : std::filesystem::directory_iterator(m_songDirectory))
        {
            std::cout << entry.path().string() << std::endl;
        }
    }
}
