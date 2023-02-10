#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

int MAP[10][10]; //map 소문자는 헤더가 있어서 대문자 쓰는게 좋음
//방향배열 만들기
int ydir[] = { 0,1,0,-1 }; //우,하,좌,상
int xdir[] = { 1,0,-1,0 };

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
		
		//reset
		memset(MAP, 0, sizeof(MAP));
		
		//input
		int N; //map크기
		cin >> N;

		int num = 1;
		int y = 0;
		int x = 0;

		//지금 가는 방향
		int dir = 0;

		//solve

		while (num <= N * N) 
		{
			MAP[y][x] = num;

			//다음 위치, 갈 수 있는지 확인
			//다음 좌표->지금 내 좌표 기준으로, 내가 가는 방향의 offset
			int ny = y + ydir[dir];
			int nx = x + xdir[dir];

			//갈수없는공간인지 판별
			//#1.범위를 벗어났거나
			//#2.이미 기록된 공간 이면 방향을 바꾼다.

			if (ny < 0 || nx < 0 || ny >= N || nx >= N ||MAP[ny][nx]!=0) {
				if (num == N * N) break;
				//방향을 바꾼다
				dir = (dir + 1) % 4; //0,1,2,3
				continue;
			}

			//갈 수 있는 공간
			y = ny;
			x = nx;

			//다음 기록할 숫자
			num++;
		}

		//output
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cout << MAP[i][j] << " ";
			}
			cout << "\n";
		}
		
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}