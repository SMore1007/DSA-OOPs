#include<iostream>
using namespace std;

int main()
{
    int arr[10] = {3,6,2,5,7,3,6,73,6,23};
    cout << "array before sorting: " << endl;

    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }
    
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (arr[i] < arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }            
        }
    }
    
    cout << "\narray after sorting: " << endl;

    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}