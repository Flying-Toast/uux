.section .text
.globl start
start:
	la sp, kstack1
	j main
	unimp
