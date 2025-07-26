#ifndef __KERN_EMERG_H
#define __KERN_EMERG_H

#include <shared/str.h>

#define __assert_stringify2(X) #X
#define __assert_stringify(X) __assert_stringify2(X)
#define assert(COND) \
	do { \
		if (!(COND)) \
			panic(STR("[" __FILE__ ":" __assert_stringify(__LINE__) "] assertion `" #COND "` failed")); \
	} while (0)

_Noreturn void panic(str_t msg);

#endif
