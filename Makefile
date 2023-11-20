CC = gcc
CFLAGS = 
BUILDDIR = build

mainapp: $(BUILDDIR)/main.o $(BUILDDIR)/brainfuck.o
	$(CC) $^

$(BUILDDIR)/brainfuck.o: bf/brainfuck.c
	mkdir -p $(BUILDDIR)
	$(CC) $(CFLAGS) bf/brainfuck.c -c -o $@

$(BUILDDIR)/main.o: main.c
	mkdir -p $(BUILDDIR)
	$(CC) $(CFLAGS) main.c -c -o $@

.PHONY: clean
clean:
	rm -rf $(BUILDDIR)

.DEFAULT_GOAL = mainapp