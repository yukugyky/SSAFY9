#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int col[13];
int n;
int cnt;

void qween(int lev) {
    if (lev == n) {
        cnt++;
    }
    else {
        for (int i = 0; i < n; i++)
        {
            col[lev] = i; //퀸의 위치
            bool possible = true;
            for (int j = 0; j < lev; j++)
            {
                if (col[lev] == col[j] || abs(col[lev] - col[j]) == lev - j) {
                    possible = false;
                    //같은 열에 있거나 대각선에 있으면 불가능
                    break;
                }
            }
            if (possible == true) {
                qween(lev + 1); //가능하면 다음 행으로 이동해서 가능한 곳 찾아줌
            }
        }
    }
    
}
int main() {
    cin >> n;

    qween(0);
    cout << cnt;

    return 0;
}