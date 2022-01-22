# Answers

## Declaring pointers

### 1. Describe the difference between each of the used pointers.

Const pointers to const *cannot* be modified and *cannot* modify the values they are pointed to.<br/>
Const pointers to non-const *cannot* be modified but *can* modify the values they are pointed to.<br/>
Non-const pointers to const *can* be modified but *cannot* modify the values they are pointed to.<br/>
Non-const pointers to non-const *can* be modified and *can* modify the values they are pointed to.

### 2. Is it possible to change the value of the constant pointer after its definition? What if this pointer is left empty?

Constatnt pointer stores constant adress -> it cannot be modified. If const pointer is left empty you get an error: uninitialized const 'pointer_name'.

### 3. What is a purpose of constant pointers?

Their purpose is to protect the memory address from modifying during the execution of a program.

### 4. Is it possible to change the value which is pointed by a constant pointer?

It is possible, if a value has non-const type.

## Arrays and pointer arithmetic

### What is the difference between `int array[10]` and `int *ptr` definitions?

Both store certain address, but after `int array[10]` definition compiler expexts 10 integers after this address.

## Casting pointers to different types

### 1. What are these numbers after "100" that initialized with `int I = 100` at the beginning of the program?

Numbers after "100" are values of type int stored in memory after the `i` address.

### 2. Is it possible to make the next: `*(ptr + 1) = 101?` Will the output be changed to `100 101 ... ... ...`?

It is possible, but the output won't be changed to `100 101 ... ...`

### 3. `int` and `uint8_t` pointers are pointing to the same place in memory (variable `i`). But why does the output differ? Does the output really differ or not? Make some prove.

Memory cell stores binary code. What we do - we try to get the desired value by slicing  binary code after the pointer address by the size of type. `int` has 4 bytes, `uint8_t` has only 8 bits = 1 byte. `Int` is stored in memory in two's compound code, `uint8_t` - in direct.<br/>
+is needed to cast the output to the comprehensible type for compiler.
