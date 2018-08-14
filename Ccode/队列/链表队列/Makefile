a.out : main.o queue_list.o
	gcc -o a.out main.o queue_list.o
main.o : queue_list_main.c queue_list.h
	gcc -c queue_list_main.c
queue_list.o : queue_list.c queue_list.h
	gcc -c queue_list.c
clean:
	rm a.out main.o queue_list.out

	