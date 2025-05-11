#include<iostream>
using namespace std;
void function(int x)
{
    x = 200;
    cout << "x in function = " << x << endl;
}
int main()
{
    int x = 100;
    function(x);
    cout <<"x in main: "<< x << endl;
}