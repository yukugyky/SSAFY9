#include <iostream>
#include <vector>
#include <queue>
#include<cstring>
using namespace std;

int N, M, x, y, K; //세로 가로 주사위 좌표 x,y 명령 개수
int MAP[21][21];
int dice[4][3]; //주사위 정보 dice[1][1]=윗면 dice[3][1]=바닥면

bool isOut(int nx, int ny) {
	if (nx < 0 || nx >= N || ny < 0 || ny >= M) return true;
	return false;
}

void init() {
	memset(MAP, 0, sizeof(MAP));
	memset(dice, 0, sizeof(dice));
}

void rota(int dir) {
	if (dir == 1) {
		int bot = dice[1][2];
		dice[1][2] = dice[1][1];
		dice[1][1] = dice[1][0];
		dice[1][0] = dice[3][1];
		dice[3][1] = bot;
	}
	if (dir == 2) {
		int bot = dice[1][0];
		dice[1][0] = dice[1][1];
		dice[1][1] = dice[1][2];
		dice[1][2] = dice[3][1];
		dice[3][1] = bot;
	}
	if (dir == 3) {
		int bot = dice[0][1];
		for (int i = 0; i < 3; i++)
		{
			dice[i][1] = dice[i + 1][1];
		}
		dice[3][1] = bot;
	}
	if (dir == 4) {
		int bot = dice[2][1];
		dice[2][1] = dice[1][1];
		dice[1][1] = dice[0][1];
		dice[0][1] = dice[3][1];
		dice[3][1] = bot;
	}
}

int main() {
	init();
	cin >> N >> M >> x >> y >> K;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> MAP[i][j];
		}
	}

	queue<int> q; //주사위명령

	for (int i = 0; i < K; i++)
	{
		int dir;
		cin >> dir;
		q.push(dir);
	}

	//상단 좌표 dice[1][1]
	int dx = x; int dy = y;

	while (!q.empty()) {
		int dir = q.front(); q.pop();
		//dir 1:동 2:서 3:북 4:남

		if (dir == 1) {
			dx = x; dy = y+1;
			if (isOut(dx, dy) == true) continue;
		}
		if (dir == 2) {
			dx = x; dy = y - 1;
			if (isOut(dx, dy) == true) continue;
		}
		if (dir == 3) {
			dx = x-1; dy = y;
			if (isOut(dx, dy) == true) continue;
		}
		if (dir == 4) {
			dx = x+1; dy = y;
			if (isOut(dx, dy) == true) continue;
		}
		rota(dir);
		if (MAP[dx][dy] == 0) {
			MAP[dx][dy] = dice[3][1];
		}
		else {
			dice[3][1] = MAP[dx][dy]; //주사위바닥면=이동칸수
			MAP[dx][dy] = 0;
		}
		cout << dice[1][1] << "\n";
		x = dx; y = dy;
	}

}