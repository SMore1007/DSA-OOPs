#include<iostream>
using namespace std;

int main()
{
    int arr[2][2][2] = {
        {{2,4}, {5,3}},
        {{5,3}, {7,5}},
    };

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                cout << arr[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    
}