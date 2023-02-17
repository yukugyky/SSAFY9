#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

int MAP[4][9];
int visited[4][9];

struct Node {
	int i;
	int j;
};

bool isOut(int y, int x) {
	if (visited[y][x] == 1) return false;
	if (y < 0 || y>3 || x < 0 || x>8) return false;
	return true;
}

int main() {

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cin >> MAP[i][j];
		}
	}

	queue<Node> q;
	int maxCnt = -21e8;
	int maxNum;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (visited[i][j] == 1) continue;
			q.push({ i,j });
			visited[i][j] = 1;
			int cnt = 1;
			while (!q.empty()) {
				Node now = q.front(); q.pop();

				for (int k = 0; k < 4; k++)
				{
					int py[4] = { -1,1,0,0 };
					int px[4] = { 0,0,-1,1 };
					int dy = now.i + py[k];
					int dx = now.j + px[k];
					if (isOut(dy, dx) == false) continue;
					if (MAP[now.i][now.j] != MAP[dy][dx]) continue;
					q.push({ dy, dx });
					cnt++;
					visited[dy][dx] = 1;
					if (cnt > maxCnt) {
						maxCnt = cnt;
						maxNum = MAP[dy][dx];
					}

				}

			}
		}
	}

	cout << maxCnt * maxNum << "\n";

	return 0;
}