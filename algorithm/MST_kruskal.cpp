#include<iostream>
#include<vector>
#include<queue>

using namespace std;

/*
6 9
1 2 2
1 4 1
1 5 4
2 3 3
2 4 3
2 6 7
3 4 5
3 6 8
4 5 9
*/

const int MAXN = 6;
const int MAXM = 5;
int N, T;
int parent[101];

struct Edge {
	int x;
	int y;
	int cost;
};

vector<Edge> adg;

bool cmp(Edge left, Edge right) {
	if (left.cost < right.cost) return true;
	if (left.cost > right.cost) return false;
	return false;
}

int Find(int now) {
	if (now == parent[now]) {
		return now;
	}

	int ret = Find(parent[now]);
	parent[now] = ret;
	return ret;
}

void Union(int a, int b) {
	int ra = Find(a);
	int rb = Find(b);
	if (ra == rb) return;
	parent[rb] = ra;
}

int main()
{

	cin >> N >> T;

	for (int i = 0; i < T; i++)
	{
		int a, b, cost;
		cin >> a >> b >> cost;
		adg.push_back({ a,b,cost });
	}

	for (int i = 1; i <= T; i++)
	{
		parent[i] = i;
	}

	sort(adg.begin(), adg.end(), cmp);

	int sum = 0;
	for (int i = 0; i < adg.size(); i++)
	{
		// edge를 MST에 포함할지말지 -> Union Find로 작성하기
		if (Find(adg[i].x) == Find(adg[i].y)) continue;
		Union(adg[i].x, adg[i].y);
		sum += adg[i].cost;
	}

	cout << sum;

	return 0;
}