#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include<vector>
#include <unordered_map> // set : key만있음(있는지 없는지), map : key,value가 모두 
using namespace std;
 
int MAP[4][4];
int N, M;
 
unordered_map<string, int> um;
 
int solution() {
    cin >> N >> M;
    int cnt = 0;
    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        um[s] = 1;
    }
    for (int i = 0; i < M; i++)
    {
        string s;
        cin >> s;
        if (um.find(s) != um.end()) {
            cnt++;
        }
    }
    return cnt;
}
 
 
int main(void)
{
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        um.clear();
        cout << "#" << tc << " " << solution() << "\n";
    }
}