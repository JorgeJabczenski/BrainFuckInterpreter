#include <stdio.h>
#include <stdlib.h>

#define MAXMEM  5000
#define MAXCODE 1000000
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

	int end = 0, tamCode = 0;
	char mem[MAXMEM];
	char source[MAXCODE];

	/* Joga todo o código em um vetor */
	char c;
	while((c = fgetc(program)) != EOF)
		source[tamCode++] = c;
	tamCode--; /* Ajusta para o tamanho certo */

	int i = 0;
	while(i < tamCode)
	{
		c = source[i++];

		if (c == '>') end = (end + 1) % MAXMEM;
		else if (c == '<') end = (end - 1 + MAXMEM) % MAXMEM;
		else if (c == '+') mem[end]++;
		else if (c == '-') mem[end]--;
		else if (c == '.') printf("%c", mem[end]);
		else if (c == ',') mem[end] = fgetc(stdin);
		//else if (c == '[')
		else if (c == ']')
		{
			if (mem[end] != 0)
			{
				while(source[--i] != '[');
			}
		}
	}

	return EXIT_SUCCESS;
}
