#include<iostream>

using namespace std;

int N, L;
int MAP[101][101];
int ans;

void isOut(int mapi[]) {
	int visited[101] = { 0, }; //경사로 설치 표시
	for (int j = 0; j < N - 1; j++)
	{
		int sub = mapi[j] - mapi[j+1];
		if (abs(sub) > 1) return; //차이가 2이상이면 경사로 설치 불가
		if (sub == 1) {
			//다음 칸과 차이가 1일때
			if (j + L > N-1) return; //0 이상
			for (int k = j + 1; k < j + L + 1; k++)
			{
				if (mapi[j] - mapi[k] != 1) return; //경사로 설치 가능 여부 확인
				visited[k] = 1; //설치 표시
			}
		}
		if (sub == -1) {
            //다음 칸과 차이가 -1일때
			if (j - L + 1 < 0) return; //N-1 이하
			for (int k = j-L+1; k <= j; k++)
			{
				if (visited[k] == 1) return; //이전에 경사로 설치했으면 설치 x니깐 return
				if (mapi[k] - mapi[j+1] != -1) return; //경사로 설치 가능 여부 확인
				visited[k] = 1; //설치 표시
			}
		}
	}
	ans++;
}

int main() {
	cin >> N >> L;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> MAP[i][j];
		}
	} //지도 입력

	for (int i = 0; i < N; i++)
	{//가로줄 검사
		int MAPI[101] = { 0, };
		for (int j = 0; j < N; j++)
		{
			MAPI[j] = MAP[i][j];
		}
		isOut(MAPI);
	}

	for (int i = 0; i < N; i++)
	{//세로줄 검사
		int MAPI[101] = { 0, };
		for (int j = 0; j < N; j++)
		{
			MAPI[j] = MAP[j][i];
		}
		isOut(MAPI);
	}

	cout << ans;
}