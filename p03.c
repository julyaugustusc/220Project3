// CSE220 Spring 2019, Project 3

// Augustus Crosby
// Programming environment used: VS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#pragma warning(disable : 4996)  // to avoid scanf error, Visual Studio only

#define MAX_DIM 3
#define STUDENTS 5		// total number of students
int matrixA[MAX_DIM][MAX_DIM], matrixB[MAX_DIM][MAX_DIM], sum[MAX_DIM][MAX_DIM];
int scores[STUDENTS];
int *pScores = NULL;

/*
Question 1: Forward declaration (5 points)
Declare here the functions used in the program, as needed
*/
int *p = 0;
//forward declaration
void inputMatrixA();
void copyToMatrixB();
void addMatrix();
void displaySumMatrix();
void inputScores();
void scoreStats();
void createUsername();
void lowerToUpperCase();
void searchPattern();

// DO NOT modify main()
int main()
{
	printf("\nProblem 2,3,4,5: \n");
	inputMatrixA();

	copyToMatrixB();

	addMatrix();

	displaySumMatrix();

	printf("\nProblem 6,7: \n");
	inputScores();

	scoreStats();

	getchar();			// neded to flushout Enter(\n) character left behind. Comment out if not needed
	printf("\nProblem 8: \n");
	createUsername();

	printf("\n\nProblem 9: \n");
	lowerToUpperCase();

	printf("\nProblem 10: \n");
	searchPattern();

	system("pause");	// needed to keep console open in VS
	return 0;
}


/*
Question 2: inputMatrixA (5 points)
matrixA[][] is already declared. Input the elements of matrixA from the user.
Use the macro MAX_DIM in your code, so that when MAX_DIM is changed from 3 to any other number, this function would still work.
Note: Usually, matrix is entered row-wise. So input 1st row of elemets , followed by 2nd row and so on.
*/
void inputMatrixA()
{
	int i, j;

	for (i = 0; i < MAX_DIM; i++) {				// each row input for Matrix A
		for (j = 0; j < MAX_DIM; j++) {			// each value in a row for Matrix A
			printf("Enter matrix element:\n");
			scanf("%d", &matrixA[i][j]);		// put into address of matrixA at [i][j]
		}
	}
}

/*
Question 3: copyToMatrixB (5 points)
matrixB[][] is already declared. Compose matrixB identical to matrixA.
Copy elements of matrixA to matrixB. You may use array operation or pointer to do the copying.
So, after calling this function, matrixB and matrixA should have same elements.
Use the macro MAX_DIM in your code, so that when MAX_DIM is changed from 3 to any other number, this function would still work.
Debug tip: Use display function below to temporarily display matrixA and matrixB to verify if your functions work correctly.
*/
void copyToMatrixB()
{
	int i, j;									// declared for 'for' loops
	p = &matrixA[0][0];							// initialize pointer

	for (i = 0; i < MAX_DIM; i++) {				// each row input
		for (j = 0; j < MAX_DIM; j++) {			// each value in a row 
			matrixB[i][j] = *p;					// taking the value in the pointer (frist at matrixA[0][0]) and putting that value into matrixB
			p++;								// adding 1 to the value of p, the address of matrixA[0][0]
			//printf("%d\n", matrixA[i][j]);		// temporarily display matrixA and matrixB
			//printf("%d\n", matrixB[i][j]);
		}
	}


}


/*
Question 4: addMatrix (10 points)
sum[][] is already declared. Implement this math operation: (2*A) + B and store the result in matrix 'sum'.
Use the macro MAX_DIM in your code, so that when MAX_DIM is changed from 3 to any other number, this function would still work.
*/
void addMatrix()
{
	int i, j;									// declared for 'for' loops			

	for (i = 0; i < MAX_DIM; i++) {				// each row input
		for (j = 0; j < MAX_DIM; j++) {			// each value in a row 
			sum[i][j] = ((matrixA[i][j]) * 2) + matrixB[i][j];		//sum = 2*matrixA + matrixB
		}
	}


}

/*
Question 5: displaySumMatrix (10 points)
Implement the function to display the 'sum' matrix. Display in this format :
The matrix sum=
1	2	3
4	5	6
7	8	9
*/
void displaySumMatrix()
{
	int i, j;									// declared for 'for' loops	
	printf("The matrix sum=\n");

	for (i = 0; i < MAX_DIM; i++) {				// each row input
		for (j = 0; j < MAX_DIM; j++) {			// each value in a row
			printf("%d\t", sum[i][j]);			// print each value in the row followed by a tab
		}
		printf("\n");							// print a 'enter' after each row
	}
}

/*
Question 6: inputScores (10 points)
Input the scores of students.
The valid range of score is 0 to 100 (0 and 100 included). Keep prompting the user to input valid score if invalid score is input.
This function should work as expected when STUDENTS macro is changed.
You MUST use pointer 'pScores' to input the scores to gain full points.
Using array operation (scores[i]) will earn you half points.
*/
void inputScores()
{
	pScores = &scores[0];						// declare the pScores pointer
	int i;										// declared for 'for' loops	

	for (i = 0; i < STUDENTS; i++) {
		printf("Enter score %d:\n", i+1);		// i + 1 to count the scores
		scanf("%d", pScores);					
		while (*pScores < 0 || *pScores > 100) {	// the program will reject the number if out of bounds
			printf("Input was not valid, please re-enter a valid score %d:\n", i+1);
			scanf("%d", pScores);
		}
		pScores++;								// the pointer also moves 1 
	}

}

/*
Question 7: scoreStats (10 points)
Now that the scores of students are stored, find the maximun and the average of those scores. Display these stats.
Ignore the decimal point accuracy since we are dealing with integers. This function should work as expected when STUDENTS macro is changed.
You MUST use pointer 'pScores' to gain full points.
Using array operation (scores[i]) will earn you half points.
Note: Make sure pointer 'pScores' is pointing to correct place.
*/
void scoreStats()
{
	pScores = &scores[0];						// initalize the pScores pointer
	int maxScore = 0;							// the min accepted score is 0, so initalized to 0
	int totalScore = 0;							// total score can minimally be 0, so initialized to 0
	int aveScore;								// ave score variable initialized
	int i;										// declared for 'for' loops	

	for (i = 0; i < STUDENTS; i++) {
		if (*pScores > maxScore) {				// the pointer points to the value in the matrix,
			maxScore = *pScores;				// if the value in the matrix is bigger, the new max score is that
		}

		totalScore = totalScore + *pScores;		// total is previous total plus pointer value
		pScores++;								// pointer moves 1
	}

	aveScore = totalScore / STUDENTS;			// no decimals, ave = total/#ofstudents

	printf("Max Score: %d\nAverage Score: %d\n", maxScore, aveScore);

}

/*
Question 8: createUsername (15 points)
Implement the function that creates and displays the user name of the user. Ask the user for their first and last name.
The username is the first letter of first name, followed by the last name. For instance, if the user's name is John Doe, then the username is jdoe.
The user may input upper or lower case characters for first and last name. Make sure that the username is all lower case.
Note : When using fgets(), when you press Enter to finish entering the string, the Enter (\n) character is also added to the string.
	Try to remove that character.
*/
void createUsername()
{
	char firstName[15], lastName[15], userName[20];
	int i;										// declare for 'for' loops	

	printf("Please enter your first name:\n");
	fgets(firstName, 15, stdin);				//takes input from stdin and puts it in firstName

	for (i = 0; i < 15; i++) {								// 15 is the max amount of characters
		if (firstName[i] >= 'A' && firstName[i] <= 'Z') {	// if it's an uppercase
			firstName[i] = firstName[i] + 32;				//adding 32 lowercases it
		}
	}

	printf("Please enter your last name:\n");
	fgets(lastName, 15, stdin);					//takes input from stdin and puts it in lastName

	for (i = 0; i < 15; i++) {								// 15 is the max amount of characters
		if (lastName[i] >= 'A' && lastName[i] <= 'Z') {		// if it's an uppercase
			lastName[i] = lastName[i] + 32;					//adding 32 lowercases
		}
	}

	userName[0] = firstName[0];								// only need to worry about the first letter
	for (i = 0; i < 20; i++) {								//20 is the max amount of characters
		userName[i + 1] = lastName[i];						// offset by 1 because of firstname[0] character
	}

	printf("User name: %s", userName);
}

/*
Question 9: (10 points)
Count the number of lower case characters in array 'sentence' and convert lower case characters to upper case.
Print the number of lower case characters and print the newly formed sentence[] which has all upper case characters.
You may not add more variables than already declared. You may use 'int i' in 'for' loop, if needed.
Hint: Lookup ASCII chart of alphabets
*/
void lowerToUpperCase()
{
	char sentence[] = "THiS SentENCE HAS SOMe LoWEr CASE ChARAcTERs";
	int lowerCases = 0;										// counter for lowercase letters
	int i;													//declared for 'for' loops

	for (i = 0; sentence[i] != '\0'; i++) {							//'\0' character has to be there by the way it's declared. no need to count characters
		if (sentence[i] >= 'a' && sentence[i] <= 'z') {				// if it's a lowercase
			lowerCases++;											//count the lowercases
			sentence[i] = sentence[i] - 32;							// adding 32 capitializes
		}
	}

	printf("Number of lower case characters= %d \n", lowerCases);
	printf("Upper case sentence : %s \n", sentence);
}

/*
Question 10: (20 points)
Implement the function to take in a 10-character string 'string'1' and 3-character pattern string 'pattern' from the user.
Search for the 'pattern' in 'str' and display "Pattern found" if 'pattern' is found in 'str', else display "Pattern not found".
For instance, if user enters str= "abcdefghij" and pattern = "ghi", then the pattern exists in str, so display "Pattern found".
You MUST use pointers and not arrays for this question. You may use string functions.
You may not add more variables than already declared. You may use 'int i' in 'for' loop, if needed.

Note : When using fgets(), when you press Enter to finish entering the string, the Enter (\n) character is also added to the string. Try to remove that character.
So a 10-character string actually looks like "abcdefghij\n\0". So consider storing 12 elements for 10-character string.
Assume user inputs correct length strings.
*/
void searchPattern()
{
	char *str, *pattern;								// declare pointers which act as constants
	int strLen = 12, patternLen = 5;					// assuming 10 and 3 are put in, \n and \0 characters, not really necessary given the assignment
	int i;												// declare for 'for' loops

	printf("Enter a 10 character string: \n");
	str = (char*)malloc(strLen * sizeof(char));			// allodocate memory for str
	fgets(str, strLen, stdin);							//take input from stdin into str
	


	printf("Enter a 3 character pattern: \n");
	pattern = (char*)malloc(patternLen * sizeof(char));	// allodocate memory for pattern
	fgets(pattern, patternLen, stdin);					// take input from stdin into pattern

	while(*str != '\0'){
		if (*str = *pattern) {							// if str matches pattern char for 1st of each
			str++;										// add one to both to match next char
			pattern++;
			if (*str = *pattern) {						// if next str matches next pattern char
				str++;									// add one to both to match next char
				pattern++;
				if (*str = *pattern) {					// if final char matches
					printf("Pattern found\n");			// inputs pattern found and exists string because the str doesn't need to be preserved given the scope of this assignment
					*str = '\0';
				}
				else {
					str--;								// goes to next string but back to first pattern char
					pattern = pattern - 2;
				}
			}
			else {
				pattern--;								// stays at str character but back to first pattern char
			}
		}
		else {
			str++;
			if (*str = '\0') {
				printf("Pattern not found\n");			// at end of string, if not found output yet
			}
		}
	}







}