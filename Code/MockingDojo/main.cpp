#include <iostream>

#include "InternalDataUser.h"
#include "DataPersistence.h"

int main(int argc, char** argv)
{
    std::cout << "main called" << std::endl;
    std::cout << "loading data..." << std::endl;

    std::tr2::sys::path data_path("..\\MockingData\\MockingData1.txt");
    auto data_persistence = std::make_unique<DataPersistence>(data_path);
    InternalDataUser data_user(std::move(data_persistence));

    std::vector <std::string> loaded_data_names(data_user.getDataNames());
    std::cout << "Found " << loaded_data_names.size() << " items" << std::endl;

    for (const auto& name : loaded_data_names)
    {
        std::cout << "Item: " << name << std::endl;
    }

    system("pause");

    return 0;
}