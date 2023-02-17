#include <iostream>
#include <algorithm>

using namespace std;

string book[100001];
int N;
int num;
string target;
int Time;

void findBook() {
	int s = 0;
	int e = N - 1;
	int mid = (s + e) / 2;
	int cnt = 0;

	cin >> target;
	cin >> Time;

	while (s <= e) {
		mid = (s + e) / 2;
		if (book[mid] == target) {
			if (cnt < Time) {
				cout << "pass\n";
				return;
			}
			else {
				cout << "fail\n";
				return;
			}
		}
		if (book[mid] < target) {
			s = mid + 1;
			cnt++;
		}
		else if (book[mid] > target) {
			e = mid - 1;
			cnt++;
		}
	}
	cout << "fail\n";
}

int main() {
	
	cin >> N;
	
	for (int i = 0; i < N; i++)
	{
		cin >> book[i];
	}

	sort(book + 0, book + N);

	cin >> num;

	for (int i = 0; i < num; i++)
	{
		findBook();
	}

	return 0;
}