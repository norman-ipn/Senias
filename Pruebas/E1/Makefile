run: a.out
	./a.out airplane.jpg

a.out: ejemplo1.c
	 gcc ejemplo1.c `pkg-config opencv --cflags --libs`

clean:
	rm a.out
