#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<queue>
#include<string.h>
using namespace std;

int n, w, h;//벽돌 개수, 가로, 세로
int MAP[16][16];
int mincnt = 2e8;

struct Node {
	int y;
	int x;
	int val; //벽돌값
};

queue<Node> q;

bool isOut(int dy, int dx) {
	if (dy < 0 || dy >= h || dx < 0 || dx >= w) return true;
	return false;
}

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

void breakbricks(int y, int x, int num) {
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i] * num;
		int nx = x + dx[i] * num;
		if (isOut(ny, nx) == false && MAP[ny][nx] != 0) {
			q.push({ ny,nx,MAP[ny][nx] });
			MAP[ny][nx] = 0;
		} //네 방향
	}
}

int downbricks() {
	int flag = 0;
	for (int i = 0; i < w; i++)
	{
		int t = h - 1;
		for (int j = h - 1; j >= 0; j--)
		{
			if (MAP[j][i] != 0) {
				int back = MAP[j][i];
				MAP[j][i] = 0;
				MAP[t--][i] = back;
				flag = 1;
			}
		}
	}
	if (flag == 0) return -1;
}

int mapCount() {
	int a = 0;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (MAP[i][j] == 0) continue;
			a++;
		}
	}
	return a;
}

int topBrick(int row) {
	int flag = 0;
	for (int i = 0; i < h; i++)
	{
		if (MAP[i][row] != 0) return i;
	}
	if (flag == 0) return -1;
}

void dfs(int noww) {
	if (noww == n) {
		int cnt = mapCount();
		if (cnt < mincnt) mincnt = cnt;
		return;
	}


	int cpy[16][16];
	memcpy(cpy, MAP, sizeof(MAP));

	for (int i = 0; i < w; i++)
	{
		int Top = topBrick(i);
		if (Top == -1) continue;

		q.push({ Top, i,MAP[Top][i] });
		MAP[Top][i] = 0;
		while (!q.empty()) {
			Node now = q.front(); q.pop();
			int value = now.val;
			for (int j = 1; j <= value - 1; j++)
			{
				breakbricks(now.y, now.x, j);
			}
		}

		if (downbricks() == -1) {
			mincnt = 0;
			return;
		}

		dfs(noww + 1);

		memcpy(MAP, cpy, sizeof(MAP));
	}	

}

void init() {
	memset(MAP, 0, sizeof(MAP));
	mincnt = 2e8;
}

int main() {

	//freopen("input.txt", "r", stdin);
	int T;
	cin >> T;

	for (int t = 0; t < T; t++)
	{

		cin >> n >> w >> h;
		init();

		int cnt = 0;
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				cin >> MAP[i][j];
			}
		}

		dfs(0);


		cout << "#" << t + 1 << " " << mincnt << "\n";
	}
	return 0;
}