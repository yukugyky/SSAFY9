#include<iostream>
#include<algorithm>
 
using namespace std;
 
int N, M;
int arr[50][50];
int prefix[50][50];
 
void input() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> arr[i][j];
        }
    }
}
 
void calcSum() {
    for (int row = 1; row <= N; row++)
    {
        for (int col = 1; col <= N; col++)
        {
            prefix[row][col] = prefix[row - 1][col] + prefix[row][col - 1]
                - prefix[row - 1][col - 1] + arr[row][col];
        }
    }
 
}
 
void print() {
    for (int row = 1; row <= N; row++)
    {
        for (int col = 1; col <= N; col++)
        {
            cout << prefix[row][col] << " ";
        }
        cout << "\n";
    }
}
 
int func(int ar, int ac, int br, int bc) { //ar,ac~br,bc까지의 구간 합
    return prefix[br][bc] - prefix[ar - 1][bc] - prefix[br][ac - 1] + prefix[ar - 1][ac - 1];
 
}//시간 복잡도 1;
 
 
int solution() {
    int ans = 0;
    for (int row = 1; row <= N-M+1; row++)
    {
        for (int col = 1; col <= N; col++) //ar=row, ac=col, br=row+M-1,bc=col+M-1
        {
            ans = max(ans, func(row, col, row + M - 1, col + M - 1));
        }
    }
    return ans;
}
 
int main() {
    int T;
    cin >> T;
 
    for (int t = 1; t <= T; t++)
    {
        //초기화 추가해야함.
        input();
        calcSum();
 
        cout << "#" << t << " " << solution() << "\n";
 
    }
}