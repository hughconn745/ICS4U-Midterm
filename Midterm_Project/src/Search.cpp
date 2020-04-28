//Creator: Tahrima Rahman
//Name: search
//Description: looks for *find in *input and adds each index at which "find" occurs in "input" to a pointer, returns int pointer
//Parameters: user input, what to search, int pointer pointing to the first element of an int array
//Dependencies: Includes from Main.h :  stdlib.h, stdio.h, iostream,
//Throws: Message notifying user that no occurrences of find were present in input

#include "Search.h"
#include "Main.h"

void search(char ** input, const char find[], const int rows, const int cols){

	int numFound = 0; //number of occurences of char find[] that were found in char input[][]
		int wrdSize = 0; //number of letters in find[]

		int firstCol; //keeps track of the first column in which the first letter of find[] was found in input[][]
		int firstRow; //keeps track of the first row in which the first letter of find[] was found in input[][]
		int findLetter; //keeps track of what index in find[] is being compared with a letter in input[][]


		//get how many letters there are in find[]:
		while (find[wrdSize] != '\0'){
		    wrdSize++;

		    }


		int tempSize = wrdSize; //meant to store the number of letters in find[] temporarily if wrdSize's value needs to change during searching process
		cout << "Word size is " << wrdSize << endl;


		bool checkEach = false; //will confirm whether a part of input[][] matched each letter in find[]


	    //two for loops to iterate through each char in input[][]
			for (int i = 0; i < rows; i++){
				for (int j = 0; j< cols; j++){

	                //if a letter in input[][] matched the first letter in find[]:
					if (tolower(input[i][j]) == tolower(find[0])){


						findLetter = 0; //mark the position in find[] being evaluated again input[][]

						for (int x = 0; x < wrdSize; x++){//for the length of the number of letters in find[]:

							if ((j+x) >= cols || input[i][j+x] == '\0'){//if number of columns searched in a specific row exceed array bounds of if null terminator in a specific row is reached:

								firstRow = i; //mark the row the first letter was found
								i++;//increase row number in input[][]

								wrdSize-=x; //decrease the number of comparisons between letters since it is a new row
								x=0;//starting at new row

								firstCol = j; //mark the column the first letter was found
								j=0;//start at the beginning of the column of the next row

							}
							if (tolower(input[i][j+x]) == tolower(find[findLetter])){//makes search non-case sensitive
								checkEach = true;

	                            findLetter++;//compare next letter in the next iteration


							}//end inner if
							else{

								checkEach = false;
								break;

							}//end inner else

						}//end inner inner for

		                if (checkEach == true){
						numFound++;


						printf("Occurrence of: \"%s\" found at row: %d and column: %d to row : %d and column: %d\n", find, firstRow+1, firstCol+1, (i+1), j+wrdSize);
	                    wrdSize = tempSize; //revert wrdSize to reflect the actual number of indices in find[] again

				    	}//end second inner if

					}//end if


				}//end inner for



			}//end for

			if(numFound == 0){
				cout << "No occurrences found" << endl;


			}//end outer if

			else {
				cout << "Total of " << numFound << " occurrences were found" << endl;


			}//end outer else

}//end function
