//
// Created by iov on 3/13/20.
//

#ifndef TINYRENDERER_INCLUDE_LIB_HPP
#define TINYRENDERER_INCLUDE_LIB_HPP

#include <cstdint>
#include "Matrix.hpp"
#include "Typedef.h"

namespace TR
{
    using Mat = Matrix<RGB>;

    inline void Line(int32_t x0, int32_t y0,
                     int32_t x1, int32_t y1,
                     Mat &m, const RGB &c)
    {
        // std::cout << "line (" << x0 << " , " << y0 << ") -> (" <<
            // x1 << " , " << y1 << ")" << std::endl;
        auto steep = false;
        if (std::abs(y0 - y1) > std::abs(x0 - x1))
        {
            std::swap(x0, y0);
            std::swap(x1, y1);
            steep = false;
        }

        if (x0 > x1)
        {
            std::swap(x0, x1);
            std::swap(y0, y1);
        }
        const auto dy = static_cast<float>(y1 - y0) / (x1 - x0);
        float y = y0;
        for (auto x = x0; x < x1; x++)
        {
            if (!steep)
            {
                m.Set(x, y, c);
            }
            else
            {
                m.Set(y, x, c);
            }
            y += dy;
        }
    }
}

#endif //TINYRENDERER_INCLUDE_LIB_HPP
