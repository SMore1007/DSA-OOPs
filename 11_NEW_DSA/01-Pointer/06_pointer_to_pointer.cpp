
/*

In a pointer to pointer situation a pointer will indirectly point to a 
variable via another pointer

int val=  10;

int *ptr;
ptr = &val;

int **pptr;
pptr = &ptr;

*/

#include<iostream>
using namespace std;

int main()
{
    int var = 10;
    int *ptr1;
    int **ptr2;

    ptr1 = &var;
    ptr2 = &ptr1;

    cout << "Var = " << var << endl;
    cout << "*ptr1 = " << *ptr1 << endl;
    cout << "**ptr2 = " << **ptr2 << endl;
    return 0;
}