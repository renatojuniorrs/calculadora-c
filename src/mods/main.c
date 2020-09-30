int operacao_impossivel(){
    system("cls");
    printf("- Não é possível concluir esta operação!");
    system("pause");

    return 0;
}

double** novamatriz (unsigned int quantidade_de_linhas, unsigned int quantidade_de_colunas)
{
    double** ret = (double**)malloc(quantidade_de_linhas*sizeof(double*));

    unsigned int linha;

    for (linha=0; linha<quantidade_de_linhas; linha++)
    ret[linha] = (double*)malloc(quantidade_de_colunas*sizeof(double));

    return ret;
}

char* removerEspaco(char* input)
{
    int i,j;
    char *output=input;
    for (i = 0, j = 0; i<strlen(input); i++,j++)
    {
        if (input[i]!=' ')
            output[j]=input[i];
        else
            j--;
    }
    output[j]=0;
    return output;
}

int tabela (char simbolo_empe[1], char simbolo_deitado[1])
{
    // Converter
    // X || x para *

    int index_empe, index_deitado;

    /*
        Dicionário de dados
        ( = 0
        ^ = 1
        * = 2
        / = 3
        + = 4
        - = 5
        ) = 6
    */
int tabeladesequencia[7][7];
tabeladesequencia = {
    {0,0,0,0,0,0,1},
    {0,0,1,1,1,1,1},
    {0,0,1,1,1,1,1},
    {0,0,1,1,1,1,1},
    {0,0,0,0,1,1,1},
    {0,0,0,0,1,1,1},
    {0,0,0,0,0,0,0},
};
    return tabeladesequencia[]
}
