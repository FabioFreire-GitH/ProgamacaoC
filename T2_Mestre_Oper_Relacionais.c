#include <stdio.h>

int main() {
    int a = 20;
    int b = 20;

    printf("a >= b: %d\n", a >= b);
    printf("a <= b: %d\n", a <= b);
    printf("a == b: %d\n", a == b);
    printf("a != b: %d\n\n", a != b);

    int x = 5;
    float y = 5.0;
    char c = 'a';

    printf("x >= y: %d\n", x >= y);
    printf("x == y: %d\n", x == y);
    printf("x != y: %d\n\n", x != y);
    
    printf("x >=c: %d\n", x>=c);
    printf("O valor ASCII de %c é: %d\n", c, c);

    int num = 10;
    float result = 10.0;

    int comparison = (float)num == result;

    printf("num == result: %d\n", comparison);


    return 0;
}