/*
* File:   main.cpp
* Author: PARTH BHOIWALA
*
* Created on April 2, 2015, 7:27 PM
*/

#include <cstdlib>
#include <iostream>
#include <conio.h>
#include <iomanip>
#include <string>
using namespace std;

void displayBoard(char Numbers[], string player1, string player2, char choice1, char choice2);
bool CheckForWinnerO(char Numbers[]);
bool CheckForWinnerX(char Numbers[]);
bool checkIfGameOver(char Numbers[]);

int main(int argc, char** argv) {

	string player1, player2;
	char choice1, choice2;
	bool invalidEntry = true;
	cout << " WELCOME TO TIC-TAC-TOE " << endl;
	cout << " Enter Player 1's Name:  ";
	cin >> player1;
	cout << endl;
	cout << " Enter Player 2's Name:  ";
	cin >> player2;
	while (invalidEntry)
	{
		cout << " " << player1 << ", which one do you want to pick 'X' or 'O' ?  ";
		cin >> choice1;
		if (choice1 != 'O' && choice1 != 'o' && choice1 != 'X' && choice1 != 'x')
		{
			cout << " Invalid Entry! Try Again!" << endl;
			invalidEntry = true;
		}
		else { invalidEntry = false; }

	}
	if (choice1 == 'O' || choice1 == 'o')
	{
		choice2 = 'X';
		cout << " Okay! So " << player2 << " is " << choice2 << endl;
	}
	else
	{
		choice2 = 'O';
		cout << " Okay! So " << player2 << " is " << choice2 << endl;
	}

	char goFirst;
	invalidEntry = true;
	while (invalidEntry)
	{
		cout << " Who wants to go first? Player 'X' or 'O'?  ";
		cin >> goFirst;
		if (goFirst != 'O' && goFirst != 'o' && goFirst != 'X' && goFirst != 'x')
		{
			cout << " Invalid Entry! Try Again!" << endl;
			invalidEntry = true;
		}
		else { invalidEntry = false; }
	}

	
	char Layout[9] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };

	displayBoard(Layout, player1, player2, choice1, choice2);

	char Numbers[9] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
	

	
	int i;
	if (goFirst == 'O' || goFirst == 'o')
	{
		i = 0;
	}
	else { i = 1; }
	
	int choice;
	while (true)
	{
		//8-9-10-11-12
		if (i % 2 == 0)  // if 'i' is even - PLAYER 1
		{
			cout << endl << endl;
			cout << " " << player1 << "  :  ";
			cin >> choice;
			// make sure user enters only 1-9
			if (choice > 9 || Numbers[choice - 1] == 'X' || Numbers[choice - 1] == 'O') { cout << " Invalid Entry! Try Again " << endl; }
			else{
				Numbers[choice - 1] = 'O';
				displayBoard(Numbers, player1, player2, choice1, choice2);
				i++;
			}
			bool checkWin = CheckForWinnerO(Numbers);
			if (checkWin == true)
			{
				cout << " YAY! " << player1 << " WINS " << endl;
				break;
			}
			



		}
		else /*if (i % 2 != 0)*/ // if 'i' is odd - PLAYER 2
		{
			cout << endl << endl;
			cout << " " << player2 << "  :  ";
			cin >> choice;
			// make sure user enters only 1-9
			if (choice > 9 || Numbers[choice - 1] == 'X' || Numbers[choice - 1] == 'O') { cout << " Invalid Entry! Try Again " << endl; }
			else {
				Numbers[choice - 1] = 'X';
				displayBoard(Numbers, player1, player2, choice1, choice2);
				i++;
			}
			bool checkWin = CheckForWinnerX(Numbers);
			if (checkWin == true)
			{
				cout << " YAY! " << player2 << " WINS " << endl;
				break;
			}


		}

		bool checkGameOver = checkIfGameOver(Numbers);
		if (checkGameOver == true)
		{
			cout << " GAME OVER! NOBODY WON " << endl;
			break;
		}



	}








	system("pause");

	return 0;
}

void displayBoard(char Numbers[], string player1, string player2, char choice1, char choice2)
{
	system("cls");
	
	cout << endl;
	cout << " ===================================" << endl;
	cout << "         TIC - TAC - TOE " << endl;
	cout << "        " << player1 << " vs " << player2 << endl;
	cout << " ===================================" << endl;
	cout << " " << player1 << " is '" << choice1 << "' and " << player2 << " is '" << choice2 << "' " << endl;
	//cout << "  PLAYER 1 IS 'O' & PLAYER 2 IS 'X' " << endl;
	//clrscr();

	// level 1
	cout << setw(5) << endl << endl << endl;
	 cout << setw(8)  << "   |" << "    |" << "    " << endl;
	cout << setw(5) << " " << Numbers[0] << " |" << "  " << Numbers[1] << " |" << "  " << Numbers[2] << " " << endl;
	cout << setw(8) << "   ____|____|____" << endl;
	// level 2
	cout << setw(8) << "   |" << "    |" << "    " << endl;
	cout << setw(5) << " " << Numbers[3] << " |" << "  " << Numbers[4] << " |" << "  " << Numbers[5] << " " << endl;
	// cout << setw(8)  << "   |" << "    |" << "    " << endl;
	cout << setw(5) << "   ____|____|____" << endl;
	// level 3
	cout << setw(8) << "   |" << "    |" << "    " << endl;
	cout << setw(5) << " " << Numbers[6] << " |" << "  " << Numbers[7] << " |" << "  " << Numbers[8] << " " << endl;
	cout << setw(8) << "   |" << "    |" << "    " << endl;
	//  cout << setw(5)  << "   ____|____|____" << endl;
	// level 4
	

}




bool CheckForWinnerO(char Numbers[])
{
	if ((Numbers[0] == 'O' && Numbers[1] == 'O' && Numbers[2] == 'O') ||
		(Numbers[3] == 'O' && Numbers[4] == 'O' && Numbers[5] == 'O') ||
		(Numbers[6] == 'O' && Numbers[7] == 'O' && Numbers[8] == 'O') ||
		(Numbers[0] == 'O' && Numbers[3] == 'O' && Numbers[6] == 'O') ||
		(Numbers[1] == 'O' && Numbers[4] == 'O' && Numbers[7] == 'O') ||
		(Numbers[2] == 'O' && Numbers[5] == 'O' && Numbers[8] == 'O') ||
		(Numbers[0] == 'O' && Numbers[4] == 'O' && Numbers[8] == 'O') ||
		(Numbers[2] == 'O' && Numbers[4] == 'O' && Numbers[6] == 'O'))
	{ // being long if

		return true;
	} // exit long if

	else
		return false;

}



bool CheckForWinnerX(char Numbers[])
{
	if ((Numbers[0] == 'X' && Numbers[1] == 'X' && Numbers[2] == 'X') ||
		(Numbers[3] == 'X' && Numbers[4] == 'X' && Numbers[5] == 'X') ||
		(Numbers[6] == 'X' && Numbers[7] == 'X' && Numbers[8] == 'X') ||
		(Numbers[0] == 'X' && Numbers[3] == 'X' && Numbers[6] == 'X') ||
		(Numbers[1] == 'X' && Numbers[4] == 'X' && Numbers[7] == 'X') ||
		(Numbers[2] == 'X' && Numbers[5] == 'X' && Numbers[8] == 'X') ||
		(Numbers[0] == 'X' && Numbers[4] == 'X' && Numbers[8] == 'X') ||
		(Numbers[2] == 'X' && Numbers[4] == 'X' && Numbers[6] == 'X'))
	{ // being long if

		return true;
	} // exit long if

	else
		return false;

}


bool checkIfGameOver(char Numbers[])
{
	if ((Numbers[0] != ' ') &&
		(Numbers[1] != ' ') &&
		(Numbers[2] != ' ') &&
		(Numbers[3] != ' ') &&
		(Numbers[4] != ' ') &&
		(Numbers[5] != ' ') &&
		(Numbers[6] != ' ') &&
		(Numbers[7] != ' ') &&
		(Numbers[8] != ' '))
	{
		return true;
	}
	else
	{
		return false;
	}
		


}