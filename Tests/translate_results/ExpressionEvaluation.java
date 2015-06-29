import java.io.IOException;

public class ExpressionEvaluation{
    public static byte[][] Prior = {{(byte)'>', (byte)'>', (byte)'<', (byte)'<', (byte)'<', (byte)'>', (byte)'>', (byte)'<'}, {(byte)'>', (byte)'>', (byte)'<', (byte)'<', (byte)'<', (byte)'>', (byte)'>', (byte)'<'}, {(byte)'>', (byte)'>', (byte)'>', (byte)'>', (byte)'<', (byte)'>', (byte)'>', (byte)'<'}, {(byte)'>', (byte)'>', (byte)'>', (byte)'>', (byte)'<', (byte)'>', (byte)'>', (byte)'<'}, {(byte)'<', (byte)'<', (byte)'<', (byte)'<', (byte)'<', (byte)'=', (byte)' ', (byte)'<'}, {(byte)'>', (byte)'>', (byte)'>', (byte)'>', (byte)' ', (byte)'>', (byte)'>', (byte)'>'}, {(byte)'<', (byte)'<', (byte)'<', (byte)'<', (byte)'<', (byte)' ', (byte)'=', (byte)'<'}, {(byte)'>', (byte)'>', (byte)'>', (byte)'>', (byte)'<', (byte)'>', (byte)'>', (byte)'>'}};

    public static float atof_(byte[] str) throws IOException
    {
        float result = 0;
        int flag = 0;
        int n = 1;
        float temp = 0;
        for (int i = 0; str[i] != (byte)0; (i)++)
        {
            if (str[i] == (byte)'.')
            {
                flag = 1;
                continue;
            }
            if (flag == 0)
                result = result * 10 + str[i] - (byte)'0';
            else
            {
                temp = str[i] - (byte)'0';
                for (int j = 0; j < n; (j)++)
                    temp /= 10;
                result += temp;
                (n)++;
            }
        }
        return result;
    }

    public static int PushChar(byte[] s, byte c, int top) throws IOException
    {
        s[top] = c;
        return top + 1;
    }

    public static int PushNum(float[] s, float x, int top) throws IOException
    {
        s[top] = x;
        return top + 1;
    }

    public static int PopChar(byte[] s, int top) throws IOException
    {
        return top - 1;
    }

    public static int PopNum(float[] s, int top) throws IOException
    {
        return top - 1;
    }

    public static void strcat(byte[] str1, byte[] str2, byte[] result) throws IOException
    {
        int i = 0;
        int j = 0;
        while (str1[i] != (byte)0)
        {
            result[i] = str1[i];
            (i)++;
        }
        while (str2[j] != (byte)0)
        {
            result[i] = str2[j];
            str1[(i)++] = str2[(j)++];
        }
        result[i] = (byte)0;
        str1[i] = (byte)0;
    }

    public static void strcpy(byte[] dest, byte[] source, byte[] result) throws IOException
    {
        int i = 0;
        while (source[i] != 0)
        {
            dest[i] = source[i];
            result[i] = source[i];
            (i)++;
        }
        dest[i] = source[i];
        result[i] = source[i];
    }

    public static float Operate(float a, byte theta, float b) throws IOException
    {
        if (theta == (byte)'+')
        {
            return a + b;
        }
        else
            if (theta == (byte)'-')
            {
                return a - b;
            }
            else
                if (theta == (byte)'*')
                {
                    return a * b;
                }
                else
                    if (theta == (byte)'/')
                    {
                        return a / b;
                    }
                    else
                    {
                        return 0;
                    }
    }

    public static byte[] OPSET = {(byte)'+', (byte)'-', (byte)'*', (byte)'/', (byte)'(', (byte)')', (byte)'#', (byte)'^'};

    public static int In(byte Test, byte[] TestOp) throws IOException
    {
        int Find = 0;
        for (int i = 0; i < 8; (i)++)
        {
            if (Test == TestOp[i])
                Find = 1;
        }
        return Find;
    }

    public static int ReturnOpOrd(byte op, byte[] TestOp) throws IOException
    {
        int Find = 0;
        for (int i = 0; i < 8; (i)++)
        {
            if (op == TestOp[i])
                Find = i;
        }
        return Find;
    }

    public static byte precede(byte Aop, byte Bop) throws IOException
    {
        return Prior[ReturnOpOrd(Aop, OPSET)][ReturnOpOrd(Bop, OPSET)];
    }

    public static float EvaluateExpression(byte[] MyExpression) throws IOException
    {
        int optr_top = 0;
        int opnd_top = 0;
        byte[] OPTR = new byte[100];
        OPTR[0] = 0;
        float[] OPND = new float[100];
        OPND[0] = 0;
        byte[] TempData = new byte[20];
        float Data;
        float a;
        float b;
        byte theta;
        byte[] c = new byte[100];
        byte[] TempC = new byte[100];
        byte[] Dr = {(byte)'#', (byte)0};
        optr_top = PushChar(OPTR, (byte)'#', optr_top);
        strcpy(c, MyExpression, c);
        strcat(c, Dr, c);
        strcpy(TempData, "\0".getBytes(), TempC);
        int temp = 0;
        while (c[temp] != (byte)'#' || OPTR[optr_top - 1] != (byte)'#')
        {
            if (In(c[temp], OPSET) == 0)
            {
                Dr[0] = c[temp];
                strcat(TempData, Dr, TempC);
                (temp)++;
                if (In(c[temp], OPSET) == 1)
                {
                    Data = atof_(TempData);
                    opnd_top = PushNum(OPND, Data, opnd_top);
                    strcpy(TempData, "\0".getBytes(), TempC);
                }
            }
            else
            {
                byte preTemp = precede(OPTR[optr_top - 1], c[temp]);
                if (preTemp == (byte)'<')
                {
                    optr_top = PushChar(OPTR, c[temp], optr_top);
                    (temp)++;
                }
                else
                    if (preTemp == (byte)'=')
                    {
                        optr_top = PopChar(OPTR, optr_top);
                        (temp)++;
                    }
                    else
                        if (preTemp == (byte)'>')
                        {
                            theta = OPTR[optr_top - 1];
                            optr_top = PopChar(OPTR, optr_top);
                            b = OPND[opnd_top - 1];
                            opnd_top = PopNum(OPND, opnd_top);
                            a = OPND[opnd_top - 1];
                            opnd_top = PopNum(OPND, opnd_top);
                            opnd_top = PushNum(OPND, Operate(a, theta, b), opnd_top);
                        }
                        else
                        {
                        }
            }
        }
        return OPND[opnd_top - 1];
    }

    public static void main(String[] args) throws IOException
    {
        byte[] s = "13.745*5.2+2/5\0".getBytes();
        System.out.print(EvaluateExpression(s));
        return;
    }
}
