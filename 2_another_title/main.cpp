#include <iostream>
#define COLUMN 4
#define ROW 2


int main(){
    // DECLARING POINTERS
    // declare and assign 

    int * ptr_int_to_var;
    const char * ptr_char_to_const;
    // float * const ptr_float_const_to_var;        -- const pointers must be initialized
    // const bool * const ptr_bool_const_to_const;  -- const pointers must be initialized

    int var_int = 1;
    float var_float = 0.2f;
    const char var_const_char = 'A';
    const bool var_const_bool = true;

    ptr_int_to_var = &var_int;
    ptr_char_to_const = &var_const_char;

    float * const ptr_float_const_to_var = &var_float;
    const bool * const ptr_bool_const_to_const = &var_const_bool;

    // change pointers' values
    float float_modifier = .15f;
    int int_modifier = 10;
    bool bool_modifier = false;

    ptr_int_to_var = (int *)&float_modifier;
    // ptr_float_const_to_var = (float *)&int_modifier; -- assignment of read-only variable
    ptr_char_to_const = (char *)&int_modifier;
    // ptr_bool_const_to_const = &bool_modifier; -- assignment of read-only variable
    
    
    // change values pointed to by the pointers

    * ptr_int_to_var = 10;
    * ptr_float_const_to_var = 0.1f; 
    // * ptr_char_to_const = 'B'; -- assignment of read-only location
    // * ptr_bool_const_to_const = false; -- assignment of read-only location ‘* ptr_bool_const_to_const’
  

    // ARRAYS AND POINTER ARITHMETIC
    // create a C-style array of some type and fill it with values

    char arr[] = {'A', 'a', 'b', 'B'};
    // char arr[] = {'A', 'a', 'b', 'B', '\00'};
    // char arr[] = "AaBb";
    
    // modify and print each value of the array

    char mod_values[] = {'c', 'd', 'e', 'f'};
    for(int index = 0; index < sizeof(arr) && index < sizeof(mod_values); index++){
        std::cout << index << "# arr index value before modification: " << arr[index] << std::endl;
        arr[index] = {mod_values[index]};
        std::cout << index << "# arr index value after modification: " << arr[index] << std::endl;
    }

    // declare a pointer for the beginning of the arr

    char *ptr_arr = arr;
    std::cout << "\nArray address: " << &ptr_arr << std::endl;

    // modify and print values using pointer arithmetic


    char mod_ptr_values[] = {'C', 'D', 'E', 'F'};
    for(int index = 0; index < sizeof(arr) && index < sizeof(mod_ptr_values); index++){
        
        std::cout << index << "# mem cell value before modification: " << *ptr_arr << ", int adress: " << (long int)ptr_arr << std::endl;
        *ptr_arr = mod_ptr_values[index];
        std::cout << index << "# mem cell value after modification: " << *ptr_arr << std::endl;

        ptr_arr++;
    }




    // EXTRA TASK 
    std::cout << "\nExtra task" << std::endl;
    char arr_2dim[ROW][COLUMN] = {{'A', 'a', 'b', 'B'}, {'c', 'd', 'e', 'f'}};

    
    // modify and print each value of the array

    char mod_values_2dim[ROW][COLUMN] = {{'c', 'd', 'e', 'f'}, {'A', 'a', 'b', 'B'}};
    int index = 0;
    for(int row = 0; row < ROW; row++){
        for(int column = 0; column < COLUMN; column++){

        std::cout << index << "# arr element value before modification: " << arr_2dim[row][column] << std::endl;
        arr_2dim[row][column] = {mod_values_2dim[row][column]};
        std::cout << index << "# arr element value after modification: " << arr_2dim[row][column] << std::endl;
        }
    }
    index = 0;

    // declare a pointer for the beginning of the arr

    char (*ptr_arr_2dim)[COLUMN] = arr_2dim;
    std::cout << "\nArray address: " << &ptr_arr_2dim << std::endl;

    // modify and print values using pointer arithmetic

    char mod_ptr_values_2dim[ROW][COLUMN] = {{'C', 'D', 'E', 'F'}, {'G', 'H', 'I', 'J'}};
    for(int row = 0; row < ROW; row++){
        for(int column = 0; column < COLUMN; column++){

            std::cout << index << "# mem cell value before modification: " << (*ptr_arr_2dim)[column] << ", int adress: " << index + (long int)ptr_arr_2dim << std::endl;
            (*ptr_arr_2dim)[column] = mod_ptr_values_2dim[row][column];

            std::cout << index << "# mem cell value after modification: " << (*ptr_arr_2dim)[column] << std::endl;
            
            index++;
        }
        ptr_arr_2dim++;
    }
    index = 0;

    return 0;
}
