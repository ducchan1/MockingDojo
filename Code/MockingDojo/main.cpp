#include <iostream>

#include "InternalDataUser.h"

int main(int argc, char** argv)
{
    std::cout << "main called" << std::endl;
    std::cout << "loading data..." << std::endl;

    std::tr2::sys::path data_path("..\\MockingData");
    InternalDataUser data_user(data_path);

    std::vector <std::string> loaded_data_names(data_user.getDataNames());
    std::cout << "Found " << loaded_data_names.size() << " items" << std::endl;

    for (const auto& name : loaded_data_names)
    {
        std::cout << "Item: " << name << std::endl;
    }

    system("pause");

    return 0;
}