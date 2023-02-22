#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int memo[101][3]; //type별로 만들어줘야 값이 안겹친침!!!!!!!!!주의!!!!!!!!!!!!!!!
int N;
int step[101];

int func(int now, int type) {
	//type=1은 한 칸, type=2는 두칸//1은 연속2번 못씀
	if (now == N+1) return 0;
	if (now > N+1) return -2e8;
	if (memo[now][type] != 0) return memo[now][type];


	int result;

	if (type == 1) {
		int a = func(now + 2, 2) + step[now];
		memo[now][type] = a;
	}
	else {
		int b = func(now + 1, 1) + step[now];
		int c = func(now + 2, 2) + step[now];
		memo[now][type] = max(b, c);
		
	}

	return memo[now][type];
}

int main()
{
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> step[i];
	}
	cout << func(0, 0);
	cout << endl;

	return 0;
}