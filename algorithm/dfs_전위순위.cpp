//전위 순위(preorder) (노드 번호가 큰 번호 우선으로 탐색)
#include <iostream>
#include <cstring>
using namespace std;

int arr[101][101] = { 0, };
int computer;
int edge;
int used[101] = { 0, };
int from, to;
int s;

void run(int now) {

	cout << now << " ";

	for (int i = computer+1; i >=1; i--)
	{
		if (arr[now][i] == 0) continue;
		if (used[i] == 1) continue;

		used[i] = 1;
		run(i);
		//used[i] = 0;
	}
}

int main() {

	cin >> computer;
	cin >> edge;
	cin >> s;

	for (int i = 0; i < edge; i++)
	{
		cin >> from >> to;
		arr[from][to] = 1;
	}
	used[s] = 1;
	run(s);

	return 0;
}