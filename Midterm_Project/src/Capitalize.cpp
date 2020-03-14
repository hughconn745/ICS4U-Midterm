//Creator: Tahrima Rahman
//Name: sentence_case
//Description: capitalizes first word of every sentence in "input" parameter
//Parameters: array of chars/ a string literal
//Dependencies: NA
//Throws: NA
void sentence_case(char *input){

	if (isalpha(input[0])){//capitalize first letter in input if it is a letter
		input[0] = toupper(input[0]);


	}//end if

	for(int x = 0; input[x] != '\0'; x++){

		if (input[x] == '.' && input[x+2] != '\0'){
			if (input[x + 1] != 0x20 && isalpha(input[x+1])){ //if user didn't put a space between period of previous sentence and beginning of new sentence AND next element is a letter
				input[x+1] = toupper(input[x+1]); //capitalize the first letter of the new sentence anyway

			} else {
				if (isalpha(input[x+2])){

					input[x+2] = toupper(input[x+2]); //capitalize first letter after the space after a period

				}//end inner inner if




			}//end inner if

		}//end outer if


	}//end for


}//end sentence_case
