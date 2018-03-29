#include "DataPersistence.h"

#include <fstream>


DataPersistence::DataPersistence(const DataPersistence::Path& data_path)
    : data_path_(data_path)
{
    loadFile();
}


DataPersistence::~DataPersistence()
{
}

const InternalData& DataPersistence::getData() const
{
    return *data_;
}

void DataPersistence::saveData() const
{
    std::string data_to_save(convertDataToString());
    std::ofstream out_file;
    out_file.open(data_path_.string());
    out_file << data_to_save;
    out_file.close();
}

void DataPersistence::updateData(const InternalData& new_data)
{
    data_ = std::make_unique<InternalData>(new_data);
}

void DataPersistence::loadFile()
{
    std::string id;
    std::string name;
    std::map<std::string, std::string> data_values;

    std::ifstream in_file;
    in_file.open(data_path_.string());

    while (!in_file.eof())
    {
        std::string current_line;
        getline(in_file, current_line);

        auto first_marker_pos = current_line.find_first_of('@');
        auto second_marker = current_line.find_first_of(':');

        auto data_type = current_line.substr(first_marker_pos, second_marker);
        auto data_value = current_line.substr(second_marker);

        if (data_type == "ID")
        {
            id == data_value;
        }
        else if (data_type == "Name")
        {
            name = data_value;
        }
        else
        {
            data_values.emplace(data_type, data_value);
        }
    }

    InternalData new_data(id, name);
    new_data.setData(data_values);

    updateData(new_data);
}

std::string DataPersistence::convertDataToString() const
{
    std::string converted_data;

    converted_data += "@ID:" + data_->getId() + "\n";
    converted_data += "@Name:" + data_->getName() + "\n";

    for (auto data_entry : data_->getData())
    {
        converted_data += "@" + data_entry.first + ":" + data_entry.second + "\n";
    }

    return converted_data;
}