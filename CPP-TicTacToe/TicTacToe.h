#pragma once
#include "Game.h"
#include "Player.h"
#include <string>
struct Board {
	std::string line1;
	std::string line2;
	std::string line3;
	std::string line4;
	std::string line5;
};

class TicTacToe : public Game
{
private:
	Player m_player1;
	Player m_player2;
	Player * pCurrentPlayer;
	Board currentBoard;

public:
	TicTacToe(){ 
		pCurrentPlayer = &m_player1;
		currentBoard.line1 = "1 | 2 | 3\n";
		currentBoard.line2 = "---------\n";
		currentBoard.line3 = "4 | 5 | 6\n";
		currentBoard.line4 = "---------\n";
		currentBoard.line5 = "7 | 8 | 9\n";
	}
	~TicTacToe() {}
	void EditLine(std::string & targetLine, std::string newLine) { targetLine = newLine; }
	bool IsGameOver() const;
	void TakeTurn();
	void Display() const;
	bool HasMoves(const std::vector<int> & moves, const std::vector<int> & tryMoves) const;
	void SwitchPlayer() { if (pCurrentPlayer == &m_player1) { pCurrentPlayer = &m_player2; } else { pCurrentPlayer = &m_player1; } }
};

