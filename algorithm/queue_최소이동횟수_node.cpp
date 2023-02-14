#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node {
	int n;
	int lev;
};

vector<vector<int>>alist(5);
queue<Node> q;
int used[5];

void bfs(int start,int level) {
	q.push({ start,level });

	while (!q.empty()) {
		Node now = q.front();
		q.pop();

		if (now.n == 4) {
			cout << now.lev;
			break;
		}

		for (int i = 0; i < alist[now.n].size(); i++)
		{
			int next = alist[now.n][i];
			if (used[next] == 1) continue;
			used[next] = 1;
			q.push({ next, now.lev + 1 });
		}
	}
}

int main() {

	alist[0] = { 1,2,3 };
	alist[1] = { 2,3 };
	alist[2] = { 3 };
	alist[3] = { 4 };

	bfs(0,0);

	return 0;
}