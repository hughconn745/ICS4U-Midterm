#include "Main.h"

/**Description: Searches a 1-dimensional array for the keyphrase, and returns the position of the first character
 *
 * Parameters:
 *	char * input: The char array to be searched
 *
 *	char * keyphrase: The phrase to be searched for
 *
 *	int pos: The inital position to search at
 *
 *Returns:
 *	int pos, the position of the first phrase found, or -1 if no phrase is found
 *
 */
int searchForPhrase(char * input, char * keyphrase, int pos) {

	bool found = false;

	char * toCmp = new char[strlen(keyphrase)];

	//Write the block of text to compare
	for(int i = 0; i < strlen(keyphrase) - 1; i++)
		toCmp[i] = input[i + pos];

	//Main search loop
	while(pos <= strlen(input) - strlen(keyphrase)) {

		//Check if a match was found, if so stop searching
		if(strncmp(toCmp, keyphrase, strlen(keyphrase) - 1) == 0) {
			found = true;
			break;
		}

		pos++;

		//Update comparison string
		for(int i = 0; i < strlen(keyphrase) - 1; i++) {
			toCmp[i] = input[i + pos];
		}
	}

	if(found) {

		cout << "Instance of keyphrase found:" << pos << endl;

		//Output a snippet of the phrase so the user understands where the instance of the key phrase is
		int ext = 10;

		if(pos + 10 > strlen(input) - 1)
			ext = strlen(input) - pos;

		cout << '\n';

		if(pos > 10) {
			for(int i = pos - 10; i < pos + ext; i++)
				cout << input[i];

		} else {
			for(int i = 0; i < pos + ext; i++)
				cout << input[i];
		}

		cout << '\n';

		return pos;

	} else {

		cout << "No instances of keyphrase found!" << endl;

		return -1;

	}
}


/**Description: Takes a two dimensional array, and key phrase and word to replace the key phrase with and will prompt the
 * user if they wish to change each found instance of the key phrase
 *
 * Parameters:
 * 	char ** input, the 2-dimensional array to search and replace
 *
 * 	char * key phrase, the phrase to be changed in the array
 *
 * 	char * newChar, the phrase to replace the key phrase
 *
 * Returns:
 * 	None
 *
 */
void replaceWord(char ** input, char * keyphrase, char * newChar) {

	int arraySize = ARRAY_LENGTH * (para_size - 1);
	char* output = new char[arraySize];

	//Converts the main 2-dimensional array into a 1-dimensional array
	output[0] = '\0';
	for(int i = 0; i < para_size - 1; i++) {
	    strncat(output, array[i], ARRAY_LENGTH - 1);
	}

	int pos = 0;

	while(pos < strlen(output) - strlen(keyphrase)) {

		pos = searchForPhrase(output, keyphrase, pos);

		if(pos <= strlen(output) - strlen(keyphrase) || pos != -1) {

			cout << "Would you like to replace this instance? yes/no" << endl;

			char * choice = new char[5];

			if(fgets(choice, 3, stdin) == NULL) {
				cout << "Error: Failed to receive input" << endl;
			}

			if(strncmp(choice, "no", 2) == 0) {

				cout << "skipping" << endl;

				pos++;

				continue;

			}

			fflush(stdin);

			delete choice;

			char * buffer = new char[arraySize - pos];


			for(int l = pos + strlen(keyphrase) - 1; l < strlen(output); l++)
				buffer[l - (pos + strlen(keyphrase) - 1)] = output[l];

			if(strlen(newChar) - strlen(keyphrase) > 0) {

				grow1DArray(output, arraySize, arraySize + (strlen(newChar) - strlen(keyphrase)));

			}
				arraySize += (strlen(newChar) - strlen(keyphrase));

				for(int m = pos; m < pos + strlen(newChar) - 1; m++)
					output[m] = newChar[m - pos];

				cout << "check 1 :" << output <<  " : " << pos + strlen(newChar) - 2 <<endl;
				output[pos + strlen(newChar) - 1] = ' ';

				cout << "check 2 :" << output << " : " << pos + strlen(newChar) - 1 << endl;
				for(int n = pos + strlen(newChar) , l = 0; n < strlen(buffer); n++, l++)
					output[n] = buffer[l];

				delete buffer;

				cout << "check 3 :" << output << " : " << pos + strlen(newChar) << endl;
				int progress = 0;
				int line = 0;

				while(progress <= strlen(output)) {

					for(int p = 0; p < 29; p++) {

						array[line][progress] = output[progress];

						if(output[progress] == '\n' || output[progress] == '\0'){

							progress++;
							break;
						}
							progress++;
					}

				cout << "check 11 : " << progress << " : " << line << endl;

				if(line == para_size)
					growArray(para_size + 1);

				line++;
				}
				cout << "check 13" << endl;

		}
	}

	delete output;
}
