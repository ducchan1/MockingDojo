#pragma once

#include <memory>
#include <filesystem>
#include <vector>

#include "InternalData.h"

class InternalDataUser
{
    typedef std::tr2::sys::path Path;

public:
    InternalDataUser(const Path& dir_path);
    ~InternalDataUser();

    void changeData(const std::string& data_id, const std::string& data_type, const std::string& data_value);

    const std::vector<std::string> getDataIds() const;
    const std::vector<std::string> getDataNames() const;
    const std::vector<InternalData>& getData() const;

private:
    void load();
    void save();

    std::vector<InternalData> data_;
    Path data_path_;
};

