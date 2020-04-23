#include <windows.h>
#include <iostream>
#include <string.h>
#include "Main.h"

using namespace std;

void outputToClipboard(char ** array) {
    char* output = new char[ARRAY_LENGTH * para_size];

    cout << output << endl;

    for(int i = 0; i < para_size; i++) {
    	strncat(output, array[i], ARRAY_LENGTH);
    	//cout << output << endl;
    }

    const size_t len = strlen(output) + 1;
    HGLOBAL hMem =  GlobalAlloc(GMEM_MOVEABLE, len);
    memcpy(GlobalLock(hMem), output, len);
    GlobalUnlock(hMem);
    OpenClipboard(0);
    EmptyClipboard();
    SetClipboardData(CF_TEXT, hMem);
    CloseClipboard();

}
