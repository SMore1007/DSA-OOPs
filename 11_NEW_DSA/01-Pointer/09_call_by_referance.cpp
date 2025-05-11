#include<iostream>
using namespace std;

void fun(int *var)
{
    *var = 200;
    cout << "Var in fun: " << *var << endl;
}

int main()
{
    int var = 100;
    fun(&var);     // address argument
    cout << "Var in main: " << var << endl;
}