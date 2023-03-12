#include<iostream>

using namespace std;

int N;
int num[101];
int oper[4]; //0->+ 1->- 2->x 3->/
int maxi = -2e8;
int mini = 2e8;

void run(int now, int sum) {
	if (now == N) {
		if (maxi < sum) maxi = sum;
		if (mini > sum) mini = sum;
	}

	for (int i = 0; i < 4; i++)
	{
		if (oper[i] < 1) continue;
		if (i == 0) {
			//+
			oper[i]--;
			run(now + 1, sum + num[now]);
			oper[i]++;
		}
		if (i == 1) {
			//-
			oper[i]--;
			run(now + 1, sum - num[now]);
			oper[i]++;
		}
		if (i == 2) {
			//*
			oper[i]--;
			run(now + 1, sum * num[now]);
			oper[i]++;
		}
		if (i == 3) {
			//나누기
			oper[i]--;
			run(now + 1, sum / num[now]);
			oper[i]++;
		}
	}
}

int main() {

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> num[i];
	}

	for (int i = 0; i < 4; i++)
	{
		cin >> oper[i];
	}

	run(1, num[0]);

	cout << maxi << "\n";
	cout << mini << "\n";
}