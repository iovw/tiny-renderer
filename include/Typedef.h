//
// Created by iov on 3/13/20.
//

#ifndef TINYRENDERER_INCLUDE_TYPE_H
#define TINYRENDERER_INCLUDE_TYPE_H

#include <cstdint>
#include <array>

namespace TR
{
    using RGB = std::array<uint8_t, 3>;

    namespace ColorRGB
    {
        const auto WHITE = RGB{255, 255, 255};
        const auto DARK = RGB{0, 0, 0};
        const auto RED = RGB{255, 0, 0};
        const auto GREEN = RGB{0, 255, 0};
        const auto BLUE = RGB{0, 0, 255};
    }
}

#endif //TINYRENDERER_INCLUDE_TYPE_H
