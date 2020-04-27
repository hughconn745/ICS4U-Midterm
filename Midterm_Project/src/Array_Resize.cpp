#include "Main.h"
#include "Array_Resize.h"

void growArray(int new_size) {

	char ** buffer = new char *[para_size];

	for(int i = 0; i < para_size; i++) {
		for(int j = 0; j < ARRAY_LENGTH; j++)
			buffer[i] = array[i];
	}

	array = new char *[new_size];

	for(int i = para_size; i < new_size; i++) {
		array[i] = new char[ARRAY_LENGTH];
	}

	for(int i = 0; i < para_size; i++) {
		for(int j = 0; j < ARRAY_LENGTH; j++)
			array[i] = buffer[i];
	}

	delete buffer[para_size];

	return;
}

void shrinkArray(int new_size) {

	char ** buffer = new char *[para_size];

	for(int i = 0; i < new_size; i++) {
			buffer[i]  = new char[ARRAY_LENGTH];

	}

	for(int i = 0; i < new_size; i++) {
		for(int j = 0; j < ARRAY_LENGTH; j++)
			buffer[i] = array[i];
	}

	array = new char *[new_size];

	for(int i = 0; i < new_size; i++) {
		array[i] = new char[ARRAY_LENGTH];
	}

	for(int i = 0; i < new_size; i++) {
		for(int j = 0; j < ARRAY_LENGTH; j++)
			array[i] = buffer[i];
	}

	delete buffer[para_size];
	return;
}
