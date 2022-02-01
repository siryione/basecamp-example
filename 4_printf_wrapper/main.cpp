#include <ctime>
#include <iostream>
#include "PrintfWrapper.hpp"


int main(){
    clock_t start_time, end_time, delta_printf, delta_cout;
    
    PrintfWrapper pw;
    pw.print("so");
    pw.print("me_string");
    pw.print("!");
    pw.print("another string");

    std::cout << std::endl;
    std::cout << "std::cout" << std::endl;
    start_time = clock();
    std::cout << "some_string!" << std::endl;
    end_time = clock();
    delta_cout = end_time - start_time;
    std::cout << "Cout execution: " << delta_cout << " ms" << std::endl;
    std::cout << std::endl;

    return 0;
}
