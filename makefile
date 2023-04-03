init:
	echo "Please pick a command..."

arrays1: ./arrays/arrays1.c
	gcc ./arrays/arrays1.c
	./a.out

linkedlists1: ./linkedlists/linkedlists1.c
	gcc ./linkedlists/linkedlists1.c
	./a.out

pq1: ./priorityqueues/priorityqueues1.py
	python3 ./priorityqueues/priorityqueues1.py
