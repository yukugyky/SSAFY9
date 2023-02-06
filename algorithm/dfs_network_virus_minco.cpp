#include <iostream>
#include <cstring>
using namespace std;

int arr[101][101] = { 0, };
int computer;
int edge;
int used[101] = { 0, };
int num[101];
int cnt = 0;
int from, to;

void run(int now) {

	num[now] = 1;

	for (int i = 0; i < computer+1; i++)
	{
		if (arr[now][i] == 0) continue;
		if (used[i] == 1) continue;

		used[i] = 1;
		run(i);
		used[i] = 0;
	}
}

int main() {

	cin >> computer;
	cin >> edge;

	for (int i = 0; i < edge; i++)
	{
		cin >> from >> to;
		arr[from][to] = 1;
	}

	run(1);

	for (int i = 0; i < computer; i++)
	{
		if (num[i] == 1)
			cnt++;
	}

	cout << cnt - 1; //카운트에서 처음컴퓨터 제외해줘야함
	return 0;
}