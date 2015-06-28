int post_fix_expression()
{
	a[5];
	a.b;
	c->d;
	c++;
	c--;
	a(b);
	a();
}

int primary_expression()
{
	_23ideNtifIer;
	233333;
	"StringLiteral\n";
	'a';
	'\0';
	(5);
}

int unary_expression()
{
	++x;
	--y;
	&a;
	*b;
	+12;
	-23;
	~c;
	!d;
}

int binary_expression()
{
	(a) * b;
	a / (b);
	a % b;
	a + (b - c);
	a << b >> c;
	a < b;
	a >= b;
	a == b;
	a != b;
	a & b;
	a ^ b;
	a | b;
	a && b;
	a || b;
}

int assignment_expression()
{
	a = b;
	a *= b;
	a /= b;
	a %= b;
	a += b;
	a -= b;
	a <<= b;
	a >>= b;
	a &= b;
	a ^= b;
	a |= b;
}