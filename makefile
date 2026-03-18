build-debug:
	cmake -S . -B ./build -DCMAKE_BUILD_TYPE=Debug

build-release:
	cmake -S . -B ./build -DCMAKE_BUILD_TYPE=Release

compile:
	cmake --build ./build

run: compile
	./build/DSA