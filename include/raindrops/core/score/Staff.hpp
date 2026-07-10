#ifndef RAINDROPS_STAFF_HPP
#define RAINDROPS_STAFF_HPP

#include "StaffLine.hpp"
#include <vector>

namespace raindrops
{
    /**
     * @brief A musical staff.
     */
    class Staff {
    public:
        explicit Staff();

        [[nodiscard]] std::vector<StaffLine>& getLines();
        [[nodiscard]] int getNumberOfLines() const;

    private:
        std::vector<StaffLine> m_staffLines;
    };
}


#endif //RAINDROPS_STAFF_HPP