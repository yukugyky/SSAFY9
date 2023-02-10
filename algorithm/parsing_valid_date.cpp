#include <iostream>
#include <string>
#include <cstring>

using namespace std;

string s;
int n, a, b;
int sum;

int main()
{
    cin >> s;

    n = s.length();
    int dot2 = s.find('.', 5);
    string month = s.substr(5,  dot2- 5);
    string day = s.substr(dot2 + 1, n - dot2);

    int monthNum = 0;
    int dayNum = 0;
    int YesDay = 0;
    if (month == "XX") {
        monthNum = 3;
    }
    else if (month.find('X') != -1) {
        monthNum = 9;
    }

    if (day == "XX") {
        dayNum = 31;
    }
    else if (day.find('X') != -1) {
        if (day[0] == 'X') {
            dayNum = 2;
        }
        else {
            dayNum = 10;
        }
    }

    if (monthNum == 0) {
        YesDay = dayNum;
    }
    else {
        if (dayNum == 0) {
            YesDay = monthNum;
        }
        else {
            YesDay = monthNum * dayNum;
        }
    }

    cout << YesDay;


}