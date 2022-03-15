#include <iostream>
#include <io.h>
using namespace std;

char plane[9];
char current_player = 'x';


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

bool char_placer(int index) {
	index--;
	if (plane[index] == ' ') {
		plane[index] = current_player;
		return true;
	}
	else return false; 
}

void game_loop() {
	while (!false) {
		print();
		cout << (char)0xa << "Tura " << current_player << " ";
		char_placer(take_input());
		player_switcher();
	}
}

int main() {
	setup();
	game_loop();

	return 0;
}
