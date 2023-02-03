#include <stdio.h>
#define SUM(a,b) (a+b)
int main() {
    int u,v;
    u=99;
    v=10*SUM(u,13);
    printf("%d\n",v);
    return 0;
}
