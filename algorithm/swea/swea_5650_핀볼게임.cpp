#include<iostream>
#include<cstring>
#include<vector>
#include<unordered_map>
#include<string>
#include<algorithm>
#include<queue>

using namespace std;

int N;
int MAP[150][150];

struct Node {
	int y;
	int x;
	int dir; //방향 1->상 2->하 3->좌 4->우
};

unordered_map<int, vector<Node>> block; //월홈 2쌍 좌표찾아주기
queue<Node> q;

int func(Node start) {
	q.push(start);
	int sum = 0;
	//위로 출발
	while (!q.empty()) {
		Node now = q.front(); q.pop();
		if (now.dir == 1) {//가는 방향이 1->상 이라면
			int mapValue = MAP[now.y - 1][now.x];
			if (mapValue == 0) {
				if (sum != 0) {
					if (start.y == now.y && start.x == now.x) {
						return sum;
					}
				}
				Node next = { now.y - 1,now.x,1 };
				q.push(next);
			}
			if (mapValue == 1|| mapValue == 4|| mapValue == 5) {
				sum = sum * 2 + 1;
				return sum;
			}
			if (mapValue == 2) {
				Node next = { now.y - 1,now.x,4 };
				sum++;
				q.push(next);
			}
			if(mapValue == 3) {
				Node next = { now.y - 1,now.x,3 };
				sum++;
				q.push(next);
			}
			if (mapValue >= 6 && mapValue <= 10) {
				for (int i = 0; i < 2; i++)
				{
					if (block[mapValue][i].y == now.y && block[mapValue][i].x == now.x) continue;
					Node next = { block[mapValue][i].y,block[mapValue][i].x,1 }; //웜홀일 때 같은 웜홀 찾아서 같은 방향으로 nextNode
					q.push(next);
				}
			}
			if (mapValue == -1) {
				return sum;
			}
		}
		if (now.dir == 2) { //가는 방향이 하라면
			int mapValue = MAP[now.y + 1][now.x];
			if (mapValue == 0) {
				if (sum != 0) {
					if (start.y == now.y && start.x == now.x) {
						return sum;
					}
				}
				Node next = { now.y + 1,now.x,2 };
				q.push(next);
			}
			if (mapValue == 1) {
				Node next = { now.y + 1,now.x,4 };
				sum++;
				q.push(next);
			}
			if (mapValue == 2||mapValue==3||mapValue==5) {
				sum = sum * 2 + 1;
				return sum;
			}
			if (mapValue == 4) {
				Node next = { now.y + 1,now.x,3 };
				sum++;
				q.push(next);
			}
			if (mapValue >= 6 && mapValue <= 10) {
				for (int i = 0; i < 2; i++)
				{
					if (block[mapValue][i].y == now.y && block[mapValue][i].x == now.x) continue;
					Node next = { block[mapValue][i].y,block[mapValue][i].x,2 }; //웜홀일 때 같은 웜홀 찾아서 같은 방향으로 nextNode
					q.push(next);
				}
			}
			if (mapValue == -1) {
				return sum;
			}
		}
		if (now.dir == 3) {//가는 방향이 3->좌 이라면
			int mapValue = MAP[now.y][now.x-1];
			if (mapValue == 0) {
				if (sum != 0) {
					if (start.y == now.y && start.x == now.x) {
						return sum;
					}
				}
				Node next = { now.y,now.x-1,3 };
				q.push(next);
			}
			if (mapValue == 1) {
				Node next = { now.y,now.x - 1,1 };
				sum++;
				q.push(next);
			}
			if (mapValue == 2) {
				Node next = { now.y,now.x-1,2 };
				sum++;
				q.push(next);
			}
			if (mapValue == 3|| mapValue == 4|| mapValue == 5) {
				sum = sum * 2 + 1;
				return sum;
			}
			if (mapValue >= 6 && mapValue <= 10) {
				for (int i = 0; i < 2; i++)
				{
					if (block[mapValue][i].y == now.y && block[mapValue][i].x == now.x) continue;
					Node next = { block[mapValue][i].y,block[mapValue][i].x,3 }; //웜홀일 때 같은 웜홀 찾아서 같은 방향으로 nextNode
					q.push(next);
				}
			}
			if (mapValue == -1) {
				return sum;
			}
		}
		if (now.dir == 4) {//가는 방향이 4->우 이라면
			int mapValue = MAP[now.y][now.x + 1];
			if (mapValue == 0) {
				if (sum != 0) {
					if (start.y == now.y && start.x == now.x) {
						return sum;
					}
				}
				Node next = { now.y,now.x + 1,4 };
				q.push(next);
			}
			if (mapValue == 1|| mapValue == 2|| mapValue == 5) {
				sum = sum * 2 + 1;
				return sum;
			}
			if (mapValue == 3) {
				Node next = { now.y,now.x + 1,4 };
				sum++;
				q.push(next);
			}
			if (mapValue == 4) {
				Node next = { now.y,now.x + 1,1 };
				sum++;
				q.push(next);
			}
			if (mapValue >= 6 && mapValue <= 10) {
				for (int i = 0; i < 2; i++)
				{
					if (block[mapValue][i].y == now.y && block[mapValue][i].x == now.x) continue;
					Node next = { block[mapValue][i].y,block[mapValue][i].x,4 }; //웜홀일 때 같은 웜홀 찾아서 같은 방향으로 nextNode
					q.push(next);
				}
			}
			if (mapValue == -1) {
				return sum;
			}
		}
	}

	return sum;
}


int main() {
	int T;
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		memset(MAP, 0, sizeof(MAP));
		q = queue<Node>();

		int maxi = -2e8;
		cin >> N;
		for (int i = 0; i <= N+1; i++)
		{
			for (int j = 0; j <= N+1; j++)
			{
				if (i == 0 || i == N + 1 || j == 0 || j == N + 1) MAP[i][j] = 5; //맵 블록5로 감싸기
				else {
					int a;
					cin >> a;
					MAP[i][j] = a;
					block[a].push_back({ i,j,0 });
				}
			}
		}

		int len = block[0].size();
		for (int i = 0; i < len; i++)
		{
			Node now = block[0][i];
			for (int j = 1; j <= 4; j++)
			{
				now.dir = j;
				int result = func(now);
				if (result > maxi) {
					maxi = result;
				}
			}
		}

		block.clear();

		cout << "#" << t + 1 << " " << maxi << "\n";

	}

}