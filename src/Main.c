#include <stdio.h>

typedef struct Human {
    int a;
    int b;
} Human;

int main(){
    Human h = { 0,1 };
    h.a = 0;

    int a = 0;
    float b = (float)a;

    printf("Hello World!\n");
    return 0;
}
