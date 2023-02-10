#include <iostream>
#include <string>
#include <cstring>

using namespace std;

string s;
int n, a, b;
int sum;

int badword()
{
    int Find1 = s.find("bad");
    int Find2 = s.find("no");
    int Find3 = s.find("puck");
    if (Find1 != -1 || Find2 != -1 || Find3 != -1) {
        return -1;
    }
    return 0;
}

int underbar() {
    int Find1 = s.find("______");
    if (Find1 != -1) {
        return -1;
    }
    return 0;
}

int alphabet() {
    int dat[150] = { 0, };

    for (int i = 0; i < n; i++)
    {
        if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z')) {
            dat[s[i]]++;
        }
        if (dat[s[i]] > 5) {
            return -1;
        }
    }
    return 0;
}

int isnumber() {
    for (int i = 0; i < n; i++)
    {
        if (s[i] >= '0' && s[i] <= '9') {
            return -1;
        }
    }
    return 0;
}




int main()
{
    cin >> s;

    n = s.length();

    if (badword() == -1 || underbar()==-1 || alphabet()==-1 || isnumber()==-1) {
        cout << "fail";
        return 0;
    }
    else
    {
    cout << "pass";
    }
}