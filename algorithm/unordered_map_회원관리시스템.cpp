#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<unordered_map> //uno쓰고 탭
#include<string>
using namespace std;

int height, width;
int N;
int maxi = -2e8;
int nowreg;
int nowlogin;

unordered_map<string,int> info;
unordered_map<string,int> login;


int main() {

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		if (s == "reg") {
			string id;
			int pwd;
			cin >> id >> pwd;
			if (info.count(id) > 0) {
				cout << "reg fail\n";
			}
			else {
				nowreg++;
				info[id]=pwd;
				cout << "welcome " << nowreg<<"\n";
			}
		}
		if (s == "login") {
			string id;
			int pwd;
			cin >> id >> pwd;
			if (info.count(id) > 0) {
				if (info[id] == pwd) {
					if (login.count(id) > 0) {
						cout << "login fail\n";
					}
					else {
						nowlogin++;
						login[id] = pwd;
						cout << "login " << nowlogin << "\n";
					}
				}
				else {
					cout << "login fail\n";
				}
			}
			else cout << "login fail\n";
		}
		if (s == "change") {
			string id;
			int oldpwd, newpwd;
			cin >> id >> oldpwd >> newpwd;
			if(info.count(id)>0){
				if (info[id] == oldpwd) {
					info[id] = newpwd;
					cout << "success\n";
				}
				else {
					cout << "change fail\n";
				}
			}
			else {
				cout << "change fail\n";
			}
		}
		if (s == "logout") {
			string id;
			cin >> id;
			if (login.count(id) > 0) {
				nowlogin--;
				login.erase(id);
				cout << "logout " << nowlogin<<'\n';
			}
			else {
				cout << "logout fail\n";
			}
		}
		if (s == "bye") {
			string id;
			cin >> id;
			if (info.count(id) > 0) {
				if (login.count(id) > 0) {
					nowlogin--;
					nowreg--;
					login.erase(id);
					info.erase(id);
					cout << "bye " << nowreg << "\n";
				}
				else {
					cout << "bye fail\n";
				}
			}
			else {
				cout << "bye fail\n";
			}
		}
		
	}

	return 0;
}
