#include <iostream>
#include <algorithm>

using namespace std;

int target;

int main() {
	
	cin >> target;
	int ans;

	int s = 1;
	int e = target;
	int answer = -1;
	int mid = s + e / 2; //s=10억 e=12억 일때 22억은 int 범위 초과이므로 long long도 고려해야함

	while (s <= e) {
		int mid = (s + e) / 2;

		if (mid * mid <= target) {
			//정답의 후보임
			answer = max(mid,answer);
			s = mid + 1; //아직 끝난게 아니기때문에 하나 더 좁혀줌
		}
		else {
			e = mid - 1;
		}

	}

	cout << answer;


	return 0;
}