# Answers
## __new__ and __delete__ operators

### 1. What is a memory leak? How to prevent leaking of memory?

It is a situation when the memory address is no longer accessable. To prevent leaking of memory we have to release the memory after its allocation and usage and before exiting blocks.

### 2. What does happen if allocating memory without providing a pointer?

Memory allocation has * type and can't be converted to basic non-'*' type.

### 3. How to prevent throwing the "bad_alloc" exception? Provide an example.

Exceptions are prevented by mechanisms of exceptions handling: wraping the "dangerous" code with `{try catch}` or simply `throw` an exception.

## Smart pointers

### 1. Why is it impossible to copy one `unique_ptr` to another?

It is imposible because of the nature of `unique_ptr`, that are used to provide unique pointers to objects.

### 2. When is the `unique_ptr` useful?

It is useful to manage dynamicaly allocated object/resources, to delete stored data after exiting scope.

### 3. How is the `shared_ptr` implemented? What is a references counter?

Shared_ptr is implemented as a pair of pointers, one - stores resource address, another - is a counter of references. Counter of references allows detecting whether the resource is still pointed to make a decision of deleting the data, if it`s no longer needed.

### 4. What is the difference between raw pointers and smart pointers?

Smart pointers has more complex structure and they handle the allocated memory - provide memory releasing in case of "smart" usage.