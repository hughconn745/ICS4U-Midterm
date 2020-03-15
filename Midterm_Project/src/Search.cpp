//Creator: Tahrima Rahman
//Name: search
//Description: looks for *find in *input and adds each index at which "find" occurs in "input" to a pointer
//Parameters: array of chars/ a string literal
//Dependencies: compare_each, stdlib.h for strlen function
//Throws: NA
int* search(char *input, char *find, int *indexPtr){

    bool found = true; //will evaluate if find has been found in indexPtr based on whether each char is identical
    char x = 0; //keeps track of index in indexPtr
    char numStr = strlen(input);
    char numFind = strlen(find);

    for (int j = 0; j < numStr; j++){
        if (input[j] == find[0] && j + numFind < numStr){ //if letter at input is equal to the first letter of find AND if the length of find when added to the index value at input is less than the bounds of input
            found = compare_each(input, find, j, numFind); //compare each letter to validate if find has been found in input
            if (found == true); //if all letters were identical
            cout << "adding " << j << endl;
            *(indexPtr + x) = j; //add index at which find occurs to int array
            x++;
        }

    }

    *(indexPtr + x) = -1;//sentinel

    return indexPtr;

}//end search
