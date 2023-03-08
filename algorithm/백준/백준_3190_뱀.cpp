#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
#include<queue>
using namespace std;

int N;
int K;
int L;
int MAP[101][101];
int nowtime;

struct info {
	int X;//x초가 끝난 뒤
	char C;//x초가 끝난 뒤에 회전 방향
};

struct Node {
	int y;
	int x;
	int dir;
};

vector<Node> nextsnake;

void move(Node snake) {
	if (snake.dir == 1) {
		snake.x++;
	}
	if (snake.dir == 2) {
		snake.y++;
	}
	if (snake.dir == 3) {
		snake.x--;
	}
	if (snake.dir == 4) {
		snake.y--;
	}

}

bool isOut(int y, int x) {
	if (y<1 || x<1 || y>N || x>N) return true;
	return false;
}

Node findpos(Node snake) {
	Node Find = { 0,0,0 };
	if (snake.dir == 1) {
		Find = { snake.x--,snake.y,snake.dir };
		return Find;
	}
	if (snake.dir == 2) {
		Find = { snake.x,snake.y--,snake.dir };
		return Find;
	}
	if (snake.dir == 3) {
		Find = { snake.x++,snake.y,snake.dir };
		return Find;
	}
	if (snake.dir == 4) {
		Find = { snake.x,snake.y++,snake.dir };
		return Find;
	}
}

vector<info> v;

void run(vector<Node> snake) {

	for (int k = 0; k < v.size(); k++)
	{
		info target = v[k];
		int tim = nowtime;
		for (int i = tim; i < v[k].X; i++)
		{
			nowtime++;
			int len = snake.size();
			move(snake[0]);
			if (isOut(snake[0].y, snake[0].x) == true) return;
			if (MAP[snake[0].y][snake[0].x] == 1) {
				//뱀의 머리가 움직인 곳에 사과가 있다면
				Node add = findpos(snake[0]);
				snake.push_back(add);
			}
			if (len > 2) {
				for (int j = 1; j < len; j++)
				{
					snake[j] = snake[j - 1];
				}
			}
		}

		snake[0].dir = v[k].C;

	}
}
int main() {

	cin >> N >> K;

	for (int i = 0; i < K; i++)
	{
		int y, x;
		cin >> y >> x;
		MAP[y][x] = 1;//사과표시
	}

	cin >> L;

	for (int i = 0; i < L; i++)
	{
		int x;
		char c;
		cin >> x >> c;
		v.push_back({ x,c });
	}

	Node start = { 1,1,1 };
	vector<Node> startsnake;
	startsnake.push_back(start);

	run(startsnake);

	cout << nowtime;

	return 0;
}