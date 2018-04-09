#pragma once

#include "../MockingDojo/IDataPersistence.h"

#include <gmock/gmock.h>

class MockIDataPersistence final : public IDataPersistence
{
public:
    MockIDataPersistence() = default;
    ~MockIDataPersistence() override = default;

    MOCK_CONST_METHOD0(getData, const std::vector<InternalData>&());
    MOCK_CONST_METHOD0(saveData, void());
    MOCK_METHOD1(updateData, void(const std::vector<InternalData>&));
};

