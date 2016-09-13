#include "node.h"

Node::Node(std::vector<int> gameState, std::string moves)
{
	this->mGameState = gameState;
	this->mMoves = moves;
}

std::vector<int> Node::getGameState()
{
	return this->mGameState;
}

std::string Node::getMove()
{
	return this->mMoves;
}

void Node::setString(std::string path)
{
	this->mMoves += path;
}