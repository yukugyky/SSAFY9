#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;

/*
Hash map
c++에서 쓸 수 있는 map의 종류는 두개가 있다
1. unordered_map //얘를 쓰세요(정렬되지 않은 맵)
-> hash-table 구조를 이용
-> 만들고, 삭제, 탐색 O(1)~O(logN)
string의 데이터를 전부 변환

2. map<--정렬된 맵
-> red-black tree
-> 새로 만들고, 삭제, 탐색 -> O(logN)
비교적으로 양이 많은 경우 불리하다.
string으 key로 쓸 때
*/


int main() {
	//MAP= 고유의 키 값을 가진다
	//이미 존재하는게 있다면->덮어씌우는게 아니라
	//무시함
	int arr[] = { 1,200000000,200000000,1,5 };
	//MAP 생성
	// unordered_map<key type, value type>
	unordered_map<int, int>um;

	/*
	for (int i = 0; i < 5; i++)
	{
		um.insert({ arr[i],1 });
	}
	*/

	for (int i = 0; i < 5; i++)
	{
		//만약 이미 map에 키가 등록되어있다면
		//해당 키값에 연결된 value+1
		//find(값)->없으면 um.end()
		if (um.find(arr[i]) != um.end()) {
			um[arr[i]]++;
		}

		//만약 key가 없다면
		//새로 찾은 숫자=value=1
		else {
			um.insert({ arr[i],1 });
		}

	}

	cout << um[1]<<"\n";
	
	//um[key] ->key가 만약 없으면 하나 생성됨 ex) um[3]

	//traversal / iteration
	//시간이 꽤 걸림
	for (auto it = um.begin(); it != um.end(); it++)
	{
		cout << it->first << " " << it->second << "\n";
	}



	return 0;
}
