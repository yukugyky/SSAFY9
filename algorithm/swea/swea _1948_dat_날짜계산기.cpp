#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <stdio.h>
#include <cstring>
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
		
		
		//reset
		int DAT[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

		//input
		int m1, d1, m2, d2;
		cin >> m1 >> d1 >> m2 >> d2;

		//solve->
		//#1. 시작 월~ 끝나는 월까지의 모든 날짜의 수의 합(total)
		//#2. total -이미 지나간 날(m1)
		//#3. total- 아직 안온 날 만큼
		int total = 1;
		for (int i = m1; i <= m2; i++) {
			total += DAT[i];
		}
		total -= d1;
		total -= DAT[m2] - d2;

		//output
		cout << "#" << test_case<< " "<< total << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}