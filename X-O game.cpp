/*
****************************************************************************
*                        FCI – Programming 1 – 2017                        *
** Project Name: X-O game                                                  *
** Last Modification Date: 01/12/2017                                      *
** Author: Mahmoud Ahmed Tawfik                                            *
****************************************************************************
*/
#include <iostream>
#include <iomanip>

using namespace std;

char matrix[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char player ='X';
int counter = 0;

void printHello()
{
	cout<<"Hello."<<endl;
}
void draw()
{
	cout<<"   -----------"<<endl;
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
			cout<<setw(4)<<matrix[i][j]<<" ";
		cout<<endl; 
	}  
	cout<<"   -----------"<<endl;
}
void input()
{
	int a;
	cout<<"(PLAYER "<<player<<":"<<counter<<") ... Enter the number you select : ";
	cin>>a;
	a--;
	system("CLS");
	if(matrix[a/3][a%3] != 'X' && matrix[a/3][a%3] != 'O' && a <= 8 && a >= 0)
	{
		counter++;
		matrix[a/3][a%3] = player;
		if(player == 'X')
			player = 'O';
		else
			player = 'X';
	}
	else
	{
		cout<<"ERORR."<<endl;
	}
}
	

char check()
{
	//for rows and columuns
	for(int i = 0;i < 3;i++)
	{
		if((matrix[i][0] == 'O' && matrix[i][1] == 'O' && matrix[i][2] == 'O') || (matrix[i][0] == 'X' && matrix[i][1] == 'X' && matrix[i][2] == 'X'))
			return matrix[i][0];

		if((matrix[0][i] == 'O' && matrix[1][i] == 'O' && matrix[2][i] == 'O') || (matrix[0][i] == 'X' && matrix[1][i] == 'X' && matrix[2][i] == 'X'))
			return matrix[0][i];
	}

	//for diameters 1
	if((matrix[0][0] == 'O' && matrix[1][1] == 'O' && matrix[2][2] == 'O') || (matrix[0][0] == 'X' && matrix[1][1] == 'X' && matrix[2][2] == 'X'))
	{
		return matrix[0][0];
	}

	//for diameters 2
	if((matrix[2][0] == 'O' && matrix[1][1] == 'O' && matrix[0][2] == 'O') || (matrix[0][2] == 'X' && matrix[1][1] == 'X' && matrix[2][0] == 'X'))
		return matrix[2][0];

	return 0; 
}
int main()
{
	printHello();
	while(true)
    {
		draw();
		input();
		if((check() == 'X') || (check() == 'O'))
		{
			cout<<check()<<" is win."<<endl;
			break;
		}
		if(counter == 9)
		{
			cout<<"End."<<endl;
			break;
		}
    }
}