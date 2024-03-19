#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void extenso(int valor, FILE *texto)
{
    if (valor >= 1 && valor <= 9)
    {
        switch (valor)
        {
        case 1:
            printf("um");
            fprintf(texto,"um");
            break;
        case 2:
            printf("dois");
            fprintf(texto,"dois");
            break;
        case 3:
            printf("tres");
            fprintf(texto,"tres");
            break;
        case 4:
            printf("quatro");
            fprintf(texto,"quatro");
            break;
        case 5:
            printf("cinco");
            fprintf(texto,"cinco");
            break;
        case 6:
            printf("seis");
            fprintf(texto,"seis");
            break;
        case 7:
            printf("sete");
            fprintf(texto,"sete");
            break;
        case 8:
            printf("oito");
            fprintf(texto,"oito");
            break;
        case 9:
            printf("nove");
            fprintf(texto,"nove");
            break;
        default:
            break;
        }
    }
    else if (valor >= 10 && valor <= 19)
    {
        switch (valor)
        {
        case 10:
            printf("dez");
            fprintf(texto,"dez");
            break;
        case 11:
            printf("onze");
            fprintf(texto,"onze");
            break;
        case 12:
            printf("doze");
            fprintf(texto,"doze");
            break;
        case 13:
            printf("treze");
            fprintf(texto,"treze");
            break;
        case 14:
            printf("quatorze");
            fprintf(texto,"quatorze");
            break;
        case 15:
            printf("quinze");
            fprintf(texto,"quinze");
            break;
        case 16:
            printf("dezesseis");
            fprintf(texto,"dezesseis");
            break;
        case 17:
            printf("dezessete");
            fprintf(texto,"dezessete");
            break;
        case 18:
            printf("dezoito");
            fprintf(texto,"dezoito");
            break;
        case 19:
            printf("dezenove");
            fprintf(texto,"dezenove");
            break;
        }
    }
    else if (valor >= 20 && valor <= 99)
    {
        int dezena = valor / 10;
        int unidade = valor % 10;
        switch (dezena)
        {
        case 2:
            printf("vinte");
            fprintf(texto,"vinte");
            break;
        case 3:
            printf("trinta");
            fprintf(texto,"trinta");
            break;
        case 4:
            printf("quarenta");
            fprintf(texto,"quarenta");
            break;
        case 5:
            printf("cinquenta");
            fprintf(texto,"cinquenta");
            break;
        case 6:
            printf("sessenta");
            fprintf(texto,"sessenta");
            break;
        case 7:
            printf("setenta");
            fprintf(texto,"setenta");
            break;
        case 8:
            printf("oitenta");
            fprintf(texto,"oitenta");
            break;
        case 9:
            printf("noventa");
            fprintf(texto,"noventa");
            break;
        }
        if (unidade > 0)
        {
            printf(" e ");
            fprintf(texto," e ");
            extenso(unidade, texto);
        }
    }

    else if (valor >= 100 && valor <= 999)
    {
        int centena = valor / 100;
        int resto = valor % 100;

        switch (centena)
        {
        case 1:
            if (valor == 100)
            {
                printf("cem");
                fprintf(texto,"cem");
            }
            else
            {
                printf("cento");
                fprintf(texto,"cento");
            }
            break;
        case 2:
            printf("duzentos");
            fprintf(texto,"duzentos");
            break;
        case 3:
            printf("trezentos");
            fprintf(texto,"trezentos");
            break;
        case 4:
            printf("quatrocentos");
            fprintf(texto,"quatrocentos");
            break;
        case 5:
            printf("quinhentos");
            fprintf(texto,"quinhentos");
            break;
        case 6:
            printf("seiscentos");
            fprintf(texto,"seiscentos");
            break;
        case 7:
            printf("setecentos");
            fprintf(texto,"setecentos");
            break;
        case 8:
            printf("oitocentos");
            fprintf(texto,"oitocentos");
            break;
        case 9:
            printf("novecentos");
            fprintf(texto,"novecentos");
            break;
        }
        if (resto > 0)
        {
            printf(" e ");
            fprintf(texto," e ");
            extenso(resto, texto);
        }
    }
    else if (valor >= 1000 && valor <= 9999)
    {
        int milhar = valor / 1000;
        int resto = valor % 1000;

        extenso(milhar, texto);
        printf(" mil ");

        if (resto > 0)
        {
            extenso(resto, texto);
        }
    }
    else if (valor < 0 || valor > 9999)
    {
        printf("Numero fora do intervalo de R$1 ate R$9.999");
        fprintf(texto,"Numero fora do intervalo de R$1 ate R$9.999");
    }
}

void centavosExtenso(int centavos,int reais, FILE *texto)
{
    if (centavos == 1)
    {
        printf(" e um centavo");
        fprintf(texto," e um centavo");
        return;
    }
    else if (reais > 1)
    {
        printf(" e ");
        fprintf(texto," e ");
    }
    extenso(centavos,texto);

    printf(" centavos");
    fprintf(texto," centavos");

}

void extensoTexto(){
    FILE *texto;
    char linha[100];

    texto = fopen("cheque.txt", "r");

    if (texto == NULL){
        printf("Erro ao abrir o arquivo\n");
        return;
    }

    printf("\nNumeros do arquivo:\n");

    while (fgets(linha, sizeof(linha), texto) != NULL){
        printf("%s", linha);
    }

    printf("\n");

    fclose(texto);
}

int main()
{
    int centavos = 0;
    int MENU;
    int numero = 0;

    FILE *texto;

    while (1)
    {
        printf("Bem vindo ao leitor de cheque\n");
        printf("Menu:\n");
        printf("1-leitor de numeros por extenso\n");
        printf("2-Imprimir todos os arquivos em tela\n");
        printf("3-Sair\n");
        scanf("%d", &MENU);

        switch (MENU)
        {
        case 1:
            system("cls");
            texto = fopen("cheque.txt","a");

            if(texto == NULL){
                printf("erro ao executar\n");
            }

            printf("Digite o valor do seu cheque(ate R$9999.99):\n");
            scanf("%d.%d", &numero, &centavos);
            if (numero == 1)
            {
                printf("um real");
                fprintf(texto,"um real");
            }
            else if (numero > 1)
            {
                extenso(numero, texto);
                printf(" reais");
                fprintf(texto," reais");
            }
            if(centavos > 0)
            {
                centavosExtenso(centavos, numero, texto);
            }
            printf("\n");
            fprintf(texto,"\n");
            fclose(texto);
            fflush(stdin);
            getch();
            system("cls");
            break;

        case 2:
            extensoTexto();
            break;
        case 3:
            return 0;
            break;
        default:
            system("cls");
            printf("Numero invalido\n");
            fflush(stdin);
            getch();
            system("cls");
            break;
        }
    }
    return 0;
}
