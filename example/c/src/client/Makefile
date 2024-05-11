WASI_SDK_PATH ?= /opt/wasi-sdk

CC = ${WASI_SDK_PATH}/bin/clang --sysroot=${WASI_SDK_PATH}/share/wasi-sysroot
CFLAGS = --target=wasm32-wasi -Wl,--import-undefined

example.wasm: main.c
	$(CC) $(CFLAGS) -o $@ $<
