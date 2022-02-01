#include <string>
#include <iostream>
#define BUFF_SIZE 10
#define CHAR_STR_SIZE 32


class PrintfWrapper{
    char * buff_ptr;
    int free_space;
    int offset;
    int call_counter;
    void write(const char *s);
    void free_buff();
    public:
    void flush();
    PrintfWrapper(){
        buff_ptr = new char[BUFF_SIZE];
        free_space = BUFF_SIZE;
        offset = 0;
        call_counter = 0;
    }
    ~PrintfWrapper(){
        std::cout << "destructor:" <<std::endl;
        flush();
        delete[] buff_ptr;
    }
    void print(const char *str);
};
