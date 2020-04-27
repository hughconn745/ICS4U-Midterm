#include <windows.h>
#include <iostream>
#include <string.h>
#include "Main.h"
#include "Clipboard_Output.h"
using namespace std;

void outputToClipboard(char ** array) {
    char* output = new char[ARRAY_LENGTH * (para_size - 1)];

    output[0] = '\0';
    for(int i = 0; i < para_size - 1; i++) {
    	strncat(output, array[i], ARRAY_LENGTH - 1);
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
