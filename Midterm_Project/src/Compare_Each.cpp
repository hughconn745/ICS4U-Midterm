//Creator: Tahrima Rahman
//Name: compare_each
//Description: compares two strings char by char for the length of ref and returns whether strings are identical within the frame of reference specified (from start->end)
//Parameters: char array that is being compared by a reference array, the reference array in question, an int for where in the first char array comparison will start, an int for number of chars comparison will go on for
//Dependencies: NA
//Throws: NA

bool compare_each(char *arr, char *ref, int start, int last){
    bool found = true;

    for (int p = 0; p < last; p++){
         //cout << "found a potential match" << endl;
        if (arr[start+p] != ref[p]){
              //cout << "inside inner most if statement of compare_each" << endl;
              found = false;
              break;
        }

    }

    return found;

}//end compare_each
