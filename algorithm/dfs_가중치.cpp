#include <iostream>
#include <cstring>
using namespace std;

int arr[4][4] = {
	0,50,60,300,
	0,0,7,0,
	30,0,0,10,
	0,0,0,0 };

int used[4];
int mini = 21e8;

void run(int now, int sum) {

	if (now == 3) {
		if (sum < mini) {
			mini = sum;
		}
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		if (arr[now][i] == 0) continue;
		if (used[i] == 1) continue;

		used[i] = 1;
		run(i, sum+arr[now][i]);
		used[i] = 0;
	}
}

int main() {

	used[0] = 1;
	run(0, 0);
	cout << "\n최소:";
	cout << mini;

	return 0;
}