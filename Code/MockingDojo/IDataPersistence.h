#pragma once

#include "InternalData.h"

#include <vector>

class IDataPersistence
{
public:
    virtual ~IDataPersistence() = default;

    virtual const std::vector<InternalData>& getData() const = 0;
    virtual void saveData() const = 0;
    virtual void updateData(const std::vector<InternalData>& new_data) = 0;
};