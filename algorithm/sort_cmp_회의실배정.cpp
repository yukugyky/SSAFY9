#include <iostream>
#include <algorithm> //정렬기능이 포함된 라이브러리
#include <queue> //priority queue 포함
#include <vector>

using namespace std;

struct node {
	int a;
	int b;
};

bool cmp(node& left, node& right) {
	if (left.b < right.b) return true;
	return false;
}

int main()
{
	vector<node> arr;
	node res;

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> res.a >> res.b;
		arr.push_back(res);
	}

	//가장 빨리 끝나는 회의부터 선택을 해간다.
	//정렬하면 빨리끝나는 회의가 왼쪽에 가겠지
	sort(arr.begin(), arr.end(),cmp);

	int prev = -1; //prev<=startTime
	int cnt = 0;

	for (int i = 0; i < n; i++)
	{
		if (!(prev <= arr[i].a)) continue;
		cnt++;
		prev = arr[i].b;
	}

	cout << cnt;

}