#include <stdio.h> //scanf, fflush, etc.
#include <ctype.h> //for comparing chars
#include <string.h> //string processing functions
#include <cstring>
#include <iostream>
#include "Main.h"
#include "Array_Resize.h"

using namespace std;

void resizeArray(int new_size) {


	cout << "test 1" << endl;

	char *buffer[new_size];

	cout << "test 2" << endl;

	for(int i = 0; i < new_size; i++) {
		cout << "test 2.5" << endl;

			buffer[i]  = new char[ARRAY_LENGTH];

	}

	cout << "test 3" << endl;

	for(int i = 0; i < para_size; i++) {
		for(int j = 0; j < ARRAY_LENGTH; j++)
			buffer[i][j] = array[i][j];
	}

		//cout << array << endl;
		//cout << buffer << endl;
	cout << "test 4" << endl;

	array = new char *[new_size];

	for(int i = 0; i < new_size; i++) {
		array[i] = new char[ARRAY_LENGTH];
	}

	cout << "test 5" << endl;

	for(int i = 0; i < para_size; i++) {
		for(int j = 0; j < ARRAY_LENGTH; j++)
			array[i][j] = buffer[i][j];
	}

	//cout << array << endl;
	//cout << buffer << endl;

	delete []buffer;

	return;
}
