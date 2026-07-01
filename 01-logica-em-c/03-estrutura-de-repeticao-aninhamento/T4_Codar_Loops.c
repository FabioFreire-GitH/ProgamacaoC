#include <stdio.h>
/* Para cada execução do loop externo,
 o loop interno é executado completamente.*/

int main() {

    int i, j;
    char letra;

    for  (i = 1; i<=5; i++)
    {
        letra = 'A';

        for (j = 1; j<=i; j++)
        {
            printf("%c ", letra);
            ++letra;
        }
        printf("\n");
    }

    return 0;
}