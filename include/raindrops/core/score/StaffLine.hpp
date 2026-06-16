#ifndef RAINDROPS_STAFFLINE_HPP
#define RAINDROPS_STAFFLINE_HPP

#include "core/math/Vector2.hpp"

namespace raindrops
{
    class StaffLine {
    public:
        explicit StaffLine(int positionY, bool isVisible);

        [[nodiscard]] int getPositionY() const;
        void setPositionY(int value);

        [[nodiscard]] bool isVisible() const;
        void setVisible(bool visible);

    private:
        Vector2<int> m_position;
        bool m_isVisible;
    };
}


#endif //RAINDROPS_STAFFLINE_HPP