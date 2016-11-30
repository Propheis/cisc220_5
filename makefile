# Deven Bernard     - 10099810
# Marissa Huang     - 10179169
# Kevin Zuern       - 10134425
# Quentin Petraroia - 10145835

udll.o: udll.c udll.h
		gcc -Wall -c udll.c

universalDoubleLinkedList: udll.omain.c
		gcc -Wall -o universalDoubleLinkedList udll.c main.c