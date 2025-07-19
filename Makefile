.POSIX:

OUTDIR = out

qemu: _kern
	@printf 'QEMU\t$(OUTDIR)/kern/vmuux\n'
	@qemu-system-riscv64 \
		-machine virt \
		-smp 1 \
		-m 128M \
		-serial vc:80Cx24C \
		-monitor none \
		-kernel $(OUTDIR)/kern/vmuux \
		-s &
	@printf "Press Enter for debugger: "
	@read
	@lldb -o 'gdb-remote 1234' $(OUTDIR)/kern/vmuux

_kern:
	@cd kern && make

clean:
	@printf 'CLEAN\t$(PWD)\n'
	@rm -fr $(OUTDIR)
	@cd kern && make clean
