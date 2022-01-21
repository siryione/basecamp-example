#include <iostream>
#include <memory>
#include <string>

using std::endl;
using std::cout;
using std::unique_ptr;
using std::make_unique;
using std::string;
using std::ostream;


struct Some_struct {
    string name;
    int value;
};

ostream& operator<<(ostream& os, const Some_struct some_struct){
    os << some_struct.name << ", " << some_struct.value;
    return os;
}

template <typename T>
void unique_ptr_print(unique_ptr<T>& up) {
    unique_ptr_print<T>(up);
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

    // // SMART POINTERS
    // cout << "\nSmart pointers" << endl;
    // unique_ptr<Some_struct> ptr_initialized = make_unique<Some_struct>("some string", 10);
    // unique_ptr<Some_struct> ptr_uninitialized;

    // // print addresses
    // // initialized
    // cout << "address of the initialized pointer: " << &ptr_initialized << endl;
    // cout << "address that initialized pointer points to: " << ptr_initialized.get() << endl;
    // unique_ptr_print<Some_struct>(ptr_initialized);

    // // uninitialized
    // cout << "\naddress of the uninitialized pointer: " << &ptr_uninitialized << endl;
    // // cout << "address that uninitialized pointer points to: " << ptr_uninitialized.get() << endl;  -- pointing to 0, therefore the atempt of reaching 
    // // cout << "value that uninitialized pointer points to: " << *(ptr_uninitialized.get()) << endl; -- its value outside the stack leads to -> segfault

    // // move ownership
    // ptr_uninitialized = move(ptr_initialized);

    // // print addresses
    // // initialized
    // cout << "address of the initialized pointer: " << &ptr_initialized << endl;
    // // cout << "address that initialized pointer points to: " << ptr_initialized.get() << endl; --behaviour changed vice versa
    // // cout << "value that initialized pointer points to: " << *(ptr_initialized.get()) << endl;

    // // uninitialized
    // cout << "\naddress of the uninitialized pointer: " << &ptr_uninitialized << endl;
    // cout << "address that uninitialized pointer points to: " << ptr_uninitialized.get() << endl; 
    // cout << "value that uninitialized pointer points to: " << *(ptr_uninitialized.get()) << endl;


    return 0;
}