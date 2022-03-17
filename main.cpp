#include <iostream>
#include <io.h>
using namespace std;

bool isCorrect;
char plane[9], current_player = 'x';
int move_number = 0, game_state = 0;

void setup();
int take_input();
void print();
void player_switcher();
void char_placer(int index);
void win_checker();
void game_loop();


int main() {
	setup();
	game_loop();

	return 0;
}

void setup() {
	for (int i = 0; i < 9; i++) {
		plane[i] = ' ';
	}
}
int take_input() {
	int number = -1;
	while (number > 9 || number < 1) {
		cout << "Podaj liczbe [1-9]: ";
		cin >> number;
	}
	return number;
}
void print() {
	system("cls");
	for (int i = 0; i < 9; i++) {
		if (i % 3 == 0) cout << (char)0xa;
		cout << "[" << plane[i] << "] ";

	}
}
void player_switcher() {
	if (current_player == 'x') current_player = 'o';
	else current_player = 'x';
}
void char_placer(int index) {
	index--;
	if (plane[index] == ' ') {
		plane[index] = current_player;
		isCorrect = true;
	}
	else isCorrect = false;
}
void win_checker() {
	int vertical[] = { 4,5,6 };
	int horizontal[] = { 2,5,8 };
	int cross[] = { 5 };
	for (int x : vertical) {
		if (plane[x] != ' ') {
			if ((plane[x] == plane[x - 3]) && (plane[x] == plane[x + 3])) {
				cout << "Winner: " << plane[x] << "\n";
				game_state = -1;
			}
		}
	}
	for (int x : horizontal) {
		if (plane[x] != ' ') {
			if ((plane[x] == plane[x - 1]) && (plane[x] == plane[x + 1])) {
				cout << "Winner: " << plane[x] << "\n";
				game_state = -1;
			}
		}
	}
	for (int x : cross) {
		if (plane[x] != ' ') {
			if ((plane[x] == plane[x - 4]) && (plane[x] == plane[x + 4])) {
				cout << "Winner: " << plane[x] << "\n";
				game_state = -1;
			}
			if ((plane[x] == plane[x - 2]) && (plane[x] == plane[x + 2])) {
				cout << "Winner: " << plane[x] << "\n";
				game_state = -1;
			}
		}
	}
}
void game_loop() {
	while (game_state == 0) {
		isCorrect = false;
		move_number++;
		print();
		win_checker();
		if (game_state != 0) break;
		cout << (char)0xa << "Tura " << current_player << " ";
		while (!isCorrect) {
			char_placer(take_input());
		}
		player_switcher();
		if (move_number == 9) {
			print();
			cout << endl << "Draw" << endl;
			game_state = -1;
		}
	}
}
