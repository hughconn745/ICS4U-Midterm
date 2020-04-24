//Creator: Tahrima Rahman
//Name: count_words
//Description: returns number of words in "input" parameter
//Parameters: array of chars/ a string literal
//Dependencies: NA
//Throws: NA

#include "Word_Count.h"

int ROWS;
int COLS;

int word_count(const char input[ROWS][COLS], const int rows, const int cols){

	int words = 0;

	for (int r = 0; r < rows; r++){
	    words++;//count first word of every new line
		for (int c = 0; c < cols; c++){
			if (isblank(input[r][c])){
			    if (isalnum(input[r][c-1]) || isalnum(input[r][c+1])){
			        words++;

			        }//end inner if



			}//end if

		}//end inner for

	}//end for


	return words;
}//end function
