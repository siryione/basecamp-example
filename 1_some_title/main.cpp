#include <iostream>


bool GLOBAL_BOOL = true;
bool* GLOBAL_BOOL_POINTER = &GLOBAL_BOOL;
bool &GLOBAL_BOOL_REFERENCE = GLOBAL_BOOL;
static bool GLOBAL_BOOL_STATIC = false;
const bool GLOBAL_BOOL_CONST = false;
const bool* GLOBAL_BOOL_POINTER_CONST = &GLOBAL_BOOL_CONST;
const bool &GLOBAL_BOOL_REFERENCE_CONST = GLOBAL_BOOL_CONST;
const static bool GLOBAL_BOOL_STATIC_CONST = true;

int GLOBAL_INT = 0;
int* GLOBAL_INT_POINTER = &GLOBAL_INT;
int &GLOBAL_INT_REFERENCE = GLOBAL_INT;
static int GLOBAL_INT_STATIC = 1;
const int GLOBAL_INT_CONST = 2;
const int* GLOBAL_INT_POINTER_CONST = &GLOBAL_INT_CONST;
const int &GLOBAL_INT_REFERENCE_CONST = GLOBAL_INT_CONST;
const static int GLOBAL_INT_STATIC_CONST = 3;

float GLOBAL_FLOAT = 4.0f;
float* GLOBAL_FLOAT_POINTER = &GLOBAL_FLOAT;
float &GLOBAL_FLOAT_REFERENCE = GLOBAL_FLOAT;
static float GLOBAL_FLOAT_STATIC = 5.0f;
const float GLOBAL_FLOAT_CONST = 6.0f;
const float* GLOBAL_FLOAT_POINTER_CONST = &GLOBAL_FLOAT_CONST;
const float &GLOBAL_FLOAT_REFERENCE_CONST = GLOBAL_FLOAT_CONST;
const static float GLOBAL_FLOAT_STATIC_CONST = 7.0f;

double GLOBAL_DOUBLE = 8.0;
double* GLOBAL_DOUBLE_POINTER = &GLOBAL_DOUBLE;
double &GLOBAL_DOUBLE_REFERENCE = GLOBAL_DOUBLE;
static double GLOBAL_DOUBLE_STATIC = 9.0;
const double GLOBAL_DOUBLE_CONST = 10.0;
const double* GLOBAL_DOUBLE_POINTER_CONST = &GLOBAL_DOUBLE_CONST;
const double &GLOBAL_DOUBLE_REFERENCE_CONST = GLOBAL_DOUBLE_CONST;
const static double GLOBAL_DOUBLE_STATIC_CONST = 11.0;

char GLOBAL_CHAR = 'a';
char* GLOBAL_CHAR_POINTER = &GLOBAL_CHAR;
char &GLOBAL_CHAR_REFERENCE = GLOBAL_CHAR;
static char GLOBAL_CHAR_STATIC = 'b';
const char GLOBAL_CHAR_CONST = 'c';
const char* GLOBAL_CHAR_POINTER_CONST = &GLOBAL_CHAR_CONST;
const char &GLOBAL_CHAR_REFERENCE_CONST = GLOBAL_CHAR_CONST;
const static char GLOBAL_CHAR_STATIC_CONST = 'd';

unsigned char GLOBAL_UNSIGNED_CHAR = '1';
unsigned char* GLOBAL_UNSIGNED_CHAR_POINTER = &GLOBAL_UNSIGNED_CHAR;
unsigned char &GLOBAL_UNSIGNED_CHAR_REFERENCE = GLOBAL_UNSIGNED_CHAR;
static unsigned char GLOBAL_UNSIGNED_CHAR_STATIC = '2';
const unsigned char GLOBAL_UNSIGNED_CHAR_CONST = '3';
const unsigned char* GLOBAL_UNSIGNED_CHAR_POINTER_CONST = &GLOBAL_UNSIGNED_CHAR_CONST;
const unsigned char &GLOBAL_UNSIGNED_CHAR_REFERENCE_CONST = GLOBAL_UNSIGNED_CHAR_CONST;
const static unsigned char GLOBAL_UNSIGNED_CHAR_STATIC_CONST = '4';


// int GLOBAL_VARS_WITH_SAME_NAME;
// int GLOBAL_VARS_WITH_SAME_NAME; --main.cpp:60:5: error: redefinition of ‘int GLOBAL_VARS_WITH_SAME_NAME’

int main(){
    // int local_vars_with_same_name;
    // int local_vars_with_same_name; --main.cpp: In function ‘int main()’: main.cpp:64:9: error: redeclaration of ‘int local_vars_with_same_name’

    // const int to_change = 10;
    // to_change = 100; --main.cpp: In function ‘int main()’:main.cpp:67:15: error: assignment of read-only variable ‘to_change’

    // int &reference_with_no_assigned_value; --main.cpp: In function ‘int main()’:main.cpp:69:10: error: ‘reference_with_no_assigned_value’ declared as reference but not initialized

    // int var = 10;
    // char* var_pointer = &var; -- main.cpp: In function ‘int main()’:main.cpp:72:25: error: cannot convert ‘int*’ to ‘char*’ in initialization

    // int* ptr = NULL;
    // std::cout << *ptr << std::endl; -- Segmentation fault (core dumped)

    // int* ptr = nullptr;
    // std::cout << *ptr << std::endl; -- Segmentation fault (core dumped)

    // int var;
    // *var = 0; -- main.cpp: In function ‘int main()’:main.cpp:81:6: error: invalid type argument of unary ‘*’ (have ‘int’)

    // int *var;
    // *var = "some_string"; // -- main.cpp: In function ‘int main()’:main.cpp:84:11: error: invalid conversion from ‘const char*’ to ‘int’ [-fpermissive]

    // int* ptr;
    // ptr("some_string"); -- main.cpp:87:22: error: ‘ptr’ cannot be used as a function


    bool local_bool = true;
    bool* local_bool_pointer = &local_bool;
    bool &local_bool_reference = local_bool;
    static bool local_bool_static = false;
    const bool local_bool_const = false;
    const bool* local_bool_pointer_const = &local_bool_const;
    const bool &local_bool_reference_const = local_bool_const;
    const static bool local_bool_static_const = true;

    int local_int = 0;
    int* local_int_pointer = &local_int;
    int &local_int_reference = local_int;
    static int local_int_static = 1;
    const int local_int_const = 2;
    const int* local_int_pointer_const = &local_int_const;
    const int &local_int_reference_const = local_int_const;
    const static int local_int_static_const = 3;

    float local_float = 4.0f;
    float* local_float_pointer = &local_float;
    float &local_float_reference = local_float;
    static float local_float_static = 5.0f;
    const float local_float_const = 6.0f;
    const float* local_float_pointer_const = &local_float_const;
    const float &local_float_reference_const = local_float_const;
    const static float local_float_static_const = 7.0f;

    double local_double = 8.0;
    double* local_double_pointer = &local_double;
    double &local_double_reference = local_double;
    static double local_double_static = 9.0;
    const double local_double_const = 10.0;
    const double* local_double_pointer_const = &local_double_const;
    const double &local_double_reference_const = local_double_const;
    const static double local_double_static_const = 11.0;

    char local_char = 'a';
    char* local_char_pointer = &local_char;
    char &local_char_reference = local_char;
    static char local_char_static = 'b';
    const char local_char_const = 'c';
    const char* local_char_pointer_const = &local_char_const;
    const char &local_char_reference_const = local_char_const;
    const static char local_char_static_const = 'd';

    unsigned char local_unsigned_char = '1';
    unsigned char* local_unsigned_char_pointer = &local_unsigned_char;
    unsigned char &local_unsigned_char_reference = local_unsigned_char;
    static unsigned char local_unsigned_char_static = '2';
    const unsigned char local_unsigned_char_const = '3';
    const unsigned char* local_unsigned_char_pointer_const = &local_unsigned_char_const;
    const unsigned char &local_unsigned_char_reference_const = local_unsigned_char_const;
    const static unsigned char local_unsigned_char_static_const = '4';


    // print the values and adresses of each variable and constant you have
    // GLOBAL

    std::cout << "Values and adresses of each variable and constant" << std::endl;
    std::cout << "GLOBAL\n" << std::endl;

    std::cout << GLOBAL_BOOL << std::endl;
    std::cout << GLOBAL_BOOL_POINTER << std::endl;
    std::cout << GLOBAL_BOOL_REFERENCE << std::endl;
    std::cout << GLOBAL_BOOL_STATIC << std::endl;
    std::cout << GLOBAL_BOOL_CONST << std::endl;
    std::cout << GLOBAL_BOOL_POINTER_CONST << std::endl;
    std::cout << GLOBAL_BOOL_REFERENCE_CONST << std::endl;
    std::cout << GLOBAL_BOOL_STATIC_CONST << std::endl;


    std::cout << GLOBAL_INT << std::endl;
    std::cout << GLOBAL_INT_POINTER << std::endl;
    std::cout << GLOBAL_INT_REFERENCE << std::endl;
    std::cout << GLOBAL_INT_STATIC << std::endl;
    std::cout << GLOBAL_INT_CONST << std::endl;
    std::cout << GLOBAL_INT_POINTER_CONST << std::endl;
    std::cout << GLOBAL_INT_REFERENCE << std::endl;
    std::cout << GLOBAL_INT_STATIC << std::endl;


    std::cout << GLOBAL_FLOAT << std::endl;
    std::cout << GLOBAL_FLOAT_POINTER << std::endl;
    std::cout << GLOBAL_FLOAT_REFERENCE << std::endl;
    std::cout << GLOBAL_FLOAT_STATIC << std::endl;
    std::cout << GLOBAL_FLOAT_CONST << std::endl;
    std::cout << GLOBAL_FLOAT_POINTER_CONST << std::endl;
    std::cout << GLOBAL_FLOAT_REFERENCE_CONST << std::endl;
    std::cout << GLOBAL_FLOAT_STATIC_CONST << std::endl;


    std::cout << GLOBAL_DOUBLE << std::endl;
    std::cout << GLOBAL_DOUBLE_POINTER << std::endl;
    std::cout << GLOBAL_DOUBLE_REFERENCE << std::endl;
    std::cout << GLOBAL_DOUBLE_STATIC << std::endl;
    std::cout << GLOBAL_DOUBLE_CONST << std::endl;
    std::cout << GLOBAL_DOUBLE_POINTER_CONST << std::endl;
    std::cout << GLOBAL_DOUBLE_REFERENCE_CONST << std::endl;
    std::cout << GLOBAL_DOUBLE_STATIC_CONST << std::endl;


    std::cout << GLOBAL_CHAR << std::endl;
    std::cout << GLOBAL_CHAR_POINTER << std::endl;
    std::cout << GLOBAL_CHAR_REFERENCE << std::endl;
    std::cout << GLOBAL_CHAR_STATIC << std::endl;
    std::cout << GLOBAL_CHAR_CONST << std::endl;
    std::cout << GLOBAL_CHAR_POINTER_CONST << std::endl;
    std::cout << GLOBAL_CHAR_REFERENCE_CONST << std::endl;
    std::cout << GLOBAL_CHAR_STATIC_CONST << std::endl;


    std::cout << GLOBAL_UNSIGNED_CHAR << std::endl;
    std::cout << GLOBAL_UNSIGNED_CHAR_POINTER << std::endl;
    std::cout << GLOBAL_UNSIGNED_CHAR_REFERENCE << std::endl;
    std::cout << GLOBAL_UNSIGNED_CHAR_STATIC << std::endl;
    std::cout << GLOBAL_UNSIGNED_CHAR_CONST << std::endl;
    std::cout << GLOBAL_UNSIGNED_CHAR_POINTER_CONST << std::endl;
    std::cout << GLOBAL_UNSIGNED_CHAR_REFERENCE_CONST << std::endl;
    std::cout << GLOBAL_UNSIGNED_CHAR_STATIC_CONST << std::endl;


    // local

    std::cout << "\nlocal\n" << std::endl;

    std::cout << local_bool << std::endl;
    std::cout << local_bool_pointer << std::endl;
    std::cout << local_bool_reference << std::endl;
    std::cout << local_bool_static << std::endl;
    std::cout << local_bool_const << std::endl;
    std::cout << local_bool_pointer_const << std::endl;
    std::cout << local_bool_reference_const << std::endl;
    std::cout << local_bool_static_const << std::endl;


    std::cout << local_int << std::endl;
    std::cout << local_int_pointer << std::endl;
    std::cout << local_int_reference << std::endl;
    std::cout << local_int_static << std::endl;
    std::cout << local_int_const << std::endl;
    std::cout << local_int_pointer_const << std::endl;
    std::cout << local_int_reference << std::endl;
    std::cout << local_int_static << std::endl;


    std::cout << local_float << std::endl;
    std::cout << local_float_pointer << std::endl;
    std::cout << local_float_reference << std::endl;
    std::cout << local_float_static << std::endl;
    std::cout << local_float_const << std::endl;
    std::cout << local_float_pointer_const << std::endl;
    std::cout << local_float_reference_const << std::endl;
    std::cout << local_float_static_const << std::endl;


    std::cout << local_double << std::endl;
    std::cout << local_double_pointer << std::endl;
    std::cout << local_double_reference << std::endl;
    std::cout << local_double_static << std::endl;
    std::cout << local_double_const << std::endl;
    std::cout << local_double_pointer_const << std::endl;
    std::cout << local_double_reference_const << std::endl;
    std::cout << local_double_static_const << std::endl;


    std::cout << local_char << std::endl;
    std::cout << local_char_pointer << std::endl;
    std::cout << local_char_reference << std::endl;
    std::cout << local_char_static << std::endl;
    std::cout << local_char_const << std::endl;
    std::cout << local_char_pointer_const << std::endl;
    std::cout << local_char_reference_const << std::endl;
    std::cout << local_char_static_const << std::endl;


    std::cout << local_unsigned_char << std::endl;
    std::cout << local_unsigned_char_pointer << std::endl;
    std::cout << local_unsigned_char_reference << std::endl;
    std::cout << local_unsigned_char_static << std::endl;
    std::cout << local_unsigned_char_const << std::endl;
    std::cout << local_unsigned_char_pointer_const << std::endl;
    std::cout << local_unsigned_char_reference_const << std::endl;
    std::cout << local_unsigned_char_static_const << std::endl;


    // Modify all references 

    GLOBAL_BOOL_REFERENCE = false;
    // GLOBAL_BOOL_REFERENCE_CONST = true; -- constants can not be modified (must be a modifieble value)
    GLOBAL_INT_REFERENCE = 20;
    GLOBAL_FLOAT_REFERENCE = 30.0f;
    GLOBAL_DOUBLE_REFERENCE = 40.0;
    GLOBAL_CHAR_REFERENCE = 'z';
    GLOBAL_UNSIGNED_CHAR_REFERENCE = 'x';

    local_bool_reference = false;
    local_int_reference = 20;
    local_float_reference = 30.0f;
    local_double_reference = 40.0;
    local_char_reference = 'z';
    local_unsigned_char_reference = 'x';

    // print original variables values

    std::cout << "\nOriginal vars after modifying references\n" << std::endl; 

    std::cout << GLOBAL_BOOL << std::endl;
    std::cout << GLOBAL_INT << std::endl;
    std::cout << GLOBAL_FLOAT << std::endl;
    std::cout << GLOBAL_DOUBLE << std::endl;
    std::cout << GLOBAL_CHAR << std::endl;
    std::cout << GLOBAL_UNSIGNED_CHAR << std::endl;

    std::cout << local_bool << std::endl;
    std::cout << local_int << std::endl;
    std::cout << local_float << std::endl;
    std::cout << local_double << std::endl;
    std::cout << local_char << std::endl;
    std::cout << local_unsigned_char << std::endl;

    // Modify all variables

    GLOBAL_BOOL = true;
    // GLOBAL_BOOL_CONST = true; -- constants can not be modified (must be a modifieble value)
    GLOBAL_INT = 120;
    GLOBAL_FLOAT = 130.0f;
    GLOBAL_DOUBLE = 140.0;
    GLOBAL_CHAR = 'q';
    GLOBAL_UNSIGNED_CHAR = 'y';

    local_bool = true;
    local_int = 120;
    local_float = 130.0f;
    local_double = 140.0;
    local_char = 'q';
    local_unsigned_char = 'y';

    // print references

    std::cout << "\nReferences after modifying variables\n" << std::endl; 

    std::cout << GLOBAL_BOOL_REFERENCE << std::endl;
    std::cout << GLOBAL_INT_REFERENCE << std::endl;
    std::cout << GLOBAL_FLOAT_REFERENCE << std::endl;
    std::cout << GLOBAL_DOUBLE_REFERENCE << std::endl;
    std::cout << GLOBAL_CHAR_REFERENCE << std::endl;
    std::cout << GLOBAL_UNSIGNED_CHAR_REFERENCE << std::endl;

    std::cout << local_bool_reference << std::endl;
    std::cout << local_int_reference << std::endl;
    std::cout << local_float_reference << std::endl;
    std::cout << local_double_reference << std::endl;
    std::cout << local_char_reference << std::endl;
    std::cout << local_unsigned_char_reference << std::endl;

    // assign a value of a different type to a specific type variable

    int var_int_float = 10.0f;
    double var_double_int = 10;
    int var_int_char = 'a';
    char var_char_int = 10;
    unsigned char var_uchar_int = 10;

    std::cout << "\nVariables with odd value types\n" << std::endl;

    std::cout << "[log] variable int with float value assigned: " << var_int_float << std::endl; // 10
    std::cout << "[log] variable double with int value assigned: " << var_double_int << std::endl; // 10
    std::cout << "[log] variable int with char value assigned: " << var_int_char << std::endl; // decimal value of 'a' char in ASCII table: 97
    std::cout << "[log] variable char with int value assigned: " << var_char_int << std::endl; // new line
    std::cout << "[log] variable unsigned with int value assigned: " << var_uchar_int << std::endl; // new line

    // assign an address of a specific variable to a pointer

    int specific_variable = 100;
    int* address = &specific_variable;

    std::cout << "\nChanging and printing pointer values\n" << std::endl;

    std::cout << "[log] pointer value: " << *address << std::endl; // 100

    *address = 1000;

    std::cout << "[log] variable value after modification of pointer value: " << specific_variable << std::endl; // 1000

    // create auto-type variable, assign a value, get its type

    auto auto_float = 1.234567f;
    
    std::cout << "\ngetting actual data type of auto variable: " << typeid(auto_float).name() << std::endl; // f --float


    return 0;
}
