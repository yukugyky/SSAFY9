#include<iostream>
#include<queue>
using namespace std;

char parent[200]; //'A'=65 'Z'=90
int de;

void init() {
    for (char ch = 'A'; ch < 'Z'; ch++)
    {
        parent[ch] = ch;
    }
}


int Find(char now)
{
    if (now == parent[now]) {
        return now;
    }

    char ret = Find(parent[now]);
    parent[now] = ret; //경로 압축
    return ret;
}

void Union(char a, char b)
{
    char pa = Find(a);
    char pb = Find(b);
    if (pa == pb) return; // a 와 b 는 이미 같은 그룹 
    parent[pb] = pa;
}

int main()
{
    init();
    int Q;
    cin >> Q;
    int found = 0;
    for (int q = 0; q < Q; q++)
    {
        char a, b;
        cin >> a >> b;
        if (Find(a) == Find(b)) {
            found = 1;
        }
        Union(a, b);
    }

    if (found) cout << "발견";
    else cout << "미발견";

    return 0;
}