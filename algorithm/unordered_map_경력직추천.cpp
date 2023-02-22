#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<unordered_map> //uno쓰고 탭
#include<string>
using namespace std;

int N;

unordered_map<int, int> rcmCnt; //사번이 추천한 사람 수
unordered_map<int,vector<string>> recomender; //추천한 사람이 누구 추천했는지
unordered_map<string, vector<int>> referral; //추천받은 사람을 누가 추천했는지


int main() {

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		if (s == "recommand") {
			int id;
			string name;
			cin >> id >> name;
			rcmCnt[id]++;
			recomender[id].push_back(name);
			referral[name].push_back(id);
			cout << rcmCnt[id] << "\n";
		}
		if (s == "print") {
			int id;
			cin >> id;
			if (recomender.count(id) > 0) {
				int len = recomender[id].size();
				for (int i = 0; i < len; i++)
				{
					cout << recomender[id][i] << " ";
				}
				cout << "\n";
			}
			else cout << "none\n";
		}
		if (s == "whois") {
			string name;
			cin >> name;
			if (referral.count(name) > 0) {
				int len = referral[name].size();
				sort(referral[name].begin(), referral[name].end());
				for (int i = 0; i < len; i++)
				{
					cout << referral[name][i]<<" ";
				}
				cout << "\n";
			}
			else cout << "none\n";
		}

	}
	

	return 0;
}
