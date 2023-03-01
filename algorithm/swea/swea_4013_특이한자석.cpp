#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int K;//자석 회전 횟수
int magnet[5][9];

void rota(int num) {
	//해당 번호 자석 시계방향으로 회전
	int tmp = magnet[num][7];
	for (int i = 6; i >= 0; i--)
	{
		magnet[num][i + 1] = magnet[num][i];
	}
	magnet[num][0] = tmp;
}

void opRota(int num) {
	int tmp = magnet[num][0];
	for (int i = 0; i < 7; i++)
	{
		magnet[num][i] = magnet[num][i + 1];
	}
	magnet[num][7] = tmp;
}

struct info {
	int magnet;
	int dir;
};

void init() {
	memset(magnet, 0, sizeof(magnet));
}

int main(void)
{
	//freopen("input.txt", "r", stdin);
	int T;
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		cin >> K;
		init();

		//자석 정보 입력
		for (int i = 1; i <= 4; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				cin >> magnet[i][j];
			}
		}

		//K번 돌릴 자석과 방향 입력
		queue<info> q;
		for (int i = 0; i < K; i++)
		{
			int magnetnumber;
			int magnetdir;
			cin >> magnetnumber>> magnetdir;
			q.push({ magnetnumber,magnetdir });
		}

		vector<info> information;

		while (!q.empty()) {
			info nowRot = q.front(); q.pop();

			queue<info> rotainfo;
			rotainfo.push(nowRot);
			information.push_back(nowRot);
			int visited[5] = { 0 };

			while (!rotainfo.empty()) {
				info now = rotainfo.front(); rotainfo.pop();
				visited[now.magnet] = 1;

				if (now.magnet + 1 <= 4 && visited[now.magnet + 1] == 0) {
					if (magnet[now.magnet][2] != magnet[now.magnet + 1][6]) {
						//돌릴 자석의 오른쪽 자석과 맞닿은 날이 같은 방향이면 pass
						//다른 방향이라면 그 자석으로 이동
						if (now.dir == 1) {
							rotainfo.push({ now.magnet + 1,-1 }); //반대방향으로 입력해주기
							information.push_back({ now.magnet + 1,-1 }); //회전할 정보 입력
						}
						if (now.dir == -1) {
							rotainfo.push({ now.magnet + 1,1 }); //반대방향으로 입력해주기
							information.push_back({ now.magnet + 1,1 }); //회전할 정보 입력
						}
					}
				}
				if (now.magnet - 1 >= 1 && visited[now.magnet - 1] == 0) {
					if (magnet[now.magnet][6] != magnet[now.magnet - 1][2]) {
						//돌릴 자석의 오른쪽 자석과 맞닿은 날이 같은 방향이면 pass
						//다른 방향이라면 그 자석으로 이동
						if (now.dir == 1) {
							rotainfo.push({ now.magnet - 1,-1 }); //반대방향으로 입력해주기
							information.push_back({ now.magnet - 1,-1 }); //회전할 정보 입력
						}
						if (now.dir == -1) {
							rotainfo.push({ now.magnet - 1,1 }); //반대방향으로 입력해주기
							information.push_back({ now.magnet - 1,1 }); //회전할 정보 입력
						}
					}
				}
			}

			int len = information.size();
			for (int i = 0; i < len; i++)
			{
				if (information[i].dir == 1) {
					rota(information[i].magnet);
				}
				if (information[i].dir == -1) {
					opRota(information[i].magnet);
				}
			}
			information = vector<info>(); //회전 후 초기화
		}
		
		int sum = 0;
		for (int i = 1; i <= 4; i++)
		{
			if (magnet[i][0] == 0) continue;
			if (i == 1) sum += 1;
			if (i == 2) sum += 2;
			if (i == 3) sum += 4;
			if (i == 4) sum += 8;

		}
		cout << "#" << t + 1 << " " << sum << "\n";
		
	}//테케 안

	
}