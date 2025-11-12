#ifndef RAINDROPS_STATE_HPP
#define RAINDROPS_STATE_HPP

#include <raylib-cpp/raylib-cpp.hpp>
#include <memory>

namespace raindrops
{
    class StateMachine;

    class State {
    public:
        State(StateMachine& stateMachine, raylib::Window& renderWindow, bool replace = true, std::string  stateName = "");
        virtual ~State() = default;

        State(const State&) = delete;
        State& operator=(const State&) = delete;

        virtual void pause() = 0;
        virtual void resume() = 0;

        virtual void update() = 0;
        virtual void draw() = 0;

        std::unique_ptr<State> next();

        [[nodiscard]] bool isReplacing() const;

        std::string getName() const;
    protected:
        StateMachine& m_stateMachine;
        raylib::Window& m_renderWindow;

        bool m_replacing;
        std::string m_stateName;

        std::unique_ptr<State> m_next;
    };
}


#endif //RAINDROPS_STATE_HPP