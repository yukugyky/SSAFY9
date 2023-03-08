#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<string.h>
#include<algorithm>
#include<queue>

using namespace std;

int N, M; //세로,가로
int K;//배양 시간
int MAP[1000][1000];

struct cell {
	int y;
	int x;
	int life; //hp2배 (비활성+활성)
	int hp;

	bool operator<(cell right) const{
		if (hp < right.hp) return true;
		if (hp > right.hp) return false;
		if (life < right.life) return true;
		if (life > right.life) return false;
		if (y < right.y) return true;
		if (y > right.y) return false;
		if (x < right.x) return true;
		if (x > right.x) return false;
		return false;
	}
};

priority_queue<cell> pq;

priority_queue<cell> ff(priority_queue<cell> nowpq) {
	
	priority_queue<cell> nextpq;
	
	while (!nowpq.empty()) {
		cell now = nowpq.top(); nowpq.pop();
		now.life--;
		if (now.life) nextpq.push(now); //아직 살아있으면 next

		if (now.life < now.hp) {
			//활성화 상태
			int dy[4] = { -1,1,0,0 };
			int dx[4] = { 0,0,-1,1 };
			for (int i = 0; i < 4; i++)
			{
				int ny = now.y + dy[i];
				int nx = now.x + dx[i];
				if (MAP[ny][nx] != 0) continue;//이미 있으면 넘기기
				MAP[ny][nx] = now.hp;
				nextpq.push({ ny,nx,2 * now.hp,now.hp });
			}
		}

		
	}
	return nextpq; //다음 시간에 진행할 pq
}

void init() {
	memset(MAP, 0, sizeof(MAP));
	pq = priority_queue<cell>();
}

int main() {

	int T;
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		cin >> N >> M>>K;
		init();

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				int hp;
				cin >> hp;
				if (hp == 0) continue;
				MAP[500 + i][500 + j]=hp;
				pq.push({ 500+i,500+j,2 * hp,hp });
			}
		}
		
		for (int i = 0; i < K; i++)
		{
			pq = ff(pq);
		}

		//마지막 pq는 k시간 후 살아있는 세포들
		int ans = pq.size();
		cout << "#" << t + 1 << " " << ans << "\n";
	}
	return 0;
}