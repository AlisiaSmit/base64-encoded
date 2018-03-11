void decoded(FILE *in, FILE *out)
{
	unsigned char sym[1];
	unsigned short i = 0;
	unsigned int value = 0, a = 0, b = 0;

	fread(sym, 1, 1, in);
	a = searchInBase(sym[0]);
	if (a = 65)
	{
		fprintf("%s", "Error: file contains non-base64 characters");
		help();
		return;
	}
	if (!feof(in))
		fread(sym, 1, 1, in);

	
	while (!feof(in))
	{
		b = searchInBase(sym[0]);
		if (b = 65)
		{
			fprintf("%s", "Error: file contains non-base64 characters");
			help();
			return;
		}
		if (b == 64) break;
		
		i++;

		switch (i % 3)
		{
		case 1:
			value = (a << 2) | ((b >> 4) & 3);
			fprintf(out, "%c", value);
			break;
		case 2:
			value = ((a & 15) << 4) | ((b >> 2) & 15);
			fprintf(out, "%c", value);
			break;
		case 0:
			value = ((a & 3) << 6) | b;
			fprintf(out, "%c", value);
			i = 0;
			fread(sym, 1, 1, in);
			b = searchInBase(sym[0]);
			if (a = 65)
			{
				fprintf("%s", "Error: file contains non-base64 characters");
				help();
				return;
			}
			break;
		}
		a = b;
		fread(sym, 1, 1, in);
	}
	if (i % 3 == 2)
	{
		value = ((a & 15) << 4);
		fprintf(out, "%c", value);
	}
	if (i % 3 == 1)
	{
		value = ((a & 3) << 6);
		fprintf(out, "%c", value);
	}
}


void decoded_i(FILE *in, FILE *out)
{
	unsigned char sym[1];
	unsigned short i = 0;
	unsigned int value = 0, a = 0, b = 0;

	fread(sym, 1, 1, in);
	a = searchInBase(sym[0]);
	if (!feof(in))
		fread(sym, 1, 1, in);


	while (!feof(in))
	{
		b = searchInBase(sym[0]);
		if (b == 64) break;

		i++;

		switch (i % 3)
		{
		case 1:
			value = (a << 2) | ((b >> 4) & 3);
			fprintf(out, "%c", value);
			break;
		case 2:
			value = ((a & 15) << 4) | ((b >> 2) & 15);
			fprintf(out, "%c", value);
			break;
		case 0:
			value = ((a & 3) << 6) | b;
			fprintf(out, "%c", value);
			i = 0;
			fread(sym, 1, 1, in);
			b = searchInBase(sym[0]);
			break;
		}
		a = b;
		fread(sym, 1, 1, in);
	}
	if (i % 3 == 2)
	{
		value = ((a & 15) << 4);
		fprintf(out, "%c", value);
	}
	if (i % 3 == 1)
	{
		value = ((a & 3) << 6);
		fprintf(out, "%c", value);
	}
}

int searchInBase(unsigned char c)
{
	unsigned int i = 0;
	if (c == '=') return 64;
	for (i; i < 64; i++)
		if (c == abc[i]) return i;
	return 65;
}