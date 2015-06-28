import java.io.IOException;

public class expression{
    public static post_fix_expression(){
        a[5];
        a.b;
        c -> d;
        (c)++;
        (c)--;
        a(b);
        a();
    }
    public static primary_expression(){
        _23ideNtifIer;
        233333;
        "StringLiteral
";
        a;
        \0;
        5;
    }
    public static unary_expression(){
        ++(x);
        --(y);
        &(a);
        *(b);
        12;
        -(23);
        ~(c);
        !(d);
    }
    public static binary_expression(){
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
    public static assignment_expression(){
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
