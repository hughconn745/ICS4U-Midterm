//Creator: Tahrima Rahman
//Name: word_count
//Description: returns number of words in argument for input parameter
//Parameters: pointer to argument for a 2D array of chars, two integers for the dimensions of char array
//Dependencies: includes from "Main.h" : iostream and ctype.h
//Throws: NA

#include "Word_Count.h"
#include "Main.h"

int word_count(char ** input, const int rows, const int cols){

	int words = 0;

		for (int r = 0; r < rows; r++){
		    words++;//count first word of every new line
			for (int c = 0; c < cols; c++){
				if (isblank(input[r][c])){
				    if (isalnum(input[r][c-1]) || isalnum(input[r][c+1])){//if there is a non graphic, non punctuation character before or after the blank, add to word count
				        words++;

				        }//end inner if



				}//end if

			}//end inner for

		}//end for


		cout << "Word Count: " << words << endl;

}//end function
