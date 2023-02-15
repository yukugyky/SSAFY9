#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Node {
	int r;
	int c;
	int accCost;
};

Node start;

const int MAXN = 1000;
int Y,X; //시어머니 위치 
int MAP[MAXN][MAXN];
int dist[MAXN][MAXN];
int visited[MAXN][MAXN];
int N;

struct cmp {
	bool operator()(Node left, Node right) {
		return left.accCost > right.accCost;
	}
};

void input() {
	cin >> start.r >> start.c;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> MAP[i][j];
		}
	}
	//MAP 정보 입력받기
	start.accCost = MAP[start.r][start.c];
}

void dijkstra() {
	const int INF = 1e9;
	for (int row = 0; row < N; row++)
	{
		for (int col = 0; col < N; col++)
		{
			dist[row][col] = INF;
		}
	}

	priority_queue<Node, vector<Node>, cmp> pq;
	dist[start.r][start.c] = start.accCost; //MAP[star.c][start.r];
	pq.push(start);

	while (!pq.empty()) {
		Node now = pq.top(); pq.pop();
		if (dist[now.r][now.c] < now.accCost) continue;

		int py[4] = { -1, 1, 0, 0 };
		int px[4] = { 0, 0, -1, 1 };
		//위->아래->왼->오

		for (int k = 0; k < 4; k++)
		{
			int dy = now.r + py[k];
			int dx = now.c + px[k];
			if (dy < 0 || dy >= N || dx < 0 || dx >= N) continue;
			if (MAP[dy][dx] == -1) continue;

			int newCost = now.accCost + MAP[dy][dx];
			if (newCost < dist[dy][dx]) {
				//newcost가 더 작을때 갱신할 가치가 있다
				dist[dy][dx] = newCost;
				pq.push({ dy, dx, newCost });
			}
		}
	}
}

int main() {

	input();
	
	dijkstra();
	
	int maxValue = -1;
	for (int row = 0; row < N; row++)
	{
		for (int col = 0; col < N; col++)
		{
			if (maxValue < dist[row][col] && MAP[row][col]!=-1) { //MAP이 장애물!!!! dist는 최단거리!!!
				maxValue = dist[row][col];
			}
		}
	}

	cout << maxValue;
	return 0;
}