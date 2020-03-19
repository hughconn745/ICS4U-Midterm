//Creator: Tahrima Rahman
//Name: count_words
//Description: returns true if there is no element in int array, false if otherwise
//Parameters: an int array to evaluate
//Dependencies: NA
//Throws: NA
//
bool is_empty(int arr[]){
    bool noElement;

    if (arr[0] == '\0' || arr[0] == -1){
        noElement = true;

    } else {
        noElement = false;

    }

    return noElement;

}// end is_empty
