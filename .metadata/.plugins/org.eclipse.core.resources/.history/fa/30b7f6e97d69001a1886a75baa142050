//Creator: Tahrima Rahman
//Name: count_words
//Description: returns number of words in "input" parameter
//Parameters: array of chars/ a string literal
//Dependencies: NA
//Throws: NA
int count_words(char *input){

	int words = 0;

	for (int i = strlen(input)-1; i > 0; i--) {

		if (isblank(input[i]) && (isalpha(input[i-1]) || ispunct(input[i-1]))){//if blank space is found and element before it was a letter or punctuation symbol
			words++;


		}//end if


	}//end for

	words++; //(count last word)

	return words;


}//end count_words
