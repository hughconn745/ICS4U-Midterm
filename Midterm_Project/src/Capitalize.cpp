//Creator: Tahrima Rahman
//Name: sentence_case
//Description: capitalizes first word of every sentence in argument for input parameter; also capitalizes all single I's
//Parameters: a pointer to a 2D array of chars, two integers representing the dimensions of the array
//Dependencies: includes from Main.h : ctype.h, iostream
//Throws: NA

#include "Capitalize.h"
#include "Main.h"

void capitalize(char ** input, const int rows, const int cols){

	int row = 0; //used to iterate through the rows in input[][]
	int col = 0;//used to iterate through the columns in input[][]

    int tempR; //will start at row and iterate through input until a letter to be capitalized is found
	int tempC; //will start at col and iterate through input until a letter to be capitalized is found

	while (row < rows && col < cols){

		if ((row == 0 && col == 0) || (input[row][col] == '!' || input[row][col] == '.' || input[row][col] == '?')){
			if (isalpha(input[row][col])){
				input[row][col] = toupper(input[row][col]);


			}//end inner if
			else{ //if the first character after a blank at the end of a sentence is not a letter:
				tempR = row;
				tempC = col;
				while(tempR < rows && tempC < cols){ //iterate through input[] until a letter is found
					if (isalpha(input[tempR][tempC])){
						input[tempR][tempC] = toupper(input[tempR][tempC]);

						//once a letter is found start searching for another end of a sentence whereever the iteration ended for the last letter capitalized:
						row = tempR;
						col = tempC;
						break;

					}//end inner inner if
					else{
						tempC++;

						//code to prevent exceeding bounds of a particular row:
						if (tempC == (cols -1 ) && !(isalpha(input[tempR][tempC]))){
							tempC = 0;
							tempR++;
						}//end inner inner inner if


					}//end inner inner else
				}//end inner while


			}//end inner else


		}//end if

		//code to prevent exceeding bounds of a particular row:
		if ((col+1) < cols){
			col++;

		}//end if
		else{
			col=0;
			row++;

		}//end else


	}//end while


    //separate for loop to capitalize all single i's into I's
    for (int r = 0; r < rows; r++){
        for (int c = 0; c < cols; c++){
            if (c==0){
            	//if there is a lone i at the beginning of a new row followed by a period or other sentence ending punctuation mark:
                if (input[r][c] == 'i' && (isblank(input[r][c+1]) || input[r][c+1] == '.' || input[r][c+1] == '!' ||  input[r][c+1] == '?')){
                    input[r][c] = toupper(input[r][c]);

                    }//end inner for

                } else if ((c+1 == cols)){ //if there is a lone i near the end of a row
                    if (input[r][c] == 'i' && isblank(input[r][c-1])){
                        input[r][c] = toupper(input[r][c]);

                        }//end inner if

                    } else {
                    	//if there is a lone i anywhere in the middle of a row:
                        if (input[r][c] == 'i' && isblank(input[r][c-1]) && (isblank(input[r][c+1]) || input[r][c+1] == '.')){

                             input[r][c] = toupper(input[r][c]);

                            }//end inner if

                        }//end else


            }//end c for

        }//end r for



    //for loop to print out results:
    for (int i = 0; i < rows; i++){
            cout << input[i] << endl;

            }

}//end function
