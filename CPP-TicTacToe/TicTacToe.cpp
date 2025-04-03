#include "TicTacToe.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>

bool TicTacToe::IsGameOver() const {
	const std::vector<int> p1Moves = m_player1.GetMoves();
	const std::vector<int> p2Moves = m_player2.GetMoves();

	if (HasMoves(p1Moves, { 1, 2, 3 })) return true ;
	if (HasMoves(p1Moves, { 4, 5, 6 })) return true;
	if (HasMoves(p1Moves, { 7, 8, 9 })) return true;
	if (HasMoves(p1Moves, { 1, 4, 7 })) return true;
	if (HasMoves(p1Moves, { 2, 5, 8 })) return true;
	if (HasMoves(p1Moves, { 3, 6, 9 })) return true;
	if (HasMoves(p1Moves, { 1, 5, 9 })) return true;
	if (HasMoves(p1Moves, { 3, 5, 7 })) return true;

	if (HasMoves(p2Moves, { 1, 2, 3 })) return true;
	if (HasMoves(p2Moves, { 4, 5, 6 })) return true;
	if (HasMoves(p2Moves, { 7, 8, 9 })) return true;
	if (HasMoves(p2Moves, { 1, 4, 7 })) return true;
	if (HasMoves(p2Moves, { 2, 5, 8 })) return true;
	if (HasMoves(p2Moves, { 3, 6, 9 })) return true;
	if (HasMoves(p2Moves, { 1, 5, 9 })) return true;
	if (HasMoves(p2Moves, { 3, 5, 7 })) return true;

	if (p1Moves.size() + p2Moves.size() == 9) return true;

	return false;
}

bool TicTacToe::HasMoves(const std::vector<int> & moves, const std::vector<int> & tryMoves) const {
	for (int tryMove : tryMoves) {
		bool match = false;
		for (int move : moves) { if (move == tryMove) match = true; }
		if (!match) return false;
	}
	return true;
}

void TicTacToe::Display() const {
	system("cls");
	std::cout << currentBoard.line1 << currentBoard.line2 << currentBoard.line3 << currentBoard.line4 << currentBoard.line5 << std::endl;
}

void TicTacToe::TakeTurn() {
	int input;
	bool isValid = true;
	do {
		const std::vector<int> p1Moves = m_player1.GetMoves();
		const std::vector<int> p2Moves = m_player2.GetMoves();
		Display();
		if (!isValid) {
			std::cout << "Invalid input. Space already taken.\n";
		}
		isValid = true;
		std::cout << pCurrentPlayer->GetName() << ", where would you like to place your mark? (1-9): ";
		std::cin >> input;
		while (input > 9 || input < 1) {
			std::cout << "Invalid input. Please enter a number 1-9 to place your mark.";
			std::cin >> input;
		}

		for (int i = 0; i < p1Moves.size(); i++)
		{
			if (input == p1Moves[i]) isValid = false;
		}
		
		if (isValid) {
			for (int i = 0; i < p2Moves.size(); i++)
			{
				if (input == p2Moves[i]) isValid = false;
			}
		}
	} while (!isValid);

	pCurrentPlayer->AddMove(input);

	const std::vector<int> p1Moves = m_player1.GetMoves();
	const std::vector<int> p2Moves = m_player2.GetMoves();

	std::string p1 = "1", p2 = "2", p3 = "3", p4 = "4", p5 = "5", p6 = "6", p7 = "7", p8 = "8", p9 = "9";

	for (int move : p1Moves) {
		switch (move) {
			case 1: p1 = "X"; break;
			case 2: p2 = "X"; break;
			case 3: p3 = "X"; break;
			case 4: p4 = "X"; break;
			case 5: p5 = "X"; break;
			case 6: p6 = "X"; break;
			case 7: p7 = "X"; break;
			case 8: p8 = "X"; break;
			case 9: p9 = "X"; break;
		}
	}

	for (int move : p2Moves) {
		switch (move) {
			case 1: p1 = "O"; break;
			case 2: p2 = "O"; break;
			case 3: p3 = "O"; break;
			case 4: p4 = "O"; break;
			case 5: p5 = "O"; break;
			case 6: p6 = "O"; break;
			case 7: p7 = "O"; break;
			case 8: p8 = "O"; break;
			case 9: p9 = "O"; break;
		}
	}

	EditLine(currentBoard.line1, p1 + " | " + p2 + " | " + p3 + "\n");
	EditLine(currentBoard.line3, p4 + " | " + p5 + " | " + p6 + "\n");
	EditLine(currentBoard.line5, p7 + " | " + p8 + " | " + p9 + "\n");

	SwitchPlayer();
}