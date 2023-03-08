#include<iostream>
#include<cstring>

using namespace std;

int N;//시험장 개수
int site[1000001];
int general;
int assistant;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> site[i];
	}

	cin >> general >> assistant;
	long long ans = 0; //주의!!

	for (int i = 0; i < N; i++)
	{
		if (site[i] - general <= 0) {
			ans++;
		}
		else {
			if ((site[i] - general) % assistant == 0) {
				ans++;//총감독++
				ans += (site[i] - general) / assistant;//부감독추가
			}
			else {
				ans++;//총감독++
				ans += ((site[i] - general) / assistant) + 1;//부감독추가
			}
		}
	}

	cout << ans;
}