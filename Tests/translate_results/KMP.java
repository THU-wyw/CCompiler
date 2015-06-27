public class KMP{
    public static strlen( s)
    {
         i = 0;
        for (i = 0; (i); s[i] != 0)
            ;
        return i;
    }
    public static get_next( t,  next)
    {
         tlen;
         i = 1;
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
    public static Index_KMP( s,  t,  pos)
    {
         slen;
         next;
        if (s == NULL || t == NULL)
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
    public static void main(String[] args)
    {
         str = "helloWorld";
         c = "Wo";
        printf("%d\n", Index_KMP(str, c, 0));
        return 0;
    }
}
