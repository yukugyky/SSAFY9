#include<iostream>
#include<cstring>
#include<vector>
#include<unordered_map>
#include<string>
#include<algorithm>

using namespace std;

int N,K;
string s;

int main() {
	int T;
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		cin >> N>>K;
		cin >> s;

		vector<string> v;
		unordered_map<string, int> um;

		int len = N / 4; //길이

		s+= s.substr(0, len);
		int slen = s.length();
		for (int i = 0; i + len - 1 < slen; i++) {
			string a = s.substr(i, len);
			if (um.find(a) != um.end()) continue;
			um[a]++;
			v.push_back(a);
		}

		sort(v.begin(), v.end(), greater<string>());

		string Kth = v[K-1];

		int klen = Kth.length();
		int last = 0;
		for (int i = 0; i < klen; i++)
		{
			int kint = 0;
			if (Kth[i] >= '0' && Kth[i] <= '9') kint = (int)Kth[i] - 48;
			else kint = (int)Kth[i] - 55;
			last = (last * 16) + kint;
		}


		cout << "#" << t + 1 << " " << last << "\n";

	}


}