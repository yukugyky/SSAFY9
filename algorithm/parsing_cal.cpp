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
		if (s[i] == '+') return i;
		if (s[i] == '-') return i;
	}
	return -1;
}

int end(int num) {
	for (int i = num; i < n; i++)
	{
		if (s[i] == '+') return i-1;
		if (s[i] == '-') return i-1;
	}
	return n;
}

void cal(int aa, int bb) {
	int subnum = stoi(s.substr(aa + 1, bb - aa));

	if (s[aa] == '+')
		sum += subnum;
	if (s[aa] == '-')
		sum -= subnum;
}

int main() {
	cin >> s;
	if (s[0] != '-') {
		s.insert(0, "+");
	}

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