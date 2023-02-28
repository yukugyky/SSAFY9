#include <iostream>
#include <algorithm>

using namespace std;

int N = 0;
char arr[10] = { 4,4,5,7,8,10,20,22,23,24 };
int target;

void run(int s, int e, int target) {
	
	if (s > e) {
		cout << "X";
		return;
	}
	int mid = (s + e) / 2;
	if (target==arr[mid]) {
		cout << "O\n";
		return;
	}
	if (target < arr[mid]) {
		run(s, mid - 1, target);
	}
	else {
		run(mid + 1, e, target);
	}


}

int main() {
	
	cin >> target;

	run(0,9,target);

	return 0;
}