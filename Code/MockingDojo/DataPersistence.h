#pragma once

#include "InternalData.h"

#include <filesystem>
#include <memory>

class DataPersistence
{
    typedef std::tr2::sys::path Path;
public:
    DataPersistence(const Path& data_path);
    ~DataPersistence();

    const InternalData& getData() const;
    void saveData() const;
    void updateData(const InternalData& new_data);

private:
    void loadFile();
    std::string convertDataToString() const;

    std::unique_ptr<InternalData> data_;
    Path data_path_;
};

