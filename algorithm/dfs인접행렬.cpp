//dfs 인접행렬
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;


/*
5 4(node개수, edge개수)
1 2(edge정보(from to)
1 3
1 4
2 5
*/

int node, edge;
int adg[6][6] = { 0, };//adj[from][to]=갈 수 있는가?

void dfs(int now) {
	//지금 now라는 점에 도착했다!

	//2. 기저조건(option)

	for (int to = 1; to <= node; to++)
	{
		//재귀에서 다룰 때, 기능적으로 비슷한 부분
		//가지치기(가능한지 판별)
		if (adg[now][to] == 0) continue; //now->to로 갈 수 없으면 무시
		
		cout <<now<<"에서"<<to << "로 갑니다\n";
		//1. 재귀 기본 구조
		dfs(to);
	}
}

//1.인접행렬
int main() {


	cin >> node >> edge;

	for (int i = 0; i < edge; i++)
	{
		int from, to;
		cin >> from >> to;
		adg[from][to] = 1;
	}

	int de = 1;

	////특정 from에서 갈 수 있는 모든 to찾기
	//int node = 1; //특정 from으로 둘 점
	//for (int to = 1; to <= 5; to++) {
	//	if (adg[node][to] == 0) continue;
	//	//갈 수 있는 점이다
	//	cout << to << " ";
	//}

	dfs(1);

}