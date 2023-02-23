#include<iostream>
#include<cstring>
#include<vector>

using namespace std;

int N;
int num[20];
int leftOper[4];// + - * / 개수
int maxi;
int mini;

void run(int now,int result) {
	if (now == N-1) {
		if (maxi < result) maxi = result;
		if (mini > result) mini = result;
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		if (leftOper[i] == 0) continue;
		leftOper[i]--;
		if (i == 0) run(now+1,result + num[now+1]);
		if (i == 1) run(now+1,result - num[now+1]);
		if (i == 2) run(now+1,result * num[now+1]);
		if (i == 3) run(now+1,result / num[now+1]);
		leftOper[i]++;
	}
	
}

void init() {
	maxi = -2e8;
	mini = 2e8;
	memset(num, 0, sizeof(num));
	memset(leftOper, 0, sizeof(leftOper));
}

int main() {
	int T;
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		init();
		cin >> N;

		for (int i = 0; i < 4; i++)
		{
			cin >> leftOper[i];
		}

		for (int i = 0; i < N; i++)
		{
			cin >> num[i];
		}

		run(0, num[0]);
		cout << "#" << t + 1 << " " << maxi-mini << "\n";

	}


}