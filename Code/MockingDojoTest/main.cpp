#include <gtest/gtest.h>
#include <gmock/gmock.h>

int main(int argc, char** argv)
{
    int gtest_result(0);

    ::testing::InitGoogleMock(&argc, argv);

    gtest_result += RUN_ALL_TESTS();

    system("pause");

    return gtest_result;
}