#include <iostream>
#include <conio.h>
using namespace std;

class TicTacToe{
	int winCountP1, winCountP2, drawCount;
	int SIZE;
	char **board;
	void initializeBoard(){
		for (int i = 0; i < SIZE; i++){
			for (int j = 0; j < SIZE; j++){
				board[i][j] = '-';
			}
		}
	}
	void printBoard(){
		for (int i = 0; i < SIZE; i++){
			for (int j = 0; j < SIZE; j++){
				cout << board[i][j] << ' ';
			}
			cout << endl;
		}
	}
	bool isWin(char ch){
		int count;
		for (int i = 0; i < SIZE; i++){
			count = 0;
			for (int j = 0; j < SIZE; j++){
				if (board[i][j] == ch)
					count++;
			}
			if (count == SIZE)
				return true;
		}
		for (int i = 0; i < SIZE; i++){
			count = 0;
			for (int j = 0; j < SIZE; j++){
				if (board[j][i] == ch)
					count++;
			}
			if (count == SIZE)
				return true;
		}
		count = 0;
		for (int i = 0; i < SIZE; i++){
			if (board[i][i] == ch)
				count++;
		}
		if (count == SIZE)
			return true;
		count = 0;
		for (int i = 0, j = SIZE - 1; i < SIZE; i++, j--){
			if (board[i][j] == ch)
				count++;
		}
		if (count == SIZE)
			return true;
		return false;
	}
	bool isDraw(){
		for (int i = 0; i < SIZE; i++){
			for (int j = 0; j < SIZE; j++){
				if (board[i][j] == '-')
					return false;
			}
		}
		return true;
	}
	void printSummary(){
		cout << "Player X wins: " << winCountP1 << endl;
		cout << "Player O wins: " << winCountP2 << endl;
		cout << "Draw Games: " << drawCount << endl;

	}
public:
	TicTacToe(){
		winCountP1 = winCountP2 = drawCount = 0;
		SIZE = 3;
		for (int i = 0; i < SIZE; i++){
			board = new char *[SIZE];
		}
		for (int i = 0; i < SIZE; i++){
			board[i] = new char[SIZE];
		}
	}
	
	void runGame(){
	start:
		initializeBoard();
		bool isGameEnd = false;
		int row, col, playerTurn = 1;
		
		char player;
		while (!isGameEnd){
			system("cls");
			if (playerTurn == 1){
				player = 'X';
				playerTurn = 2;
			}
			else if (playerTurn == 2){
				player = 'O';
				playerTurn = 1;
			}
			do{
				system("cls");
				printSummary();
				printBoard();
				cout << "Player " << player << " Turn" << endl;
				cout << "Enter Row: "; cin >> row;
				cout << "Enter Col: "; cin >> col;
				row--;
				col--;
			} while (!(row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == '-'));
			board[row][col] = player;
			if (isWin(player)){
				system("cls");
				if (player == 'X')
					winCountP1++;
				else
					winCountP2++;
				printSummary();
				printBoard();
				cout << "Player " << player << " Wins" << endl;
				isGameEnd = true;
			}
			else if (isDraw()){
				system("cls");
				drawCount++;
				printSummary();
				printBoard();
				cout << "Game Draw" << endl;
				isGameEnd = true;
			}
		}
		cout << "Play AGAIN? (y/n)" << endl;
		if (_getch() == 'y')  goto start;

		system("pause");
	}
};