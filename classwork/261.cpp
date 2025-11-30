#include <stdio.h>
#include <stdlib.h>
int power(int x,int y);

int main()
{
    int x, y;
    scanf("%d%d", &x, &y);
    printf("%d", power(x, y));
    return 0;

}
