#ifndef _NODE_H_
#define _NODE_H_
#include <vector>
#include <string>

class Node
{
public:
	Node(std::vector<int> gameState, std::string moves);
	std::vector<int> getGameState();//returns the current game board
	std::string getMove();//returns the move used to get the current game board
	void setString(std::string path);

private:
	std::vector<int> mGameState; //the current overall board state
	std::string mMoves;//the move that caused the current gamestate
};


#endif