char Prior[8][8] =
{ // 运算符优先级表 
 // '+' '-' '*' '/' '(' ')' '#' '^' 
 /*'+'*/{'>','>','<','<','<','>','>','<'},
 /*'-'*/{'>','>','<','<','<','>','>','<'}, 
 /*'*'*/{'>','>','>','>','<','>','>','<'}, 
 /*'/'*/{'>','>','>','>','<','>','>','<'}, 
 /*'('*/{'<','<','<','<','<','=',' ','<'}, 
 /*')'*/{'>','>','>','>',' ','>','>','>'}, 
 /*'#'*/{'<','<','<','<','<',' ','=','<'}, 
 /*'^'*/{'>','>','>','>','<','>','>','>'} 
}; 

double atof_(char str[])
{
	double result = 0;
	int flag = 0;
	int n = 1;
	double temp = 0;
	for(int i = 0; str[i] != '\0'; i++)
	{
		if(str[i] == '.')
		{
			flag = 1;
			continue;
		}
		if(flag == 0)
			result = result * 10 + str[i] - '0';
		else
		{
			temp = str[i] - '0';
			for(int j = 0; j < n; j++)
				temp /= 10;
			result += temp;
		}
	}
	return result;
}

int PushChar(char s[], char c, int top)
{
	s[top] = c;
	return (top+1);
}

int PushNum(double s[], double x, int top)
{
	s[top] = x;
	return (top+1);
}

int PopChar(char s[], int top)
{
	return (top-1);
}

int PopNum(double s[], int top)
{
	return (top-1);
}

void strcat(char str1[], char str2[], char result[])
{
	int i = 0;
	int j = 0;
	while (str1[i] != '\0')
	{
		result[i] = str1[i];
		i++;
	}
	while(str2[j] != '\0')
	{
		result[i] = str2[j];
		str1[i++] = str2[j++];
	}
	result[i] = '\0';
	str1[i] = '\0';
}

void strcpy(char dest[], char source[], char result[])
{
	int i = 0;
	while (source[i] != 0) {
		dest[i] = source[i];
		result[i] = source[i];
		i++;
	}
	dest[i] = source[i];
	result[i] = source[i];
}


double Operate(double a, char theta, double b)      //计算函数Operate
{
	if (theta == '+')
	{
		return a+b;
	}
	else if (theta == '-')
	{
		return a-b;
	}
	else if (theta == '*')
	{
		return a*b;
	}
	else if (theta == '/')
	{
		return a/b;
	}
	else
	{
		return 0;
	}/*
	switch(theta)
	{
		case '+': return a+b; 
		case '-': return a-b; 
		case '*': return a*b; 
		case '/': return a/b; 
		//case '^': return pow(a,b); 
		default : return 0; 
	} */
} 

char OPSET[8]={'+','-','*','/','(',')','#','^'}; 

int In(char Test,char TestOp[])
{
	int Find = 0; 
	for (int i=0; i< 8; i++)
	{
		if(Test == TestOp[i])
		Find= 1; 
	} 
	return Find; 
} 

int ReturnOpOrd(char op,char TestOp[])
{ 
	int Find = 0;
	for(int i = 0; i < 8; i++)
	{
		if (op == TestOp[i])
			Find = i;
	}
	return Find;
}

char precede(char Aop, char Bop)
{ 
	return Prior[ReturnOpOrd(Aop,OPSET)][ReturnOpOrd(Bop,OPSET)]; 
} 

double EvaluateExpression(char MyExpression[])
{ 
	// 算术表达式求值的算符优先算法
	// 设OPTR和OPND分别为运算符栈和运算数栈，OP为运算符集合 
	int optr_top = 0;
	int opnd_top = 0;
	char OPTR[100] = {0};		// 运算符栈，字符元素
	double OPND[100] = {0};	// 运算数栈，实数元素 
	char TempData[20]; 
	double Data; 
	double a;
	double b;
	char theta;
	char c[100];
	char TempC[100];
	char Dr[]={'#','\0'}; 
	optr_top = PushChar(OPTR,'#',optr_top); 
	strcat(MyExpression, Dr, c); 
	strcpy(TempData,"\0",TempC);//字符串拷贝函数 
	int temp = 0;
	while (c[temp] != '#' || OPTR[optr_top-1] != '#')
	{ 
		if (In(c[temp], OPSET) == 0)
		{ 
			Dr[0]=c[temp]; 
			strcat(TempData,Dr,TempC);           //字符串连接函数 
			temp++; 
			if (In(c[temp], OPSET) == 1)
			{ 
				Data = atof_(TempData);       //字符串转换函数(double) 
				opnd_top = PushNum(OPND, Data, opnd_top); 
				strcpy(TempData,"\0",TempC); 
			} 
		} 
		else    // 不是运算符则进栈 
		{
			char preTemp = precede(OPTR[optr_top - 1], c[temp]);
			if (preTemp == '<')
			{
				optr_top = PushChar(OPTR, c[temp], optr_top);
				temp++; 
			}
			else if (preTemp == '=')
			{
				optr_top = PopChar(OPTR, optr_top);
				temp++;
			}
			else if (preTemp == '>')
			{
				theta = OPTR[optr_top-1];
				optr_top = PopChar(OPTR, optr_top);
				b = OPND[opnd_top-1];
				opnd_top = PopNum(OPND, opnd_top);
				a = OPND[opnd_top-1];
				opnd_top = PopNum(OPND, opnd_top);
				opnd_top = PushNum(OPND, Operate(a, theta, b), opnd_top);
			}
			else
			{
				
			}
		} 
	} //while 
	return OPND[opnd_top-1]; 
} //EvaluateExpression 

int main()
{ 
	char s[]="13.7*5.2+2/5\0";
	printf("%g\n",EvaluateExpression(s));

	return 0;
}