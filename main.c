#include <stdio.h>
#include <stdlib.h>

#define MAXMEM 5000

int 
main(int argc, char **argv)
{

	FILE *program;

	/* Confere os argumentos */
	if (argc != 2)
	{
		fprintf(stderr,"Usage: ./bf file");
		exit(EXIT_FAILURE);
	}

	/* Abre o arquivo do programa */
	program = fopen(argv[1], "r");
	if (!program)
	{
		fprintf(stderr, "Can't open program file");
		exit(EXIT_FAILURE);
	}

	int end = 0;
	char mem[MAXMEM];

	char c;
	while((c = fgetc(program)) != EOF)
	{
		if (c == '>') end = (end + 1) % MAXMEM;
		else if (c == '<') end = (end - 1 + MAXMEM) % MAXMEM;
		else if (c == '+') mem[end]++;
		else if (c == '-') mem[end]--;
		else if (c == '.') printf("%c", mem[end]);
		else if (c == ',') mem[end] = fgetc(stdin);

	}

	return EXIT_SUCCESS;
}
