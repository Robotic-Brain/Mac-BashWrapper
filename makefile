
CC = gcc -O3
RM = rm -rfv
MKDIR = mkdir -pv

BUILD_DIR = ./build


all: copyTemplate
	${CC} main.c -o ${BUILD_DIR}/Wrap.app/Contents/MacOS/stub

copyTemplate: prepare
	cp -R Wrap.app ${BUILD_DIR}/Wrap.app

prepare:
	${MKDIR} ${BUILD_DIR}

clean:
	${RM} ${BUILD_DIR}