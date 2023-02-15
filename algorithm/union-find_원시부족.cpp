#include<iostream>
#include<queue>
using namespace std;

char parent[200]; //'A'=65 'Z'=90
int de;
int dat[200];

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
    dat[pa] += dat[pb];
    dat[pb] = 0;
}

int main()
{
    init();
    Union('B','A');
    Union('B','C');
    Union('E','F');
    Union('E','D');
    Union('I','J');
    Union('H','G');

    dat['B'] = 3;
    dat['E'] = 3;
    dat['I'] = 2;
    dat['H'] = 2;

    int n;
    cin >> n;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        char a, b;
        cin >> a >> b;
        if (Find(a) != Find(b)){
            Union(a, b);
            cnt++;
        };

    }
    
    int Group = 4;
    int nowGroup = Group - cnt;

    cout << nowGroup<<"개\n";

    int maxCnt=-21e8;

    for (int i = 0; i < 200; i++)
    {
        if (dat[i] > maxCnt) {
            maxCnt = dat[i];
        }
    }

    cout << maxCnt<<"명";

    return 0;
}