#include "InternalDataUser.h"
#include "DataPersistence.h"

#include <algorithm>
#include <assert.h>

InternalDataUser::InternalDataUser(std::unique_ptr<IDataPersistence> data_persistence)
    : data_persistence_(std::move(data_persistence))
{
    assert(nullptr != data_persistence_);
    load();
}


InternalDataUser::~InternalDataUser()
{
}

void InternalDataUser::changeData(const std::string& data_id, const std::string& data_type, const std::string& data_value)
{
    auto data_it = std::find_if(data_.begin(), data_.end(), 
        [&data_id](const InternalData &arg) {
        return arg.getId() == data_id; });

    if (data_it != data_.end())
    {
        data_it->setData(data_type, data_value);
    }

    save();
}

const std::vector<std::string> InternalDataUser::getDataIds() const
{
    std::vector<std::string> data_ids;

    for (const auto& internal_data : data_)
    {
        data_ids.emplace_back(internal_data.getId());
    }

    return data_ids;
}

const std::vector<std::string> InternalDataUser::getDataNames() const
{
    std::vector<std::string> data_ids;

    for (const auto& internal_data : data_)
    {
        data_ids.emplace_back(internal_data.getName());
    }

    return data_ids;
}

const std::vector<InternalData>& InternalDataUser::getData() const
{
    return data_;
}

void InternalDataUser::load()
{
    data_ = data_persistence_->getData();
}

void InternalDataUser::save()
{
    data_persistence_->updateData(data_);
    data_persistence_->saveData();
}