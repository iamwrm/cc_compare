.PHONY: $(MAKECMDGOALS)

BUILD_DIR=build
SOURCE_DIR=${PWD}
CC=gcc
CXX=g++

help:
	echo "Check Makefile"

configure:
	bash ci/setup_gbench.sh

	cmake -E make_directory ${BUILD_DIR}

	#conan install ${SOURCE_DIR} --build=missing -if=${BUILD_DIR}

	cmake -S ${SOURCE_DIR} -B ${BUILD_DIR} \
		-DCMAKE_EXPORT_COMPILE_COMMANDS=1 \
		-DCMAKE_BUILD_TYPE=Debug \
		-G Ninja

	## Make clangd work	
	ln -f -s ${BUILD_DIR}/compile_commands.json \
		${SOURCE_DIR}/compile_commands.json

build:
	cmake --build ${BUILD_DIR} -j
	
run: 
	${BUILD_DIR}/et-bench

clean:
	rm -rf ${BUILD_DIR}