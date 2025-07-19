#include <kern/platform.h>
#include <shared/types.h>

/* kernel stack of process 1 */
_Alignas(16) u8 kstack1[PLATFORM_PAGESIZE];

_Noreturn void main(void) {
	for (;;) ;
}
