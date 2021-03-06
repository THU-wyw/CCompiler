import java.io.IOException;

public class KMP{
    public static void getString(byte[] buffer) throws IOException
    {
        int i = 0;
        System.in.read(buffer);
        while (buffer[i] != 0 && buffer[i] != 10 && buffer[i] != 13)
            (i)++;
        buffer[i] = 0;
    }

    public static int strlen(byte[] s) throws IOException
    {
        int i = 0;
        for (i = 0; s[i] != (byte)0; (i)++)
            ;
        return i;
    }

    public static void get_next(byte[] t, int[] next) throws IOException
    {
        int tlen;
        int i = 1;
        int j = 0;
        next[0] = 0;
        next[1] = 0;
        tlen = strlen(t);
        while (i < tlen)
        {
            if (t[i] == t[j])
            {
                ++(i);
                ++(j);
                next[i] = j;
            }
            else
            {
                j = next[j];
                if (j == 0)
                    next[++(i)] = 0;
            }
        }
    }

    public static int Index_KMP(byte[] s, byte[] t, int pos) throws IOException
    {
        int slen;
        int tlen;
        int i;
        int j;
        int[] next = new int[100];
        if (s == null || t == null)
            return -(1);
        slen = strlen(s);
        tlen = strlen(t);
        get_next(t, next);
        if (tlen > slen || pos < 0 || pos > tlen - 1)
            return -(1);
        i = pos;
        j = 0;
        while (i < slen && j < tlen)
        {
            if (s[i] == t[j])
            {
                ++(i);
                ++(j);
            }
            else
            {
                if (j == 0)
                    ++(i);
                else
                    j = next[j];
            }
        }
        if (j >= tlen)
            return i - tlen;
        else
            return 0;
    }

    public static void main(String[] args) throws IOException
    {
        byte[] str = new byte[100];
        byte[] c = new byte[100];
        System.out.print("请输入文本串：\n".getBytes());
        getString(str);
        System.out.print("请输入模式串：\n".getBytes());
        getString(c);
        System.out.print(Index_KMP(str, c, 0));
        return;
    }
}
