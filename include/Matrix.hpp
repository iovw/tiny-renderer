//
// Created by iov on 3/13/20.
//

#ifndef TINYRENDERER_INCLUDE_MATRIX_HPP
#define TINYRENDERER_INCLUDE_MATRIX_HPP
#include <vector>
#include "Typedef.h"

namespace TR
{
    template <typename T>
    class Matrix
    {
        std::vector<T> Data{};
        uint32_t Width;
        uint32_t Height;

        [[nodiscard]] uint64_t GetOffset(const uint32_t x, const uint32_t y) const
        {
            return static_cast<uint64_t>(y) * Width + x;
        }

    public:
        Matrix(const uint32_t width, const uint32_t height) :
            Width(width), Height(height)
        {
            Data.resize(static_cast<uint64_t>(width) * height);
        }

        [[nodiscard]] const uint8_t *GetData() const
        {
            uint8_t *p = new uint8_t[Data.size() * sizeof(T)], *ph = p;
            for (auto y : Data)
            {
                for (uint8_t x = 0; x < y.size(); ++x) // NOLINT(bugprone-too-small-loop-variable)
                {
                    *p++ = y[x];
                }
            }
            return ph;
        }

        [[nodiscard]] uint32_t GetWidth() const
        {
            return Width;
        }

        [[nodiscard]] uint32_t GetHeight() const
        {
            return Height;
        }

        void Set(const uint32_t x, const uint32_t y, T c)
        {
            Data[GetOffset(x, y)] = c;
        }

        [[nodiscard]] T Get(const uint32_t x, const uint32_t y) const
        {
            return Data[GetOffset(x, y)];
        }

        bool FlipVertically()
        {
            auto it = Data.begin(), itRv = Data.end();
            for (auto i = 0; i < Height / 2; ++i)
            {
                auto begin{it};
                std::advance(it, Width);
                std::advance(itRv, -static_cast<int32_t>(Width));
                std::swap_ranges(begin, it, itRv);
            }
            return false;
        }
    };
}

#endif //TINYRENDERER_INCLUDE_MATRIX_HPP
