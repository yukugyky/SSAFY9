#include<iostream>
#include<algorithm> //정렬 사용해야하니깐

using namespace std;

/*
거스름돈 예시
1200 4
100 50 10 500
*/

bool cmp(int left, int right) {
	if (left > right) return true;
	if (left < right) return false;
	return false;
}
int target;//거스름돈
int coins[5] = { 500,100,50,10 };

int main() {

	cin >> target;

	//S:탐욕적으로 가장 큰 단위의 동전부터 돌려준다!
	sort(coins, coins + 4, cmp);

	int ans = 0;

	for (int i = 0; i < 4; i++)
	{
		int now = coins[i];
		ans += target / now;
		target %= now;
	}

	cout << ans;
	
}