//
// Created by iov on 3/13/20.
//

#ifndef TINYRENDERER_INCLUDE_TYPE_H
#define TINYRENDERER_INCLUDE_TYPE_H

#include <cstdint>

namespace tr {
using RGB = std::array<uint8_t, 3>;

namespace rgb {
const auto White = RGB{255, 255, 255};
const auto Dark = RGB{0, 0, 0};
const auto Red = RGB{255, 0, 0};
const auto Green = RGB{0, 255, 0};
const auto Blue = RGB{0, 0, 255};
}
}

#endif //TINYRENDERER_INCLUDE_TYPE_H
