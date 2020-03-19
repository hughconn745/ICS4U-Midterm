#include <stdio.h> //scanf, fflush, etc.
#include <ctype.h> //for comparing chars
#include <string.h> //string processing functions
#include <cstring>
#include <iostream>
#include "Main.h"
#include "Array_Resize.h"


using namespace std;
int para_size = 1;

int main() {

	/*THINGS TO CONSIDER WHEN PROGRAMMING MAIN:
	 * I'm guessing that the program will run through a while loop with the condition looking something like
	 * while (1){
	 * }
	 * or will the user have the option to exit?
	 *
	 * the search function will accept an int pointer pointing to the first element of the int array so main needs something like:
	 *
	 * int indexes[size of user input];
	 * int *indexPtr = &index[0];
	 *
	 *
	 *
	 *
*/

	char * paragraph[para_size + 1];


	for(int i = 0; i < para_size; i++)
		paragraph[i] = new char[ARRAY_LENGTH];

	cout << "Please input your paragraph, type end when done." << endl;

	fflush(stdout);
	int i = 0;
	while(fgets(paragraph[i], 30, stdin) != NULL){
		cout << "Copying all paragraph contents" << endl;
			paragraph = resizeArray(paragraph);
			i++;


			cout << "Printing Paragraph contents" << endl;
				for(int j = 0; j < i; j++) {
					fputs(paragraph[j], stdout);
					fflush(stdout);
				}
	}

	cout << "Printing Paragraph contents" << endl;
	for(int j = 0; j < i; j++)
		fputs(paragraph[j], stdout);


	return 0;
}
