#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<queue>
#include<string.h>
#include<algorithm>

using namespace std;

int MAP[16][16];
int N, M;
int visited[16][16];
int maxsum = -2e8;

struct Node {
	int y;
	int x;
	int cnt;
	int sum;
};

bool isOut(int y, int x) {
	if (y < 0 || x < 0 || y >= N || x >= M) return true;
	if (visited[y][x] == 1) return true;
	return false;
}

void odd(Node now);

void even(Node now) {
	if (now.cnt == 3) {
		if (now.sum > maxsum) maxsum = now.sum;
		return;
	}

	int py[6] = { -1,1,0,0,-1,-1 };
	int px[6] = { 0,0,-1,1,-1,1 };
	if (now.cnt == 0) {
		int max1 = MAP[now.y][now.x]; int max2 = MAP[now.y][now.x];
		for (int i = 0; i < 6; i++)
		{
			int dy = now.y + py[i]; int dx = now.x + px[i];
			if (isOut(dy, dx) == true) continue;
			if (i == 0 || i == 2 || i == 3) max1 += MAP[dy][dx];
			if (i == 1 || i == 4 || i == 5) max2 += MAP[dy][dx];
			maxsum = max(maxsum,max(max1, max2));
		}
	}
	for (int i = 0; i < 6; i++)
	{
		int dy = now.y + py[i];
		int dx = now.x + px[i];
		if (isOut(dy, dx) == true) continue;
		Node next={ dy, dx, now.cnt + 1, now.sum + MAP[dy][dx] };
		visited[dy][dx] = 1;
		if (dx % 2 == 0) {
			even(next);
			visited[dy][dx] = 0;
		}
		else {
			odd(next);
			visited[dy][dx] = 0;
		}
	}

}

void odd(Node now) {
	if (now.cnt == 3) {
		if (now.sum > maxsum) maxsum = now.sum;
		return;
	}

	int py[6] = { -1,1,0,0,1,1 };
	int px[6] = { 0,0,-1,1,-1,1 };
	if (now.cnt == 0) {
		int max1 = MAP[now.y][now.x]; int max2 = MAP[now.y][now.x];
		for (int i = 0; i < 6; i++)
		{
			int dy = now.y + py[i]; int dx = now.x + px[i];
			if (isOut(dy, dx) == true) continue;
			if (i == 1 || i == 2 || i == 3) max1 += MAP[dy][dx];
			if (i == 0 || i == 4 || i == 5) max2 += MAP[dy][dx];
			maxsum = max(maxsum,max(max1, max2));
		}
	}
	for (int i = 0; i < 6; i++)
	{
		int dy = now.y + py[i];
		int dx = now.x + px[i];
		if (isOut(dy, dx) == true) continue;
		Node next={ dy, dx, now.cnt + 1, now.sum + MAP[dy][dx] };
		visited[dy][dx] = 1;
		if (dx % 2 == 0) {
			even(next);
			visited[dy][dx] = 0;
		}
		else {
			odd(next);
			visited[dy][dx] = 0;
		}
	}
}

void run() {

	for (int i = 0; i < N; i++)
	{
		int de = 1;
		for (int j = 0; j < M; j++)
		{

			Node now = { i,j,0,MAP[i][j] };
			visited[now.y][now.x] = 1;
			if (now.x % 2 == 0) {
				//짝수행이면
				even(now);
				visited[now.y][now.x] = 0;
			}
			else {
				//홀수행이면
				odd(now);
				visited[now.y][now.x] = 0;
			}

		}

	}
}


int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> MAP[i][j];
		}
	}

	run();

	cout << maxsum;
	return 0;
}