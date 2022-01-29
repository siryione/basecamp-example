#define BUFF_SIZE 128

class Buffer{
    char *buff_ptr;
    int offset;
    int free_space;
    void free_buff();
    public:
    void push(const char *d);
    char * read();
    Buffer(){
        buff_ptr = new char[BUFF_SIZE];
        offset = 0;
        free_space = 0;
    }
    ~Buffer(){
        delete[] buff_ptr;
    }
};
