#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int N, M, C; //맵크기, 벌꿀채취크기, 채취최대량
int MAP[15][15];
int visited[15]; //왜 일차??
int result;
int tmpMax=-1;

struct map {
	int y;
	int x;
	int value;
};

bool cmpPossible(map left, map right){
	return left.value > right.value;
}

vector<int> arr;

void dfs(int now, int sum, int bef, vector<int>& tmp) {
	//now, 합, 이전까지합, M개 넣은 vector

	if (sum >= C || now == M) { //최대 이윤인지 확인

		bool reduce = false;
		if (sum > C) {
			sum -= bef;
			reduce = true;
		}

		int size = arr.size();
		if (reduce) size--;

		int tmpsum = 0;
		for (int i = 0; i < size; i++)
		{
			tmpsum = tmpsum + (arr[i] * arr[i]);
		}
		if (tmpMax < tmpsum) tmpMax = tmpsum;
		return;

	}

	for (int i = 0; i < tmp.size(); i++)
	{
		if (visited[i] == 1) continue;
		visited[i] = 1;

		arr.push_back(tmp[i]);

		dfs(now + 1, sum + tmp[i], tmp[i], tmp);
		visited[i] = 0;
		arr.pop_back();

	}
}

int main(void)
{

	int T;
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		cin >> N >> M >> C;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> MAP[i][j];
			}
		}

		vector<map> possible;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N-M+1; j++)
			{
				vector<int> tmp;
				for (int k = 0; k < j+M; k++)
				{
					tmp.push_back(MAP[i][k]); //M개만큼 넣음
				}
				tmpMax = -1;

				dfs(0, 0, 0, tmp); //인덱스,합,이전까지합
				
				possible.push_back({ i,j,tmpMax }); //시작지점, 이익

				tmp = vector<int>(); //초기화
			}
		}

		sort(possible.begin(), possible.end(), cmpPossible); //총합 큰순서로 정렬

		int maxi = -1;
		int len = possible.size();
		for (int i = 0; i < len; i++)
		{
			for (int j = i+1; j < len; j++)
			{
				if (possible[i].y == possible[j].y) {
					//같은 y칸일때
					if (possible[j].x <= possible[i].x + M - 1 ||
						possible[i].x <= possible[j].x + M - 1) continue;
					//칸 겹치면 continue
				}
				if (possible[i].value + possible[j].value > maxi) maxi = possible[i].value + possible[j].value;
			}
		}


		cout << "#" << t + 1 << " "<<maxi<<"\n";
		possible = vector<map>();
	}
	

}