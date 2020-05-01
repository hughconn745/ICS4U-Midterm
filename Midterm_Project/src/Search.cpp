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

		    }//end while


		int tempSize = wrdSize; //meant to store the number of letters in find[] if wrdSize's value needs to change during searching process

		bool checkEach = false; //will confirm whether a section of input[][] matched each letter in find[]


	    //two for loops to iterate through each char in input[][]
			for (int i = 0; i < rows; i++){
				for (int j = 0; j < strlen(input[i]); j++){

	                //if a letter in input[][] matched the first letter in find[]:
					if (tolower(input[i][j]) == tolower(find[0])){

						firstRow = i; //mark the row the first letter was found
						firstCol = j; //mark the column the first letter was found

						wrdSize = tempSize; //reassign wrdSize the value that reflects the actual number of indices in find[]

						findLetter = 0; //mark the position in find[] being evaluated against input[][]

						for (int x = 0; x < wrdSize; x++){//for the length of the number of letters in find[]:

							if (j+x == strlen(input[i])){//if number of columns searched in a specific row exceed array bounds of a row:

								i++;//increase row number in input[][]
								j=0;//start at the first column of the next row

								wrdSize = wrdSize-x-1; //decrease the number of comparisons between letters since it is a new row

								x=0;//starting at new row

								if (isblank(find[findLetter])){ //if there is a blank space in find[] in the same spot that a row needs to be jumped:

									findLetter++;//skip the space

									}//end inner inner if

							} //end inner if

							if (tolower(input[i][j+x]) == tolower(find[findLetter])){//makes search non-case-sensitive

								checkEach = true;

	                            findLetter++;//compare next letter in the next iteration


							}//end inner if #2

							else{

								checkEach = false;
								break;

							}//end inner else #2

						}//end inner inner for


						if (checkEach == true){
						numFound++;


						printf("Occurrence of: \"%s\" found at row: %d column: %d to row : %d column: %d\n", find, firstRow+1, firstCol+1, (i+1), j+wrdSize);


				    	}//end second inner if


					}//end if


				}//end inner for loop for columns



			}//end for loop for rows

			if(numFound == 0){
				cout << "No occurrences of " << find << " were found" << endl;


			}//end outer if

			else {
				cout << "Total of " << numFound << " occurrences of " << find << " were found" << endl;


			}//end outer else

}//end function
