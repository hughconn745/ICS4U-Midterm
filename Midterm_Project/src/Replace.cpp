#include "Replace.h"
#include "Main.h"
#include "Array_Resize.h"

void replaceWord(char ** input, char * keyphrase, char * newChar) {

	int arraySize = ARRAY_LENGTH * (para_size - 1);
	char* output = new char[arraySize];

	output[0] = '\0';
	for(int i = 0; i < para_size - 1; i++) {
	    strncat(output, array[i], ARRAY_LENGTH - 1);
	}

	int pos = 0;

	while(pos < ARRAY_LENGTH * (para_size - 1) - strlen(keyphrase)) {
		while(strncmp(output, keyphrase, strlen(keyphrase)))
			pos++;

		cout << "Instance of keyphrase found:" << endl;

		if(pos > 10){

			for(int j = pos - 10; j < pos + 10; j++) {
				cout << output[j];
			}
		}else{
			for(int k = pos - 10; k < pos + 10; k++) {
				cout << output[k];
			}
		}

		cout << "Would you like to replace this instance? Y/N" << endl;

		char * choice = new char[3];

		if(fgets(choice, 1, stdin) == NULL) {
			cout << "Error: Failed to receive input" << endl;
		}

		if(strncmp(choice, "N", 1) != 0)
			continue;
		if(strlen(newChar) - strlen(keyphrase) > 0) {
				grow1DArray(output, arraySize, arraySize + (strlen(newChar) - strlen(keyphrase)));
				char * buffer = new char(arraySize - pos);
				for(int l = pos; l < arraySize; l++)
					buffer[l] = output[l];


		} else {

		}
	}
}
