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
int N; //물 새는 곳 수
int point[1001]; //물 새는 지점
int len; //테이프 길이

int main() {

	cin >> N >> len;

	for (int i = 0; i < N; i++)
	{
		cin >> point[i];

	}

	//S:탐욕적으로 가장 큰 단위의 동전부터 돌려준다!
	sort(point, point + N);

	int num = 0;
	int cnt = 1;

	for (int i = num; i < N; i++)
	{
		if (point[i] <= point[num] + len - 1) continue;
		cnt++;
		num = i;
	}

	cout << cnt;
	
}