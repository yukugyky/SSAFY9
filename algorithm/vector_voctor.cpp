#include <iostream>
#include <vector>
using namespace std;

vector< vector<int> > arr(4);

int main() {

    arr[0] = { 1, 2, 3 };
    arr[1] = { 2 };
    arr[2] = { 2 };

    for (int y = 0; y < arr.size(); y++) {
        for (int x = 0; x < arr[y].size(); x++) {
            cout << arr[y][x];
        }
        cout << endl;
    }
    return 0;
}