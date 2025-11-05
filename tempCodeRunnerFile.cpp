#include <iostream>
#include <list>
#include <filesystem>
using namespace std;

namespace fs = std::filesystem;


int main() {


    std::string path;
    std::cout << "Enter the path you want to search in : ";
    std::cin >> path;

    std::string keyword;
    std::cout << "Enter what you want to search : ";
    std::cin >> keyword;


    fs::path filePath = path;
    if(!fs::exists(path)) {
        std::cerr << "File not found" << std::endl;
        return;
    }
    return 0;
}

