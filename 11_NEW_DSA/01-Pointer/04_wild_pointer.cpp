/*

Wild pointer is pointer which does not point to any address of the variables in throught the code


*/

#include<iostream>
using namespace std;

int main()
{
    int  *ptr;

    cout << "Wild Pointer: " << *ptr << endl;

    return 0;
}