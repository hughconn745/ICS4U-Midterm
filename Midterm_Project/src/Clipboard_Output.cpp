#include <windows.h>
#include "Main.h"

/**Description: Copy's the contents of a 2-dimensional array to the clip board of the user
 *
 *Parameters:
 *	char ** array, the 2-dimensional array to copy to the clip board
 *
 *Returns:
 *	None
 */
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
