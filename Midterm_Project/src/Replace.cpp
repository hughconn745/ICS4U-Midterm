#include "Main.h"

int searchForPhrase(char * input, char * keyphrase, int pos) {

	char * toCmp = new char[strlen(keyphrase)];

	for(int i = pos, j = 0; i < strlen(keyphrase) + pos; i++, j++)
		toCmp[j] = input[i];

	while(strncmp(toCmp, keyphrase, strlen(keyphrase)) && pos <= strlen(input)) {

		pos++;

		for(int i = 0; i < strlen(keyphrase); i++) {

			toCmp[i] = input[i + pos];
		}
		}

		cout << "Instance of keyphrase found:" << pos << endl;
		int ext = 10;

		if(strlen(input) < 10)
			ext = strlen(input);

		if(pos > 10){

			for(int j = pos - 10; j < pos + ext; j++)
				cout << input[j];

		}else{
			for(int k = pos; k < pos + ext; k++) {
				cout << input[k];
			}
		}

		fflush(stdout);
	return pos;
}

void replaceWord(char ** input, char * keyphrase, char * newChar) {

	int arraySize = ARRAY_LENGTH * (para_size - 1);
	char* output = new char[arraySize];

	output[0] = '\0';
	for(int i = 0; i < para_size - 1; i++) {
	    strncat(output, array[i], ARRAY_LENGTH - 1);
	}

	int pos = 0;

	while(pos < strlen(output) - strlen(keyphrase)) {

		pos = searchForPhrase(output, newChar, pos);

		cout << "Would you like to replace this instance? yes/no" << endl;

		char * choice = new char[5];

		if(fgets(choice, 2, stdin) == NULL) {
			cout << "Error: Failed to receive input" << endl;
		}

		if(strncmp(choice, "no", 2) == 0)
			continue;

		char * buffer = new char[arraySize - pos];

		if(strlen(newChar) - strlen(keyphrase) > 0) {


			for(int l = pos; l < strlen(output); l++)
				buffer[l - pos] = output[l];

			grow1DArray(output, arraySize, arraySize + (strlen(newChar) - strlen(keyphrase)));

		} else {

			for(int l = pos; l < strlen(output); l++)
				buffer[l - pos] = output[l];

			shrink1DArray(output, arraySize, arraySize - (strlen(newChar) - strlen(keyphrase)));
		}
			arraySize += (strlen(newChar) - strlen(keyphrase));
			cout << "check 10" << endl;
			for(int m = pos; m < pos + strlen(newChar); m++)
				output[m] = newChar[m];

			output[pos + strlen(newChar) + 1] = ' ';

			for(int n = pos + strlen(newChar) + 2; n < arraySize; n++)
				output[n] = buffer[n - (pos + strlen(newChar) + 2)];

			int progress = 0;
			int line = 0;

			for(int i = 0; i < strlen(output); i++)
				cout << output[i];

			while(progress != strlen(output)) {
				for(int p = 0; p < 29; p++) {
					array[line][p + progress] = output[p + progress];
					if(output[p + progress] == '\n'){
						cout << " breaky boi" << endl;
						progress += p;
						break;
					}

				}
				cout << "check 11 : " << progress << " : " << line << endl;
			if(line == para_size)
				growArray(para_size + 1);
			cout << "check 12" << endl;
			line++;
			}
			cout << "check 13" << endl;

	}
}
