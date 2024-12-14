#include "strutils.h"

#include <ctype.h>
#include <string.h>


int
str_trim(char* str, size_t strsize) {
    int start = 0;
    int end = strsize - 1;
    size_t newsize = strsize;

    // Trim leading whitespace
    while (isspace(str[start])) {
        start++;
        newsize--;
    }

    // Trim trailing whitespace
    while (end > start && isspace(str[end])) {
        end--;
        newsize--;
    }

    // Shift remaining characters to the beginning of the string
    if (start != 0 || end != strsize - 1) {
        int i;
        for (i = start; i <= end; i++) {
            str[i - start] = str[i];
        }
        str[i - start] = '\0';
    }
}

bool
str_endswith(const char* str, const char* suffix) {
    size_t len = strlen(str);
    size_t sufflen = strlen(suffix);
    if (sufflen > len) {
        return false;
    }
    return strncmp(str + len - sufflen, suffix, sufflen) == 0;
}
