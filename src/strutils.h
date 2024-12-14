#ifndef BIRD_CLIENT__STRUITLS_H
#define BIRD_CLIENT__STRUTILS_H

#include <stdbool.h>
#include <stddef.h>

int str_trim(char* str, size_t strsize);

bool str_endswith(const char* str, const char* suffix);

#endif // BIRD_CLIENT__STRUTILS_H
