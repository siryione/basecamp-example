#include <iostream>
#include <memory>
#include <string>

using std::endl;
using std::cout;
using std::unique_ptr;
using std::make_unique;
using std::shared_ptr;
using std::make_shared;
using std::string;
using std::ostream;


struct Some_struct {
    string name;
    int value;
    Some_struct(string name, int value);
};

Some_struct::Some_struct(string n, int v):name{n}, value{v}{}

ostream& operator<<(ostream& os, const Some_struct& some_struct){
    os << some_struct.name << ", " << some_struct.value;
    return os;
}

int main(){
    // NEW AND DELETE OPERATORS

    // allocate memory of type int dynamicalle with the new operator and hold it with a provided pointer
    cout << "Allocation of a single integer" << endl;
    int *ptr = new int;

    // set a value
    *ptr = 10;

    // print a pointer and its value
    cout << *ptr << " - value stored at: " << ptr << " address" << endl;

    // free allocated memory
    delete ptr;
    
    // same steps with an array
    cout << "\nAllocation of an array" << endl;
    int *ptr_arr = new int [3];

    for(int index = 0; index < 3; index++){
        ptr_arr[index] = rand();
    }

    for(int index = 0; index < 3; index++){
        cout << *(ptr_arr + index) << " - value stored at: " << index + ptr_arr << " address" << endl;
    }
    
    delete[] ptr_arr;

    // SMART POINTERS
    cout << "\nSmart pointers" << endl;
    // unique pointers
    cout << "Unique_ptr" << endl;
    unique_ptr<Some_struct> ptr_initialized = make_unique<Some_struct>("some string", 10);
    unique_ptr<Some_struct> ptr_uninitialized_unique;

    // print addresses
    // initialized
    cout << "address of the initialized pointer: " << &ptr_initialized << endl;
    cout << "address that initialized pointer points to: " << ptr_initialized.get() << endl;
    cout << "value that initialized pointer points to: " << *ptr_initialized << endl;

    // uninitialized
    cout << "\naddress of the uninitialized pointer: " << &ptr_uninitialized_unique << endl;
    // cout << "address that uninitialized pointer points to: " << ptr_uninitialized_unique.get() << endl;  -- pointing to 0, therefore the atempt of reaching 
    // cout << "value that uninitialized pointer points to: " << *(ptr_uninitialized_unique.get()) << endl; -- its value outside the stack leads to -> segfault

    // move ownership
    ptr_uninitialized_unique = move(ptr_initialized);

    // print addresses
    // initialized
    cout << "address of the initialized pointer: " << &ptr_initialized << endl;
    // cout << "address that initialized pointer points to: " << ptr_initialized.get() << endl; --behaviour changed vice versa
    // cout << "value that initialized pointer points to: " << *(ptr_initialized.get()) << endl;

    // uninitialized
    cout << "\naddress of the uninitialized pointer: " << &ptr_uninitialized_unique << endl;
    cout << "address that uninitialized pointer points to: " << ptr_uninitialized_unique.get() << endl; 
    cout << "value that uninitialized pointer points to: " << *(ptr_uninitialized_unique.get()) << endl;

    // shared pointers
    cout << "\nShared_ptr" << endl;
    shared_ptr<Some_struct> ptr_initialized_shared = make_shared<Some_struct>("another string", 20);
    shared_ptr<Some_struct> ptr_uninitialized_shared;
    {
        auto ptr_initialized_shared_inblock = ptr_initialized_shared;
        auto ptr_uninitialized_shared_inblock = ptr_uninitialized_shared;
        // print addresses
        // initialized
        cout << "\nInside block" << endl;
        cout << "address of the initialized pointer: " << &ptr_initialized_shared << endl;
        cout << "address that initialized pointer points to: " << ptr_initialized_shared.get() << endl;
        cout << "value that initialized pointer points to: " << *ptr_initialized_shared << endl;

        //initialized inblock
        cout << "address of the initialized inblock pointer: " << &ptr_initialized_shared_inblock << endl;
        cout << "address that initialized pointer inblock points to: " << ptr_initialized_shared_inblock.get() << endl;
        cout << "value that initialized pointer inblock points to: " << *ptr_initialized_shared_inblock << endl;

        // uninitialized
        cout << "\naddress of the uninitialized pointer: " << &ptr_uninitialized_shared << endl;
        // cout << "address that uninitialized pointer points to: " << ptr_uninitialized_shared.get() << endl; -- pointing to 0, therefore the atempt of reaching 
        // cout << "value that uninitialized pointer points to: " << *(ptr_uninitialized_shared.get()) << endl; -- its value outside the stack leads to -> segfault

        // uninitialized inblock
        cout << "\naddress of the uninitialized inblock pointer: " << &ptr_uninitialized_shared_inblock << endl;
        // cout << "address that uninitialized pointer points to: " << ptr_uninitialized_shared.get() << endl; -- pointing to 0, therefore the atempt of reaching 
        // cout << "value that uninitialized pointer points to: " << *(ptr_uninitialized_shared.get()) << endl; -- its value outside the stack leads to -> segfault
    
    }

    // print addresses
    // initialized
    cout << "\nOutside block" << endl;
    cout << "address of the initialized pointer: " << &ptr_initialized_shared << endl;
    cout << "address that initialized pointer points to: " << ptr_initialized_shared.get() << endl;
    cout << "value that initialized pointer points to: " << *ptr_initialized_shared << endl;

    //initialized inblock - killed after exiting block
    // cout << "address of the initialized pointer: " << &ptr_initialized_shared_inblock << endl; 
    // cout << "address that initialized pointer points to: " << ptr_initialized_shared_inblock.get() << endl; 
    // cout << "value that initialized pointer points to: " << *ptr_initialized_shared_inblock << endl;

    // uninitialized
    cout << "\naddress of the uninitialized pointer: " << &ptr_uninitialized_shared << endl;
    // cout << "address that uninitialized pointer points to: " << ptr_uninitialized_shared.get() << endl; -- pointing to 0, therefore the atempt of reaching 
    // cout << "value that uninitialized pointer points to: " << *(ptr_uninitialized_shared.get()) << endl; -- its value outside the stack leads to -> segfault

    // uninitialized inblock - killed after exiting block
    // cout << "\naddress of the uninitialized pointer: " << &ptr_uninitialized_shared_inblock << endl;
    // cout << "address that uninitialized pointer points to: " << ptr_uninitialized_shared.get() << endl; 
    // cout << "value that uninitialized pointer points to: " << *(ptr_uninitialized_shared.get()) << endl;
    
    
    // move ownership
    ptr_uninitialized_shared = move(ptr_initialized_shared);

    // print addresses
    // initialized
    cout << "address of the initialized pointer: " << &ptr_initialized_shared << endl;
    // cout << "address that initialized pointer points to: " << ptr_initialized_shared.get() << endl; -- behaviour changed vice versa
    // cout << "value that initialized pointer points to: " << *(ptr_initialized_shared.get()) << endl;

    // uninitialized
    cout << "\naddress of the uninitialized pointer: " << &ptr_uninitialized_shared << endl;
    cout << "address that uninitialized pointer points to: " << ptr_uninitialized_shared.get() << endl; 
    cout << "value that uninitialized pointer points to: " << *(ptr_uninitialized_shared.get()) << endl;



    return 0;
}
