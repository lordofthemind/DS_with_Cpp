#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::ifstream file("example.txt");
    std::string line;

    if (file.is_open())
    {
        while (std::getline(file, line))
        {
            std::cout << line << std::endl;
        }
        file.close();
    }
    else
    {
        std::cerr << "Error opening file!" << std::endl;
    }

    return 0;
}
