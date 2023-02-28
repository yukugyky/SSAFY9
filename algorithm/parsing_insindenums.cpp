#include <iostream>
#include <string>
#include <cstring>

using namespace std;

string s;
int n, a, b;
int sum;

void badword()
{
    int Find1 = s.find("bad");
    int Find2 = s.find("no");
    int Find3 = s.find("puck");
    if (Find1 != -1 || Find2!=-1 || Find3 != -1){
        cout<<"fail";
        return;
        }
}

void underbar(){
    int Find1 =s.find("______");
    if(Find1!=-1){
        cout<<"fail";
    return;
    }
}

void alphabet(){
    for (int i = 0; i < n; i++)
    {
        
    }
    
}


#include <iostream>
#include <string>
#include <cstring>

using namespace std;

string s;
int n, a, b;
int sum;

int start(int num) {
	
	for (int i = num; i < n; i++)
	{
		if (s[i] == '[') return i;
		if (s[i] == '{') return i;
	}
	return -1;
}

int end(int num) {
	for (int i = num; i < n; i++)
	{
		if (s[i] == ']') return i-1;
		if (s[i] == '}') return i-1;
	}
	return -1;
}

void cal(int aa, int bb) {
	int subnum = stoi(s.substr(aa + 1, bb - aa));

	if (s[aa] == '[')
		sum += subnum;
	if (s[aa] == '{')
		sum *= subnum;
}

int main() {
	cin >> s;

	n = s.length();

	b = -1;
	while (1) {
		a = start(b + 1);
		if (a == -1) break;

		b = end(a + 1);
		if (b == -1) break;

		cal(a, b);
	}
	
	cout << sum;



}

int main()
{
    cin >> s;

    n = s.length();

    badword();
    underbar();


    cout << sum;
}