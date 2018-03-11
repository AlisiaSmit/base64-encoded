char abc[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

#include "encoded.h"
#include "decoded.h"


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