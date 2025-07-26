.section .entry, "ax"
.globl start
start:
	// TODO: Turn on high vectors at the same time we turn
	// TODO: on virtual memory, and map physical page 0 to
	// TODO: the high vectors location.
	// Install exception vector table at 0x00000000
	mov r0, #0
	adr r1, __start_vectors
0:
	ldr r2, [r1, +r0]
	str r2, [r0], #4
	cmp r0, #(__end_vectors - __start_vectors)
	blt 0b

	adr sp, bootstrap_stack
	b main

__start_vectors:
// 0x00000000: reset
	0: b 0b // TODO
// 0x00000004: undefined instruction
	0: b 0b // TODO
// 0x00000008: software interrupt (SWI)
	0: b 0b // TODO
// 0x0000000C: prefetch abort (instruction fetch memory abort)
	0: b 0b // TODO
// 0x00000010: data abort (data access memory abort)
	0: b 0b // TODO
	nop
// 0x00000018: IRQ
	0: b 0b // TODO
// 0x0000001C: FIQ
	0: b 0b // TODO
__end_vectors:
