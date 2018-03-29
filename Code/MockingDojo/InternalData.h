#pragma once

#include <map>
#include <string>

class InternalData
{
public:
    InternalData(const std::string& id, const std::string& name);
    ~InternalData();

    const std::map<std::string, std::string>& getData() const;
    const std::string& getId() const;
    const std::string& getName() const;

    void setData(const std::map<std::string, std::string>& data_values);
    void setData(const std::string& data_type, const std::string& data_value);

private:
    std::map<std::string, std::string> data_;
    std::string id_;
    std::string name_;
};

