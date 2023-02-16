#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

using namespace std;

int arr[101][101];

struct Node {
	int y;
	int x;
	int cost;
};

int main() {

	int N;
	cin >> N;

	int py[4] = {-1, 1, 0, 0};
	int px[4] = { 0,0,-1,1 };

	Node node;
	vector<Node> v;
	
	for (int i = 0; i < 2; i++)
	{
		int y, x;
		cin >> y >> x;
		arr[y][x] = 1;
		v.push_back({ y,x,arr[y][x]});
	}

	int de = 1;

	while (!v.empty()) {
		Node now = v.back(); v.pop_back();

		for (int i = 0; i < 4; i++)
		{
			int dy = now.y + py[i];
			int dx = now.x + px[i];
			if (dy < 0 || dy >= N || dx < 0 || dx >= N) continue;
			int newCost = now.cost + 1;
			if (arr[dy][dx] == 0 || arr[dy][dx] >= newCost) {
				arr[dy][dx] = newCost;
				v.push_back({ dy,dx,newCost });
			}
		}

	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << arr[i][j];
		}
		cout << "\n";
	}


}