#include <stdio.h> //scanf, fflush, etc.
#include <ctype.h> //for comparing chars
#include <string.h> //string processing functions
#include <cstring>
#include <iostream>

using namespace std;

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

	char * paragraph[para_size];

	for(int i = 0; i < para_size; i++)
		paragraph[i] = new char[ARRAY_LENGTH];

	cout << "Please input your paragraph, type end when done." << endl;

	fflush(stdout);

	while(strncmp(paragraph[para_size], "end", 3)) {

	if(fgets(paragraph[para_size - 1], 30, stdin) != NULL) {
		cout << "Printing Paragraph contents" << endl;
		fputs(paragraph[1], stdout);
	}else
		break;
	}


	return 0;
}
