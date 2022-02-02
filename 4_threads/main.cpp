#include <iostream>
#include <thread>
#include <fstream>
#include <string>
#include <mutex>
#define N 10

struct Buffer
{
    char data[N];
    bool is_full;
};

std::mutex mtx;
Buffer buffer;
std::ifstream file("textfile.txt");

void thread1_function(){
    std::cout << "[log]: thread1 function entrance" << std::endl;
    while(!file.eof()){
        mtx.lock();
        if(buffer.is_full){
            mtx.unlock();
            continue;
        }
        file.read(buffer.data, N);
        buffer.is_full = true;

        mtx.unlock();
    }
    std::cout << "[log]: thread1 function exit" << std::endl;
}

void thread2_function(){
    std::cout << "[log]: thread2 function entrance" << std::endl;
    bool last_buff_read = false;
    while(!last_buff_read){
        mtx.lock();
        if(file.eof()){
            last_buff_read = true;
        }
        if(buffer.is_full){
            for(auto &c: buffer.data){
                std::cout << c;
            } 
            std::cout << std::endl;
            buffer.is_full = false;
        }
        mtx.unlock();
    }
    std::cout << std::endl;
    std::cout << "[log]: thread2 function exit" << std::endl;
}

int main(){
    if(file.is_open()){
        std::thread first(thread1_function);
        std::thread second(thread2_function);
        first.join();
        second.join();
    }
    else{
        return 1;
    }
    return 0;
}
