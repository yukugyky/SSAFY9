#include<iostream>
#include<queue>
using namespace std;

char parent[200]; //'A'=65 'Z'=90
int N;
char K;

char Find(char now)
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


void input() {
    cin >> N >> K; //품목리스트의 개수, 고기의 개수
}

int main()
{   
    for (int i = 0; i < 200; i++)
    {
        parent[i] = i;
    }

    input();

    for (int i = 0; i < N; i++)
    {
        char a, b;
        cin >> a>> b;
        if (a < b) {
            char tmp = a;
            a = b;
            b = tmp;
        }
        Union(a, b);
    }

    for (char ch='1'; ch <= K; ch++)
    {
        cout << Find(ch);
    }

    return 0;
}