#include <stdio.h> //scanf, fflush, etc.
#include <ctype.h> //for comparing chars
#include <string.h> //string processing functions
#include <cstring>
#include <iostream>
#include "Main.h"
#include "Array_Resize.h"


using namespace std;
int para_size = 1;
int ARRAY_LENGTH = 30;
char ** array = new char*[para_size + 1];

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

	cout << "Please input your paragraph, type end when done." << endl;

	fflush(stdout);

	int k = 0;






	if(fgets(array[k], 28, stdin) == NULL) {
		return 1;
	}

	resizeArray(3);

	k++;
	para_size++;

	cout << array << endl;
			cout << "Printing Paragraph contents" << endl;
				for(int j = 0; j < k; j++) {

					fputs(array[j], stdout);
					fflush(stdout);
				}

			cout << "End of paragraph contents" << endl;



	cout << "Printing Paragraph contents" << endl;
	for(int j = 0; j < k; j++)
		fputs(array[j], stdout);

	return 0;


}
