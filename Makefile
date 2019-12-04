# Author: Zack Zeplin
# PID: 730244229
# I pledge the UNC and COMP290 Honor Code.
.PHONY: dirs run clean

objects = obj/stack.o obj/main.o
bsd = bin/stack-demo

all: $(bsd)

%/: 
	mkdir -p $@

dirs: | obj/ bin/

obj/%.o: src/%.c | obj/
	gcc -g -Wall -std=c11 -c -o $@ $<

bin/%: $(objects) | bin/ $(objects)
	gcc -g -Wall -std=c11 -o $@ $^

run: | $(bsd)
	./$(bsd)

clean:
	rm -rf obj/ bin/
