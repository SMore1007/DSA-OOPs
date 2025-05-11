#include<iostream>
using namespace std;
int main()
{
    int val = 5;
    void *ptr; // void pointer declaration
    ptr = &val;

    cout << "*ptr = " << *(int*)ptr << endl;
    return 0;
}