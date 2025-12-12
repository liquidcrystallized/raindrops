#ifndef RAINDROPS_STATE_HPP
#define RAINDROPS_STATE_HPP

#include "MidiMonitor.hpp"
#include "Renderer.hpp"
#include <raylib-cpp.hpp>
#include <memory>

namespace raindrops
{
    class StateMachine;

    /**
     * @brief Also known as a screen/scene. Where the "game" gets updated and drawn.
     */
    class State {
    public:
        State(StateMachine&, Renderer&, MidiMonitor&, bool replace = true, std::string stateName = "");
        virtual ~State() = default;

        State(const State&) = delete;
        State& operator=(const State&) = delete;

        virtual void pause() = 0;
        virtual void resume() = 0;

        virtual void update() = 0;
        virtual void draw() = 0;

        virtual void onWindowResize() = 0;

        std::unique_ptr<State> next();

        [[nodiscard]] bool isReplacing() const;

        [[nodiscard]] std::string getName() const;

        [[nodiscard]] MidiMonitor& getMidiMonitor() const;

        [[nodiscard]] raylib::Vector2 getWindowCentrePosition() const;
        void setWindowCentrePosition(float x, float y);
    protected:
        StateMachine& m_stateMachine;
        Renderer& m_renderer;
        raylib::Vector2 m_windowCentrePosition;

        MidiMonitor& m_midiMonitor;

        bool m_replacing;
        std::string m_stateName;

        std::unique_ptr<State> m_next;
    };
}


#endif //RAINDROPS_STATE_HPP