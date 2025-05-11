/*
 A dangling pointer is a pointer that continues to reference a memory location 
 after the object it points to has been deallocated or gone out of scope. 
 Accessing a dangling pointer leads to undefined behavior and can cause crashes or data corruption.

*/
#include <iostream>
#include <cstdlib> // for malloc and free
using namespace std;

int main()
{
    int* ptr = (int*) malloc(sizeof(int)); // dynamic allocation
    *ptr = 10;
    free(ptr);                             // memory is freed

    // ptr is now a dangling pointer
    cout << *ptr << endl;                  // Undefined behavior (dangling pointer)

    return 0;
}
