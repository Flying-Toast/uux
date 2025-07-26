#include <kern/emerg.h>
#include <kern/platform.h>
#include <kern/vm.h>

extern u8 __phy_load_end[];

struct freelist_page {
	struct freelist_page *next;
} *freelist = NULL;

static void free_page(void *paddr) {
	struct freelist_page *fp = paddr;
	fp->next = freelist;
	freelist = fp;
}

static void freerange(u8 *start_paddr, usize end_paddr) {
	assert((usize)start_paddr % PAGESIZE == 0);

	while ((usize)start_paddr < end_paddr) {
		free_page(start_paddr);
		start_paddr += PAGESIZE;
	}
}

void vm_init(void) {
	freerange(__phy_load_end, PHYSTOP);
}
