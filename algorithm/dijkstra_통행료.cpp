//dfs로 풀기 
//bfs 도전해보기
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int visited[101][101];
int arr[101][101];
int N, M;

void dfs(int row, int col) {
	int dr[] = { -1,1,0,0 };
	int dc[] = { 0,0,-1,1 };

	for (int t = 0; t < 4; t++)
		{
			int nr = row + dr[t];
			int nc = col + dc[t];
			if (nr < 0 || nr >= N || nc < 0 || nr >= N) continue;
			if (arr[nr][nc] == 1 && visited[nr][nc] == 0) {
				visited[nr][nc] = 1;
				dfs(nr, nc);
			}
		}
}

int cnt;

int main() {

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (arr[i][j] == 1 && visited[i][j] == 0) {
				cnt++;
				dfs(i, j);
			}
		}
	}
	cout << cnt;

}