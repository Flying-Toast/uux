#ifndef __KERN_PLATFORM_H
#define __KERN_PLATFORM_H

#define PLATFORM_PAGESIZE 1024

/* Physical address to start loading the kernel at.
 * Leaves room for OpenSBI firmware. */
#define PLATFORM_PHY_LOAD_START (0x80000000 + 0x200000)

/* First invalid physical address. */
#define PLATFORM_PHYSTOP (0x80000000 + 128 * 1024 * 1024)

#endif
