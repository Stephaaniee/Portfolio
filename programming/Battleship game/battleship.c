#include <stdio.h>
#include <stdlib.h>
#include<time.h>


char getLetter(int num) //fuction to get corresponding letter from a given index
{
	if (num == 0)
	{
		return 'A';
	}
	else if (num == 1)
	{
		return 'B';
	}
	else if (num == 2)
	{
		return 'C';
	}
	else if (num == 3)
	{
		return 'D';
	}
	else if (num == 4)
	{
		return 'E';
	}
	else if (num == 5)
	{
		return 'F';
	}
	else if (num == 6)
	{
		return 'G';
	}
	else if (num == 7)
	{
		return 'H';
	}
	else if (num == 8)
	{
		return 'I';
	}
	else if (num == 9)
	{
		return 'J';
	}

}
int getNumber(char letter) //function to get corresponding index from the letter
{
	if (letter == 'A')
	{
		return 0;
	}
	else if (letter == 'B')
	{
		return 1;
	}
	else if (letter == 'C')
	{
		return 2;
	}
	else if (letter == 'D')
	{
		return 3;
	}
	else if (letter == 'E')
	{
		return 4;
	}
	else if (letter == 'F')
	{
		return 5;
	}
	else if (letter == 'G')
	{
		return 6;
	}
	else if (letter == 'H')
	{
		return 7;
	}
	else if (letter == 'I')
	{
		return 8;
	}
	else if (letter == 'J')
	{
		return 9;
	}
	else
		return 0;
}

int checkForSunk(int grid[10][10], int x, int y, int opponentID) //check whether opponent ship has sunk or not
{
	int resume = 1;

	if (x > 0)//check if left exists
		{
			if (grid[y][x - 1] == opponentID) //check left for unsunk part
			{
				return 0;
			}
			else if (grid[y][x - 1] == -1) //if some part already sunk  
			{
				int i = 2;
				while (x-i >= 0)
				{
					if (grid[y][x - i] == opponentID)   //keep going in that directionand keep checking if there is any unsunk part available or not
					{
						return 0;
					}
					if (grid[y][x - i] == 0) //end of ship found since each ship is sepearted by atleast one space which is represented by 0
					{
						break;
					}
					i++;
				}
			}
		}

		if (x < 9) //check if right exists
		{
			if (grid[y][x+1] == opponentID) //check right for unsunk part
			{
				return 0;
			}
			else if (grid[y][x + 1] == -1)
			{
				int i = 2;
				while (x + i <= 9)
				{
					if (grid[y][x + i] == opponentID)
					{
						return 0;
					}
					if (grid[y][x + i] == 0)
					{
						break;
					}
					i++;
				}
			}
		}

		if (y > 0) //check if below exists
		{
			if (grid[y-1][x] == opponentID) //check below for unsunk part
			{
				return 0;
			}
			else if (grid[y-1][x] == -1)
			{
				int i = 2;
				while (y - i >= 0)
				{
					if (grid[y-i][x] == opponentID)
					{
						return 0;
					}
					if (grid[y-i][x] == 0)
					{
						break;
					}
					i++;
				}
			}
		}
		if (y < 9)//check if above exists
		{
			if (grid[y+1][x] == opponentID)// check above for unsunk part
			{
				return 0;
			}
			else if (grid[y+1][x] == -1)
			{
				int i = 2;
				while (y + i <= 9)
				{
					if (grid[y+i][x] == opponentID)
					{
						return 0;
					}
					if (grid[y+i][x] == 0)
					{
						break;
					}
					i++;
				}
			}
		}

		return 1;
	
}
int checkForWinner(int grid[10][10]) //checking if any player has won the game
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (grid[i][j] != 0 && grid[i][j]!= -1 && grid[i][j] != -2) //if 1 or 2 isn't present in the entire grid that means one of the player has won
			{
				return 0;
			}
		}
	}
	return 1;
}

void takeTurn(int opponentGrid[10][10], int opponentID, int randomFlag) 
{
	int found = 1;

	while (found == 1) //continue till the user keeps guessing correctly
	{
		char letter;
		int x, y;
		if (randomFlag == 0) //user will play
		{
			printf("Enter location for guess:");

			scanf("%c", &letter); //random '\n' skipped
			scanf("%c", &letter); //get letter
			y = getNumber(letter); //convert letter into index
			int num;
			scanf("%d", &num); //get x location
			x = num - 1; //subtract by one to convert to corresponding index in the grid
			printf("\n\n");
		}
		else //computer will play
		{
			x = rand() % 10;
			y = rand() % 10;
			printf("The Computer's guess was:%c%d\n\n",getLetter(y),x+1);
		}

		if (opponentGrid[y][x] == opponentID)// ship/part of ship found
		{
			opponentGrid[y][x] = -1; //ship found
			printf("Ship found in this location! There will be another turn\n\n"); 
			found = 1;

			if (checkForSunk(opponentGrid, x, y, opponentID) == 1) //checking if the entire ship has sunk or not
			{
				printf("Opponent ship sunk!\n\n");
			}
		}
		else if (opponentGrid[y][x] == -2 || opponentGrid[y][x] == -1) //already explored area
		{
			printf("Area already explored! Guess another location.\n\n");
			found = 1;
		}
		else
		{
			opponentGrid[y][x] = -2; //explored area but ship not found
			printf("No ship found in this location!\n\n");
			found = 0;
		}
		
	}

	
	
}

void printShipPlacements(int grid[10][10]) //print ships placed on the board
{
	printf("\t   1  2  3  4  5  6  7  8  9  10\n");
	printf("\t +---------------------------------+\n");
	
	for (int i = 0; i < 10; i++)
	{
		printf("%c\t|  ", getLetter(i));
		for (int j = 0; j < 10; j++)
		{
			if (grid[i][j] == 1 || grid[i][j] == 2)
			{
				printf("X  ");
			}
			else
			{
				printf("   ");
			}
		}
		printf("  |\n");
	}
	printf("\t +---------------------------------+\n");

}
void printGrid(int grid[10][10], int player) //print guesses of the players
{
	printf("\t   1  2  3  4  5  6  7  8  9  10\n");
	printf("\t +---------------------------------+\n");

	for (int i = 0; i < 10; i++)
	{
		printf("%c\t|  ", getLetter(i));
		for (int j = 0; j < 10; j++)
		{
			if (grid[i][j] == -1 || grid[i][j] == -2)
			{
				if (player == 1)
				{
					printf("A  ");
				}
				else
				{
					printf("B  ");
				}
			}
			else
			{
				printf("   ");
			}
		}
		printf("  |\n");
	}
	printf("\t +---------------------------------+\n");
}
int checkForFreeSpaceHorizontally(int grid[10][10], int x, int y, int size) //check for horizontal space
{
	if (x + size -1 <= 9)
	{
		int endingIndex = size;
		int startingIndex = 0;
		if (x + size <= 9)
		{
			endingIndex = size + 1;
		}
		if (x > 0)
		{
			startingIndex = -1;
		}

		for (int i = startingIndex; i < endingIndex; i++)
		{
			if (grid[y][x + i] != 0)
			{
				return 0;
			}
			if (y > 0)
			{
				if (grid[y - 1][x + i] != 0)
				{
					return 0;
				}
			}
			if (y < 9)
			{
				if (grid[y + 1][x + i] != 0)
				{
					return 0;
				}
			}
		}

		return 1;
	}
	else
	return 0;
}

int checkForFreeSpaceVertically(int grid[10][10], int x, int y, int size) //check for vertical space
{
	if (y + size - 1 <= 9)
	{
		int endingIndex = size;
		int startingIndex = 0;
		if (y + size <= 9)
		{
			endingIndex = size + 1;
		}
		if(y>0)
		{ 
			startingIndex = - 1;
		}
		for (int i = startingIndex; i < endingIndex; i++)
		{
			if (grid[y+i][x] != 0)
			{
				return 0;
			}
			if (x > 0)
			{
				if (grid[y+i][x - 1] != 0)
				{
					return 0;
				}
			}
			if (x < 9)
			{
				if (grid[y + i][x + 1] != 0)
				{
					return 0;
				}
			}
		}
		return 1;
	}
	else
		return 0;
}

void placeShips(int grid[10][10],int player,int randomFlag)
{
	
	int randomX = 0;
	int randomY = 0;
	int horizontal = 0;

	int size2 = 0;
	int size3 = 0;
	int size4 = 0;
	int size5 = 0;
	
	if (randomFlag == 0)
	{
		printf("In order to place the ships manually use a combination of a letter for rows and a number for the columns.\nFor example, G5\n");
		printf("Press 0 for Vertical and press 1 for Horizontal placement\n\n\n");
	}
	while (size2 != 4  || size3 != 3 || size4 != 2 || size5 != 1) //continue until all ships are placed on the board
	{
		
		if (randomFlag == 1) //random placement
		{
			randomX = rand() % 10; //generate random x value
			randomY = rand() % 10; //generate random y value
			horizontal = rand() % 2; // generate random horizontal value
		}
		else //manual placement
		{
			printShipPlacements(grid); //show current placement
			char letter;
			if (size5 != 1)
			{
				printf("Enter location for ship with size 5:");
			}
			else if (size4 != 2)
			{
				printf("Enter location for ship with size 4:");
			}
			else if (size3 != 3)
			{
				printf("Enter location for ship with size 3:");
			}
			else if (size2 != 4)
			{
				printf("Enter location for ship with size 2:");
			}
			scanf("%c", &letter);
			scanf("%c", &letter);
			randomY = getNumber(letter);
			int num;
			scanf("%d", &num);
			randomX = num - 1;
			printf("Enter orientation:");
			scanf("%d", &horizontal);
			printf("\n");
		}

		int free = 1;
		if (horizontal == 1) //placing horizontal 
		{
		 if (size5 != 1)
		{
			free = checkForFreeSpaceHorizontally(grid, randomX, randomY, 5); //checking if space available or not
			if (free == 1)
			{
				for (int i = 0; i < 5; i++) 
				{
					grid[randomY][randomX + i] = player; //placing the ship on the board
				}
				size5++;
				
			}
			else
			{
				if (randomFlag == 0)
				{
					printf("Insufficent space to place the required ship. Kindly, choose another location or try a different orientation!\n\n");
				}
			}

		}
		 else if (size4 != 2)
		 {
			 free = checkForFreeSpaceHorizontally(grid, randomX, randomY, 4);
			 if (free == 1)
			 {
				 for (int i = 0; i < 4; i++)
				 {
					 grid[randomY][randomX + i] = player;
				 }
				 size4++;
				
			 }
			 else
			 {
				 if (randomFlag == 0)
				 {
					 printf("Insufficent space to place the required ship. Kindly, choose another location or try a different orientation!\n\n");
				 }
			 }

		 }

		 else if (size3 != 3)
		 {
			 free = checkForFreeSpaceHorizontally(grid, randomX, randomY, 3);
			 if (free == 1)
			 {
				 for (int i = 0; i < 3; i++)
				 {
					 grid[randomY][randomX + i] = player;
				 }
				 size3++;
				 
			 }
			 else
			 {
				 if (randomFlag == 0)
				 {
					 printf("Insufficent space to place the required ship. Kindly, choose another location or try a different orientation!\n\n");
				 }
			 }

		 }
		else if (size2 != 4)
			{
				free = checkForFreeSpaceHorizontally(grid, randomX, randomY, 2);
				if (free == 1)
				{
					for (int i = 0; i < 2; i++)
					{
						grid[randomY][randomX + i] = player;
					}
					size2++;
					
				}
			}
		else
		 {
			 if (randomFlag == 0)
			 {
				 printf("Insufficent space to place the required ship. Kindly, choose another location or try a different orientation!\n\n");
			 }
		 }

		}
		else
		{
			 if (size5 != 1)
			 {
				free = checkForFreeSpaceVertically(grid, randomX, randomY, 5);
				if (free == 1)
				{
					for (int i = 0; i < 5; i++)
					{
						grid[randomY + i][randomX] = player;
					}
					size5++;
					
				}
				else
				{
					if (randomFlag == 0)
					{
						printf("Insufficent space to place the required ship. Kindly, choose another location or try a different orientation!\n\n");
					}
				}
			 }
			 else if (size4 != 2)
			 {
				 free = checkForFreeSpaceVertically(grid, randomX, randomY, 4);
				 if (free == 1)
				 {
					 for (int i = 0; i < 4; i++)
					 {
						 grid[randomY + i][randomX] = player;
					 }
					 size4++;
				 }
				 else
				 {
					 if (randomFlag == 0)
					 {
						 printf("Insufficent space to place the required ship. Kindly, choose another location or try a different orientation!\n\n");
					 }
				 }

			 }

			 else if (size3 != 3)
			 {
				 free = checkForFreeSpaceVertically(grid, randomX, randomY, 3);
				 if (free == 1)
				 {
					 for (int i = 0; i < 3; i++)
					 {
						 grid[randomY + i][randomX] = player;
					 }
					 size3++;
					
				 }
				 else
				 {
					 if (randomFlag == 0)
					 {
						 printf("Insufficent space to place the required ship. Kindly, choose another location or try a different orientation!\n\n");
					 }
				 }

			 }
			else if (size2 != 4)
			{
				free = checkForFreeSpaceVertically(grid, randomX, randomY, 2);
				if (free == 1)
				{
					for (int i = 0; i < 2; i++)
					{
						grid[randomY+i][randomX] = player;
					}
					size2++;
				}
				else
				{
					if (randomFlag == 0)
					{
						printf("Insufficent space to place the required ship. Kindly, choose another location or try a different orientation!\n\n");
					}
				}
				
			}
		}
	}
}
int main()
{
	int grid1[10][10] = { 0 };
	int grid2[10][10] = { 0 };
	int input = 0;
	int player1Score = 100;
	int player2Score = 100;
	

	printf("Welcome to the Battleship Game!\n\n\n\n");
	printf("Play against:\n1-Computer\n2-Human\n\n");
	
	while (input != 1 && input != 2)
	{
		scanf("%d", &input);
		if (input != 1 && input != 2)
		{
			printf("Incorrect input. Try again!\n\n");
		}
	}

	if (input == 1)
	{
		printf("Would you like to place your ships:\n1-Manually\n2-Randomly\n\n");
		
		scanf("%d", &input);
		while (input != 1 && input != 2)
		{
			if (input != 1 && input != 2)
			{
				printf("Incorrect input. Try again!\n\n");
			}
		}

		if (input == 1)
		{
			placeShips(grid1, 1, 0);
		}
		else if (input == 2)
		{

			placeShips(grid1, 1, 1);
		}
		int headStart = 0;

		printf("Choose difficulty level:\n1-Easy (You get 5 guesses as head start)\n2-Medium (You get 3 guesses as head start)\n3-Hard (You get no head start)\n\n");
		scanf("%d", &input);
		if (input == 1)
		{
			headStart = 5;
		}
		else if(input == 2)
		{
			headStart = 3;
		}
			srand(time(0));
			placeShips(grid2, 2, 1);
			printf("Here is the placement of your ships:\n\n");
			printShipPlacements(grid1);
			printf("\n\n\n");

			if(headStart!=0)
			printf("You have %d guesses head start!\n\n",headStart);
			
			int resume = 1;
			while (resume)
			{
				printf("Player 1's current guesses:\n\n");
				printGrid(grid2, 1);
				printf("It is the turn of Player 1 now...\n\n");
				takeTurn(grid2, 2, 0);
				if (checkForWinner(grid2) == 1)
				{
					printf("Player 1 has sunk all the ships of the Computer and has won the game!\n\n");
					FILE* fptr = fopen("Score.txt", "a");
					fprintf(fptr, "%d\n", player1Score);
					fclose(fptr);
					break;
				}
				system("pause");
				system("cls");
				if (headStart == 0)
				{
					printf("\nComputer's current guesses:\n\n");
					printGrid(grid1, 2);
					printf("It is Computer's turn now...\n\n\n");
					takeTurn(grid1, 1, 1);
					if (checkForWinner(grid1) == 1)
					{
						printf("Computer has sunk all the ships of Player 1 and has won the game!\n\n");
						break;
					}
					system("pause");
					system("cls");
				}
				else
				{
					headStart--;
				}
				player1Score--;
			}
			
		
	}
	else if (input == 2)
	{
		srand(time(0));
		printf("Player 2 kindly move away from the screen till Player 1 is setting up his ships!\n\n");
		printf("Player 1 would you like to place your ships:\n1-Manually\n2-Randomly\n\n");

		scanf("%d", &input);
		while (input != 1 && input != 2)
		{
			if (input != 1 && input != 2)
			{
				printf("Incorrect input. Try again!\n\n");
			}
		}

		if (input == 1)
		{
			placeShips(grid1, 1, 0);
		}
		else if (input == 2)
		{

			placeShips(grid1, 1, 1);
		}

		printf("Here is the placement of your ships:\n\n");
		printShipPlacements(grid1);

		system("pause");
		system("cls");

		printf("Player 1 kindly move away from the screen till Player 2  is setting up his ships!\n\n");
		printf("Player 2 would you like to place your ships:\n1-Manually\n2-Randomly\n\n");

		scanf("%d", &input);
		while (input != 1 && input != 2)
		{
			if (input != 1 && input != 2)
			{
				printf("Incorrect input. Try again!\n\n");
			}
		}

		if (input == 1)
		{
			placeShips(grid2, 1, 0);
		}
		else if (input == 2)
		{
			placeShips(grid2, 1, 1);
		}

		printf("Here is the placement of your ships:\n\n");
		printShipPlacements(grid2);

		system("pause");
		system("cls");


		int resume = 1;
		while (resume)
		{
			printf("Player 1's current guesses:\n\n");
			printGrid(grid2, 1);
			printf("It is the turn of Player 1 now...\n\n");
			takeTurn(grid2, 2, 0);
			if (checkForWinner(grid2) == 1)
			{
				printf("Player 1 has sunk all the ships of the Computer and has won the game!\n\n");
				FILE* fptr = fopen("Score.txt", "a");
				fprintf(fptr, "%d\n", player1Score);
				fclose(fptr);
				break;
			}
			system("pause");
			system("cls");
			
				printf("\nPlayer 2's current guesses:\n\n");
				printGrid(grid1, 2);
				printf("It is Player 2's turn now...\n\n\n");
				takeTurn(grid1, 1, 0);
				if (checkForWinner(grid1) == 1)
				{
					printf("Player 2 has sunk all the ships of Player 1 and has won the game!\n\n");
					FILE* fptr = fopen("Score.txt", "a");
					fprintf(fptr, "%d\n", player2Score);
					fclose(fptr);
					break;
				}
				system("pause");
				system("cls");
			
			player1Score--;
			player2Score--;
		}

	}

}