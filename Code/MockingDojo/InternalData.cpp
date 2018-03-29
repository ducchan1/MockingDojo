#include "InternalData.h"


InternalData::InternalData(const std::string& id, const std::string& name)
    : id_(id)
    , name_(name)
{
}


InternalData::~InternalData()
{
}

const std::map<std::string, std::string>& InternalData::getData() const
{
    return data_;
}

const std::string& InternalData::getId() const
{
    return id_;
}

const std::string& InternalData::getName() const
{
    return name_;
}

void InternalData::setData(const std::map<std::string, std::string>& data_values)
{
    data_ = data_values;
}

void InternalData::setData(const std::string& data_type, const std::string& data_value)
{
    data_[data_type] = data_value;
}