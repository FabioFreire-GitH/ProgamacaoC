#include <stdio.h>

int main () {

    int index;

    char * nomesAlunos [3][3]= {
        {"Aluno 1", "Por:30", "Mat:90"},
        {"Aluno 2", "Por:60", "Mat:60"},
        {"Aluno 3", "Por:90", "Mat:30"}
    };

        printf("Digite o numero do aluno que deseja ver a nota\n");
        printf("Para o Aluno 1 digite 0\n");
        printf("Para o Aluno 2 digite 1\n");
        printf("Para o Aluno 3 digite 2\n");

        scanf ("%d", &index);

        printf ("As notas do %s sao: %s em Portugues e %s em Matematica.\n", nomesAlunos[index][0], nomesAlunos[index][1], nomesAlunos[index][2]);
        printf ("\n");
        
    return 0;
}
