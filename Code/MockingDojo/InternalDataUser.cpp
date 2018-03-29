#include "InternalDataUser.h"
#include "DataPersistence.h"

#include <algorithm>

InternalDataUser::InternalDataUser(const InternalDataUser::Path& dir_path)
    :dir_path_(dir_path)
{
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
    for (auto file = std::tr2::sys::recursive_directory_iterator(dir_path_); file != std::tr2::sys::recursive_directory_iterator(); ++file)
    {
        DataPersistence data_persistence(file->path());
        data_.emplace_back(data_persistence.getData());
    }
}

void InternalDataUser::save()
{
    std::tr2::sys::remove_all(dir_path_);
    for (const auto& internal_data : data_)
    {
        DataPersistence data_persistence(dir_path_ / std::tr2::sys::path(internal_data.getId() + internal_data.getName() + ".txt"));
        data_persistence.updateData(internal_data);
        data_persistence.saveData();
    }
}