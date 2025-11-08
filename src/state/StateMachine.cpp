#include "StateMachine.hpp"
#include <iostream>

namespace raindrops
{
    StateMachine::StateMachine() : m_resume { false }, m_running { false }
    {
        std::cout << "StateMachine Init\n";
    }

    void StateMachine::run(std::unique_ptr<State> state)
    {
        m_running = true;

        m_states.push(std::move(state));
    }

    void StateMachine::nextState()
    {
        if (m_resume)
        {
            // Cleanup current state
            if (!m_states.empty())
            {
                m_states.pop();
            }

            // Resume previous state
            if (!m_states.empty())
            {
                m_states.top()->resume();
            }

            m_resume = false;
        }

        // There needs to be a state
        if (!m_states.empty())
        {
            std::unique_ptr<State> temporaryState = m_states.top()->next();

            // Only change states if there's a next one existing
            if (temporaryState != nullptr)
            {
                // Replace the running state
                if (temporaryState->isReplacing())
                {
                    m_states.pop();
                }
                // Pause the running state
                else
                {
                    m_states.top()->pause();
                }

                m_states.push(std::move(temporaryState));
            }
        }
    }

    void StateMachine::lastState()
    {
        m_resume = true;
    }

    void StateMachine::update()
    {
        // Let the current state update the game
        m_states.top()->update();
    }

    void StateMachine::draw()
    {
        // Let the current state draw the screen
        m_states.top()->draw();
    }

    bool StateMachine::running() const
    {
        return m_running;
    }

    void StateMachine::quit()
    {
        m_running = false;
    }
}