#include <iostream>
#include <fstream>

void create_file()
{
    std::ofstream myfile;
    myfile.open ("example.txt");
    myfile << "Writing this to a file.\n";
    myfile.close();
}

int main()
{
    std::cout << "Hello, World!" << std::endl;
    std::cout << "Creating File!" << std::endl;
    create_file();
    return 0;
}