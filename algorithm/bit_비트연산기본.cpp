#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

//비트 연산
//Bit = 가장 작은 데이터 단위
// tb gb mb kb byte -> bit
// 1byte = 8bit
// 2진수로 표현 0과 1로만 이루어져있다

//비트연산자
//A&B (AND) : A,B가 모두 1이면 1 아니면 0
//A|B (OR) : A,B 중 하나만 1이여도 1 아니면 0
//A^B (Xor, Exclusive or): 둘이 다르면 1 아니면 0
//~A (Not, *Complement): 0이면 1, 1이면 0
//<<N (left shift): 모든 비트를 N칸 왼쪽으로 이동
//>>N (right shift) : 모든 비트를 N칸 오른쪽으로 이동

int main() {
	int A = 3;
	int B = 5;

	int C = A & B;
	cout << C<<"\n";


	//0011
	//0101

	int D = A | B;
	cout << D << '\n';

	int E = A ^ B;
	cout << E << "\n";
	
	///특정 비트를 1로 바꾸고싶다
	//0101
	//0010
	//-----
	//0111
	int N = 1;
	int res = B | (1 << N);

	//특정 bit를 토글 ->내가 정한 위치를 바꾸는거
	/*
	B=5=>0101
	N=1=>0111
	N=0=>0100
	*/
	N = 1;
	res = B ^ (1 << N);
	cout << res << '\n';

	/*
	특정 bit를 삭제
	B=5 => 0101
	N=0 => 0100
	N=2 => 0001
	N=1 => 0101

	 0101
	 0100 =>보수로 바꾸기
	^------
	 0001

	 0101
	 1011
	&----
	 0001

	*/

	N = 2;
	res = B & ~(1 << N);
	cout << res << '\n';

	return 0;
}
