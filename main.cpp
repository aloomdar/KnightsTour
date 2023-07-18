#include <vector>
#include <iostream>
#include <iomanip>
using namespace std;

bool goodMove(int x, int y, const vector<vector<int>>& board);
bool knightsTour(int x, int y, int moveCounter, vector<vector<int>>& board, int moveX[], int moveY[]);
void print(const vector<vector<int>>& board);
void solveKnightsTour(int size);

bool goodMove(int x, int y, const vector<vector<int>>& board) {
	return (x >= 0 && x < 8 && y >= 0 && y < 8 && board[x][y] == 0);
}

bool knightsTour(int x, int y, int moveCounter, vector<vector<int>>& board, int moveX[], int moveY[]) {
	if (moveCounter == 65) {
		return true;
	}

	for (int i = 0; i < 8; i++) {
		int nextX = x + moveX[i];
		int nextY = y + moveY[i];
		if (goodMove(nextX, nextY, board)) {
			board[nextX][nextY] = moveCounter;
			if (knightsTour(nextX, nextY, moveCounter + 1, board, moveX, moveY)) {
				return true; 
			}
			else {
				board[nextX][nextY] = 0;
			}
		}
	}
	return false;
}

void print(const vector<vector<int>>& board) {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cout << board[i][j] << setw(2) << " ";
		}
		cout << endl;
	}
}

void solveKnightsTour(int size) {
	vector<vector<int>> board(size, vector<int>(size, 0));

	int moveX[] = { 2, 1, -1, -2, -2, -1, 1, 2 };
	int moveY[] = { 1, 2, 2, 1, -1, -2, -2, -1 };
	
	int xStart = 0;
	int yStart = 0;
	board[xStart][yStart] = 1;

	if (knightsTour(xStart, yStart, 2, board, moveX, moveY)) {
		print(board);
	}
}

int main() {

	int size = 8;
	solveKnightsTour(size);
	return 0;
}