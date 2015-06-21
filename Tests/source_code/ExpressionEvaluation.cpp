#define true 1 
#define false 0 
#define OPSETSIZE 8 
#define MAXSIZE 100
typedef int Status; 
unsigned char Prior[8][8] =
{ // ��������ȼ��� 
 // '+' '-' '*' '/' '(' ')' '#' '^' 
 /*'+'*/'>','>','<','<','<','>','>','<', 
 /*'-'*/'>','>','<','<','<','>','>','<', 
 /*'*'*/'>','>','>','>','<','>','>','<', 
 /*'/'*/'>','>','>','>','<','>','>','<', 
 /*'('*/'<','<','<','<','<','=',' ','<', 
 /*')'*/'>','>','>','>',' ','>','>','>', 
 /*'#'*/'<','<','<','<','<',' ','=','<', 
 /*'^'*/'>','>','>','>','<','>','>','>' 
}; 
typedef struct StackChar
{
	char c; 
	struct StackChar *next; 
}SC;       //StackChar���͵Ľ��SC

typedef struct StackFloat
{
	float f; 
	struct StackFloat *next; 
}SF;       //StackFloat���͵Ľ��SF

SC *Push(SC *s,char c)          //SC���͵�ָ��Push������p
{
	SC *p=(SC*)malloc(sizeof(SC)); 
	p->c=c; 
	p->next=s; 
	return p; 
} 

SF *Push(SF *s,float f)        //SF���͵�ָ��Push������p
{
	SF *p=(SF*)malloc(sizeof(SF)); 
	p->f=f; 
	p->next=s; 
	return p; 
} 

SC *Pop(SC *s)    //SC���͵�ָ��Pop
{
	SC *q=s; 
	s=s->next; 
	free(q); 
	return s; 
} 

SF *Pop(SF *s)      //SF���͵�ָ��Pop
{
	SF *q=s; 
	s=s->next; 
	free(q); 
	return s; 
} 

char* strcat(char* str1, char* str2)
{
	if(str1 == NULL && str2 == NULL)
		return NULL;

	int i = 0;
	int j = 0;
	while (str1[i] != '\0')
	{
		i++;
	}
	while(str2[j] != '\0')
	{
		str1[i++] = str2[j++];
	}
	str1[i] = '\0';

	return str1;
}

char* strcpy(char* dest, char* source)
{
	int i = 0;
	while(true)
	{
		dest[i] = source[i];
		if(source[i] == '\0') break;
		i++;
	}
	return dest;
}


float Operate(float a,unsigned char theta, float b)      //���㺯��Operate
{
	switch(theta)
	{
		case '+': return a+b; 
		case '-': return a-b; 
		case '*': return a*b; 
		case '/': return a/b; 
		//case '^': return pow(a,b); 
		default : return 0; 
	} 
} 

char OPSET[OPSETSIZE]={'+','-','*','/','(',')','#','^'}; 

Status In(char Test,char *TestOp)
{
	int Find=false; 
	for (int i=0; i< OPSETSIZE; i++)
	{
		if(Test == TestOp[i])
		Find= true; 
	} 
	return Find; 
} 

Status ReturnOpOrd(char op,char *TestOp)
{ 
	for(int i=0; i< OPSETSIZE; i++)
	{
		if (op == TestOp[i])
			return i;
	}
}

char precede(char Aop, char Bop)
{ 
	return Prior[ReturnOpOrd(Aop,OPSET)][ReturnOpOrd(Bop,OPSET)]; 
} 

float EvaluateExpression(char* MyExpression)
{ 
	// �������ʽ��ֵ����������㷨
	// ��OPTR��OPND�ֱ�Ϊ�����ջ��������ջ��OPΪ��������� 
	SC *OPTR=NULL;       // �����ջ���ַ�Ԫ�� 
	SF *OPND=NULL;       // ������ջ��ʵ��Ԫ�� 
	char TempData[20]; 
	float Data,a,b; 
	char theta,*c,Dr[]={'#','\0'}; 
	OPTR=Push(OPTR,'#'); 
	c=strcat(MyExpression,Dr); 
	strcpy(TempData,"\0");//�ַ����������� 
	while (*c!= '#' || OPTR->c!='#')
	{ 
		if (!In(*c, OPSET))
		{ 
			Dr[0]=*c; 
			strcat(TempData,Dr);           //�ַ������Ӻ��� 
			c++; 
			if (In(*c, OPSET))
			{ 
				Data=atof(TempData);       //�ַ���ת������(double) 
				OPND=Push(OPND, Data); 
				strcpy(TempData,"\0"); 
			} 
		} 
		else    // ������������ջ 
		{
			switch (precede(OPTR->c, *c))
			{
				case '<': // ջ��Ԫ�����ȼ��� 
					OPTR=Push(OPTR, *c); 
					c++; 
					break; 
				case '=': // �����Ų�������һ�ַ� 
					OPTR=Pop(OPTR); 
					c++; 
					break; 
				case '>': // ��ջ������������ջ 
					theta=OPTR->c;OPTR=Pop(OPTR); 
					b=OPND->f;OPND=Pop(OPND); 
					a=OPND->f;OPND=Pop(OPND); 
					OPND=Push(OPND, Operate(a, theta, b)); 
					break; 
			} //switch
		} 
	} //while 
	return OPND->f; 
} //EvaluateExpression 

int main(void)
{ 
	char s[]="1+(3*4)/(2-1)\0";
	printf("%g\n",EvaluateExpression(s));

	return 0;
}