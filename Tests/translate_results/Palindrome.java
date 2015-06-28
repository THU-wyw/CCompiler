import java.io.IOException;

public class Palindrome{
    public static void main(String[] args) throws IOException
    {
        byte[] str = new byte[100];
        int flag = 0;
        int length = 0;
        System.in.read(str);
        while (str[length] != 10)
            (length)++;
        for (int i = 0; i < length / 2; (i)++)
        {
            if (str[i] != str[length - i - 1])
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            System.out.print("yes\n");
        }
        else
        {
            System.out.print("no\n");
        }
        return;
    }
}
