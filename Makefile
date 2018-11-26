.PHONY: build build/simulator build/testbench simulator testbench

build:
	-rm -rf build
	mkdir build
	make build/simulator
	make build/testbench

build/simulator:
	cd build && \
	cmake -DCMAKE_BUILD_TYPE=Release .. && \
	cmake --build .

build/testbench:
	cd build && \
	pyinstaller ../test/testbench.py
	cp test/testbench build

# Dummy for build simulator to conform to spec.
# To actually build, use `make build`.
simulator:
	@>&2 echo "\033[0;1;31mThis is a dummy makefile for automated testing purposes only!\033[0m"
	@>&2 echo "\033[0;1;31mPlease use \`make build\` to build the simulator.\033[0m"
	@mkdir -p bin && cp build/simulator bin/mips_simulator

# Dummy for build testbench to conform to spec.
# To actually build, use `make build`.
testbench:
	@>&2 echo "\033[0;1;31mThis is a dummy makefile for automated testing purposes only!\033[0m"
	@>&2 echo "\033[0;1;31mPlease use \`make build\` to build the testbench.\033[0m"
	@mkdir -p bin && cp build/testbench bin/mips_testbench

########################################################################################################################

SRCDIR = test/src
OBJDIR = test/bin
ELFDIR = test/bin
BINDIR = test/bin
ASMDIR = test/bin

# For MIPS binaries. Turn on all warnings, enable all optimisations and link everything statically
MIPS_CC = mips-linux-gnu-gcc
MIPS_OBJCOPY = mips-linux-gnu-objcopy
MIPS_OBJDUMP = mips-linux-gnu-objdump
MIPS_CPPFLAGS = -W -Wall -fno-builtin -march=mips1 -mfp32 -fno-stack-protector
MIPS_LDFLAGS = -nostdlib -Wl,-melf32btsmip -march=mips1 -nostartfiles -mno-check-zero-division -Wl,--gpsize=0 -static -Wl,-Bstatic -Wl,--build-id=none

OUTDIR = @mkdir -p $(@D)

# Compile C file (.c) or MIPS assembly file (.s) into MIPS object file (.o)
$(OBJDIR)/%.mips.o: $(SRCDIR)/%.c
	$(OUTDIR)
	$(MIPS_CC) $(MIPS_CPPFLAGS) -c $< -o $@

$(OBJDIR)/%.mips.o: $(SRCDIR)/%.s
	$(OUTDIR)
	$(MIPS_CC) $(MIPS_CPPFLAGS) -c $< -o $@

# Link MIPS object file (.o), producing .elf, using memory locations specified in spec
$(ELFDIR)/%.mips.elf: $(OBJDIR)/%.mips.o
	$(OUTDIR)
	$(MIPS_CC) $(MIPS_CPPFLAGS) $(MIPS_LDFLAGS) -T linker.ld $< -o $@

# Extract binary instructions only from linked object file (.elf)
$(BINDIR)/%.mips.bin: $(ELFDIR)/%.mips.elf
	$(OUTDIR)
	$(MIPS_OBJCOPY) -O binary --only-section=.text $< $@

# Disassemble linked object file (.elf), pulling out instructions as MIPS assembly file (.s)
$(ASMDIR)/%.mips.asm: $(ELFDIR)/%.mips.elf
	$(OUTDIR)
	$(MIPS_OBJDUMP) -j .text -D $< > $@
