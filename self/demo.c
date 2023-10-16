#include <stdio.h>
#include <stdlib.h>

int change(int a ,int val){
    a = val;
    return a;
}
void main(){
    int a = 3;
    printf("%d",a);
    a = change(a,5);
    printf("\n%d",a);
}