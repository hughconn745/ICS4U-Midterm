#include "Main.h"
#include "Array_Resize.h"
#include "Replace.h"
#include "Clipboard_Output.h"
#include "Capitalize.h"
#include "Search.h"
#include "Word_Count.h"


int para_size = 1;
int ARRAY_LENGTH = 30;
char ** array = new char*[para_size + 1];
char * select = new char[11];
char * keywordBuffer = new char[ARRAY_LENGTH];
char * replaceBuffer = new char[ARRAY_LENGTH];

int main() {
	array[0] = new char[30];
	array[1] = new char[30];

	cout << "Please input your paragraph, type end when done." << endl;

	fflush(stdout);



	int k = 0;

	do {
		cout << "stage 1" << endl;
		if(fgets(array[k], 28, stdin) == NULL) {
			return 1;
		}
		cout << "stage 2" << endl;
		if(k == para_size - 1) {
			cout << "stage 2.5" << endl;
			growArray(para_size + 1);
		}
		cout << "stage 3" << endl;
		k++;
		para_size++;
		cout << "stage 4" << endl;
	} while(strncmp(array[k - 1], "end", 3) != 0);

	do {
		cout << "Please enter one of the following commands:\n" << "-> replace\n-> search\n-> capitalize\n-> wordcount\n-> copy\n-> print\n-> quit" << endl;

		if(fgets(select, 10, stdin) == NULL) {
					return 1;
				}

		if(strncmp(select, "replace", 7) == 0) {

			cout << "Please input the word you wish to replace" << endl;

			if(fgets(keywordBuffer, 28, stdin) == NULL) {
				return 1;
			}

			cout << "Please input the word you wish to replace the first word" << endl;

			if(fgets(replaceBuffer, 28, stdin) == NULL) {
				return 1;
			}

			replaceWord(array, keywordBuffer, replaceBuffer);
			continue;
		}

		if(strncmp(select, "search", 7) == 0) {

			cout << "Please input the word you wish to search for" << endl;

			if(fgets(keywordBuffer, 28, stdin) == NULL) {
				return 1;
			}

			search(array, keywordBuffer, para_size - 1, ARRAY_LENGTH);

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
		cout << "Error: Unrecognized command" << endl;

	} while(strncmp(select, "quit", 10) != 0);
	cout << "quitting..." << endl;

}
