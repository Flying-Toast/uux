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

static void *alloc_page_aligned(usize alignment) {
	assert(alignment % PAGESIZE == 0);

	struct freelist_page *i = freelist;
	struct freelist_page **prevnext = &freelist;

	for (; i; prevnext = &i->next, i = i->next) {
		if ((usize)i % alignment == 0) {
			*prevnext = i->next;
			return i;
		}
	}

	panic(STR("failed to allocate aligned page"));
}

void vm_init(void) {
	freerange(__phy_load_end, PHYSTOP);
        /*
        Before the MMU is enabled all relevant CP15 registers must be
        programmed. This includes setting up suitable translation tables in
        memory. Prior to enabling the MMU, the instruction cache should be
        disabled and invalidated. The instruction cache can then be re-enabled
        at the same time as the MMU is enabled.

        Prior to VMSAv6, a single TTBR existed. Only bits[31:14] of the
        Translation Table Base Register are significant, and bits[13:0] should
        be zero. Therefore, the first-level page table must reside on a 16KB
        boundary.
        */
	void *_________________ = alloc_page_aligned(1024 * 16);
        // TODO: Turn on high vectors at the same time we turn
	// TODO: on virtual memory, and map physical page 0 to
	// TODO: the high vectors location.
}
