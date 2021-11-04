LIBS=sources/file_reader.c

test:
	gcc main.c $(LIBS) -o hxe
	./hxe ls