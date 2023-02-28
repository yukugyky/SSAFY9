#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

char MAP[7][7];
int visited[7][7];

struct Node {
	int i;
	int j;
};

bool isOut(int y, int x) {
	if (visited[y][x] == 1) return false;
	if (y < 0 || y>6 || x < 0 || x>6) return false;
	return true;
}

int main() {

	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			cin >> MAP[i][j];
		}
	}

	queue<Node> q;
	int maxCnt = -21e8;
	int maxNum;

	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if (MAP[i][j] == '0') continue;
			if (visited[i][j] == 1) continue;
			q.push({ i,j });
			visited[i][j] = 1;
			int cnt = 1;
			while (!q.empty()) {
				Node now = q.front(); q.pop();

				if (MAP[now.i][now.j] == '2') {
					for (int k = 0; k < 12; k++)
					{
						int py[12] = { -1,-2,-3,1,2,3,0,0,0,0,0,0 };
						int px[12] = { 0,0,0,0,0,0,-1,-2,-3,1,2,3 };
						int dy = now.i + py[k];
						int dx = now.j + px[k];
						if (isOut(dy, dx) == false) continue;
						if (MAP[dy][dx] == '0') continue;
						if (MAP[now.i][now.j] == MAP[dy][dx]) {
							cout << "fail\n";
							return 0;
						}
					}
				}

				if (MAP[now.i][now.j] == '1') {
					for (int k = 0; k < 8; k++)
					{
						int py[8] = { -1,-2,1,2,0,0,0,0 };
						int px[8] = { 0,0,0,0,-1,-2,1,2 };
						int dy = now.i + py[k];
						int dx = now.j + px[k];
						if (isOut(dy, dx) == false) continue;
						if (MAP[dy][dx] == '0') continue;
						if (MAP[now.i][now.j] == MAP[dy][dx]) {
							cout << "fail\n";
							return 0;
						}
					}
				}
				
			}
		}
	}

	cout << "pass\n";

	return 0;
}