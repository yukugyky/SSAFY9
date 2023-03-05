#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

int MAP[10][10];
int N, K;
int cnt;
int ans = -2e8;
int visited[10][10];

struct Node {
	int y;
	int x;
	int canbreak;
};

bool isOut(int y, int x) {
	if (y < 0 || x < 0 || y >= N || x >= N) return true;
	if (visited[y][x] == 1) return true;
	return false;
}

void dfs(Node now) {
	if (cnt > ans) {
		ans = cnt;
	}

	int dy[4] = { -1,1,0,0 };
	int dx[4] = { 0,0,-1,1 };

	for (int i = 0; i < 4; i++)
	{
		int ny = now.y + dy[i];
		int nx = now.x + dx[i];
		if (isOut(ny, nx) == true) continue;
		if (MAP[ny][nx] >= MAP[now.y][now.x]) {
			if (now.canbreak == 1) {
				//가려는 곳 높이가 더 높거나 같으면 못가지만 깍을 수 있다면
				if (MAP[ny][nx] - K < MAP[now.y][now.x]) {
					//최대 K만큼 깍았을 때 지금 높이보다 낮을경우만
					int tmp = MAP[ny][nx];
					MAP[ny][nx] = MAP[now.y][now.x] - 1; //지금높이에서 1 작아야 다른 곳 많이 갈수있으니깐
					visited[ny][nx] = 1;
					cnt++;
					Node next = { ny,nx,0 };
					dfs(next);
					cnt--;
					visited[ny][nx] = 0;
					MAP[ny][nx] = tmp;
				}
			}
		}
		else {
			visited[ny][nx] = 1;
			cnt++;
			Node next = { ny,nx,now.canbreak };
			dfs(next);
			visited[ny][nx] = 0;
			cnt--;
		}
	}
}

void init() {
	memset(MAP, 0, sizeof(MAP));
	memset(visited, 0, sizeof(visited));
	ans = -2e8;
}

int main() {
	int T;
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		cin >> N >> K;
		init();
		int maxdep = -2e8;
		vector<Node> v;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> MAP[i][j];
				if (MAP[i][j] > maxdep) {
					maxdep = MAP[i][j];
					v = vector<Node>();
					v.push_back({ i,j,1 });
				}
				else if (MAP[i][j] == maxdep) {
					v.push_back({ i,j,1 });
				}
			}
		}

		for (int i = 0; i < v.size(); i++)
		{
			Node now = v[i];
			memset(visited, 0, sizeof(visited));
			cnt = 1;
			visited[now.y][now.x] = 1;
			dfs(now);
		}



		cout << "#" << t + 1 << " " << ans << "\n";
	}
}