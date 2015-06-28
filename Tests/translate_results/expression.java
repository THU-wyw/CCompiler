import java.io.IOException;

public class expression{
    public static int post_fix_expression()
    {
        a[5];
        a.b;
        c -> d;
        (c)++;
        (c)--;
        a(b);
        a();
    }

    public static int primary_expression()
    {
        _23ideNtifIer;
        233333;
        "StringLiteral\n";
        a;
        \0;
        5;
    }

    public static int unary_expression()
    {
        ++(x);
        --(y);
        &(a);
        *(b);
        12;
        -(23);
        ~(c);
        !(d);
    }

    public static int binary_expression()
    {
        a * b;
        a / b;
        a % b;
        a + b - c;
        a << b > c;
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

    public static int assignment_expression()
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
}
