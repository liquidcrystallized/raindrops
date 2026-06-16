#ifndef RAINDROPS_STAFF_HPP
#define RAINDROPS_STAFF_HPP

#include "StaffLine.hpp"
#include <vector>

namespace raindrops
{
    /**
     * @brief A musical staff, helps with managing line positioning.
     */
    class Staff {
    public:
        /**
         * @param firstLinePositionY Y position of the first line of this specific staff.
         * @param lineSpacing Vertical spacing between the staff lines.
         */
        explicit Staff(int firstLinePositionY, int lineSpacing);

        [[nodiscard]] const std::vector<StaffLine>& getLines() const;
        [[nodiscard]] int getNumberOfLines() const;

    private:
        std::vector<StaffLine> m_staffLines;
    };
}


#endif //RAINDROPS_STAFF_HPP