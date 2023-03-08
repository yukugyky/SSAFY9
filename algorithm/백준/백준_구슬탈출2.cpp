#include<iostream>
#include<cstring>
#include<string>

using namespace std;

int N, M;
char board[11][12];
int mini = 2e8;
int flagover;
int l, r, u, d;
int visited[5];

struct Node {
	int y;
	int x;
};

Node red;
Node blue;

int right() {

	int flagr = 0;
	if (red.x > blue.x) {
		while (board[red.y][red.x+1] == '.') {
			board[red.y][red.x + 1] = 'R';
			board[red.y][red.x] = '.';
			red.x++;
		}
		if (board[red.y][red.x+1] == 'O') {
			board[red.y][red.x] = '.';
			flagr = 1;
		}
		while (board[blue.y][blue.x+1] == '.') {
			board[blue.y][blue.x + 1] = 'B';
			board[blue.y][blue.x] = '.';
			blue.x++;
		}
		if (board[blue.y][blue.x+1] == 'O') return -1;
	}
	else {
		while (board[blue.y][blue.x+1] == '.') {
			board[blue.y][blue.x + 1] = 'B';
			board[blue.y][blue.x] = '.';
			blue.x++;
		}
		if (board[blue.y][blue.x+1] == 'O') return -1;
		while (board[red.y][red.x+1] == '.') {
			board[red.y][red.x + 1] = 'R';
			board[red.y][red.x] = '.';
			red.x++;
		}
		if (board[red.y][red.x+1] == 'O') flagr = 1;
	}
	if (flagr == 1) return 1;
}

int left() {

	int flagr = 0;
	if (red.x < blue.x) {
		while (board[red.y][red.x - 1] == '.') {
			board[red.y][red.x - 1] = 'R';
			board[red.y][red.x] = '.';
			red.x--;
		}
		if (board[red.y][red.x - 1] == 'O') {
			board[red.y][red.x] = '.';
			flagr = 1;
		}
		while (board[blue.y][blue.x - 1] == '.') {
			board[blue.y][blue.x - 1] = 'B';
			board[blue.y][blue.x] = '.';
			blue.x--;
		}
		if (board[blue.y][blue.x - 1] == 'O') return -1;
	}
	else {
		while (board[blue.y][blue.x - 1] == '.') {
			board[blue.y][blue.x - 1] = 'B';
			board[blue.y][blue.x] = '.';
			blue.x--;
		}
		if (board[blue.y][blue.x - 1] == 'O') return -1;
		while (board[red.y][red.x - 1] == '.') {
			board[red.y][red.x - 1] = 'R';
			board[red.y][red.x] = '.';
			red.x--;
		}
		if (board[red.y][red.x - 1] == 'O') flagr = 1;
	}
	if (flagr == 1) return 1;
}

int up() {

	int flagr = 0;
	if (red.y < blue.y) {
		while (board[red.y - 1][red.x] == '.') {
			board[red.y-1][red.x] = 'R';
			board[red.y][red.x] = '.';
			red.y--;
		}
		if (board[red.y - 1][red.x] == 'O') {
			board[red.y][red.x] = '.';
			flagr = 1;
		}
		while (board[blue.y - 1][blue.x] == '.') {
			board[blue.y-1][blue.x] = 'B';
			board[blue.y][blue.x] = '.';
			blue.y--;
		}
		if (board[blue.y - 1][blue.x] == 'O') return -1;
	}
	else {
		while (board[blue.y - 1][blue.x] == '.') {
			board[blue.y - 1][blue.x] = 'B';
			board[blue.y][blue.x] = '.';
			blue.y--;
		}
		if (board[blue.y - 1][blue.x] == 'O') return -1;
		while (board[red.y - 1][red.x] == '.') {
			board[red.y - 1][red.x] = 'R';
			board[red.y][red.x] = '.';
			red.y--;
		}
		if (board[red.y - 1][red.x] == 'O') flagr = 1;
	}
	if (flagr == 1) return 1;
}

int down() {

	int flagr = 0;
	if (red.y <
		blue.y) {
		while (board[red.y + 1][red.x] == '.') {
			board[red.y + 1][red.x] = 'R';
			board[red.y][red.x] = '.';
			red.y++;
		}
		if (board[red.y + 1][red.x] == 'O') {
			board[red.y][red.x] = '.';
			flagr = 1;
		}
		while (board[blue.y + 1][blue.x] == '.') {
			board[blue.y + 1][blue.x] = 'B';
			board[blue.y][blue.x] = '.';
			blue.y++;
		}
		if (board[blue.y + 1][blue.x] == 'O') return -1;
	}
	else {
		while (board[blue.y + 1][blue.x] == '.') {
			board[blue.y + 1][blue.x] = 'B';
			board[blue.y][blue.x] = '.';
			blue.y++;
		}
		if (board[blue.y + 1][blue.x] == 'O') return -1;
		while (board[red.y + 1][red.x] == '.') {
			board[red.y + 1][red.x] = 'R';
			board[red.y][red.x] = '.';
			red.y++;
		}
		if (board[red.y + 1][red.x] == 'O') flagr = 1;
	}
	if (flagr == 1) return 1;
}


void dfs(int cnt) {
	
	if (cnt > 10) {
		flagover = 1;
		return;
	}
	

	for (int i = 0; i < 4; i++)
	{
		char cpy[11][12] = { 0 };
		memcpy(cpy, board, sizeof(board));
		if (visited[0] == 1) {
			if (i == 0) continue;
			if (i == 1) continue;
			visited[0] = 0;
		}
		if (visited[1] == 1) {
			if (i == 0) continue;
			if (i == 1) continue;
			visited[1] = 0;
		}
		if (visited[2] == 1) {
			if (i == 2) continue;
			if (i == 3) continue;
			visited[2] = 0;

		}
		if (visited[3] == 1) {
			if (i == 2) continue;
			if (i == 3) continue;
			visited[3] = 0;
		}
 		if (i == 0) {
			l = 0;
			l = left();
			if (l == -1) continue;
		}
		if (i == 1) {
			r = 0;
			r = right();
			if (r == -1) continue;
		}
		if (i == 2) {
			u = 0;
			u = up();
			if (u == -1) continue;
		}
		if (i == 3) {
			d = 0;
			d = down();
			if (d == -1) continue;
		}
		if (l == 1 || r == 1 || u == 1 || d == 1) {
			if (cnt < mini) mini = cnt;
			return;
		}
		visited[i] = 1;
		dfs(cnt + 1);
		memcpy(board, cpy, sizeof(board));
	}
}

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		cin >> board[i];
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (board[i][j] == 'R') {
				red = { i,j };
			}
			if (board[i][j] == 'B') {
				blue = { i,j };
			}
		}
	}

	int de = 1;
	dfs(1);

	if (mini != 2e8) {
		cout << mini << "\n";
		return 0;
	}

	if (flagover == 1) {
		cout << "-1\n";
		return 0;
	}


}