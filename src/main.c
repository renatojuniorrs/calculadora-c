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
#include <ctype.h>
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
    removerEspaco(expressao);

    int EmPe[T]; // Empe array n
    int Deitado[T]; // Deitado array n
    int PosEmPe = -1; // PosEmPe int -1
    int PosDeitado = -1; // PosDeitado int -1
    int atual; // atual int
    char pedaco[T] = ""; // Pedaco

    // Separar os pedaços
    // c = "10+(2*3-4)^2/4+6*2";

    for (size_t i = 0;(i < strlen(expressao) && expressao[i] != '\0'); i++)
    {

        if(expressao[i+1] == '\0')
        { // Se for no final

        }
        else
        { // Se não for o final
            if(verificarNumero(expressao[i+1]) == 1)
            { // Adicionar ao pedaço
                pedaco[strlen(pedaco)] = expressao[i];
            }
            else if(verificarNumero(expressao[i]))
            { // Executar operação quando o caracter atual for numero
                pedaco[strlen(pedaco)] = expressao[i];
                pedaco[strlen(pedaco)] = '\0';
                printf("==> %s\n", pedaco);

                // Operação com número
                // Mandar limpar pedaço
            }
            else
            { // Quando o caracter atual for um sinal
                pedaco[strlen(pedaco)] = expressao[i];
                pedaco[strlen(pedaco)] = '\0';
                printf("==> %s\n", pedaco);

                // Operação com sinal
                // Mandar limpar pedaço
            }

        }

        // Se for para limpar o pedaço, então que o limpe!
    }
    // strcpy(pedaco, ""); // Limpar



    return 0;
}
