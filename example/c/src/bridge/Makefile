example.h example.c: ../../example.bridgesupport
	swift run W2C2BridgeGeneratorCommand ../../example.bridgesupport \
		--c-interface example.h \
		--w2c2-implementation example.c \
		--big-endian

.PHONY: clean
clean:
	rm -f example.h example.c
