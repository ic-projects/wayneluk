build:
	-rm -rf bin
	mkdir bin
	cd bin && \
	cmake .. && \
	cmake -build . && \
	cmake --build . && \
	pyinstaller ../test/testbench.py
	cp test/testbench bin

# Dummy for build simulator to conform to spec.
# To actually build, use `make build`.
simulator:
	@>&2 echo "\033[0;1;31mThis is a dummy makefile for automated testing purposes only!\033[0m"
	@>&2 echo "\033[0;1;31mPlease use \`make build\` to build the simulator.\033[0m"
	cp bin/simulator bin/mips_simulator

# Dummy for build testbench to conform to spec.
# To actually build, use `make build`.
testbench:
	@>&2 echo "\033[0;1;31mThis is a dummy makefile for automated testing purposes only!\033[0m"
	@>&2 echo "\033[0;1;31mPlease use \`make build\` to build the testbench.\033[0m"
	cp bin/testbench bin/mips_testbench
