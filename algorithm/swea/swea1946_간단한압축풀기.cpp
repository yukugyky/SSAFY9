#include<iostream>
#include <stdio.h>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	//freopen("input.txt", "r", stdin);
	cin >> T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cout << "#" << test_case << "\n";

		int n,num, cnt;
		cin >> n;

		char alp;

		cnt = 1;
		for (int i = 0; i < n; i++)
		{
			cin >> alp >> num;
			for (int j = 0; j < num; j++)
			{
				cout << alp;
				cnt++;

				if (cnt % 10 == 1) cout << "\n";
			}
		}
		cout << "\n";	
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}