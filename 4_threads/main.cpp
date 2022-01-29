#include <iostream>
#include <thread>
#include <fstream>
#include "Buffer.hpp"

int main(){
    Buffer buffer = Buffer();
    auto res = buffer.read();

    std::ofstream MyFile("textfile.txt");
    std::thread first(MyFile << res);
    return 0;
}