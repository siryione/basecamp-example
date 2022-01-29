#include <iostream>
#include <cstdio>
#include <ctime>
#include "PrintfWrapper.hpp"


// Public

void PrintfWrapper::print(const char *str){
    call_counter++;
    write(str);
    if(call_counter == 3){
        flush();
        call_counter = 0;
    }
}

// Private

void PrintfWrapper::write(const char *str){
    int text_length = 0;
    while(str[text_length]){
        text_length++;
    }
    if(text_length > free_space){
        char *container = new char[(int)(text_length*1.2)];        ;
        for(int i = 0; i < text_length; i++){
            *(container+i) = *(buff_ptr+i);
        }
        delete[] buff_ptr;
        buff_ptr = new char[(int)((BUFF_SIZE+text_length) * 1.15)];
        free_space = (int)((BUFF_SIZE+text_length) * 1.15);
        for(int address = 0; address < text_length; address++){
            *(buff_ptr+address) = *(container + address);
        }
        delete[] container;
    }

    if(text_length != 0 && text_length <= free_space){
        for(int i = 0; i < text_length; i++){
            *(buff_ptr+offset+i) = str[i];
            free_space--;
        }
        offset += text_length;
    }
}

void PrintfWrapper::flush(){
    clock_t start_time, end_time, delta_printf;
    delta_printf = 0;
    for(int i = 0; i < offset; i++){
        start_time = clock();
        std::printf("%c", *(buff_ptr+i));
        end_time = clock();
        delta_printf += (end_time - start_time);
    }
    std::cout << std::endl;
    std::cout << "printf execution: " << delta_printf << " ms" << std::endl;
    free_buff();
}

void PrintfWrapper::free_buff(){
    offset = 0;
    delete[] buff_ptr;
    buff_ptr = new char[BUFF_SIZE];
}
