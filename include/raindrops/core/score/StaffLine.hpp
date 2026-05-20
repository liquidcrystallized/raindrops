#ifndef RAINDROPS_STAFFLINE_HPP
#define RAINDROPS_STAFFLINE_HPP

#include "core/math/Vector2.hpp"

namespace raindrops
{
    class StaffLine {
    public:
        explicit StaffLine(int positionY);

        [[nodiscard]] int getPositionY() const;
        void setPositionY(int value);

    private:
        Vector2<int> m_position;
    };
}


#endif //RAINDROPS_STAFFLINE_HPP