//识别用户输入的基本数学式子并进行计算
#include<stdio.h>
#include <stdlib.h>
#define EPSINON 0.000001 // 定义允许的误差
double add(double x, double y);
double sub(double x, double y);
double mul(double x, double y);
double divi(double x, double y);
double count(double (*fp)(double ,double ),double a,double b);
double (*select(char))(double x,double y);
double add(double x, double y)//加法函数
{
        return x + y;
}

double sub(double x, double y)//减法函数
{
        return x - y;
}

double mul(double x, double y)//乘法函数
{
        return x * y;
}

double divi(double x, double y)//除法函数
{
        // 不要对浮点数进行==或!=比较，因为IEEE浮点数是一个近似值
        if (y >= -EPSINON && y <= EPSINON)
        {
                printf("除数不能为0\n");
                // 如果除数为0，调用exit()函数直接退出程序
                exit(1);
        }
        else
        {
                return x / y;
        }
}
double count(double (*fp)(double ,double ),double a,double b)
{
    return (*fp)(a,b);
}
double (*select(char op))(double ,double )//识别符号
{
    switch (op)
    {
     case '+':return add;
        break;

     case '-':return sub;
        break;

     case '*':return mul;
        break;;
     case '/':return divi;
        break;

    
    default: 
       printf("请输入类似1+1");
        break;
    }
}
int mian()
{
    double num1;
    double num2;
    char symbol;
    double (*con)(double,double);
    printf("请输入类似于1+1的数学式子：");
    scanf("%d%c%d",&num1,&symbol,&num2);
    con=select(symbol);
    printf("%p%c%d=%p",num1,symbol,num2,count(con,num1,num2));
    return 0;
}
