//Creator: Tahrima Rahman
//Name: add_null
//Description: add null terminator to user input retrieved from fgets
//Parameters: array of chars/ a string literal
//Dependencies: NA
//Throws: NA
char* add_null(char *s){
      for (int i = 0; s[i] != 0; i++){
        //cout << "add_null's for-loop is working" << endl;
        if (s[i] == '\n'){
            //cout << "inside add_null's if statement << endl;
            s[i] = 0;
            break;
        }


    return s;
    }

}//end add_null
