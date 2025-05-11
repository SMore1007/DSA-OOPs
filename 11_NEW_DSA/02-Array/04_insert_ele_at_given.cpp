#include<iostream>
using namespace std;
int main()
{
    // one diamentional array
    int arr[5] = {2,4,6,3, 1};
    int element, pos;
    cout << " Enter element: ";
    cin >> element;
    cout << "\nEnter Position: ";
    cin >> pos;
    
    cout << "\nArray before: " << endl;

    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    arr[pos] = element;

    cout << "\narray after Adding element: " << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}