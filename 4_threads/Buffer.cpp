
#include "Buffer.hpp"

void Buffer::push(const char *data){
    int text_length = 0;
    while(data[text_length]){
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
            *(buff_ptr+offset+i) = data[i];
            free_space--;
        }
        offset += text_length;
    }
}

char * Buffer::read(){
    for(int i = 0; i < offset; i++){
        char *data;
        *(data+i) = *(buff_ptr+i);
    }
    free_buff();
}

// Private

void Buffer::free_buff(){
    delete[] buff_ptr;
    offset = 0;
    buff_ptr = new char[BUFF_SIZE];
}
