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

    char emPe[T]; // Empe array n
    char deitado[T]; // Deitado array n
    int posEmPe = -1; // PosEmPe int -1
    int posDeitado = -1; // PosDeitado int -1
    int atual; // atual int
    char pedaco[T] = ""; // Pedaco
    int resultadoTabela;
    // Separar os pedaços
    // c = "10+(2*3-4)^2/4+6*2";

    for (size_t i = 0;(i < strlen(expressao) && expressao[i] != '\0'); i++)
    {
        if(verificarNumero(expressao[i]) == 0)
        { // Significa que não é número
            pedaco[strlen(pedaco)] = expressao[i];
            pedaco[strlen(pedaco)] = '\0';
            printf("==> %s\n", pedaco);

            // Operação com sinal

            // Tempo 00:45 do vídeo da aula 1
            // Verificar o simbolo por cima do vetor em pé
            // Usar funcao tabela(emPe[posEmPe], pedeco) => Se pode tirar do vetor empé
            // Se verdade, pode-se tirar do vetor empé, e adicionar ao deitado

            if(posEmPe != -1)
            {
                resultadoTabela = tabela(emPe[posEmPe], pedaco); // Retorna 1 se verdadeiro ou 0 se falso
                if(resultadoTabela == 0)
                {
                    posEmPe++;
                    emPe[posEmPe] = pedaco;
                }
                else
                {
                    // Laço de repetição com decremento ou função recursiva
                    // Enquanto for verdadeiro e existir posição
                    for(posEmPe; tabela(emPe[posEmPe], pedaco) == 1 &&  posEmPe > -1; posEmPe--)
                    {
                        posDeitado++;
                        deitado[posDeitado] = emPe[posEmPe];
                        limparCaractere(emPe[posEmPe]);
                    }
                }
            }

            // Mandar limpar pedaço
            limparString(pedaco);
        }
        else if(verificarNumero(expressao[i+1]) == 1)
        { // Adicionar ao pedaço, significa que ainda tem mais número
            pedaco[strlen(pedaco)] = expressao[i];
        }
        else if(verificarNumero(expressao[i]))
        { // Executar operação quando o caracter atual for numero
            pedaco[strlen(pedaco)] = expressao[i];
            pedaco[strlen(pedaco)] = '\0';
            printf("==> %s\n", pedaco);

            // Operação com número
            posDeitado++;
            deitado[posDeitado] = pedaco;
            // Mandar limpar pedaço
            limparString(pedaco);
        }

    }

    return 0;
}
