#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
//
// Created by iov on 3/13/20.
//
#include <gtest/gtest.h>
#include "Matrix.hpp"
#include "Lib.hpp"
#include "Typedef.h"

using namespace TR;

TEST(MatrixTest, colorOps)
{
    Matrix<RGB> mat{100, 100};
    mat.SetColor(99, 99, RGB{255, 255, 255});
    auto c = mat.GetColor(99, 99);
    ASSERT_EQ(c, (RGB{255, 255, 255}));
    ASSERT_EQ((mat.GetColor(0, 0)), (RGB{0, 0, 0}));
}

TEST(MatrixTest, getData)
{
    uint32_t w = 10, h = 10;
    Matrix<RGB> mat{w, h};
    mat.SetColor(9, 9, RGB{255, 255, 255});

    auto d = mat.GetData();
    ASSERT_EQ(*(d + 99 * 3), 255);
    ASSERT_EQ(*(d + 99 * 3 + 1), 255);
    ASSERT_EQ(*(d + 99 * 3 + 2), 255);
}
#pragma clang diagnostic pop
