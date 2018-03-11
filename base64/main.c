#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#include "header.h"

int main(int argc, char* argv[])
{
	FILE *in, *out;

	if (!strcmp(argv[1], "-e"))
	{
		if (!strcmp(argv[2], "-f"))
		{
			int divider; 
			divider = atoi(argv[3]);
			if (divider <= 0)
			{
				help();
				return 0;
			}
			in = fopen(argv[4], "rb");
			if (verification(in)) return 0;
			out = fopen(argv[5], "w");
			encoded_f(in, out, divider);
			fclose(in);
			fclose(out);
			return 0;
		}
		in = fopen(argv[2], "rb");
		if (verification(in)) return 0;
		out = fopen(argv[3], "w+");
		encoded(in, out);
		fclose(in);
		fclose(out);
		return 0;
	}

	if (!strcmp(argv[1], "-d"))
	{
		if (!strcmp(argv[2], "-i"))
		{
			in = fopen(argv[3], "r");
			if (verification(in)) return 0;
			out = fopen(argv[4], "w+b");
			decoded_i(in, out);
			fclose(in);
			fclose(out);
			return 0;
		}
		in = fopen(argv[2], "r");
		if (verification(in)) return 0;
		out = fopen(argv[3], "w+b");
		decoded(in, out);
		fclose(in);
		fclose(out);
		return 0;
	}

	help();
	return 0;
}



int verification(FILE *in)
{
	if (in == NULL)
	{
		printf("%s", "Error: file not found");
		fclose(in);
		help();
		return 1;
	}
	return 0;
}