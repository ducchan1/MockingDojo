#include <gtest/gtest.h>

#include "MockIDataPersistence.h"

#include "../MockingDojo/InternalDataUser.h"

TEST(TestInternalDataUser, testGetDataNames)
{
    auto mock_persistence = std::make_unique<MockIDataPersistence>();

    std::vector<std::string> expected_names;
    expected_names.emplace_back("name1");
    expected_names.emplace_back("name2");

    std::vector<InternalData> data_to_return;
    data_to_return.emplace_back("id1", expected_names[0]);
    data_to_return.emplace_back("id2", expected_names[1]);

    EXPECT_CALL(*mock_persistence, getData()).WillOnce(testing::ReturnRef(data_to_return));

    InternalDataUser data_user(std::move(mock_persistence));

    std::vector<std::string> actual_names(data_user.getDataNames());

    ASSERT_EQ(expected_names, actual_names);
}