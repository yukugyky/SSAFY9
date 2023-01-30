#include <iostream>
#include <vector> //header에 벡터
using namespace std;

//vector<자료형> 변수이름
//vector<int> v(5); //v(parameter=칸수[capacity] 0으로 초기화가 된다)
// //vector<int> v(5,2); //5의 capacity를 가지는 벡터에서 안의 원소는 모두 2로 초기화
vector<int> v; //벡터 초기화

int main() {

	v.push_back(3);
	v.push_back(4);
	v.push_back(5);

	cout << v.front(); //첫번째 원소 참조
	cout << endl;
	cout << v.back(); //마지막 원소 참조

	return 0;
}