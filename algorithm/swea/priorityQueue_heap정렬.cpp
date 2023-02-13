#include <iostream>
#include <algorithm> //정렬기능이 포함된 라이브러리
#include <queue> //priority queue 포함
#include <vector>
#include <string>

using namespace std;


int main()
{
	string s;
	cin >> s;

	priority_queue<char,vector<char>,less<char>> pq; //maxheap이 기본
	
	for (int i = 0; i < s.length(); i++)
	{
		pq.push(s[i]);
	}

	//for (int i = 0; i < pq.size(); i++)
	//{
	//	cout << pq.top();
	//	pq.pop();
	//}
	//이러면 pq.size가 pop될때마다 하나씩 줄어드니깐 일정하지않아서 안됨. empty()로 while문 쓰기

	while (!pq.empty()) {
		cout << pq.top();
		pq.pop();
	}

	return 0;
}