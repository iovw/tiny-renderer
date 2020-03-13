//
// Created by iov on 3/13/20.
//

#ifndef TINYRENDERER_INCLUDE_TYPE_H
#define TINYRENDERER_INCLUDE_TYPE_H

#include <cstdint>
#include "Vector2.hpp"
#include "Vector3.hpp"
#include "Matrix.hpp"

//using i32 = int32_t;

using u8 = uint8_t;
using u16 = uint16_t;
using u32 = uint32_t;
using u64 = uint64_t;

using Point = Vector2<u32>;
using ColorRGB = Vector3<u8>;

#endif //TINYRENDERER_INCLUDE_TYPE_H
