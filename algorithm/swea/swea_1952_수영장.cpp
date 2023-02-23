//수영장 -11:40
#include<iostream>
#include<cstring>
#include<vector>

using namespace std;

int N;
int selected[13];
int sum;
int mini = 2e8;//1년 이용권
int one, month, month3, year;

struct Node {
	int Mon;
	int days;
};

vector<Node> plan;

void run(int now,int sum) {
	int len = plan.size();

	if (now == len) {
		//가격 제일 높은 거 비교하기
		if (sum < mini) {
			mini = sum;
		}
		return;
	}
	Node nowplan = plan[now];
	if (now == 0) {
		run(now + 1, sum+month3);
	}

	if (selected[nowplan.Mon - 1] == 2 || selected[nowplan.Mon - 2] == 2) {
		run(now + 1, sum + 0);
	}
	else {
		for (int i = 0; i < 3; i++) //1년은 총값이랑 마지막에 비교해주기
		{
			if (i == 2 && (nowplan.Mon == 11 || nowplan.Mon == 12)) continue;
			if (i == 0) {
				int plus = nowplan.days * one;
				selected[nowplan.Mon] = 0;
				run(now + 1, sum + plus);
			}
			if (i == 1) { //제약사항 추가
				int plus = month;
				selected[nowplan.Mon] = 1;
				run(now + 1, sum + plus);
				selected[nowplan.Mon] = 0;
			}
			if (i == 2) {
				if (selected[nowplan.Mon - 1] == 2 || selected[nowplan.Mon - 2] == 2) continue;
				int plus = month3;
				selected[nowplan.Mon] = 2;
				run(now + 1, sum + plus);
				selected[nowplan.Mon] = 0;
			}
		}
	}
	
}

void init() {
	
	memset(selected, 0, sizeof(selected));
	for (int i = 0; i < plan.size(); i++)
	{
		plan = vector<Node>();
	}
	sum = 0;
}

int main() {
	int T;
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		init();

		cin >> one >> month >> month3 >> year;

		mini = year;

		for (int i = 1; i <= 12; i++)
		{
			int a;
			cin >> a;
			if (a != 0) plan.push_back({ i,a });
		}

		run(0,0);

		cout << "#" << t + 1 << " " << mini << "\n";
	}


}