#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

using namespace std;

int MAP[1001][1001];
int used[1001][1001];
int Time[1001][1001];

struct Node {
	int y;
	int x;
	int cost;
};

int main() {

	int N, M;
	N = 4;
	M = 5;
	Node node;
	queue<Node> v;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> MAP[i][j];
			if (MAP[i][j] == 1) {
				v.push({ i,j,0 });
				used[i][j] = 1;
			}
		}
	}

	int py[8] = { -1, 1, 0, 0, -1,-1,1,1 };
	int px[8] = { 0,0,-1,1,-1,1,-1,1 };

	int lastTime = 0;

	while (!v.empty()) {
		Node now = v.front(); v.pop();

		for (int i = 0; i < 8; i++)
		{
			int dy = now.y + py[i];
			int dx = now.x + px[i];
			if (dy < 0 || dy >= N || dx < 0 || dx >= M) continue;
			int newCost = now.cost + 1;
			if (used[dy][dx] == 1) continue;
			v.push({ dy,dx,newCost });
			used[dy][dx] = 1;
		}

		lastTime = now.cost;
	}

	cout << lastTime;

}