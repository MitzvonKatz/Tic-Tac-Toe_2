//TicTacToe
//Anamarija Thomae, 20150075
//01.11.2018
//

#include<stdlib.h>
#include<stdio.h>
#include "TicTacToeHeader.h"
#include <time.h>


//Field allocation
int allocated= 0;
int player = 0;
int computer = 0;

void tictactoe()
{
	//RandGenerator
	srand(time(NULL));
	printf("---- Welcome to TicTacToe ----\n\n");
	draw();
	play();

}

int field(int f) {
	// If the field is filled, return the corresponding character.
	if (player & (1 << f))
		return 'X';
	if (computer & (1 << f))
		return 'O';
	return ' ';
}

void draw()
{
	int i;
	printf("-------------------\n");
	for (i = 0; i <= 6; i = i + 3) {
		printf("|  %c  |  %c  |  %c  |", field(i), field(i + 1), field(i + 2));
		printf("\n-------------------\n");
	}
}

void play() {
	int move = 0;
	int input;
	while (!win()) {
		//Player
		if (move == 0) {
			printf("Field: ");
			input = getchar() - 48;
			getchar(); //clear buffer
			if (input <= 8 && input >= 0 && (!((1 << input) & allocated))) {
				player = player | (1 << input);
				allocated = allocated | (1 << input);
				move = 1;
			}
		}
		//NPC
		else {
			printf("Computer's turn\n");
			do {
				input = rand() % 9;
			} while (((1 << input) & allocated));
			computer = computer | (1 << input);
			allocated = allocated | (1 << allocated);
			move = 0;
		}
		draw();
	}
	int winner = win();
	if (winner == 1)
		printf("Congatulation! You win!");
	else if (winner == 2)
		printf("Computer wins!");
	else if (winner == 3)
		printf("It's a tie.");
}

//return 0 for no win, 1 for player, 2 for computer, 3 for tie
int win()
{
	//Winning conditions
	int w1, w2, w3, w4, w5, w6, w7, w8, tie;

	//horizontally
	w1 = 0 | 1 | (1 << 1) | (1 << 2);
	w2 = 0 | (1 << 3) | (1 << 4) | (1 << 5);
	w3 = 0 | (1 << 6) | (1 << 7) | (1 << 8);


	//diagonally
	w4 = 0 | (1 << 2) | (1 << 4) | (1 << 6);
	w5 = 0 | (1 << 0) | (1 << 4) | (1 << 8);


	//vertikally
	w6 = 0 | 1 | (1 << 3) | (1 << 6);
	w7 = 0 | (1 << 1) | (1 << 4) | (1 << 7);
	w8 = 0 | (1 << 2) | (1 << 5) | (1 << 8);


	//tie
	tie = 0 | 1 | (1 << 1) | (1 << 2) | (1 << 3) | (1 << 4) | (1 << 5) | (1 << 6) | (1 << 7) | (1 << 8);


	//player
	if ((w1 & player) == w1)
		return 1;
	if ((w2 & player) == w2)
		return 1;
	if ((w3 & player) == w3)
		return 1;
	if ((w4 & player) == w4)
		return 1;
	if ((w5 & player) == w5)
		return 1;
	if ((w6 & player) == w6)
		return 1;
	if ((w7 & player) == w7)
		return 1;
	if ((w8 & player) == w8)
		return 1;
	//Computer
	if ((w1 & computer) == w1)
		return 2;
	if ((w2 & computer) == w2)
		return 2;
	if ((w3 & computer) == w3)
		return 2;
	if ((w4 & computer) == w4)
		return 2;
	if ((w5 & computer) == w5)
		return 3;
	if ((w6 & computer) == w6)
		return 2;
	if ((w7 & computer) == w7)
		return 2;
	if ((w8 & computer) == w8)
		return 2;
	if (allocated == tie)
		return 2;
	return 0;
}
