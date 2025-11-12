#include "State.hpp"
#include <utility>

namespace raindrops
{
    State::State(StateMachine& stateMachine, raylib::Window& renderWindow, const bool replace, std::string stateName)
    : m_stateMachine { stateMachine }
    , m_renderWindow { renderWindow }
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
}
