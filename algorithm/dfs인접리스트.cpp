//1->5까지 어떤 경로로 갈 수 있는지

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;


/*
5 4(node개수, edge개수)
1 2(edge정보(from to)
1 3
1 4
2 5
*/

int node, edge;
vector<int> v[100]; //v[from]:from에서 갈 수 있는 to들을 저장한 vector

//갔던 점인지 판별해줘야 cycle이 안돌겠지
int used[6];
//used[node번호]=해당 node를 들렸었는지?


vector<int> path; //지금 들리고 있는 node들의 경로

void dfs(int now) {

	//2.기저조건(option)
	if (now == 5) {
		for (int i = 0; i < path.size(); i++)
		{
			cout << path[i] << " ";
		}
		return;
	}

	for (int i = 0; i < v[now].size(); i++)
	{
		//now->to찾기
		int to = v[now][i];
		//4. 가지치기(판별)
		if (used[to] == 1) continue;

		//3.기록 및 처리
		cout << now << "에서" << to << "로 갑니다\n";
		used[to] = 1; //내가 to라는 점으로 간다라고 기록
		path.push_back(to);

		//1.재귀 기본 구조
		dfs(to);

		//3.복구
		path.pop_back(); //vector.pop_back() : vector의 맨 뒤 data메모리 삭제

	}

}
int main() {


	cin >> node >> edge;

	//2.인접 리스트
	//vector<저장할 data 형태> v;

	for (int i = 0; i < edge; i++)
	{
		int from, to;
		cin >> from >> to;
		v[from].push_back(to);
		//vector.push_back(value):vector의 맨 뒹 공간을 추가해서 value라는 값을 저장
	}

	////특정 from에서 갈 수 있는 모든 to 찾기
	//int node = 1;
	//for (int i = 0; i < v[node].size(); i++)
	//{	//vector.size() : vector가 갖고 있는 data 개수
	//	int to = v[node][i];
	//	cout << to;
	//}
	
	path.pop_back();
	used[1] = 1;//1번이라는 점을 간다라고 기록

	dfs(1);
}