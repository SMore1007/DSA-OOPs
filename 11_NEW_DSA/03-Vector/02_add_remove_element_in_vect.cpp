#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<int> v;

    v.push_back(5);     // Add 5
    v.push_back(10);    // Add 10
    v.pop_back();       // Remove last element (10)

    for (int val : v) {
        cout << val << " ";
    }

    return 0;
}
