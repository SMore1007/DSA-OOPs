#include<iostream>
using namespace std;

int main()
{
    int arr[4][4] = {
        {2,3,5,2},
        {5,2,5,3},
        {5,2,6,3},
        {5,7,3,4}
    };

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    
}