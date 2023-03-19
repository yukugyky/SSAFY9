#include<iostream>
#include<string>
using namespace std;

int N;
int S[21][21];
int Sum[21][21];
int visited[21];
int mini = 2e8;

void dfs(int lev, int num) {
	if (lev == N / 2) {
		int a = 0;
		int b = 0; //팀나누기
		for (int i = 0; i < N; i++)
		{
			for (int j = i+1; j < N; j++)
			{
				if (visited[i] == 1 && visited[j] == 1) a += Sum[i][j];
				if (visited[i] == 0 && visited[j] == 0) b += Sum[i][j];
			}
		}

		int ans = abs(a - b);
		if (mini > ans) mini = ans;

		return;
	}

	for (int i = num; i < N; i++)
	{
		visited[i] = 1;
		dfs(lev + 1, i + 1);
		visited[i] = 0;
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> S[i][j];
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = i+1; j < N; j++)
		{
			Sum[i][j] = S[i][j] + S[j][i];
		}
	}
	
	dfs(0,0);

	cout << mini;

}