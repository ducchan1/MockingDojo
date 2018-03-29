#include <gtest/gtest.h>

#include "../MockingDojo/InternalDataUser.h"

TEST(TestInternalDataUser, testGetDataNames)
{
    std::tr2::sys::path data_path("..\\MockingData");
    InternalDataUser data_user(data_path);

    std::vector<std::string> data_names(data_user.getDataNames());

    ASSERT_EQ(2, data_names.size());
}