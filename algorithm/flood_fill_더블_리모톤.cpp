#include <iostream>
#include<queue>
using namespace std;

int visited[100001];

struct Node {
	int x;
	int cnt;
};

bool isOut(int dx) {
	if (dx > 100000) return false;
	if (dx < 0) return false;
	if (visited[dx] == 1) return false;
	return true;
}

int main() {
	
	queue<Node> q;

	int start;
	cin >> start;
	int d;
	cin >> d;

	q.push({start,0});
	visited[start] = 1;

	while (!q.empty()) {
		Node now = q.front(); q.pop();

		if (now.x == d) {
			cout << now.cnt;
			return 0;
		}

		int newCnt = now.cnt + 1;
		if (isOut(now.x / 2) == true) { 
			q.push({ now.x / 2,newCnt }); 
			visited[now.x / 2] = 1; 
		}
		if (isOut(now.x * 2) == true) {
			q.push({ now.x * 2,newCnt });
			visited[now.x * 2] = 1;
		}
		if (isOut(now.x +1) == true) {
			q.push({ now.x + 1,newCnt });
			visited[now.x + 1] = 1;
		}
		if (isOut(now.x - 1) == true) {
			q.push({ now.x - 1,newCnt });
			visited[now.x - 1] = 1;
		}
	}


}