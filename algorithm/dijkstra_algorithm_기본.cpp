//어글리 넘버
#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <stdio.h>

using namespace std;

/*
7 11
1 2 60
1 3 20
1 5 40
2 7 10
3 4 10
4 2 20
4 6 50
5 2 10
5 7 10
6 2 10
7 6 10
*/

int n, e;

struct Edge {
	int node;
	int cost;
}; //간선 정보

struct Node {
	int node; //start부터 node까지의 누적비용을 저장
	int accCost;
};

struct cmp {
	bool operator() (Node left, Node right) {
		return left.accCost > right.accCost;
	}
};

vector<Edge> adj[8];

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	cin >> n >> e;
	for (int i = 0; i < e; i++)
	{
		int a,b,cost;
		cin >> a >> b >> cost;
		adj[a].push_back({b,cost});
	}

	priority_queue<Node, vector<Node>, cmp> pq;
	int processed[8] = { 0 };
	int start = 1;
	pq.push({ start, 0 }); //start, start~start 비용
	int dist[8] = { 0 };

	while (!pq.empty()) {
		Node now = pq.top();
		pq.pop();

		if (processed[now.node] == 1) continue; //이미 진행한거는 패스
		processed[now.node] = 1;
		dist[now.node] = now.accCost;
		//proccess
		for (Edge next: adj[now.node])
		{
			int newCost = now.accCost+next.cost; //start~~>now+간선비용
			pq.push({ next.node, newCost }); //간선비용
		}
	}

	for (int node = 1; node <= 7; node++)
	{
		cout << start << "~~~~~~~>" << node << "의 최소비용: " << dist[node] << endl;

	}
	return 0;
}

