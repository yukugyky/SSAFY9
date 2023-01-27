#include <iostream>
using namespace std;

/*
주사위게임
나올 수 있는 모든 경우

입력:정수1개
출력:해당 주사위들로 나올 수 있는 주사위 눈의 모든 경우

*/

int N;

int path[10]; //index: 주사위 번째, value: 해당 주사위에서 어떤 눈을 뽑았는가?
//주사위번째, 눈

int visited[7];//index: 주사위 눈, value: 해당 주사위 눈을 뽑았었는지(0: 안뽑음. 1:뽑음)
//주사위 눈->뽑았었는가
//선택을 기반으로 해당 선택을 했는가

int sum = 0;

void func(int a) {
	//지금 a번째 주사위 눈을 뽑을 차례
	
	//2.기저조건
	// 0~N번 주사위까진 정상
	//N번 주사위부터는 존재하지 않는 주사위
	//N번 주사위까지 왔다=>0~N-1번 주사위에선 모두 눈을 뽑았다

	if (a >= N) {
		//if()//같은 눈을 뽑은 기록이 없으면
		for (int i = 0; i < N; i++) {
			cout << path[i] << " ";
		}
		cout << "sum: " << sum;
		cout << "\n";
		return;
	}

	//i:1~6이라는 눈
	for (int i = 1; i <= 6; i++) 
	{
		//4. 가지치기

		//i라는 눈을 이번에 뽑고 싶은데 괜찮은가??
		if (visited[i] == 1)
			continue;//i라는 눈을 스킵하고 다음 눈으로 넘어가라.
		//break는 for문 탈출이니깐 안되고 continue를 써서 다음 눈으로 넘어감!
		// 괜찮으면 뽑아가자


		//3. '기록 및 처리'
		//a번째 주사위에서 i라는 눈을 뽑았다.
		path[a] = i;
		visited[i] = 1;
		sum += i; //합값 구하기


		//1. 재귀 기본 구조
		//a+1번째 주사위에서 눈을 뽑으러 가라!

		func(a + 1);

		visited[i]=0; //0으로 만들어주어야 다음으로 넘어갔을 때 해당 숫자가 출력이 가능함.
		sum -= i;//앞 처리를 그대로 복구해야하니깐
	}
}

int main() {

	cin >> N;
	func(0);

	return 0;
}