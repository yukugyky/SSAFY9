//금나와라
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

struct Node {
	int weight;
	bool isGold; //황금:true, 짱돌:false
};

struct cmp {
	bool operator()(Node left, Node right) {
		if (left.weight != right.weight) {
			return left.weight > right.weight;
		}
		if (left.isGold == false && right.isGold == true)
			return true;
		if (left.isGold == true && right.isGold == false)
			return false;
		return false;
	}
};

int n;

int main()
{
	priority_queue<Node, vector<Node>, cmp> pq;

	for (int i = 0; i < n; i++)
	{
		int  weight;
		cin >> weight;
		pq.push({ weight, true });
	}

	int cnt = 0;
	while (1) {
		Node first = pq.top();
		pq.pop();
		if (first.isGold == false) break;
		cnt++;

		Node second = pq.top();
		pq.pop();
		if (second.isGold == false) break;
		cnt++;

		pq.push({ 2 * second.weight, false });

	}

	cout << cnt;

	return 0;
}