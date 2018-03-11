void encoded(FILE *in, FILE *out)
{
	unsigned char sym[1], befor;
	unsigned short i = 0;
	unsigned int value = 0;

	fread(sym, 1, 1, in);

	while (!feof(in))
	{
		i++;

		switch (i % 3)
		{
		case 1:
			value = sym[0] >> 2;
			fprintf(out, "%c", abc[value]);
			break;
		case 2:
			value = (sym[0] >> 4) | ((befor & 3) << 4);
			fprintf(out, "%c", abc[value]);
			break;
		case 0:
			value = ((befor & 15) << 2) | (sym[0] >> 6);
			fprintf(out, "%c", abc[value]);

			value = (sym[0] & 63);
			fprintf(out, "%c", abc[value]);
			i = 0;
			break;
		}
		befor = sym[0];
		fread(sym, 1, 1, in);
	}
	sym[0] = 0;

	if ((i % 3) == 1)
	{
		value = (sym[0] >> 4) | ((befor & 3) << 4);
		fprintf(out, "%c", abc[value]);
		fprintf(out, "%c", '=');
		fprintf(out, "%c", '=');
	}
	if ((i % 3) == 2)
	{
		value = ((befor & 15) << 2) | (sym[0] >> 6);
		fprintf(out, "%c", abc[value]);
		fprintf(out, "%c", '=');
	}
}

void encoded_f(FILE *in, FILE *out, int num)
{
	unsigned char sym[1], befor;
	unsigned short i = 0;
	unsigned int value = 0;
	unsigned int k = 0;

	fread(sym, 1, 1, in);

	while (!feof(in))
	{
		i++; k++;

		if (k == num)
		{
			fprintf(out, "%c", '\n');
			k = 0;
		}

		switch (i % 3)
		{
		case 1:
			value = sym[0] >> 2;
			fprintf(out, "%c", abc[value]);
			break;
		case 2:
			value = (sym[0] >> 4) | ((befor & 3) << 4);
			fprintf(out, "%c", abc[value]);
			break;
		case 0:
			value = ((befor & 15) << 2) | (sym[0] >> 6);
			fprintf(out, "%c", abc[value]);
			
			k++;
			if (k == num)
			{
				fprintf(out, "%c", '\n');
				k = 0;
			}

			value = (sym[0] & 63);
			fprintf(out, "%c", abc[value]);
			i = 0;
			break;
		}
		befor = sym[0];
		fread(sym, 1, 1, in);
	}
	sym[0] = 0;
	//возможно, здесь еще где-то должна быть проверка на к
	if ((i % 3) == 1)
	{
		value = (sym[0] >> 4) | ((befor & 3) << 4);
		fprintf(out, "%c", abc[value]);
		k++;

		if (k == num)
		{
			fprintf(out, "%c", '\n');
			k = 0;
		}
		fprintf(out, "%c", '=');
		k++;

		if (k == num)
		{
			fprintf(out, "%c", '\n');
			k = 0;
		}
		fprintf(out, "%c", '=');
	}
	if ((i % 3) == 2)
	{
		value = ((befor & 15) << 2) | (sym[0] >> 6);
		fprintf(out, "%c", abc[value]);
		k++;

		if (k == num)
		{
			fprintf(out, "%c", '\n');
			k = 0;
		}fprintf(out, "%c", '=');
	}
}