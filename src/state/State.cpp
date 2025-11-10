#include "raindrops/state/State.hpp"

namespace raindrops
{
    State::State(StateMachine &stateMachine, sf::RenderWindow &renderWindow, const bool replace)
    : m_stateMachine { stateMachine }
    , m_renderWindow { renderWindow }
    , m_replacing { replace }
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
}