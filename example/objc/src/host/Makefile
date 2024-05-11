W2C2_DIR ?=
W2C2 ?= $(W2C2_DIR)/w2c2/w2c2
LDFLAGS = $(W2C2_DIR)/wasi/libw2c2wasi.a -lm -lobjc
CFLAGS = -m32 -I$(W2C2_DIR)/w2c2 -I$(W2C2_DIR)/wasi

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

%.o: %.m
	$(CC) $(CFLAGS) -c -o $@ $<

example: example.o main.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

example.c: ../client/example.wasm
	$(W2C2) $< $@

.PHONY: clean
clean:
	rm -f *.o example example.c example.h
