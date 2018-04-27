/*
****************************************************************************
*                        FCI – Programming 1 – 2017                        *
** Project Name: Connect four game                                         *
** Last Modification Date: 04/12/2017                                      *
** Author: Mahmoud Ahmed Tawfik                                            *
****************************************************************************
*/

#include <iostream>
#include <cstdlib>
#include <stdlib.h>

using namespace std;

char board[6][7]; // each cell is either 'X', 'O', or ' '
char IsWinning(char board[6][7]);
bool Insert(char board[6][7], char player, int column);
void Print(char board[6][7]);
//other global variables
void InitBoard(char board[6][7]);
int LastRowIndex; int LastColumnIndex;


int main()
{
  char player; int column; bool isPlayerWin; bool isContainEmptyCell;
  int countPlayTime; 
  //init variables
  isPlayerWin = false;
  countPlayTime = 0;
  player = ' ';
  InitBoard(board);
  
  while(true) {
    //change player
    player = player == 'X' ? 'O' : 'X';
    //Check if there is an empty cell in the board
    while(true){
        //Check the entered value by the user if it's valid
        while(true) { 
          
          
          cout << "Player " << player << ", Enter a column between 1 and 7: " << endl;
          cin >> column;
          if(!cin.fail() && (column >= 1 && column <= 7)) {
            countPlayTime ++;
            column --; // to make first column begin from one not zero
            break;
          }
          else {
            cin.clear();
            cin.ignore(256,'\n');
            cout << "Column invalid .." << endl;
          }
        }
        
      //if the board full stop input and show msg that no one win
      if(countPlayTime == 42)
        break;
        
      isContainEmptyCell = Insert(board, player, column);
      
      if(!isContainEmptyCell)
        cout << "There is no empty cell in this column: " << column << endl;
      else
        break;
    }
    
    //if the board full stop input and show msg that no one win
    if(countPlayTime == 42)
      break;
    
    //system("cls");//this clears the screen
    //clrscr();
    
    system("cls");
    
    Print(board);
    
    isPlayerWin = IsWinning(board);
    
    if(isPlayerWin) {
      cout << "Player " << board[LastRowIndex][LastColumnIndex] << " is the winner." << endl;
      char playAgain;
      cout << "Do you want to play again? enter 'a' to play again or any other key to exit " << endl;
      
      cin >> playAgain;
      if(playAgain == 'a') {
          //init variables for new game
          isPlayerWin = false;
          countPlayTime = 0;
          player = ' ';
          InitBoard(board);
      }
      else
       break;
    }
  }
  
  if(!isPlayerWin && countPlayTime == 42)
    cout << "The board is full and no one win.";
  
  return 0;
}

char IsWinning(char board[6][7]) {
  int vertical = 1;
	int horizontal = 1;
	int diagonal1 = 1;
	int diagonal2 = 1; 
	int indexVer; 
	int indexHor;	
	int r = LastRowIndex; 
	int c = LastColumnIndex;
	//get last player entered to check with it
	char player = board[r][c];
	
    //check for diagonal 1
    //up and left
	for(indexVer = r-1, indexHor= c-1;indexVer>=0 && indexHor >=0; indexVer--, indexHor --) {
        if(board[indexVer][indexHor] == player)
            diagonal1 ++;
        else
            break; //diagonal1 = diagonal1 == 0 ? 0 : diagonal1--;
    }
    //down and right
	for(indexVer = r+1, indexHor= c+1;indexVer<=5 && indexHor <=6;  indexVer ++, indexHor ++){
	   if(board[indexVer][indexHor] == player)
            diagonal1 ++;	
        else
            break; //diagonal1 = diagonal1 == 0 ? 0 : diagonal1--;
	}
    
	if(diagonal1 >= 4) 
	  return true;
	  
	//check for vertical
    //Check down
	for(indexVer = r +1;indexVer <= 5;indexVer++) {
        if(board[indexVer][c] == player)
            vertical++;
        else
            break; //vertical = vertical == 0 ? 0 : vertical--;
    }
    //Check up
	for(indexVer = r -1;indexVer >= 0;indexVer--) {
        if(board[indexVer][c] == player)
            vertical++;
        else
            break; //vertical = vertical == 0 ? 0 : vertical--;
    }
    
	if(vertical >= 4)
	  return true;
	
	//check for horizontal
    //Check left
	for(indexHor = c-1;indexHor >= 0;indexHor--) {
        if(board[r][indexHor] == player)
            horizontal++;
        else
            break; //horizontal = horizontal == 0 ? 0 : horizontal--;
    }
    //Check right
	for(indexHor = c+1;indexHor <= 6;indexHor++) {
        if(board[r][indexHor] == player)
            horizontal++;
        else
            break; //horizontal = horizontal == 0 ? 0 : horizontal--;
    }
	if(horizontal >= 4) 
	  return true;
	
	
	//check for diagonal 2
    //up and right
	for(indexVer = r-1, indexHor= c+1;indexVer>=0 && indexHor <= 6; indexVer --, indexHor ++) {
        if(board[indexVer][indexHor] == player)
            diagonal2 ++;
        else
            break; //diagonal2 = diagonal2 == 0 ? 0 : diagonal2--;
    }
    //up and left
	for(indexVer = r+1, indexHor= c-1;indexVer<=5 && indexHor >=0; indexVer ++, indexHor --) {
        if(board[indexVer][indexHor] == player)
            diagonal2 ++;
        else
            break; //diagonal2 = diagonal2 == 0 ? 0 : diagonal2--;
    }
    
	if(diagonal2 >= 4) 
	  return true;
	
	return false;
}

bool Insert(char board[6][7], char player, int column) {
  int EmptyCellIndex;
  EmptyCellIndex = -1;
  for(int i = 0; i <= 5; i++)
    if(board[i][column] == ' ') {
      EmptyCellIndex = i;
      break;
    }
  
  if(EmptyCellIndex == -1)
    return false;
  
  board[EmptyCellIndex][column] = player;
  LastRowIndex = EmptyCellIndex;
  LastColumnIndex = column;
  
  return true;
}

void Print(char board[6][7]) {
	cout<<"1 2 3 4 5 6 7\n";
	for(int i = 5; i >= 0; i--)
	{		
		for(int j = 0; j <= 6; j++) 
		  cout<< board[i][j] << " ";
		
		cout<<'\n';
	}
}

void InitBoard(char board[6][7]) {
  for(int i = 0; i < 6; i++)
  {
    for(int j = 0; j < 7; j++)
    {
        board[i][j] = ' ';
    }
  }
}

