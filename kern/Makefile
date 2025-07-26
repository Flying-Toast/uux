.POSIX:
.SUFFIXES:
.SUFFIXES: .s .ao .c .o

SHARED_HEADERS_DIR = include/shared
include ../shared.mk

OUTDIR = ../out/kern
CC = clang
CPP = clang-cpp
CFLAGS = --target=arm-unknown-none-eabi -mcpu=arm1176jzf-s -mabi=aapcs \
	-ffreestanding -nostdlib -nostdinc -fno-builtin -fno-common \
	-Iinclude -std=c11 -Wall -Wextra -Wpedantic \
	-Wno-unused-command-line-argument -g

obj = \
	src/emerg.o \
	src/main.o \
	src/start.ao \
	src/vm.o

headers = $(shared_headers) \
	include/kern/emerg.h \
	include/kern/vm.h

$(OUTDIR)/kernel.img: $(OUTDIR)/kernel.elf
	@printf 'OBJCOPY\t$@\n'
	@llvm-objcopy -O binary $(OUTDIR)/kernel.elf $@

$(obj) $(OUTDIR)/link.ld: $(headers)

$(OUTDIR)/kernel.elf: $(OUTDIR) $(obj) $(OUTDIR)/link.ld
	@printf 'LD\t$@\n'
	@$(CC) $(CFLAGS) $(obj) -o $@ -T $(OUTDIR)/link.ld

$(OUTDIR)/link.ld: $(OUTDIR) link.ld.in
	@printf 'CPP\t$@\n'
	@$(CPP) $(CFLAGS) -P link.ld.in >'$@'

$(OUTDIR):
	@mkdir -p $(OUTDIR)

.s.ao:
	@printf 'AS\t$@\n'
	@$(CC) $(CFLAGS) -c $< -o $*.ao

.c.o:
	@printf 'CC\t$@\n'
	@$(CC) $(CFLAGS) -c $< -o $*.o

clean:
	@printf 'CLEAN\t$(PWD)\n'
	@rm -f src/*.o src/*.ao
