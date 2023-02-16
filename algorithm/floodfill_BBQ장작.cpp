#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

using namespace std;

int MAP[1001][1001];
int used[1001][1001];

struct Node {
	int y;
	int x;
	int cost;
};

int main() {

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> MAP[i][j];
		}
	}


	int py[4] = { -1, 1, 0, 0 };
	int px[4] = { 0,0,-1,1 };

	Node node;
	queue<Node> v;

	int y, x;
	cin >> y >> x;
	v.push({ y,x,0 });
	used[y][x] = 1;

	int lastTime = 0;

	while (!v.empty()) {
		Node now = v.front(); v.pop();

		for (int i = 0; i < 4; i++)
		{
			int dy = now.y + py[i];
			int dx = now.x + px[i];
			if (dy < 0 || dy >= N || dx < 0 || dx >= N) continue;
			int newCost = now.cost + 1;
			if (used[dy][dx]==1) continue;
			v.push({ dy,dx,newCost });
			used[dy][dx] = 1;
		}

		lastTime = now.cost;
	}

	cout << lastTime;
}