#include "Main.h"
/**Description: Grows the 2-dimensional global array to the specified size by adding new rows
 *
 * Parameters:
 *	int new_size, the new size of the array
 *
 * Returns:
 * 	None
 *
 */
void growArray(int new_size) {

	char ** buffer = new char *[para_size];

	//Copys entries to the buffer
	for(int i = 0; i < para_size; i++) {
		for(int j = 0; j < ARRAY_LENGTH; j++)
			buffer[i] = array[i];
	}

	//Resizes the original array
	array = new char *[new_size];

	//Allocates memeory in the new array
	for(int i = para_size; i < new_size; i++) {
		array[i] = new char[ARRAY_LENGTH];
	}

	//Copys data back to the array
	for(int i = 0; i < para_size; i++) {
		for(int j = 0; j < ARRAY_LENGTH; j++)
			array[i] = buffer[i];
	}

	delete buffer;

	return;
}

/**Description: shrinks the 2-dimensional global array to the specified size by removing rows
 *
 * Parameters:
 *	int new_size, the new size of the array
 *
 * Returns:
 * 	None
 *
 */
void shrinkArray(int new_size) {

	char ** buffer = new char *[para_size];

	//Copys data to the buffer
	for(int i = 0; i < new_size; i++) {
		for(int j = 0; j < ARRAY_LENGTH; j++)
			buffer[i] = array[i];
	}

	//Resizes the original array
	array = new char *[new_size];

	//Allocates memory to the array
	for(int i = 0; i < new_size; i++) {
		array[i] = new char[ARRAY_LENGTH];
	}

	//Copys data back to the array
	for(int i = 0; i < new_size; i++) {
		for(int j = 0; j < ARRAY_LENGTH; j++)
			array[i] = buffer[i];
	}

	delete buffer;
	return;
}

/**Description: Grows a 1-dimensional array to the specified size
 *
 * Parameters:
 * 	char * input, the array to grow
 *
 * 	int old_size, the size of the input array
 *
 *	int new_size, the new size of the array
 *
 * Returns:
 * 	None
 *
 */
void grow1DArray(char * input, int old_size, int new_size) {

	char * output = new char[new_size];

	for(int i = 0; i < old_size; i++)
		output[i] = input[i];

	input = output;

	delete output;


}

/**Description: Grows a 1-dimensional array to the specified size
 *
 * Parameters:
 * 	char * input, the array to grow
 *
 * 	int old_size, the size of the input array
 *
 *	int new_size, the new size of the array
 *
 * Returns:
 * 	None
 *
 */
void shrink1DArray(char * input, int old_size, int new_size) {
	char * output = new char[new_size];

	for(int i = 0; i < new_size; i++)
		output[i] = input[i];

	input = output;

	delete output;
}
