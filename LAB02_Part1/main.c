#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**************************************************************************************
 * Author:      Kyle Lentine
 * Course:      EGR 226 - 902
 * Date:        2/2/2021
 * Project:     Lab 02 - Part 1
 * File:        main.c
 * Description: This program can convert between resistance color bands and resistance values.
 * **************************************************************************************/

 /****| main | *****************************************
* Brief: This function displays most of the information for the user.
* param:
*      N/A
* return:
*      N/A
*************************************************************/

int main(){

    //Variables
    int input = 0;
    char junk[999];
    int i = 0;
    int STATUS;
    int choice;
    char b1, b2, b3, b4;
    char band1, band2, band3, band4;
    int again = 0;

    //Promt the user for which method they would like to use
    prompt();

    //While loop until user picks correct option "1" or "2"
    while( i == 0 ){

        //Status Variable
        fflush(stdin);
        STATUS = scanf("%d", &input);

        if(STATUS == 1){

            //If user picks option 1:
            if( input == 1 ){

                //Perform Option 1:
                printf("\nOption 1\n");
                getColorBands(&b1,&b2,&b3,&b4);
                calcResistance(b1,b2,b3,b4);
                i+=1;

                    //Ask if user would like to go again:
                    printf("Would you like to go again?\n");
                    printf("Enter ""1"" for Yes, anything else for No.\n\n");
                    fflush(stdin);
                    scanf("%d", &again);

                    if(again == 1){
                        main();
                    }

                    else{ return 0; }

            }

            //If user picks option 2:
            else if( input == 2 ){

                //Perform option 2:
                printf("\nOption 2\n");
                printf("Please input resistance between 0-99,000,000:\n");

                    while( i != 1 ){

                        //Make sure user inputs int
                        if(scanf("%d", &choice) == 1){

                            //Make sure number is in between correct values
                            if( choice >= 1 && choice <= 99000000 ){

                                //Perform option 2
                                printf("\nResistor Value:\n");
                                calcResistorColors(choice);
                                i+=1;

                                        //Ask if the user would like to go again
                                        printf("Would you like to go again?\n");
                                        printf("Enter ""1"" for Yes, anything else for No.\n\n");
                                        fflush(stdin);
                                        scanf("%d", &again);

                                        if(again == 1){
                                            main();
                                        }

                            }
                            //If bad value, prompt user again
                            else{

                                printf("Please input resistance between 0-99,000,000:\n");
                            }
                        }
                        //If not a valid int, prompt user again
                        else{

                            scanf("%s", &junk);
                            printf("Please input resistance between 0-99,000,000:\n");
                        }
                    }
            }
            //If not a valid option, prompt user again
            else{

                printf("Please enter option 1 or 2:\n");
                fflush(stdin);
            }
        }
        //If not a valid option, prompt user again
        else{

            printf("Please enter option 1 or 2:\n");
            fflush(stdin);
       }
    }
}

/****| prompt() | *****************************************
* Brief: This function will prompt the user and ask which method they would like to use.
* param:
*      N/A
* return:
*      N/A
*************************************************************/

void prompt(){

    //Print display
    printf("--------------------Resistor Codes---------------------\n");
    printf("|Character| Color  | Band 1 & 2 |   Band 3  | Band 4  |\n");
    printf("|    K    | Black  |      0     |*1         |+/- 1%%   |\n");
    printf("|    N    | Brown  |      1     |*10        |+/- 2%%   |\n");
    printf("|    R    | Red    |      2     |*100       |         |\n");
    printf("|    O    | Orange |      3     |*1,000     |         |\n");
    printf("|    Y    | Yellow |      4     |*10,000    |         |\n");
    printf("|    G    | Green  |      5     |*100,000   |+/- 0.5%% |\n");
    printf("|    B    | Blue   |      6     |*1,000,000 |+/- 0.25%%|\n");
    printf("|    V    | Violet |      7     |*10,000,000|+/- 0.1%% |\n");
    printf("|    E    | Grey   |      8     |           |+/- 0.05%%|\n");
    printf("|    W    | White  |      9     |           |         |\n");
    printf("|    D    | Gold   |            |           |+/- 5%%   |\n");
    printf("|    S    | Silver |            |           |+/- 10%%  |\n");
    printf("-------------------------------------------------------\n\n");

    //Print options
    printf("Enter number for option:\n");
    printf("[1] - Convert Color-Code -> Resistance\n");
    printf("[2] - Convert Resistance -> Color-Code\n");
    }

/****| calcResistanceColors | *****************************************
* Brief: This function takes a resistance value and turns it into a color code.
* param:
*      (int input) -> resistance value that is converted
* return:
*      N/A
*************************************************************/

void calcResistorColors(int input){

    //Variables to find color bands of resistor.
    char color[10][10] = { "Black", "Brown", "Red", "Orange", "Yellow", "Green", "Blue", "Violet", "Grey", "White" };
    int band1, band2;
    int count = 0;

    //Calculate colors for resistor.

    //Check to see if input is less than 10
    if( input >= 100 ){

        //Divide the user input number until it is less or equal to 100.
        do{
            input = input / 10;
            count = count + 1;
        }

        while( input >= 100 );

        }
            //Band 1 is the first number in input, Band 2 is the second number in input.
            band1 = input / 10;
            band2 = input % 10;

    //Print out resulting color bands for the resistor.
    printf(" %s-%s-%s\n\n", color[band1], color[band2], color[count]);

}

/****| getColorBands | *****************************************
* Brief: This function collects 4 color bands for a resistor from the user.
* param:
*      (char* b1,b2,b3,b4) -> These are the 4 color bands collected.
* return:
*      N/A
*************************************************************/

void getColorBands( char* b1, char* b2, char* b3, char* b4 ){
printf("\nPlease Enter 4 of the Characters From the Table:\n");

        //Collect 4 color bands from user
        printf("b1: ");
        fflush(stdin);
        scanf("%c", b1);

        printf("b2: ");
        fflush(stdin);
        scanf("%c", b2);

        printf("b3: ");
        fflush(stdin);
        scanf("%c", b3);

        printf("b4: ");
        fflush(stdin);
        scanf("%c", b4);

}

/****| calcResistance | *****************************************
* Brief: This function takes the 4 color bands and calculates a
*        resistance for the user.
* param:
*      (char band1,band2,band3,band4) -> These are the 4
*      color bands that get converted to a resistance value.
* return:
*      N/A
*************************************************************/

void calcResistance(char band1, char band2, char band3, char band4 ){

//Variables for finding resistance and looping
float RValue = 0.0;
float part1;
float part2;
float multiplier;
int check = 0;

        //Case for band1
		switch (band1)
		{
			case('k'):
			case('K'):
				part1 = 0;
				break;

			case('n'):
			case('N'):
				part1 = 10;
				break;

			case('r'):
			case('R'):
				part1 = 20;

				break;

			case('o'):
			case('O'):
				part1 = 30;
				break;

			case('y'):
			case('Y'):
				part1 = 40;
				break;

			case('g'):
			case('G'):
				part1 = 50;
				break;

			case('b'):
			case('B'):
				part1 = 60;
				break;

			case('v'):
			case('V'):
				part1 = 70;
				break;

			case('e'):
			case('E'):
				part1 = 80;
				break;

			case('w'):
			case('W'):
				part1 = 90;
				break;

            default:
                printf("Invalid Input for Band 1: Answer will not be fully correct\n");
                check++;
                break;


		}

		//Cases for band2
		switch (band2)
		{
			case('k'):
			case('K'):
				part2 = 0;
				break;

			case('n'):
			case('N'):
				part2 = 1;
				break;

			case('r'):
			case('R'):
				part2 = 2;
				break;

			case('o'):
			case('O'):
				part2 = 3;
				break;

			case('y'):
			case('Y'):
				part2 = 4;
				break;

			case('g'):
			case('G'):
				part2 = 5;
				break;

			case('b'):
			case('B'):
				part2 = 6;
				break;

			case('v'):
			case('V'):
				part2 = 7;
				break;

			case('e'):
			case('E'):
				part2 = 8;
				break;

			case('w'):
			case('W'):
				part2 = 9;
				break;

            default:
                printf("Invalid Input for Band 2: Answer will not be fully correct\n");
                check++;
                break;

		}

        //Cases for band 3
		switch (band3)
	 	{
			case('k'):
			case('K'):
				multiplier = 1;
				break;

			case('n'):
			case('N'):
				multiplier = 10;
				break;

			case('r'):
			case('R'):
				multiplier = 100;
				break;

			case('o'):
			case('O'):
				multiplier = 1000;
				break;

			case('y'):
			case('Y'):
				multiplier = 10000;
				break;

			case('G'):
			case('g'):
				multiplier = 100000;
				break;

			case('b'):
			case('B'):
				multiplier = 1000000;
				break;

			case('v'):
			case('V'):
				multiplier = 10000000;
				break;

			case('d'):
			case('D'):
				multiplier = 0.1;
				break;

			case('s'):
			case('S'):
				multiplier = 0.01;
				break;

            default:
                printf("Invalid Input for Band 3: Answer will not be fully correct\n");
                check++;
                break;
	 	}

        //If valid first 3 numbers, perform operation to find first part of resistance:
        if( check == 0 ){
		RValue = (part1 + part2) * multiplier;
		printf("%g",RValue);
        }

        check = 0;

        //Cases for band 4
        switch (band4)
	 	{
			case('k'):
			case('K'):
				printf(" +/- 1%%\n\n");
				break;

			case('n'):
			case('N'):
				printf(" +/- 2%%\n\n");
				break;

			case('G'):
			case('g'):
				printf(" +/- 0.5%%\n\n");
				break;

			case('b'):
			case('B'):
				printf(" +/- 0.25%%\n\n");
				break;

			case('v'):
			case('V'):
				printf(" +/- 0.1%%\n\n");
				break;

			case('e'):
			case('E'):
				printf(" +/- 0.05%%\n\n");
				break;

			case('d'):
			case('D'):
				printf(" +/- 5%%\n\n");
				break;

			case('s'):
			case('S'):
				printf(" +/- 10%%\n\n");
				break;

            default:
                printf("Invalid Input for Band 4: Answer will not be fully correct\n");
               // main();
                break;
	 	}
	}




