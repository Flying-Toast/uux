.POSIX:

OUTDIR = out

qemu: _kern
	@printf 'QEMU\t$(OUTDIR)/kern/kernel.elf\n'
	@qemu-system-arm \
		-machine raspi0 \
		-monitor none \
		-serial vc:80Cx24C \
		-kernel $(OUTDIR)/kern/kernel.elf \
		-S -s &
	@printf "Press Enter for debugger: "
	@read
	@lldb -o 'gdb-remote 1234' $(OUTDIR)/kern/kernel.elf

_kern:
	@cd kern && make

clean:
	@printf 'CLEAN\t$(PWD)\n'
	@rm -fr $(OUTDIR)
	@cd kern && make clean
