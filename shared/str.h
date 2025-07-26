#ifndef __SHARED_STR_H
#define __SHARED_STR_H

#include "types.h"

#define STR(LIT) (str_t){ .ptr = ""LIT"", .len = sizeof(LIT) - 1 }

typedef struct {
	const char *ptr;
	usize len;
} str_t;

#endif
