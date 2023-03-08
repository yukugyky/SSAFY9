#include<iostream>
#include<cstring>

using namespace std;

int MAP[21][21];
int N, X;
int visited[21][21];

int validCheck(int arr[20]) {
	int marked[20] = { 0 };
	for (int i = 0; i < N-1; i++)
	{
		if (abs(arr[i + 1] - arr[i]) > 1) return 0;
		if (arr[i] < arr[i + 1]) {
			for (int j = i; j > i-X; j--)
			{
				if (j < 0) return 0;
				if (arr[i] != arr[j]) return 0;
				if (marked[j] == 1) return 0;
				marked[j] = 1;
			}

		}
		else if (arr[i] > arr[i + 1]) {
			for (int j = i+1; j <= i+X; j++)
			{
				if (j >= N) return 0;
				if (arr[i + 1] != arr[j]) return 0;
				if (marked[j] == 1) return 0;
				marked[j] = 1;
			}
		}
	}
	return 1;
}

void init() {
	memset(MAP, 0, sizeof(MAP));
}

int main() {
	int T;
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		cin >> N >> X;
		init();

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> MAP[i][j];
			}
		}

		int cnt = 0;
		for (int i = 0; i < N; i++)
		{
			int tmp[20];
			for (int j = 0; j < N; j++)
			{
				tmp[j] = MAP[i][j];
			}
			if (validCheck(tmp) == 1) cnt++;
		}

		for (int j = 0; j < N; j++)
		{
			int tmp[20];
			for (int i = 0; i < N; i++)
			{
				tmp[i] = MAP[i][j];
			}
			if (validCheck(tmp) == 1) cnt++;
		}

		cout << "#" << t + 1 << " " << cnt << "\n";
	}
}