#include<iostream>
#include<queue>
#include<algorithm>
#include <cstring>
 
using namespace std;
 
bool cmp(int left, int right) {
    if (left > right) return true;
    if (left < right) return false;
    return false;
}
 
int main() {
     
    int T;
    cin >> T;
 
    for (int t = 0; t < T; t++)
    {
        int N, M;
        cin >> N >> M;
        int container[101] = { 0 };
        int truck[101] = { 0 };
        for (int i = 0; i < N; i++)
        {
            cin >> container[i];
        }
        for (int i = 0; i < M; i++)
        {
            cin >> truck[i];
        }
 
        sort(container, container + N,cmp);
        sort(truck, truck + M,cmp);
        int finishedcontainer[101] = { 0 };
        int finishedtruck[101] = { 0 };
        int weight = 0;
 
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (finishedtruck[j] == 1) continue;
                if (finishedcontainer[i] == 1) continue;
                if (container[i] <= truck[j]) {
                    finishedcontainer[i] = 1;
                    finishedtruck[j] = 1;
                    weight += container[i];
                    continue;
                }
            }
        }
 
 
        cout << "#" << t + 1 << " " << weight << "\n";
    }
 
}