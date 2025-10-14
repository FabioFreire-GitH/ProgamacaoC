#include <stdio.h>
/* Para cada execução do loop externo,
 o loop interno é executado completamente.*/

int main() {
    int i, j;

    for (i = 1; i <= 5; i++) { // Loop externo
        for (j = 1; j <= 3; j++) { // Loop interno
            printf("i = %d, j = %d\n", i, j);
        }
    }

    while (i<=5) { // Loop externo
        j=1;
        while (j<=3) { // Loop interno
            printf("i = %d, j = %d\n", i, j);
            j++;
        }
        i++;
    }

    return 0;
}