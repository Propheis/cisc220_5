# Deven Bernard     - 10099810
# Marissa Huang     - 10179169
# Kevin Zuern       - 10134425
# Quentin Petraroia - 10145835

universalDoubleLinkedList: udll.o linkedList.c
		gcc -g -o universalDoubleLinkedList udll.c linkedList.c

udll.o: udll.c udll.h
		gcc -g -c udll.c
