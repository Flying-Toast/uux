.POSIX:
.SUFFIXES:
.SUFFIXES: .s .ao .c .o

SHARED_HEADERS_DIR = include/shared
include ../shared.mk

OUTDIR = ../out/kern
CC = clang
CPP = clang-cpp
CFLAGS = -std=c11 -Wall -Wextra -Wpedantic -Wno-unused-command-line-argument \
	-Wno-keyword-macro --target=riscv64-unknown-none-elf -fno-builtin -fno-common \
	-nostdlib -nostdinc -ffreestanding -Iinclude

obj = \
	src/main.o \
	src/start.ao

headers = $(shared_headers) \
	include/kern/platform.h

$(OUTDIR)/vmuux: $(OUTDIR) $(obj) $(OUTDIR)/link.ld
	@printf 'LD\t$@\n'
	@$(CC) $(CFLAGS) $(obj) -o $@ -T $(OUTDIR)/link.ld

$(obj) $(OUTDIR)/link.ld: $(headers)

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
