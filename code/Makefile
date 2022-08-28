.PHONY: main
main: safebox

safebox: safebox.c
	gcc $^ -O0 -s -o $@
	cp $@ ../solver/
	cp $@ ../

clean:
	rm -f safebox
	rm -f ../solver/safebox
	rm -f ../solver/flag.txt
	rm -f ../safebox