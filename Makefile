build:
	-rm -rf bin
	mkdir bin
	cd bin && \
	cmake .. && \
	cmake -build . && \
	cmake --build . && \
	pyinstaller ../test/testbench.py
	cp test/mips_testbench bin

# Dummy for build simulator to conform to spec.
# To actually build, use `make build`.
simulator:
	@>&2 echo "This is a dummy makefile for automated testing purposes only!"
	@>&2 echo "Please use \`make build\` to build the simulator."
	bin/mips_simulator

# Dummy for build testbench to conform to spec.
# To actually build, use `make build`.
testbench:
	@>&2 echo "This is a dummy makefile for automated testing purposes only!"
	@>&2 echo "Please use \`make build\` to build the testbench."
