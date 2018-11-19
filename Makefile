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
	mkdir -p bin && cp build/simulator bin/mips_simulator

# Dummy for build testbench to conform to spec.
# To actually build, use `make build`.
testbench:
	@>&2 echo "\033[0;1;31mThis is a dummy makefile for automated testing purposes only!\033[0m"
	@>&2 echo "\033[0;1;31mPlease use \`make build\` to build the testbench.\033[0m"
	mkdir -p bin && cp build/testbench bin/mips_testbench
