/*
Repositório do Código: https://github.com/renatojuniorrs/calculadora-c

Integrantes

Guilherme Araujo Alexandre 20133153
Lucas Ament 20011615
Renato Donizeti da Silva Junior 20014023

*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <string.h>
#include <assert.h>
#include "./mods/main.c"
#define T 1024

int main()
{
    setlocale( LC_ALL, "" );
    system("COLOR F0");

    // Entrada da expressão
    char expressao[T];
    printf("\n\n\t\tDigite a expressão = ");
    gets(expressao);

    // Limpar espaços
    expressao = removerEspaco(expressao);

    // Empe array n
    int EmPe[T];

    // Deitado array n
    int Deitado[T];

    // PosEmPe int -1
    int PosEmPe = -1;

    // PosDeitado int -1
    int PosDeitado = -1;

    // atual int
    int atual;

    // Pedaco
    char pedaco;

    return 0;
}
