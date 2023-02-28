#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include<vector>
#include <unordered_map> // set : key만있음(있는지 없는지), map : key,value가 모두 
using namespace std;
 
int MAP[4][4];
 
void input() {
 
    for (int r = 0; r < 4; r++)
        for (int c = 0; c < 4; c++)
            cin >> MAP[r][c];
}
 
int dr[] = { -1,1,0,0 };
int dc[] = { 0,0,-1,1 };
vector<int> path;
 
unordered_map<string, int> um;
string makePath2Key(vector<int> v) {
    string s = "";
    for (int i = 0; i < v.size(); i++)
        s += to_string(v[i]);
    return s;
}
 
void dfs(int r, int c) {
    if (path.size() >= 7) {
        um[makePath2Key(path)] = 1; // 이 path가 존재한다.
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        int nr = r + dr[i];
        int nc = c + dc[i];
 
        if (nr < 0 || nc < 0 || nr >= 4 || nc >= 4) continue;
 
        path.push_back(MAP[nr][nc]);
        dfs(nr, nc);
        path.pop_back();
 
    }
}
 
int solution() {
 
    for (int r = 0; r < 4; r++)
        for (int c = 0; c < 4; c++)
            // r, c에서 path를 만들기 시작
        {
            path.push_back(MAP[r][c]);
            dfs(r, c);
            path.pop_back();
        }
    return um.size(); // um에 등록된 path개수
}
 
 
int main(void)
{
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        um.clear();
        input();
        cout << "#" << tc << " " << solution() << "\n";
    }
}