#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

/*
5 2
1 3 3 6 7
8 13 9 12 8
4 16 11 12 6
2 4 1 23 2
9 13 4 7 3
6 3
29 21 26 9 5 8
21 19 8 0 21 19
9 24 2 11 4 24
19 29 1 0 21 19
10 29 6 18 4 3
29 11 15 3 3 29
*/


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
		//reset
		int N, M;
		int MAP[15][15] = { 0, };
		int ans = -21e8;

		//input
		cin >> N >> M;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> MAP[i][j];
			}
		}

		//solve
		//#1. 모든 좌표를 기준으로 파리채를 찍을거니깐
		for (int i = 0; i <= N-M; i++)
		{
			for (int j = 0; j <= N-M; j++)
			{
				int sum = 0;
				//지금 i,j 위치에서 M크기의 파리채를 찍는다
				for (int y = i; y < i + M; y++) {
					for (int x = j; x < j + M; x++) {
						sum += MAP[y][x];
					}
				}
				//여기까지 오면 (i,j)위치에서 M크기의 파리채를 찍은것
				//최대값 갱신
				if (sum > ans)
					ans = sum;
			}
		}



		//output
		cout << "#" << test_case<< " "<< ans << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}