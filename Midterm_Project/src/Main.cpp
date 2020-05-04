#include "Main.h"

//Global Variables
int para_size = 1;
int ARRAY_LENGTH = 30;
char ** array = new char*[para_size + 1];
char * select = new char[12];
char * keywordBuffer = new char[ARRAY_LENGTH];
char * replaceBuffer = new char[ARRAY_LENGTH];

int main() {

	//Allocating the inital memory for the main global array
	array[0] = new char[30];
	array[1] = new char[30];

	cout << "Please input your paragraph, type end when done." << endl;

	fflush(stdout);


	//Primary Input Array
	int k = 0;

	do {

		if(fgets(array[k], 28, stdin) == NULL) {
			return 1;
		}

		if(k == para_size - 1) {

			growArray(para_size + 1);
		}

		k++;
		para_size++;

	} while(strncmp(array[k - 1], "end", 3) != 0);

	//Main Command Loop
	while(true) {

		cout << "Please enter one of the following commands:\n" << "-> replace\n-> search\n-> capitalize\n-> wordcount\n-> copy\n-> print\n-> quit" << endl;

		//Command Input
		if(fgets(select, 11, stdin) == NULL) {
					return 1;
				}

		fflush(stdin);

		//Command Selection Block
		if(strncmp(select, "replace", 7) == 0) {

			cout << "Please input the word you wish to replace" << endl;

			if(fgets(keywordBuffer, 28, stdin) == NULL) {
				return 1;
			}

			cout << "Please input the word you wish to replace it with" << endl;

			if(fgets(replaceBuffer, 28, stdin) == NULL) {
				return 1;
			}

			replaceWord(array, keywordBuffer, replaceBuffer);

			fflush(stdin);

			continue;
		}

		if(strncmp(select, "search", 6) == 0) {

			cout << "Please input the word you wish to search for" << endl;

			if(fgets(keywordBuffer, 28, stdin) == NULL) {
				return 1;
			}

			keywordBuffer[strlen(keywordBuffer) - 1] = '\0';

			search(array, keywordBuffer, para_size - 1, ARRAY_LENGTH);

			fflush(stdin);

			continue;
		}

		if(strncmp(select, "capitalize", 10) == 0) {
			capitalize(array, para_size - 1, ARRAY_LENGTH);
			continue;
		}

		if(strncmp(select, "wordcount", 9) == 0) {
			word_count(array, para_size - 1, ARRAY_LENGTH);
			continue;
		}

		if(strncmp(select, "copy", 4) == 0) {
			outputToClipboard(array);
			continue;
		}

		if(strncmp(select, "print", 5) == 0) {
			for(int i = 0; i < para_size - 1; i++)
				cout << array[i];
			continue;
		}

		if(strncmp(select, "quit", 4) == 0)
			break;

		cout << "Error: Unrecognized command" << endl;

	}

	cout << "quitting..." << endl;

}
