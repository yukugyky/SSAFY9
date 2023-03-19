#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int k;
int gear[5][9]; //n극 0, s극 1

struct node {
	int num;
	int dir; //1->시계방향 -1->반시계
};

vector<node> rota;

void run() {

	for (int K = 0; K < k; K++)
	{
		vector<node> info;
		node now = rota[K];
		info.push_back(now);
		int visited[5] = { 0, };
		queue<node> next;
		next.push(now);
		visited[now.num] = 1;

		while (!next.empty()) {
			node n = next.front(); next.pop();
			if (n.num-1>0&&visited[n.num - 1] == 0 && gear[n.num][6]!=gear[n.num-1][2]) {
				visited[n.num - 1] = 1;
				if (n.dir == 1) {
					next.push({ n.num - 1,-1 });
					info.push_back({ n.num - 1,-1 });
				}
				if (n.dir == -1) {
					next.push({ n.num - 1,1 });
					info.push_back({ n.num - 1,1 });
				}
			}
			if (n.num + 1 < 5 && visited[n.num + 1] == 0 && gear[n.num][2] != gear[n.num + 1][6]) {
				visited[n.num + 1] = 1;
				if (n.dir == 1) {
					next.push({ n.num + 1,-1 });
					info.push_back({ n.num + 1,-1 });
				}
				if (n.dir == -1) {
					next.push({ n.num + 1,1 });
					info.push_back({ n.num + 1,1 });
				}
			}


		}

		int len = info.size();
		for (int i = 0; i < len; i++)
		{
			if (info[i].dir == 1) {
				int tmp = gear[info[i].num][7];
				for (int j = 6; j >= 0; j--)
				{
					gear[info[i].num][j + 1] = gear[info[i].num][j];
				}
				gear[info[i].num][0] = tmp;
			}
			if (info[i].dir == -1) {
				int tmp = gear[info[i].num][0];
				for (int j = 0; j <7; j++)
				{
					gear[info[i].num][j] = gear[info[i].num][j+1];
				}
				gear[info[i].num][7] = tmp;
			}
		}


	}
}

int main() {

	for (int i = 1; i <= 4; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			char a;
			cin >> a;
			if (a == '1') gear[i][j] = 1;
			else gear[i][j] = 0;
		}
	}

	cin >> k;

	for (int i = 0; i < k; i++)
	{
		int n, d;
		cin >> n >> d;
		rota.push_back({ n,d });
	}

	run();

	int sum = 0;

	for (int i = 1; i <= 4; i++)
	{
		if (gear[i][0] == 0) continue;
		if (i == 1) sum += 1;
		if (i == 2) sum += 2;
		if (i == 3) sum += 4;
		if (i == 4) sum += 8;
	}

	cout << sum;
}