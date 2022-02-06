#include <iostream>
#include <thread>
#include <fstream>
#include <string>
#include <mutex>
#include <csignal>

const int kBufferSize = 10;

struct Buffer {
    char data[kBufferSize];
    bool is_full;
};

std::thread first;
std::thread second;
std::mutex mtx;
Buffer buffer;
std::ifstream file("textfile.txt");

void SignalHandler(int signum){
    std::cout << "Interrupt signal (" << signum << ") received.\n";
    first.join();
    second.join();
    std::cout << "Program gracefully finished!";
    exit(signum);  
}

void FirstThreadFunction(){
    std::cout << "[log]: thread1 function entrance" << std::endl;
    while(!file.eof()){
        mtx.lock();
        if(buffer.is_full){
            mtx.unlock();
            continue;
        }
        file.read(buffer.data, kBufferSize);
        buffer.is_full = true;

        mtx.unlock();
    }
    std::cout << "[log]: thread1 function exit" << std::endl;
}

void SecondThreadFunction(){
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
    if(!file.is_open()){
        return 1;
    }
    first = std::thread(FirstThreadFunction);
    second = std::thread(SecondThreadFunction);
    std::signal(SIGINT, SignalHandler);
    first.join();
    second.join();
    return 0;
}
