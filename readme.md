


# 代码说明
## 程序组成
对于语法分析来说，整个程序是一个Program，语法将每个文件看做一个translation_unit。对于每一个translation_unit，由若干declarations（variable_declaration 或 function_declaration）组成。剩下的内容可以参看CParser.y文件。
## 代码结构
其他文件不说了。主函数在main.cpp里，printTree.cpp是在写语法调试时候用的，codeGen.cpp内填入生成代码的代码。现在的main函数跑的是我写的测试。
## 文法测试
文法测试在SyntaxTests文件夹内。tests文件夹是测试内容，results是测试结果。如果对生成的语法分析树有不清楚的地方可以：1. 查看Syntax.h里的定义，2. 参考SyntaxTests文件夹下的测试生成的语法分析树。
## 文法已知存在的问题

 - 不支持switch语句和for语句（实在做不动了。。。不过我实现了while语句和do...while语句）
 - 不支持在一句里声明多个变量，比如int x = 1, *y = &x, z[5]; 目前只能拆开成三行写。
 - 不支持小数，比如5.0, 6.6f这样的。
 - 不支持字符，比如'a', '&'，但是支持字符串“xxx”。
 - 没有写布尔类型，比如bool x = true，if(true)是不可以的。
 - 不支持type specifier，比如const, auto, unsigned等。
 - 不支持给数组赋初值，比如int a[3] = {1,2,3};
 - 没有写new。现在还不能写比如 int *a = new int [3];

