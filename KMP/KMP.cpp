#include <stdio.h>

int strlen(char s[])
{
	int i = 0;
	for (i = 0; s[i] != 0; i++);
	return i;
}

void get_next( char t[], int next[] )
{
	int tlen;
	int i = 1;
	int j = 0;
	next[0] = 0;
	next[1] = 0;
	tlen = strlen( t );
	while( i < tlen )
	{
		if( t[i] == t[j] )
		{ ++i; ++j; next[i] = j; }
		else
		{
			j = next[j];
			if( j == 0 ) /*j == 0则代表next[i + 1] = 0，即不存在k使得‘p0...pk’ = ‘pi-k...pi’*/
				next[++i] = 0;
		}
	}
}

int Index_KMP( char s[], char t[], int pos )
{
	int slen;
	int tlen;
	int i;
	int j;
	int next[100];
	if( s == NULL || t == NULL )
		return -1;
	slen = strlen( s );
	tlen = strlen( t );
	get_next( t, next );
	if( tlen > slen || pos < 0 || pos > tlen - 1 )
		return -1;
	i = pos; j = 0;
	while( i < slen && j < tlen )
	{
		if( s[i] == t[j] ) { ++i; ++j; }
		else
		{
			if( j == 0 )        /*当s[i] != t[0]时直接将i移至下一位进行比较*/
				++i;
			else
				j = next[j];
		}
	}

	if( j >= tlen )
		return i - tlen;

	else
		return 0;
}

int main()
{
	char str[100];
	char c[100];
	printf("请输入文本串：\n");
	scanf("%s", str);
	printf("请输入模式串：\n");
	scanf("%s", c);
	printf("%d\n", Index_KMP(str, c, 0));
	return 0;
}