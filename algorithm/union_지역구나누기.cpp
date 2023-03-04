#define _CRT_SECURE_NO_WARNINGS
#include <iostream
#include<string.h>
#include<algorithm>

using namespace std;

int parent[10];
int N; //마을 개수
int popu[10];
int MAP[10][10];
vector<int> reg[2];
int mini;

int Find(int now) {
	if (now == parent[now]) {
		return now;
	}
	int ret = Find(parent[now]);
	parent[now] = ret;
	return ret;
}

void Union(int a,int b) {
	int pa = Find(a);
	int pb = Find(b);
	if (pa == pb) return;
	parent[pb] = pa;
}

void dfs(int now) {
	if (now == N+1) {
		for (int i = 1; i <= N; i++)
		{
			parent[i] = i;
		}
		int lena = reg[0].size();
		int lenb = reg[1].size();
		if (lena == 0 || lenb == 0) return;
		int maxi0 = 0;
		int maxi1 = 0;
			for (int i = 0; i < lena; i++)
			{
				for (int j = 0; j < lena; j++)
				{
					if (MAP[reg[0][i]][reg[0][j]] == 1) {
						Union(reg[0][i], reg[0][j]);
					}
				}
			}
			for (int i = 0; i < lena; i++)
			{
				for (int j = 0; j < lena; j++)
				{
					if (Find(reg[0][i])!=Find(reg[0][j])) {
						return;
					}
				}
				maxi0 += popu[reg[0][i]];
			}

			for (int i = 0; i < lenb; i++)
			{
				for (int j = 0; j < lenb; j++)
				{
					if (MAP[reg[1][i]][reg[1][j]] == 1) {
						Union(reg[1][i], reg[1][j]);
					}
				}
			}
			for (int i = 0; i < lenb; i++)
			{
				for (int j = 0; j < lenb; j++)
				{
					if (Find(reg[1][i]) != Find(reg[1][j])) {
						return;
					}
				}
				maxi1 += popu[reg[1][i]];
			}

		if (maxi0 > 0 && maxi1 > 0) {
			mini = min(mini, abs(maxi0 - maxi1));
		}
		return;
	}

	for (int i = 0; i < 2; i++)
	{
		reg[i].push_back({ now });
		dfs(now + 1);
		reg[i].pop_back();
	}
}

void init() {
	memset(MAP, 0, sizeof(MAP));
	memset(popu, 0, sizeof(popu));
	memset(parent, 0, sizeof(parent));
	mini = 2e8;
}

int main() {
	
	int T;
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		cin >> N;
		init();

		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				cin >> MAP[i][j];
			}
		}

		for (int i = 1; i <= N; i++)
		{
			cin >> popu[i];
		}

		for (int i = 0; i < 2; i++)
		{
			reg[i] = vector<int>();
		}

		dfs(1);


		cout << "#" << t + 1 << " " <<mini<< "\n";
	}
	return 0;
}