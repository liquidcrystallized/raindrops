#ifndef RAINDROPS_STATEMACHINE_HPP
#define RAINDROPS_STATEMACHINE_HPP

#include "State.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <iostream>
#include <memory>
#include <stack>

namespace raindrops
{
    /**
     * @brief Manages a stack of application states (e.g., main menu, options, etc).
     */
    class StateMachine {
    public:
        StateMachine();

        std::string getCurrentStateName();

        void run(std::unique_ptr<State> state);

        void nextState();
        void lastState();

        void update();
        void draw();

        [[nodiscard]] bool running() const;
        void quit();

        template <typename T>
        static std::unique_ptr<T> build(StateMachine& stateMachine, sf::RenderWindow& renderWindow, bool replace = true);
    private:
        std::stack<std::unique_ptr<State>> m_states;

        bool m_resume;
        bool m_running;
    };

    template<typename T>
    std::unique_ptr<T> StateMachine::build(StateMachine& stateMachine, sf::RenderWindow& renderWindow, bool replace)
    {
        auto newState = std::unique_ptr<T>{ nullptr };

        try
        {
            newState = std::make_unique<T>(stateMachine, renderWindow, replace);
        }
        catch (std::runtime_error& exception)
        {
            std::cout << "Creation of new state was unsuccessful\n";
            std::cout << exception.what() << '\n';
        }

        return newState;
    }
}


#endif //RAINDROPS_STATEMACHINE_HPP