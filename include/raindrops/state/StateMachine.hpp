#ifndef RAINDROPS_STATEMACHINE_HPP
#define RAINDROPS_STATEMACHINE_HPP

#include "Renderer.hpp"
#include "State.hpp"
#include <raylib-cpp.hpp>
#include <iostream>
#include <memory>
#include <stack>

namespace raindrops
{
    /**
     * @brief Manages a stack of application states (e.g., main menu, options, etc).
     * Provides methods to transition between states, handle state pausing/resuming,
     * and manage the overall application state flow.
     */
    class StateMachine {
    public:
        StateMachine();

        /**
         * @brief Gets the current state at the top of the stack of states.
         * @return A reference to the current running state.
         */
        std::unique_ptr<State>& getCurrentState();

        /**
         * Runs a given state by pushing it onto the state stack.
         * @param state The state to be run.
         */
        void run(std::unique_ptr<State> state);

        /**
         * @brief Advances to the next state. If we're resuming, pop the current state
         * and resume the previous state. Otherwise, transition to the next state (if any exists).
         */
        void nextState();

        /**
         * @brief Flag the current state for popping at the next nexState() call.
         */
        void lastState();

        void update();
        void draw();

        [[nodiscard]] bool running() const;
        void quit();

        /**
         *
         * @tparam T The type of state to create.
         * @param stateMachine Reference to the state machine.
         * @param renderer Reference to the abstract renderer which handles drawing.
         * @param midiMonitor Reference to the midi monitor.
         * @param replace If true, the new state will replace the current one.
         * @return A unique_ptr to the newly created state.
         */
        template <typename T>
        static std::unique_ptr<T> build(StateMachine& stateMachine, Renderer& renderer, MidiMonitor& midiMonitor, bool replace = true);
    private:
        std::stack<std::unique_ptr<State>> m_states;

        bool m_resume;
        bool m_running;
    };

    template<typename T>
    std::unique_ptr<T> StateMachine::build(StateMachine& stateMachine, Renderer& renderer, MidiMonitor& midiMonitor, bool replace)
    {
        auto newState = std::unique_ptr<T>{ nullptr };

        try
        {
            newState = std::make_unique<T>(stateMachine, renderer, midiMonitor, replace);
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