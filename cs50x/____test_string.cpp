#include<stdio.h>
int main(){
    const char *s="hello";  //建立指针，指向内存中指向h的地址
    //const表明不可改写，因为*s导致hello只读，修改s会修改一整个储存的hello，不像int那样在新的
    //内存里分配了数值
    printf("%s\n",s); //可以打印一整个字符串
    printf("%s\n",s+1); //打印从e开始的一整个字符串
    printf("%p\n",&s[1]);  //&表示显示s[1]内的内容，打印e的地址信息
    printf("%c\n",s[1]);  //打印e单个字符，不需要加*
    printf("%c\n",*(s+2));  //打印l单个字符，s加2访问s向后两块的地址，所以需要加*表示访问
    printf("%p\n",*s);
    //&是获取某个变量的地址，如int a=10 int *p=&a>>>p中储存了a的地址
    //*除声明指针外，作用是解码地址，如printf（“%d”，*p）*解码了p中地址，返回10，print出来
    //最后一行的逻辑是混乱的：*s解码了地址，返回h，但是输出又为%p地址类型，所以没有意义
    //输出s本身地址如下：
    printf("%p\n",s);
    return 0;
}