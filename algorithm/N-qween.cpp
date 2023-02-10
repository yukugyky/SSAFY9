<<<<<<< HEAD
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
            col[lev] = i; //ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½Ä¡
            bool possible = true;
            for (int j = 0; j < lev; j++)
            {
                if (col[lev] == col[j] || abs(col[lev] - col[j]) == lev - j) {
                    possible = false;
                    //ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½ ï¿½Ö°Å³ï¿½ ï¿½ë°¢ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ ï¿½Ò°ï¿½ï¿½ï¿½
                    break;
                }
            }
            if (possible == true) {
                qween(lev + 1); //ï¿½ï¿½ï¿½ï¿½ï¿½Ï¸ï¿½ ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ ï¿½Ìµï¿½ï¿½Ø¼ï¿½ ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½ Ã£ï¿½ï¿½ï¿½ï¿½
            }
        }
    }
    
}
int main() {
    cin >> n;

    qween(0);
    cout << cnt;

    return 0;
=======
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
            col[lev] = i; //ÄýÀÇ À§Ä¡
            bool possible = true;
            for (int j = 0; j < lev; j++)
            {
                if (col[lev] == col[j] || abs(col[lev] - col[j]) == lev - j) {
                    possible = false;
                    //°°Àº ¿­¿¡ ÀÖ°Å³ª ´ë°¢¼±¿¡ ÀÖÀ¸¸é ºÒ°¡´É
                    break;
                }
            }
            if (possible == true) {
                qween(lev + 1); //°¡´ÉÇÏ¸é ´ÙÀ½ ÇàÀ¸·Î ÀÌµ¿ÇØ¼­ °¡´ÉÇÑ °÷ Ã£¾ÆÁÜ
            }
        }
    }
    
}
int main() {
    cin >> n;

    qween(0);
    cout << cnt;

    return 0;
>>>>>>> 0549e5456f79af563e28b7b22a5d18ab077feebf
}