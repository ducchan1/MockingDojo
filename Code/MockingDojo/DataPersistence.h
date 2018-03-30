#pragma once

#include "InternalData.h"

#include <filesystem>
#include <memory>
#include <vector>

class DataPersistence
{
    typedef std::tr2::sys::path Path;
public:
    DataPersistence(const Path& data_path);
    ~DataPersistence();

    const std::vector<InternalData>& getData() const;
    void saveData() const;
    void updateData(const std::vector<InternalData>& new_data);

private:
    void loadFile();
    std::string convertDataToString() const;

    std::vector<InternalData> data_;
    Path data_path_;
};

