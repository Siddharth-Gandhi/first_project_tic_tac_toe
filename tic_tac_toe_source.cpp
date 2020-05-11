#include <iostream>
#include <vector>

using namespace std;

vector<vector<char>> board(3, vector<char> (3));
int choice, row, col;
char turn = 'X';
bool draw = false;

void initialize(){
	board[0][0] = '1';
	board[0][1] = '2';
	board[0][2] = '3';
	board[1][0] = '4';
	board[1][1] = '5';
	board[1][2] = '6';
	board[2][0] = '7';
	board[2][1] = '8';
	board[2][2] = '9';
}

void player_turn(){
	if(turn == 'X'){
		cout << "Player 1 enter a number\n";
	}
	else{
		cout << "Plater 2 enter a number\n";
	}
	cin >> choice;
	switch(choice){
		case 1 : row = 0; col = 0; break;
		case 2 : row = 0; col = 1; break;
		case 3 : row = 0; col = 2; break;
		case 4 : row = 1; col = 0; break;
		case 5 : row = 1; col = 1; break;
		case 6 : row = 1; col = 2; break;
		case 7 : row = 2; col = 0; break;
		case 8 : row = 2; col = 1; break;
		case 9 : row = 2; col = 2; break;
		default: 
			cout << "Invalid Move, please try again";
	}
	
	if(turn == 'X' && board[row][col] != 'O' && board[row][col] != 'X'){
		board[row][col] = 'X';
		turn = 'O';
	}
	else if(turn == 'O' && board[row][col] != 'O' && board[row][col] != 'X'){
		board[row][col] = 'O';
		turn = 'X';
	}
	
}

void display_board(){
	cout << "Player 1 : X \t Player 2 : O \n";
	cout << "\t" << "  |   |  " << "\n"; 
	cout << "\t" << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << "\n";
	cout << "\t" << "__|___|__" << "\n"; 
	cout << "\t" << "  |   |  " << "\n"; 
	cout << "\t" << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << "\n";
	cout << "\t" << "__|___|__" << "\n"; 
	cout << "\t" << "  |   |  " << "\n"; 
	cout << "\t" << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << "\n";
	cout << "\t" << "  |   |  " << "\n"; 
}

bool game_over(){
	for(int i = 0 ; i < 3 ; ++i){
		if((board[0][i] == board[1][i] && board[0][i] == board[2][i]) || (board[i][0] == board[i][1] && board[i][0] == board[i][2])){
			return true;
		}
	if((board[0][0] == board[1][1] && board[0][0] == board[2][2]) || (board[0][2] == board[1][1] && board[0][2] == board[2][0])){
		return true;
		}
	}
	for(int i = 0 ; i < 3 ; ++i){
		for(int j = 0 ; j < 3 ; ++j){
			if(board[i][j] != 'X' && board[i][j] != 'O'){
				return false;
			}
		}
	}
	draw = true;
	return true;
}

int main(){
	initialize();
	while(!game_over()){
		display_board();
		player_turn();
		game_over();
	}
	if(turn == 'X' && draw == false){
		cout << "Player 2 wins\n";
	}
	else if(turn == 'O' && draw == false){
		cout << "Player 1 wins\n";
	}
	else{
		cout << "Draw bois\n";
	}
	return 0;
}

