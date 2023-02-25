#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int N, M, R, C, L;
int MAP[55][55];
int visited[55][55];

struct Node {
	int y;
	int x;
	int cnt;
};

bool isOUT(int y, int x) {
	if (y < 0 || x < 0 || y >= N || x >= M) return true;
	if (MAP[y][x] == 0) return true;
	if (visited[y][x] == 1) return true;
	return false;
}

bool isI(int i,int y, int x) {
	int next = MAP[y][x];

	if (i == 0) {
		if (next == 3 || next == 4 || next == 7) return false;
	}
	if (i == 1) {
		if (next == 3 || next == 5 || next == 6) return false;
	}
	if (i == 2) {
		if (next == 2 || next == 6 || next == 7) return false;
	}
	if (i == 3) {
		if (next == 2 || next == 4 || next == 5) return false;
	}
	return true;
}

int main(void)
{
	int T;
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		cin >> N >> M >> R >> C >> L;
		int cnt = 1;
		memset(MAP, 0, sizeof(MAP));
		memset(visited, 0, sizeof(visited));

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				cin >> MAP[i][j];
			}
		}

		//터널
		//1->상하좌우 2->상하 3->좌우 4->상우연결 5->하우연결 6->하좌연결 7->상좌연결

		queue<Node> q;

		q.push({ R,C,1 });
		visited[R][C] = 1;

		while (!q.empty()) {
			Node now = q.front(); q.pop();
			if (now.cnt >= L) break;
			int map = MAP[now.y][now.x];
			int py[] = { -1,1,0,0 };
			int px[] = { 0,0,-1,1 };
			if (map == 1) {
				for (int i = 0; i < 4; i++)
				{
					int ny = now.y + py[i];
					int nx = now.x + px[i];
					int next = MAP[ny][nx];
					if (isOUT(ny, nx) == true) continue;
					if (isI(i, ny, nx) == false) continue;
					q.push({ny,nx,now.cnt+1});
					visited[ny][nx] = 1;
					cnt++;
				}
			}
			if (map == 2) {
				for (int i = 0; i < 2; i++)
				{
					int ny = now.y + py[i];
					int nx = now.x + px[i];
					if (isOUT(ny, nx) == true) continue;
					if (isI(i, ny, nx) == false) continue;
					q.push({ ny,nx,now.cnt + 1 });
					visited[ny][nx] = 1;
					cnt++;
				}
			}
			if (map == 3) {
				for (int i = 2; i < 4; i++)
				{
					int ny = now.y + py[i];
					int nx = now.x + px[i];
					if (isOUT(ny, nx) == true) continue;
					if (isI(i, ny, nx) == false) continue;
					q.push({ ny,nx,now.cnt + 1 });
					visited[ny][nx] = 1;
					cnt++;
				}
			}
			if (map == 4) {
				for (int i = 0; i < 4; i+=3)
				{
					int ny = now.y + py[i];
					int nx = now.x + px[i];
					if (isOUT(ny, nx) == true) continue;
					if (isI(i, ny, nx) == false) continue;
					q.push({ ny,nx,now.cnt + 1 });
					visited[ny][nx] = 1;
					cnt++;
				}
			}
			if (map == 5) {
				for (int i = 1; i < 4; i += 2)
				{
					int ny = now.y + py[i];
					int nx = now.x + px[i];
					if (isOUT(ny, nx) == true) continue;
					if (isI(i, ny, nx) == false) continue;
					q.push({ ny,nx,now.cnt + 1 });
					visited[ny][nx] = 1;
					cnt++;
				}
			}
			if (map == 6) {
				for (int i = 1; i < 3; i ++)
				{
					int ny = now.y + py[i];
					int nx = now.x + px[i];
					if (isOUT(ny, nx) == true) continue;
					if (isI(i, ny, nx) == false) continue;
					q.push({ ny,nx,now.cnt + 1 });
					visited[ny][nx] = 1;
					cnt++;
				}
			}
			if (map == 7) {
				for (int i = 0; i < 3; i += 2)
				{
					int ny = now.y + py[i];
					int nx = now.x + px[i];
					if (isOUT(ny, nx) == true) continue;
					if (isI(i, ny, nx) == false) continue;
					q.push({ ny,nx,now.cnt + 1 });
					visited[ny][nx] = 1;
					cnt++;
				}
			}
		}


		cout << "#" << t + 1 << " "<<cnt<<"\n";
	}
	

}