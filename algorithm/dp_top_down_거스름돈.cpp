#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

/*
1200 5
10 50 100 400 500
*/

//index : 특정 거스름돈 액수
//value: 그 거스름돈을 돌려주기 위한 최소 동전 개수

int dp[0001];
int target;
int N;
int coins[100];

//1 top-down
int func(int now) {
	//기저 조건(base case)
	if (now == 0) //정답일때
		return 0;//정답에 영향을 주지 않는 값 return
	if (now < 0) //오답일때
		//now까지의 기록에 최소값이 저장될 수 있도록
		// 영향을 미칠 값, 아~~주 큰 값을 return
		return 21e8;


	//만약 now에 대한 답이 기억되고 있다면
	if (dp[now] != 0) {
		return dp[now];
	}
	//재귀 구성(recursive case)
	//now에서 모든 동전을 하나씩 빼가면서 쭉쭉 내려가본다
	int MIN = 21e8;

	for (int i = 0; i < N; i++)
	{
		//now로 다시 올라오면
		//func(now-coin[i])+1
		int temp = func(now - coins[i])+1;
		if (temp < MIN)
			MIN = temp;
	}

	//now까지 올라왔을때 하위 문제의 답을 모두 취합하여
	//그 중 가장 작은 값을 dp[now]에 기록
	return dp[now] = MIN;

}
int main() {
	cin >> target >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> coins[i];
	}

	cout << func(target);

}