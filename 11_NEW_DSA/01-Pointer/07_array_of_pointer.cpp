/*

Array of  pointer

*/

#include<iostream>
using namespace std;

int main()
{
    int a[3] = {2,3,5};
    int *ptr[3]; // array of pointers

    for (int i = 0; i < 3; i++)
    {
        ptr[i] = &a[i]; // assign values to a pointer to array
    }

    // print the pointer values

    for (int i = 0; i < 3; i++)
    {
        cout << *ptr[i] << endl;
    }
    
}