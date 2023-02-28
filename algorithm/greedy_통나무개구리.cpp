#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int N, Q;
int parent[100001];

struct logs {
	int start;
	int end;
	int y;
	int node;

	bool operator<(logs right) {
		if (start < right.start) {
			return true;
		}
		if (start > right.start) {
			return false;
		}
		if (end < right.start) {
			return true;
		}
		if (end > right.start) {
			return false;
		}
		return false;

	}
};

logs Log[100001];

int Find(int now) {
	if (now == parent[now]) {
		return now;
	}
	int ret = Find(parent[now]);
	parent[now] = ret;
	return ret;
}

void Union(int a, int b) {
	int pa = Find(a);
	int pb = Find(b);
	if (pa == pb) return;
	parent[pb] = pa;
}

int main() {
	cin >> N >> Q;

	for (int i = 1; i <= N; i++)
	{
		int s, e, yy;
		cin >> s >> e >> yy;
		Log[i] = { s,e,yy,i };
		parent[i] = i; //부모 초기화
	}

	sort(Log + 1, Log + N + 1);
	int endMax = Log[1].end;
	int endMaxNode = 1;;

	for (int i = 2; i <= N; i++)
	{
		if (endMax >=Log[i].start) {
			Union(Log[endMaxNode].node, Log[i].node);
		}
		if (endMax < Log[i].end) {
			endMax = Log[i].end;
			endMaxNode = i;
		}

	}

	for (int i = 0; i < Q; i++)
	{
		int startLog = 0;
		int endLog = 0;
		cin >> startLog >> endLog;
		if (Find(startLog) == Find(endLog)) cout << "1\n";
		else cout << "0\n";
	}
}