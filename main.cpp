#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include "node.h"

using namespace std;

vector<int> swapper(vector<int> toBeUpdatedVector, int indexA, int indexB){
	vector<int> myCopy;
	for (int i = 0; i < toBeUpdatedVector.size(); i++){
		myCopy.push_back(toBeUpdatedVector[i]);
	}
	int temp = myCopy[indexA];
	myCopy[indexA] = myCopy[indexB];
	myCopy[indexB] = temp;
	return myCopy;
}

bool solution(vector<int> check){
	//runs through the vector and compares its values to what a solved puzzle should look like ex:1 2 3 4 5 6 7 8 0
	for (int i = 0; i < check.size()-1; i++){//doesn't include the end tile being a blank space
		//cout << check[i] << endl;
		if (check[i] != (i+1)){
			return false;//returns false as soon as the first unmatched character is found
		} 
	}
	return true;//returns true if all characters match.
}

bool solver(int sizze, vector<int> game){
	/*
	Node parent = Node(game, ""); //first declare the initial board as the parent node
	vector<int> temp = parent.getGameState(); //testing returns from the node class
	for (int i = 0; i < temp.size(); i++){
		cout << temp[i] << endl;
		}
	cout << parent.getMove() << "<-move is empty?" << endl; //should return an empty string for the parent.
	bool test = solution(parent.getGameState());
	parent.setString("teststst");
	cout << parent.getMove() << endl;//prints moves from parent till now.
	cout << test << endl;//prints 0 for false and 1 for true, if the current state is the solution.
	*/
	queue<Node> breadthSearch;
	Node parent = Node(game, "");
	breadthSearch.push(parent);
	while (!breadthSearch.empty()){
		Node temp = breadthSearch.front();
		cout << temp.getMove() << endl;
		vector<int> tempVect = temp.getGameState();
		if (tempVect.back()==-1){
			if (solution(tempVect)){
				cout << "found it" << endl;
				cout << temp.getMove() << endl;
				break;
			}
		}
		if (tempVect.size()==9){
			//The set amount of moves is limited in each position so the following creates new child nodes based on the position of the hole.
			//after the child nodes are created the original node is popped off the queue.
			//the Node class carries each path up to its current state in its getMoves()
			if (tempVect[0] == -1){//index # 0
				vector<int> childTemp = swapper(tempVect, 0, 1);
				Node childNode = Node(childTemp, temp.getMove()+= "L");
				breadthSearch.push(childNode);
				vector<int> childTemp2 = swapper(tempVect, 0, 3);
				Node childNode2 = Node(childTemp2, temp.getMove()+= "U");
				breadthSearch.push(childNode2);
				breadthSearch.pop();

			} else if (tempVect[1] == -1){//index # 1
				vector<int> childTemp = swapper(tempVect, 1, 0);
				Node childNode = Node(childTemp, temp.getMove()+= "R");
				breadthSearch.push(childNode);
				vector<int> childTemp2 = swapper(tempVect, 1, 2);
				Node childNode2 = Node(childTemp2, temp.getMove()+= "L");
				breadthSearch.push(childNode2);
				vector<int> childTemp3 = swapper(tempVect, 1, 4);
				Node childNode3 = Node(childTemp3, temp.getMove()+= "U");
				breadthSearch.push(childNode3);
				breadthSearch.pop();

			} else if (tempVect[2] == -1){//index # 2
				vector<int> childTemp = swapper(tempVect, 2, 1);
				Node childNode = Node(childTemp, temp.getMove()+= "R");
				breadthSearch.push(childNode);
				vector<int> childTemp2 = swapper(tempVect, 2, 5);
				Node childNode2 = Node(childTemp2, temp.getMove()+= "U");
				breadthSearch.push(childNode2);
				breadthSearch.pop();

			} else if (tempVect[3] == -1){//index # 3
				vector<int> childTemp = swapper(tempVect, 3, 0);
				Node childNode = Node(childTemp, temp.getMove()+= "D");
				breadthSearch.push(childNode);
				vector<int> childTemp2 = swapper(tempVect, 3, 4);
				Node childNode2 = Node(childTemp2, temp.getMove()+= "L");
				breadthSearch.push(childNode2);
				vector<int> childTemp3 = swapper(tempVect, 3, 6);
				Node childNode3 = Node(childTemp3, temp.getMove()+= "U");
				breadthSearch.push(childNode3);
				breadthSearch.pop();

			} else if (tempVect[4] == -1){//index # 4
				vector<int> childTemp = swapper(tempVect, 4, 1);
				Node childNode = Node(childTemp, temp.getMove()+= "D");
				breadthSearch.push(childNode);
				vector<int> childTemp2 = swapper(tempVect, 4, 3);
				Node childNode2 = Node(childTemp2, temp.getMove()+= "R");
				breadthSearch.push(childNode2);
				vector<int> childTemp3 = swapper(tempVect, 4, 5);
				Node childNode3 = Node(childTemp3, temp.getMove()+= "L");
				breadthSearch.push(childNode3);
				vector<int> childTemp4 = swapper(tempVect, 4, 7);
				Node childNode4 = Node(childTemp4, temp.getMove()+= "U");
				breadthSearch.push(childNode4);
				breadthSearch.pop();

			} else if (tempVect[5] == -1){//index # 5
				vector<int> childTemp = swapper(tempVect, 5, 2);
				Node childNode = Node(childTemp, temp.getMove()+= "D");
				breadthSearch.push(childNode);
				vector<int> childTemp2 = swapper(tempVect, 5, 4);
				Node childNode2 = Node(childTemp2, temp.getMove()+= "R");
				breadthSearch.push(childNode2);
				vector<int> childTemp3 = swapper(tempVect, 5, 8);
				Node childNode3 = Node(childTemp3, temp.getMove()+= "U");
				breadthSearch.push(childNode3);
				breadthSearch.pop();

			} else if (tempVect[6] == -1){//index # 6
				vector<int> childTemp = swapper(tempVect, 6, 3);
				Node childNode = Node(childTemp, temp.getMove()+= "D");
				breadthSearch.push(childNode);
				vector<int> childTemp2 = swapper(tempVect, 6, 7);
				Node childNode2 = Node(childTemp2, temp.getMove()+= "L");
				breadthSearch.push(childNode2);
				breadthSearch.pop();
			
			} else if (tempVect[7] == -1){//index # 7
				vector<int> childTemp = swapper(tempVect, 7, 6);
				Node childNode = Node(childTemp, temp.getMove()+= "R");
				breadthSearch.push(childNode);
				vector<int> childTemp2 = swapper(tempVect, 7, 4);
				Node childNode2 = Node(childTemp2, temp.getMove()+= "D");
				breadthSearch.push(childNode2);
				vector<int> childTemp3 = swapper(tempVect, 7, 8);
				Node childNode3 = Node(childTemp3, temp.getMove()+= "L");
				breadthSearch.push(childNode3);
				breadthSearch.pop();

			} else {//index # 8
				vector<int> childTemp = swapper(tempVect, 8, 5);
				Node childNode = Node(childTemp, temp.getMove()+= "D");
				breadthSearch.push(childNode);
				vector<int> childTemp2 = swapper(tempVect, 8, 7);
				Node childNode2 = Node(childTemp2, temp.getMove()+= "R");
				breadthSearch.push(childNode2);
				breadthSearch.pop();
			}
		} else if (tempVect.size() == 16) {
			if (tempVect[0] == -1){//index # 0
				vector<int> childTemp = swapper(tempVect, 0, 1);
				Node childNode = Node(childTemp, temp.getMove()+= "L");
				breadthSearch.push(childNode);
				vector<int> childTemp2 = swapper(tempVect, 0, 4);
				Node childNode2 = Node(childTemp2, temp.getMove()+= "U");
				breadthSearch.push(childNode2);
				breadthSearch.pop();

			} else if (tempVect[1] == -1){//index # 1
				vector<int> childTemp = swapper(tempVect, 1, 0);
				Node childNode = Node(childTemp, temp.getMove()+= "R");
				breadthSearch.push(childNode);
				vector<int> childTemp2 = swapper(tempVect, 1, 2);
				Node childNode2 = Node(childTemp2, temp.getMove()+= "L");
				breadthSearch.push(childNode2);
				vector<int> childTemp3 = swapper(tempVect, 1, 4);
				Node childNode3 = Node(childTemp3, temp.getMove()+= "U");
				breadthSearch.push(childNode3);
				breadthSearch.pop();

			} else if (tempVect[2] == -1){//index # 2
				vector<int> childTemp = swapper(tempVect, 2, 1);
				Node childNode = Node(childTemp, temp.getMove()+= "R");
				breadthSearch.push(childNode);
				vector<int> childTemp2 = swapper(tempVect, 2, 3);
				Node childNode2 = Node(childTemp2, temp.getMove()+= "L");
				breadthSearch.push(childNode2);
				vector<int> childTemp3 = swapper(tempVect, 2, 6);
				Node childNode3 = Node(childTemp3, temp.getMove()+= "U");
				breadthSearch.push(childNode3);
				breadthSearch.pop();

			} else if (tempVect[3] == -1){//index # 3
				vector<int> childTemp = swapper(tempVect, 3, 2);
				Node childNode = Node(childTemp, temp.getMove()+= "R");
				breadthSearch.push(childNode);
				vector<int> childTemp2 = swapper(tempVect, 3, 7);
				Node childNode2 = Node(childTemp2, temp.getMove()+= "U");
				breadthSearch.push(childNode2);
				breadthSearch.pop();

			} else if (tempVect[4] == -1){//index # 4
				vector<int> childTemp = swapper(tempVect, 4, 0);
				Node childNode = Node(childTemp, temp.getMove()+= "D");
				breadthSearch.push(childNode);
				vector<int> childTemp2 = swapper(tempVect, 4, 5);
				Node childNode2 = Node(childTemp2, temp.getMove()+= "L");
				breadthSearch.push(childNode2);
				vector<int> childTemp3 = swapper(tempVect, 4, 8);
				Node childNode3 = Node(childTemp3, temp.getMove()+= "U");
				breadthSearch.push(childNode3);
				breadthSearch.pop();

			} else if (tempVect[5] == -1){//index # 5
				vector<int> childTemp = swapper(tempVect, 5, 1);
				Node childNode = Node(childTemp, temp.getMove()+= "D");
				breadthSearch.push(childNode);
				vector<int> childTemp2 = swapper(tempVect, 5, 4);
				Node childNode2 = Node(childTemp2, temp.getMove()+= "R");
				breadthSearch.push(childNode2);
				vector<int> childTemp3 = swapper(tempVect, 5, 6);
				Node childNode3 = Node(childTemp3, temp.getMove()+= "L");
				breadthSearch.push(childNode3);
				vector<int> childTemp4 = swapper(tempVect, 5, 9);
				Node childNode4 = Node(childTemp4, temp.getMove()+= "U");
				breadthSearch.push(childNode4);
				breadthSearch.pop();

			} else if (tempVect[6] == -1){//index # 6
				vector<int> childTemp = swapper(tempVect, 6, 2);
				Node childNode = Node(childTemp, temp.getMove()+= "D");
				breadthSearch.push(childNode);
				vector<int> childTemp2 = swapper(tempVect, 6, 5);
				Node childNode2 = Node(childTemp2, temp.getMove()+= "R");
				breadthSearch.push(childNode2);
				vector<int> childTemp3 = swapper(tempVect, 6, 7);
				Node childNode3 = Node(childTemp3, temp.getMove()+= "L");
				breadthSearch.push(childNode3);
				vector<int> childTemp4 = swapper(tempVect, 6, 10);
				Node childNode4 = Node(childTemp4, temp.getMove()+= "U");
				breadthSearch.push(childNode4);
				breadthSearch.pop();

			} else if (tempVect[7] == -1){//index # 7
				vector<int> childTemp = swapper(tempVect, 7, 3);
				Node childNode = Node(childTemp, temp.getMove()+= "D");
				breadthSearch.push(childNode);
				vector<int> childTemp2 = swapper(tempVect, 7, 6);
				Node childNode2 = Node(childTemp2, temp.getMove()+= "R");
				breadthSearch.push(childNode2);
				vector<int> childTemp3 = swapper(tempVect, 7, 11);
				Node childNode3 = Node(childTemp3, temp.getMove()+= "U");
				breadthSearch.push(childNode3);
				breadthSearch.pop();

			} else if (tempVect[8] == -1){//index # 8
				vector<int> childTemp = swapper(tempVect, 8, 4);
				Node childNode = Node(childTemp, temp.getMove()+= "D");
				breadthSearch.push(childNode);
				vector<int> childTemp2 = swapper(tempVect, 8, 9);
				Node childNode2 = Node(childTemp2, temp.getMove()+= "L");
				breadthSearch.push(childNode2);
				vector<int> childTemp3 = swapper(tempVect, 8, 12);
				Node childNode3 = Node(childTemp3, temp.getMove()+= "U");
				breadthSearch.push(childNode3);
				breadthSearch.pop();

			} else if (tempVect[9] == -1){//index # 9
				vector<int> childTemp = swapper(tempVect, 9, 5);
				Node childNode = Node(childTemp, temp.getMove()+= "D");
				breadthSearch.push(childNode);
				vector<int> childTemp2 = swapper(tempVect, 9, 8);
				Node childNode2 = Node(childTemp2, temp.getMove()+= "R");
				breadthSearch.push(childNode2);
				vector<int> childTemp3 = swapper(tempVect, 9, 10);
				Node childNode3 = Node(childTemp3, temp.getMove()+= "L");
				breadthSearch.push(childNode3);
				vector<int> childTemp4 = swapper(tempVect, 9, 13);
				Node childNode4 = Node(childTemp4, temp.getMove()+= "U");
				breadthSearch.push(childNode4);
				breadthSearch.pop();

			} else if (tempVect[10] == -1){//index # 10
				vector<int> childTemp = swapper(tempVect, 10, 6);
				Node childNode = Node(childTemp, temp.getMove()+= "D");
				breadthSearch.push(childNode);
				vector<int> childTemp2 = swapper(tempVect, 10, 9);
				Node childNode2 = Node(childTemp2, temp.getMove()+= "R");
				breadthSearch.push(childNode2);
				vector<int> childTemp3 = swapper(tempVect, 10, 11);
				Node childNode3 = Node(childTemp3, temp.getMove()+= "L");
				breadthSearch.push(childNode3);
				vector<int> childTemp4 = swapper(tempVect, 10, 14);
				Node childNode4 = Node(childTemp4, temp.getMove()+= "U");
				breadthSearch.push(childNode4);
				breadthSearch.pop();

			} else if (tempVect[11] == -1){//index # 11
				vector<int> childTemp = swapper(tempVect, 11, 7);
				Node childNode = Node(childTemp, temp.getMove()+= "D");
				breadthSearch.push(childNode);
				vector<int> childTemp2 = swapper(tempVect, 11, 10);
				Node childNode2 = Node(childTemp2, temp.getMove()+= "R");
				breadthSearch.push(childNode2);
				vector<int> childTemp3 = swapper(tempVect, 11, 15);
				Node childNode3 = Node(childTemp3, temp.getMove()+= "U");
				breadthSearch.push(childNode3);
				breadthSearch.pop();

			} else if (tempVect[12] == -1){//index # 12
				vector<int> childTemp = swapper(tempVect, 12, 8);
				Node childNode = Node(childTemp, temp.getMove()+= "D");
				breadthSearch.push(childNode);
				vector<int> childTemp2 = swapper(tempVect, 12, 13);
				Node childNode2 = Node(childTemp2, temp.getMove()+= "R");
				breadthSearch.push(childNode2);
				breadthSearch.pop();

			} else if (tempVect[13] == -1){//index # 13
				vector<int> childTemp = swapper(tempVect, 13, 9);
				Node childNode = Node(childTemp, temp.getMove()+= "D");
				breadthSearch.push(childNode);
				vector<int> childTemp2 = swapper(tempVect, 13, 12);
				Node childNode2 = Node(childTemp2, temp.getMove()+= "R");
				breadthSearch.push(childNode2);
				vector<int> childTemp3 = swapper(tempVect, 13, 14);
				Node childNode3 = Node(childTemp3, temp.getMove()+= "L");
				breadthSearch.push(childNode3);
				breadthSearch.pop();

			} else if (tempVect[14] == -1){//index # 14
				vector<int> childTemp = swapper(tempVect, 14, 10);
				Node childNode = Node(childTemp, temp.getMove()+= "D");
				breadthSearch.push(childNode);
				vector<int> childTemp2 = swapper(tempVect, 14, 13);
				Node childNode2 = Node(childTemp2, temp.getMove()+= "R");
				breadthSearch.push(childNode2);
				vector<int> childTemp3 = swapper(tempVect, 14, 15);
				Node childNode3 = Node(childTemp3, temp.getMove()+= "L");
				breadthSearch.push(childNode3);
				breadthSearch.pop();

			} else if (tempVect[15] == -1){//index # 15
				vector<int> childTemp = swapper(tempVect, 15, 11);
				Node childNode = Node(childTemp, temp.getMove()+= "D");
				breadthSearch.push(childNode);
				vector<int> childTemp2 = swapper(tempVect, 15, 14);
				Node childNode2 = Node(childTemp2, temp.getMove()+= "R");
				breadthSearch.push(childNode2);
				breadthSearch.pop();

			} 
		}
	}
	return true;
}

int main(){
	//the initial boards size for either 3 x 3 or 4 x 4
	int boardSize;
	int temp;//value being used for cin to pass arguments to they then get redistributed to the correct variables.
	bool first = true;//check to grab the first of cin as the size of the board, changes to false after collecting the first argument.
	vector<int> tiles;//all remaining integers after the initial board size get passed to the array.
	while (cin >> temp){
		if (first){
			boardSize = temp;
			first = false;
		} else {
			tiles.push_back(temp);
		}
	}
	cout << "Begin breadth search \nThis make take some time as we have not optimized the code. \nPlease wait patiently :)" << endl;
	cout << "*if you wish to watch the step finding process you can uncomment out line #51*" << endl;
	//breadth search uses too much memory for over 4 x 4 boards so a limit has been applied to prevent using those.
	//using boards of size 2 or smaller is unnecessary, so a limit has been applied to those as well.
	if (boardSize > 4){
		cout << "I'm sorry the max size at this time is a 4x4 board. \nPlease try again." << endl;
		return 0;
	} else if (boardSize < 2) {
		cout << "Boards sized smaller than 2 are either already solved or your size is wrong. \nPlease try again." << endl;
		return 0;
	} else if (boardSize == 2) {
		cout << "Here are all possible solutions for a 2x2 board" << endl;
		cout << "if empty spot is in the top left corner the solution consists of 2 steps R,D or D,R." << endl;
		cout << "if the empty spot is in the bottom left corner the solution consists of one step R." << endl;
		cout << "if the empty spot is in the top right corner then the solution consists of one step D." << endl;
		cout << "if the empty spot is in the bottom right corner than your puzzle is already solved and takes 0 steps." << endl;
		cout << "if your puzzle was not solved by any of the above steps than your puzzle is unsolvable and probably broken." << endl;
		return 0;
	}
	//comparing board size with tiles inputted and exiting if they do not match.
	if ((boardSize * boardSize) != tiles.size()){
		cout << "Incorrect number of tiles inserted for a board that is " << boardSize << "x" << boardSize << " tiles." << endl;
		cout << "Please try again" << endl;
		return 0;
	}
	solver(boardSize, tiles);
	//cout << boardSize << endl;
	
	return 0;
}
