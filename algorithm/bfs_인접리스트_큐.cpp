//입접리스트, 큐 활용  bfs
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, M;
int cnt=0;
vector<int>al[10]; //인접 리스트

//bfs
//1.queue 준비
//=> 시작 노드 queue에 삽입

//2. bfs 동작
//-> now->지금 방문하는 노드를 queue의 맨 앞에서 빼옵니다
//-> now에서 갈 수 있는 노드들을 판단하여, 갈 수 있다면 queue에 새로 삽입

void bfs2(int start) {
    queue<int> q;
    q.push(start);

    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (int i = 0; i < al[now].size(); i++)
        {
            int next = al[now][i];
            q.push(next);
        }
    }
}
int main()
{

    cin >> N>>M;// 노드, 간선 정보 받기
    
    for (int i = 0; i < M; i++)
    {
        int from, to;
        cin >> from >> to;
        al[from].push_back(to);
    }
    
    //BFS:재귀적으로 동작x
    //함수로 만들 필요 x

    bfs2(0);

}