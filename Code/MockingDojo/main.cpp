#include <iostream>

#include "InternalDataUser.h"

int main(int argc, char** argv)
{
    std::cout << "main called" << std::endl;
    std::cout << "loading data..." << std::endl;

    std::tr2::sys::path data_path("C:\work\Formation\Mocking\MockingData");
    InternalDataUser data_user(data_path);

    return 0;
}