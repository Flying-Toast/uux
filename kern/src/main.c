#include <kern/platform.h>
#include <kern/vm.h>
#include <shared/types.h>

_Alignas(sizeof(usize) * 2) char bootstrap_stack[PAGESIZE];

_Noreturn void main(void) {
	vm_init();

	for (;;)
		;
}
