#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> nums = {1,2,4,6,7,3};

    int vectorLength = nums.size();

    cout << "Vector Elements as per following\n";
    for (int i = 0; i < vectorLength; i++)
    {
        cout << nums[i] << " ";
    }
    return 0;    
}