#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<unordered_map> //uno쓰고 탭
#include<string>
using namespace std;

unordered_map<string, int> Cnt;

int main() {

	string s;
	cin >> s;
	int len = s.length();

	for (int i = 0; i < len; i++)
	{
		if (i <= len - 2) {
			string a = s.substr(i, 2);
			Cnt[a]++;
		}
		if (i <= len - 3){ 
			string b = s.substr(i, 3);
			Cnt[b]++;
		}
		if (i <= len - 4) {
			string d = s.substr(i, 4);
			Cnt[d]++;
		}
		if (i <= len - 5) {
			string c = s.substr(i, 5);
			Cnt[c]++;
		}
	}

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string ss;
		cin >> ss;
		cout << Cnt[ss] << '\n';
	}
	


	return 0;
}