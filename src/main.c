/*
Repositório do Código: https://github.com/renatojuniorrs/calculadora-c

Integrantes

Guilherme Araujo Alexandre 20133153
Lucas Ament 20011615
Renato Donizeti da Silva Junior 20014023

*/
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>
#include <stdbool.h>

// #include "./mods/main.c"
#define T 1024

int main()
{
    int atoi(const char* str)
    {
        int num = 0;
        int i = 0;
        bool isNegetive = false;
        if(str[i] == '-'){
            isNegetive = true;
            i++;
        }
        while (str[i] && (str[i] >= '0' && str[i] <= '9'))
        {
            num = num * 10 + (str[i] - '0');
            i++;
        }
        if(isNegetive) num = -1 * num;
        return num;
    }

    int operacaoImpossivel()
    {
        system("cls");
        printf("- Não é possível concluir esta operação!");
        system("pause");

        return 0;
    }

    double** novaMatriz (unsigned int quantidade_de_linhas, unsigned int quantidade_de_colunas)
    {
        double** ret = (double**)malloc(quantidade_de_linhas*sizeof(double*));

        unsigned int linha;

        for (linha=0; linha<quantidade_de_linhas; linha++)
        ret[linha] = (double*)malloc(quantidade_de_colunas*sizeof(double));

        return ret;
    }

    void removerEspaco(char *str)
    {

        int count = 0;
        for (int i = 0; str[i]; i++)
            if (str[i] != ' ')
                str[count++] = str[i];
        str[count] = '\0';
    }

    int verificarNumero(char caracter)
    {
        if (caracter >= '0' && caracter <= '9' && caracter != '\0')
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    int tabela (char simbolo_empe, char simbolo_deitado)
    {

        int index_empe, index_deitado;

        switch (simbolo_deitado) {
            case '(':
                index_deitado = 0;
                break;
            case '^':
                index_deitado = 1;
                break;
            case '*':
            case 'x':
            case 'X':
                index_deitado = 2;
                break;
            case '/':
                index_deitado = 3;
                break;
            case '+':
                index_deitado = 4;
                break;
            case '-':
                index_deitado = 5;
                break;
            case ')':
                index_deitado = 6;
                break;
        }

        switch (simbolo_empe) {
            case '(':
                index_empe = 0;
                break;
            case '^':
                index_empe = 1;
                break;
            case '*':
            case 'x':
            case 'X':
                index_empe = 2;
                break;
            case '/':
                index_empe = 3;
                break;
            case '+':
                index_empe = 4;
                break;
            case '-':
                index_empe = 5;
                break;
            case ')':
                index_empe = 6;
                break;
        }

        int tabeladesequencia[7][7] =  {{0,0,0,0,0,0,1}, {0,0,1,1,1,1,1}, {0,0,1,1,1,1,1}, {0,0,1,1,1,1,1}, {0,0,0,0,1,1,1}, {0,0,0,0,1,1,1}, {0,0,0,0,0,0,0}};
        return tabeladesequencia[index_empe][index_deitado];
        return 0;
    }
    void limparCaractere(char str)
    {
        str = '\0';
    }
    void limparString(char *str)
    {
        memset(str,0,sizeof(str));
    }



    setlocale( LC_ALL, "" );
    system("COLOR F0");

    // Entrada da expressão
    // char expressao[T] = "10+(2*3-4)^2/4+6*2";
    char expressao[T];
    printf("\n\n\t\tDigite a expressão = ");
    gets(expressao);

    // Limpar espaços
    removerEspaco(expressao);

    char emPe[T][T]; // Empe array n
    char deitado[T][T]; // Deitado array n
    int posEmPe = -1; // PosEmPe int -1
    int posDeitado = -1; // PosDeitado int -1
    int atual; // atual int
    char pedaco[T] = ""; // Pedaco
    int resultadoTabela;
    // Separar os pedaços
    // c = "10+(2*3-4)^2/4+6*2";


    for (size_t i = 0;(expressao[i] != '\0'); i++)
    {
        if(verificarNumero(expressao[i]) == 0)
        {   // Significa que não é número
            pedaco[strlen(pedaco)] = expressao[i];
            pedaco[strlen(pedaco)] = '\0';


            // Operação com sinal

            // Tempo 00:45 do vídeo da aula 1
            // Verificar o simbolo por cima do vetor em pé
            // Usar funcao tabela(emPe[posEmPe], pedeco) => Se pode tirar do vetor empé
            // Se verdade, pode-se tirar do vetor empé, e adicionar ao deitado

            if(posEmPe >= 0)
            {

                resultadoTabela = tabela(emPe[posEmPe][0], pedaco[0]); // Retorna 1 se verdadeiro ou 0 se falso


                if(resultadoTabela == 0)
                {
                    posEmPe++;
                    strcpy(emPe[posEmPe], pedaco);
                }
                else
                {
                    // Laço de repetição com decremento ou função recursiva
                    // Enquanto for verdadeiro e existir posição
                    if(pedaco[0] == ')'){
                        do {
                            posDeitado++;
                            strcpy(deitado[posDeitado], emPe[posEmPe]);
                            limparCaractere(emPe[posEmPe][0]);
                            posEmPe--;
                        } while(emPe[posEmPe][0] != '(' && posEmPe >= 0);
                        limparCaractere(emPe[posEmPe][0]);
                        posEmPe--;
                    }else{

                        do {
                            if(posEmPe != -1){
                                posDeitado++;
                                strcpy(deitado[posDeitado], emPe[posEmPe]);
                                limparCaractere(emPe[posEmPe][0]);
                            }
                            posEmPe--;

                        } while( tabela(emPe[posEmPe][0], pedaco[0]) == 1 &&  posEmPe >= -1);

                        if(posEmPe <= -1){
                            posEmPe = -1;
                        }
                        posEmPe++;
                        strcpy(emPe[posEmPe], pedaco);
                        // printf("caracter --> %s\n", pedaco);
                    }
                }
            }else{
                posEmPe++;
                strcpy(emPe[posEmPe], pedaco);
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

            // Operação com número
            posDeitado++;
            strcpy(deitado[posDeitado], pedaco);
            // Mandar limpar pedaço
            limparString(pedaco);
        }

    }


    for (posEmPe; posEmPe >=0; posEmPe--) {
        posDeitado++;
        strcpy(deitado[posDeitado], emPe[posEmPe]);
        limparCaractere(emPe[posEmPe][0]);
    }

    int num1, num2;
    char oper[1];

    for (int atual = 0; atual <= posDeitado; atual++) {

        if (verificarNumero(deitado[atual][0]) == 1) // se for número
        {
            posEmPe++;
            strcpy(emPe[posEmPe], deitado[atual]);
        }
        else
        { // Se é número e deu certo a conversão
            oper[0] = deitado[atual][0];
            num2 = atoi(emPe[posEmPe]);
            limparCaractere(emPe[posEmPe][0]);
            posEmPe--;

            num1 = atoi(emPe[posEmPe]);
            limparCaractere(emPe[posEmPe][0]);
            posEmPe--;

            posEmPe++;

            switch (oper[0]) {
                case '+':
                    sprintf(emPe[posEmPe], "%d", num1+num2);
                    break;
                case '-':
                    sprintf(emPe[posEmPe], "%d", num1-num2);
                    break;
                case '*':
                case 'x':
                case 'X':
                    sprintf(emPe[posEmPe], "%d", num1*num2);
                    break;
                case '/':
                    sprintf(emPe[posEmPe], "%d", num1/num2);
                    break;
                case '^':
                    sprintf(emPe[posEmPe], "%lf", pow(num1, num2));
                    break;
            }
        }
    }

    printf("[RESULTADO] ===>> %s\n", emPe[posEmPe]);

    return 0;
}
