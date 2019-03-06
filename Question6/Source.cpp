#include<iostream>
using namespace std;
//void add(char[9][9],int);
//void remove(char[9][9]);
void display(char[9][9]);
bool rowcolChecker(char[9][9], int, int, int);
bool boxChecker(char[9][9], int, int, int);
//bool checkSolution(char[9][9]);
bool addToSudoku(char[9][9]);
bool findEmptyCell(char[9][9], int&, int&);
int main()
{
	int num = 1;
	char arr[9][9] = { {'5','3','.' , '.','7','.' , '.','.','.'},
					   {'6','.','.' , '1','9','5' , '.','.','.'},
					   {'.','9','8' , '.','.','.' , '.','6','.'},

					   {'8','.','.' , '.','6','.' , '.','.','3'},
					   {'4','.','.' , '8','.','3' , '.','.','1'},
					   {'7','.','.' , '.','2','.' , '.','.','6'},

					   {'.','6','.' , '.','.','.' , '2','8','.'},
					   {'.','.','.' , '4','1','9' , '.','.','5'},
					   {'.','.','.' , '.','8','.' , '.','7','9'} };
	/*for (num; num < 10;num++)
	{
		add(arr, num);
	}*/
	addToSudoku(arr);
	display(arr);
	system("pause");
}

void display(char arr[9][9])
{
	cout << "-------Sudoku Grid-------" << endl;
	for (int row = 0;row < 9;row++)
	{
		for (int col = 0;col < 9;col++)
		{
			if (col == 0)
				cout << "| ";
			cout << arr[row][col] << " ";
			if ((col + 1) % 3 == 0)
				cout << "| ";
		}
		cout << endl;
		if ((row + 1) % 3 == 0)
			cout << "-------------------------" << endl;
	}
}

//void add(char arr[9][9], int num)
//{
//	for(int row=0; row < 9;row++)
//		for (int col = 0;col < 9;col++)
//		{
//			if (arr[row][col] == '.')
//			{
//				arr[row][col] = num + '0';
//				if (rowcolChecker(arr, row, col, num) != true || boxChecker(arr, row, col, num) != true)
//					arr[row][col] = '.';
//			}
//		}
//}


bool addToSudoku(char arr[9][9])
{
	//This most likely will have to be recursive
	//First check if number can be placed using rowcolChecker and boxChecker
	//Will continue until numbers 1-9 cannot enter an empty cell. 
	//We then go back and start again but increment start by 1
	// -How do we go about going back?
	//  -How do we make sure we get back to the start? Perhaps we can make a starting point variable for row and col called: 
	//                                                 int Row, Col that changes based on what position you 
	//                                                 are making the change to.
	int row, col;
 
	if (findEmptyCell(arr, row, col) != true)
		return true; 
	for (int num = 1; num <= 9; num++)
	{ 
		if (rowcolChecker(arr,row,col,num) == true && boxChecker(arr,row,col,num)==true)
		{ 
			arr[row][col] = num + '0';
			if (addToSudoku(arr)==true)
				return true;
			arr[row][col] = '.';
		}
	}
	return false; 
}


bool findEmptyCell(char arr[9][9], int & row, int & col)
{
	{
		for (row = 0; row < 9; row++)
			for (col = 0; col < 9; col++)
				if (arr[row][col] == '.')
					return true;
		return false;
	}
}

bool rowcolChecker(char arr[9][9], int row, int col, int num)
{
	//row check (horizontal check)
	if ((row + 1) < 9)
	{
		for (int i = row + 1;i < 9;i++)
		{
			if (arr[i][col] == num + '0')
				return false;
		}
	}
	if ((row - 1) > 0)
	{
		for (int i = row - 1;i >= 0;i--)
		{
			if (arr[i][col] == num + '0')
				return false;
		}
	}
	//col check (vertical check)
	if ((col + 1) < 9)
	{
		for (int i = col + 1;i < 9;i++)
		{
			if (arr[row][i] == num + '0')
				return false;
		}
	}
	if ((col - 1) > 0)
	{
		for (int i = col - 1;i >= 0;i--)
		{
			if (arr[row][i] == num + '0')
				return false;
		}
	}
	return true;
}

bool boxChecker(char arr[9][9], int row, int col, int num)
{
	//box check (3 x 3 grid)
	if (row < 3 && col < 3) //0-2 x 0-2
	{
		for(int i=0;i<3;i++)
			for (int j = 0;j < 3;j++)
			{
				if (i == row && j == col)
				{

				}
				else
				{
					if (arr[i][j] == num + '0')
						return false;
				}
			}
	}
	else if ((row >= 3 && row < 6) && col < 3) //3-5 x 0-2
	{
		for (int i = 3;i < 6;i++)
			for (int j = 0;j < 3;j++)
			{
				if (i == row && j == col)
				{

				}
				else
				{
					if (arr[i][j] == num + '0')
						return false;
				}
			}
	}
	else if ((row >= 6 && row < 9) && col < 3) //6-8 x 0-2
	{
		for (int i = 6;i < 9;i++)
			for (int j = 0;j < 3;j++)
			{
				if (i == row && j == col)
				{

				}
				else
				{
					if (arr[i][j] == num + '0')
						return false;
				}
			}
	}
	else if (row < 3 && (col >= 3 && col < 6)) //0-2 x 3-5
	{
		for (int i = 0;i < 3;i++)
			for (int j = 3;j < 6;j++)
			{
				if (i == row && j == col)
				{

				}
				else
				{
					if (arr[i][j] == num + '0')
						return false;
				}
			}
	}
	else if ((row >= 3 && row < 6) && (col >= 3 && col < 6)) //3-5 x 3-5
	{
		for (int i = 3;i < 6;i++)
			for (int j = 3;j < 6;j++)
			{
				if (i == row && j == col)
				{

				}
				else
				{
					if (arr[i][j] == num + '0')
						return false;
				}
			}
	}
	else if ((row >= 6 && row < 9) && (col >= 3 && col < 6)) //6-8 x 3-5
	{
		for (int i = 6;i < 9;i++)
			for (int j = 3;j < 6;j++)
			{
				if (i == row && j == col)
				{

				}
				else
				{
					if (arr[i][j] == num + '0')
						return false;
				}
			}
	}
	else if (row < 3 && (col >= 6 && col < 9)) //0-2 x 6-8
	{
		for (int i = 0;i < 3;i++)
			for (int j = 6;j < 9;j++)
			{
				if (i == row && j == col)
				{

				}
				else
				{
					if (arr[i][j] == num + '0')
						return false;
				}
			}
	}
	else if ((row >= 3 && row < 6) && (col >= 6 && col < 9)) //3-5 x 6-8
	{
		for (int i = 3;i < 6;i++)
			for (int j = 6;j < 9;j++)
			{
				if (i == row && j == col)
				{

				}
				else
				{
					if (arr[i][j] == num + '0')
						return false;
				}
			}
	}
	else if ((row >= 6 && row < 9) && (col >= 6 && col < 9)) //6-8 x 6-8
	{
		for (int i = 6;i < 9;i++)
			for (int j = 6;j < 9;j++)
			{
				if (i == row && j == col)
				{

				}
				else
				{
					if (arr[i][j] == num + '0')
						return false;
				}
			}
	}
	return true;
}

//bool checkSolution(char arr[9][9])
//{
//	cout << "Checking sudoku to make sure it has a complete solution..." << endl;
//	for(int row=0;row<9;row++)
//		for (int col = 0;col < 9;col++)
//		{
//			if (arr[row][col] == '.')
//			{
//				cout << "This sudoku does not have a complete solution..." << endl;
//				return false;
//			}
//		}
//	cout << "This sudoku does have a complete solution!" << endl;
//	return true;
//}

