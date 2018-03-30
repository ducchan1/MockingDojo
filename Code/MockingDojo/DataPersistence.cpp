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

const std::vector<InternalData>& DataPersistence::getData() const
{
    return data_;
}

void DataPersistence::saveData() const
{
    std::string data_to_save(convertDataToString());
    std::ofstream out_file;
    out_file.open(data_path_.string());
    out_file << data_to_save;
    out_file.close();
}

void DataPersistence::updateData(const std::vector<InternalData>& new_data)
{
    data_ = new_data;
}

void DataPersistence::loadFile()
{
    std::string id;
    std::string name;
    std::map<std::string, std::string> data_values;

    std::ifstream in_file;
    in_file.open(data_path_.string());

    std::unique_ptr<InternalData> cur_data;

    while (!in_file.eof())
    {
        std::string current_line;
        getline(in_file, current_line);

        auto first_marker_pos = current_line.find_first_of('@');
        auto second_marker = current_line.find_first_of(':');

        if (first_marker_pos != std::string::npos && second_marker != std::string::npos)
        {
            auto data_type = current_line.substr(first_marker_pos + 1, second_marker - 1);
            auto data_value = current_line.substr(second_marker+1);

            if (data_type == "ID")
            {
                id = data_value;
            }
            else if (data_type == "Name")
            {
                name = data_value;

                if (cur_data)
                {
                    data_.emplace_back(*cur_data);
                }

                cur_data = std::make_unique<InternalData>(id, name);
            }
            else
            {
                cur_data->setData(data_type, data_value);
            }
        }
    }

    //adds last entry
    data_.emplace_back(*cur_data);
}

std::string DataPersistence::convertDataToString() const
{
    std::string converted_data;

    for (const auto& cur_data : data_)
    {
        converted_data += "@ID:" + cur_data.getId() + "\n";
        converted_data += "@Name:" + cur_data.getName() + "\n";

        for (auto data_entry : cur_data.getData())
        {
            converted_data += "@" + data_entry.first + ":" + data_entry.second + "\n";
        }
    }
    return converted_data;
}