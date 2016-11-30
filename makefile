# Deven Bernard     - 10099810
# Marissa Huang     - 10179169
# Kevin Zuern       - 10134425
# Quentin Petraroia - 10145835

universalDoubleLinkedList: udll.o main.c
		gcc -Wall -o universalDoubleLinkedList udll.c main.c

udll.o: udll.c udll.h
		gcc -Wall -c udll.c