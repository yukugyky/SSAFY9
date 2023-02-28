#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

//다이나믹 프로그래밍 = 기억하기 프로그래밍 (기록)
int dp[101];
int N;

int fibo(int N) {
	if (N <= 2)
		return 1;

	//내 기억속에서 now에 대한 문제를 기억하고 있다면
	if (dp[N] != 0)
		return dp[N];

	return dp[N]=fibo(N - 1) + fibo(N - 2);
}

int main() {
	cin >> N;
	cout << fibo(N);
}