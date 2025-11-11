#ifndef RAINDROPS_STATE_HPP
#define RAINDROPS_STATE_HPP

#include <SFML/Graphics/RenderWindow.hpp>

namespace raindrops
{
    class StateMachine;

    class State {
    public:
        State(StateMachine& stateMachine, sf::RenderWindow& renderWindow, bool replace = true, const std::string& stateName = "");
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
        sf::RenderWindow& m_renderWindow;

        bool m_replacing;
        std::string m_stateName;

        std::unique_ptr<State> m_next;
    };
}


#endif //RAINDROPS_STATE_HPP