#include "State.hpp"
#include <utility>

namespace raindrops
{
    State::State(StateMachine& stateMachine, Renderer& renderer, MidiMonitor& midiMonitor, const bool replace, std::string stateName)
    : m_stateMachine { stateMachine }
    , m_renderer { renderer }
    , m_windowCentrePosition {
        static_cast<float>(m_renderer.getWindowWidth()) / 2.0f,
        static_cast<float>(m_renderer.getWindowHeight()) / 2.0f
    }
    , m_midiMonitor { midiMonitor }
    , m_replacing { replace }
    , m_stateName { std::move(stateName) }
    {
        //
    }

    std::unique_ptr<State> State::next()
    {
        return std::move(m_next);
    }

    bool State::isReplacing() const
    {
        return m_replacing;
    }

    std::string State::getName() const
    {
        return m_stateName;
    }

    MidiMonitor& State::getMidiMonitor() const
    {
        return m_midiMonitor;
    }

    Vector2 State::getWindowCentrePosition() const
    {
        return m_windowCentrePosition;
    }

    void State::setWindowCentrePosition(const float x, const float y)
    {
        m_windowCentrePosition.setX(x);
        m_windowCentrePosition.setY(y);
    }
}
