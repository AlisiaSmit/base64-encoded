char abc[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

void help() 
{
	FILE *help = fopen("help.txt", "r");
	char c;
	c = fgetc(help);
	while (!feof(help))
	{

		printf("%c", c);
		c = fgetc(help);
	}
}

#include "encoded.h"
#include "decoded.h"