#pragma once
#include <vector>
#include <string>

class Player {
	std::string m_name;
	std::vector<int> m_moves;
	static int s_playerCount;

public:
	Player() { s_playerCount++; s_playerCount == 1 ? m_name = "Player 1" : m_name = "Player 2"; }
	~Player() {}

	std::vector<int> GetMoves() const { return m_moves; }
	std::string GetName() const { return m_name; }

	void AddMove(int input) { m_moves.push_back(input); }
};