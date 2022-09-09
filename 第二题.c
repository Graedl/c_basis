//用可变函数 写多数之和 平均数
#include <stdio.h>
#include <stdarg.h>
double average(int num,...)
{
 
    va_list valist;
    double sum = 0.0;
    int i;
 
    /* 为 num 个参数初始化 valist */
    va_start(valist, num);
 
    /* 访问所有赋给 valist 的参数 */
    for (i = 0; i < num; i++)
    {
       sum += va_arg(valist, int);
    }
    /* 清理为 valist 保留的内存 */
    va_end(valist);
 
    return sum/num;
}
int sum1(int num,...)
{   
    va_list vap;
    int sum = 0;
    int i ;
    va_start(vap, num);
    for ( i = 0; i < num; i++)
    {
       sum += va_arg(vap, int); 
    }
    va_end(vap);

    return sum;
}
int main()
{


    printf("result = %d\n" ,sum1(4, 33, 5,10,15));

    printf("result = %d\n" , sum1(1,2));
    
    printf("result = %d\n" , sum1(1,2));

     printf("Average %d\n",average(3, 5,10,15));
    return 0;
}
