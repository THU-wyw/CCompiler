int ifStatement()
{
	if(x == 7)
	{
		x = 8;
	}
	else
		x = 1;
	if (x == 8)
	{
		x = 9;
	}
	else
	{
		if (x == 9) x = 10;
	}
}

int whileStatement()
{
	while (x < 10)
	{
		x *= 2;
		if (x == 6) break;
		if (x == 7) continue;
		if (x == 8) return x;
	}

	do
	{
		x *= 3;
	}while(x < 10);
}

int emptyStatement(){}