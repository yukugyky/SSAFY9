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
            col[lev] = i; //���� ��ġ
            bool possible = true;
            for (int j = 0; j < lev; j++)
            {
                if (col[lev] == col[j] || abs(col[lev] - col[j]) == lev - j) {
                    possible = false;
                    //���� ���� �ְų� �밢���� ������ �Ұ���
                    break;
                }
            }
            if (possible == true) {
                qween(lev + 1); //�����ϸ� ���� ������ �̵��ؼ� ������ �� ã����
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