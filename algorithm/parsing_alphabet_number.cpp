#include <iostream>
#include <string>
#include <cstring>

using namespace std;

string s;
int n, a, b;
int sum;

int alphabet(int num) {
	for (int i = num; i < s.length(); i++)
	{
		if (s[i] >= 'A' && s[i] <= 'Z') return i;
	}
	return -1;
}

int numbers(int num) {
	for (int i = num; i < s.length(); i++)
	{
		if (s[i] >= '0' && s[i] <= '9') return i;
	}
	return -1;
}

int nextalphbet(int num) {
	for (int i = num; i < s.length(); i++)
	{
		if (s[i] >= 'A' && s[i] <= 'Z') return i;
	}
	return -1;
}

int main()
{
	cin >> s;
	int a = 0;
	int b = -1;
	int c;

	while (1) {

		a = alphabet(b + 1);
		if (a == -1) break;
		b = numbers(a + 1);
		if (b == -1) break;
		c = nextalphbet(b + 1);

		cout << s.substr(a, b - a)<<"#"<<stoi(s.substr(b,c-b))+17<<"\n";
	}


}