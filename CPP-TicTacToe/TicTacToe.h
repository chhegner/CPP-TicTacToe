#pragma once

#include <iostream>
#include "Game.h"

class TicTacToe : public Game
{
private:
	//fields
	int turn = 1;
	int* turnPointer = &turn;

	int maxTurn = 9;
	int* maxTurnPointer = &maxTurn;

	char m_board[9];
	int userInput;
	int playerTurn = 0;
	int winMethod = 0;
	int* p_winMethod = &winMethod;

public:
	bool IsGameOver() const
	{
		if (m_board[0] == m_board[1] == m_board[2]) { *p_winMethod = 1; return true; }
		else if (m_board[3] == m_board[4] == m_board[5]) { *p_winMethod = 2; return true; }
		else if (m_board[6] == m_board[7] == m_board[8]) { *p_winMethod = 3; return true; }

		else if (m_board[0] == m_board[3] == m_board[6]) { *p_winMethod = 4; return true; }
		else if (m_board[1] == m_board[4] == m_board[7]) { *p_winMethod = 5; return true; }
		else if (m_board[2] == m_board[5] == m_board[8]) { *p_winMethod = 6; return true; }

		else if (m_board[0] == m_board[4] == m_board[8]) { *p_winMethod = 7; return true; }
		else if (m_board[2] == m_board[4] == m_board[6]) { *p_winMethod = 8; return true; }

		//if Win method is > 0, the game is not a tie. 

		else if (*turnPointer >= *maxTurnPointer) { *p_winMethod = 0; return true; }
		else return false;
	}

	void Display() const //draws board
	{
		std::cout << m_board[0] << "   |  " << m_board[1] << "   |  " << m_board[2] << "\n";
		std::cout << "------------\n";
		std::cout << m_board[3] << "   |   " << m_board[4] << "  |  " << m_board[5] << "\n";
		std::cout << "------------\n";
		std::cout << m_board[6] << "   |   " << m_board[7] << "  |  " << m_board[8] << "\n";
	}

	void TakeTurn()
	{
		if (IsGameOver() == false)
		{
			//Propmpts player for input, checks validity, passes input through to m_board on success, re-prompts user on fail. Increments turn count to check for filled board at end. 
			std::cout << "Please make a move, player " << playerTurn + 1 << ": ";
			std::cin >> userInput;
			if ((userInput - 1) < 0 && (userInput - 1) > 9)
			{
				std::cout << "Please input a valid move\n";
			}
			else
			{
				if (playerTurn = 0) { m_board[userInput - 1] = 'o', playerTurn = 1; }
				else { m_board[userInput - 1] = 'x', playerTurn = 0; }
				turn++;
			}
		}
		else if (winMethod < 1) { std::cout << "The game is a draw!"; } //If the winMethod is less than 1, the game is known to have ended in a draw.
		else if (turn % 2) { std::cout << "Player 2 wins"; } //If the last-played turn is even, and winMethod is > or = to 1, we proved Player 2 has won 
															//because Player 1 only plays on odd turn numbers, and therefore can only win on odd turns.
		else { std::cout << "Player 1 wins"; } //If neither of the above is true, player 1 (in theory) has won.
	}
};

//#pragma once
//
//#include <iostream>
//#include "Game.h"
//
//class TicTacToe : public Game
//{
//private:
//	//fields
//	int turn = 0;
//	int* turnPointer = &turn;
//
//	int maxTurn = 9;
//	int* maxTurnPointer = &maxTurn;
//
//	int userInput;
//	int playerTurn = 0;
//	int winner = 0;
//
//	int winMethod = 0;
//	int* winMethodPointer = &winMethod;
//
//public:
//	bool IsGameOver() const
//	{
//		if (board[0] = board[1] = board[2]) { *winMethodPointer == 1; return true; }
//		if (board[3] = board[4] = board[5]) { *winMethodPointer == 2; return true; }
//		if (board[6] = board[7] = board[8]) { *winMethodPointer == 3; return true; }
//
//		if (board[0] = board[3] = board[6]) { *winMethodPointer == 4; return true; }
//		if (board[1] = board[4] = board[7]) { *winMethodPointer == 5; return true; }
//		if (board[2] = board[5] = board[8]) { *winMethodPointer == 6; return true; }
//
//		if (board[0] = board[4] = board[8]) { *winMethodPointer == 7; return true; }
//		if (board[2] = board[4] = board[6]) { *winMethodPointer == 8; return true; }
//
//		if (*turnPointer >= *maxTurnPointer) { return true; }
//		else return false;
//	}
//
//	void Display() const
//	{
//		std::cout << board[0] << "   |  " << board[1] << "  |  " << board[2] << "\n";
//		std::cout << "------------\n";
//		std::cout << board[3] << "   |  " << board[4] << "  |  " << board[5] << "\n";
//		std::cout << "------------\n";
//		std::cout << board[6] << "   |  " << board[7] << "  |  " << board[8] << "\n";
//	}
//
//	void TakeTurn()
//	{
//		if (IsGameOver() == false)
//		{
//			std::cout << "Please make a move, player " << playerTurn + 1 << ": ";
//			std::cin >> userInput;
//			if (userInput + 1 < 0 || userInput + 1 > 9)
//			{
//				std::cout << "Please input a valid move\n";
//			}
//			else
//			{
//				if (playerTurn = 0) { board[userInput] = 'o', playerTurn = 1; }
//				else { board[userInput] = 'x', playerTurn = 0; }
//				turn++;
//			}
//		}
//	}
//};