#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<unordered_map> //uno쓰고 탭
#include<string>
using namespace std;

map<int, string>kkk;

string arr[] = { "HI","HI","GGG","HI","GGG" };
unordered_map<string, int> um;

int main() {
	
	/*
	* c#, python : Dictionary
	* Java : HashMap
	* C++ : map, unordered_map
	* 
	*/

	string ccc[100];
	//1. index에 음수 사용 불가
	//2. index에 아주 큰 수 사용 불가
	//3. index에 문자열 사용 불가
	//dat의 단점을 극복한게 hash


	//문자열을 하나 입력받고, 그 문자열이 배열에 몇개 있는지 출력하는 프로그램 작성하기
	//입력받기 전 사전 세팅 (빠른 검색을 위한 초기화)
	for (int i = 0; i < 5; i++)
	{
		um[arr[i]]++;
	}

	string s;
	cin >> s;
	
	
	//if (um[s] < 0) {
	//	cout << "없네"; //등록되는 않은 키 값을 읽으면 바로 s추가됨.
	//}

	if (um.count(s) == 0) {
		cout << "없네~"; //이렇게 카운트로 물어봐야함
	}

	cout << um[s];


	return 0;
}
