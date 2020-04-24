#include <stdio.h> //scanf, fflush, etc.
#include <iostream>
#include "Main.h"
#include "Array_Resize.h"
#include "Replace.h"
#include "Clipboard_Output.h"

using namespace std;

int para_size = 1;
int ARRAY_LENGTH = 30;
char ** array = new char*[para_size + 1];

int main() {
	array[0] = new char[30];
	array[1] = new char[30];

	cout << "Please input your paragraph, type end when done." << endl;

	fflush(stdout);



	int k = 0;




while(k < 5) {

	if(fgets(array[k], 28, stdin) == NULL) {
		return 1;
	}

	if(k == para_size - 1)
		growArray(para_size + 1);

	k++;
	para_size++;

	cout << k << " : " << para_size << endl;
}

	cout << "Printing Paragraph contents" << endl;

	for(int j = 0; j < k; j++)
		fputs(array[j], stdout);

	outputToClipboard(array);

	return 0;


}
