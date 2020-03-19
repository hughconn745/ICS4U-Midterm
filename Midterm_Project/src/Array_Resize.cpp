
#include "Main.h"
#include "Array_Resize.h"


char ** resizeArray(char * array[]) {


	char * buffer[para_size + 1];

	for(int i = 0; i < para_size; i++) {
		buffer[i] = new char[ARRAY_LENGTH];
	}


	for(int i = 0; i < para_size + 1; i++) {
		for(int j = 0; j < ARRAY_LENGTH; j++)
			buffer[i][j] = array[i][j];
	}

	return buffer;

}
