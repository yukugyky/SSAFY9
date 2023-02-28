#include <iostream>
#include <algorithm>

using namespace std;

int target;

int main() {
	
	char arr[11];
	cin >> arr;
	char target = '#';

	int s = 0;
	int e = 9;
	int ans = -1;
	int mid = s + e / 2; //s=10억 e=12억 일때 22억은 int 범위 초과이므로 long long도 고려해야함

	//O(logN)
	while (s <= e) {
		int mid = (s + e) / 2;

		if (arr[mid] != target) {
			//정답의 후보임
			e = mid - 1; //아직 끝난게 아니기때문에 하나 더 좁혀줌
		}
		else {
			ans = max(mid, ans);
			s = s + 1;
		}

	}
	
	cout << (ans + 1) * 10 << "%\n";

	return 0;
}