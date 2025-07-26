#ifndef __KERN_PLATFORM_H
#define __KERN_PLATFORM_H
/*
 * Platform defs for BCM2835 (Raspberry Pi Zero).
 */

#define PAGESIZE (4096)

/* The Raspberry Pi bootloader defaults to loading at 0x8000 to leave
 * room for exception vectors and ATAGS. But it can be changed, see:
 * https://www.raspberrypi.com/documentation/computers/legacy_config_txt.html#kernel_address
 * and https://www.raspberrypi.com/documentation/computers/legacy_config_txt.html#disable_commandline_tags */
#define LOAD_START (PAGESIZE)

/* First invalid physical address. */
#define PHYSTOP (512 * 1024 * 1024)

#endif
