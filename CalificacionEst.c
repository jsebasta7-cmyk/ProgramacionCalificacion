#include <stdio.h>
#include <string.h>

int main() {
    int Estudiantes = 5, Asignaturas = 3;
    int Aprobados[3] = {0}, Reprobados[3] = {0};
    int i, j;
    float Calificaciones[5][3], PromEst[5], PromAsig[3];
    float NotaMaxEst[5], NotaMinEst[5], NotaMaxAsign[3], NotaMinAsign[3], nota;
    char NombreEst[5][20], NombreAsign[3][20];

    for (j = 0; j < Asignaturas; j++) {
        printf("Ingrese el nombre de la asignatura %d: ", j + 1);
        fgets(NombreAsign[j], 20, stdin);
        NombreAsign[j][strcspn(NombreAsign[j], "\n")] = '\0';
    }

    for (i = 0; i < Estudiantes; i++) {
        PromEst[i] = 0;
        NotaMaxEst[i] = 0.0;
        NotaMinEst[i] = 10.0;
    }

    for (j = 0; j < Asignaturas; j++) {
        PromAsig[j] = 0;
        NotaMaxAsign[j] = 0.0;
        NotaMinAsign[j] = 10.0;
        Aprobados[j] = 0;
        Reprobados[j] = 0;
    }

    for (i = 0; i < Estudiantes; i++) {
        printf("Ingrese el nombre del estudiante %d: ", i + 1);
        fgets(NombreEst[i], 20, stdin);
        NombreEst[i][strcspn(NombreEst[i], "\n")] = '\0';

        for (j = 0; j < Asignaturas; j++) {
            do {
                printf("Ingrese la calificacion de %s en %s (0-10): ", NombreEst[i], NombreAsign[j]);
                scanf("%f", &nota);
                if (nota < 0 || nota > 10) {
                    printf("Error: la nota debe estar entre 0 y 10.\n");
                }
            } while (nota < 0 || nota > 10);
            Calificaciones[i][j] = nota;
            getchar(); 
        }
    }

    for (i = 0; i < Estudiantes; i++) {
        float sumaEst = 0;
        for (j = 0; j < Asignaturas; j++) {
            nota = Calificaciones[i][j];
            sumaEst += nota;

            if (nota > NotaMaxEst[i]) NotaMaxEst[i] = nota;
            if (nota < NotaMinEst[i]) NotaMinEst[i] = nota;

            PromAsig[j] += nota;

            if (nota > NotaMaxAsign[j]) NotaMaxAsign[j] = nota;
            if (nota < NotaMinAsign[j]) NotaMinAsign[j] = nota;

            if (nota >= 6) Aprobados[j]++;
            else Reprobados[j]++;
        }
        PromEst[i] = sumaEst / Asignaturas;
    }

    for (j = 0; j < Asignaturas; j++) {
        PromAsig[j] /= Estudiantes;
    }

    printf(" Resultados por estudiante ");
    for (i = 0; i < Estudiantes; i++) {
        printf("Estudiante %d: %s\n", i + 1, NombreEst[i]);
        printf("Promedio: %.2f\n", PromEst[i]);
        printf("Nota maxima: %.2f\n", NotaMaxEst[i]);
        printf("Nota minima: %.2f\n", NotaMinEst[i]);
    }

    printf("Resultados por asignatura");
    for (j = 0; j < Asignaturas; j++) {
        printf("Asignatura %d: %s\n", j + 1, NombreAsign[j]);
        printf("Promedio: %.2f\n", PromAsig[j]);
        printf("Nota maxima: %.2f\n", NotaMaxAsign[j]);
        printf("Nota minima: %.2f\n", NotaMinAsign[j]);
        printf("Aprobados: %d\n", Aprobados[j]);
        printf("Reprobados: %d\n", Reprobados[j]);
    }

    return 0;
}
