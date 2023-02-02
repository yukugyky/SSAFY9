//인접리스트 DFS 기본
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> alist(4);
int used[4];

void run(int now) {
    cout << now;

    for (int i = 0; i < alist[now].size(); i++) {
        int next = alist[now][i];
        if (used[next]) continue;
        used[next] = 1;
        run(next);
    }
}

int main() {
    alist[0] = { 1, 2, 3 };
    alist[1] = { 2, 3 };
    alist[2] = { 0, 3 };

    used[0] = 1;
    run(0);
    
    return 0;
}