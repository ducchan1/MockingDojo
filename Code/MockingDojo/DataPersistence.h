#pragma once

#include "IDataPersistence.h"

#include <filesystem>
#include <memory>
#include <vector>

class DataPersistence : public IDataPersistence
{
    typedef std::tr2::sys::path Path;
public:
    DataPersistence(const Path& data_path);
    virtual ~DataPersistence();

    virtual const std::vector<InternalData>& getData() const override;
    virtual void saveData() const override;
    virtual void updateData(const std::vector<InternalData>& new_data) override;

private:
    void loadFile();
    std::string convertDataToString() const;

    std::vector<InternalData> data_;
    Path data_path_;
};

