#include <kern/emerg.h>

_Noreturn void panic(str_t msg) {
	for(;;)(void)msg;
}
