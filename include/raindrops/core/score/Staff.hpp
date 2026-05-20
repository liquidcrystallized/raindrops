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
         * @param firstLinePosition Y position of the first line of this specific staff.
         * @param lineSpacing Vertical spacing between the staff lines.
         * @param numberOfLines Typically 5, but should be alterable just in case.
         */
        explicit Staff(int firstLinePosition, int lineSpacing, int numberOfLines);

        [[nodiscard]] const std::vector<StaffLine>& getLines() const;
        [[nodiscard]] int getNumberOfLines() const;

    private:
        std::vector<StaffLine> m_staffLines;
    };
}


#endif //RAINDROPS_STAFF_HPP