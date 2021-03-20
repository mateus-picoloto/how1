#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void menu ()
{
    printf("Selecione uma entre as seguintes opções\n");
    printf("1 - Decimal para Octal\n");
    printf("2 - Octal para Decimal\n");
    printf("0 - Sair\n");
}

int convertDecimalToOctal(int decimal)
{
    int octal = 0, base = 1;

    //Executa o loop enquanto o decimal passado como parâmetro não foi zerado
    while (decimal) {
        //Executa a conversão
        octal += (decimal % 8) * base;

        decimal /= 8;

        //Mutiplica o valor atual da base por 10
        base *= 10;
    }

    return octal;
}

int convertOctalToDecimal(int octal)
{
    int decimal = 0, base = 1;

    //Executa o loop enquanto o octal passado como parâmetro não foi zerado
    while (octal) {
        //Executa a conversão
        decimal += (octal % 10) * base;

        //Remove o um digito
        octal /= 10;

        //Mutiplica o valor atual da base por 8
        base *= 8;
    }

    return decimal;
}

int main()
{
    //Localiza os textos impressos no console para Português
    setlocale(LC_ALL, "Portuguese");

    int option = 0, integer = 0;

    //Executa o loop enquanto o valor de entrada não for zerado
    do {
        //Apresenta o menu
        menu();

        scanf("%d", &option);
        system("cls");

        //Verifica qual tipo de conversão será executada e á executa
        switch (option) {
            case 1:
                printf("Digite o valor decimal para ser convertido em octal: ");
                scanf("%d", &integer);
                printf("\nO valor em octal é: %d\n", convertDecimalToOctal(integer));
                system("pause");
                break;
            case 2:
                printf("Digite o valor octal para ser convertido em decimal: ");
                scanf("%d", &integer);
                printf("\nO valor decimal foi: %d\n", convertOctalToDecimal(integer));
                system("pause");
                break;
        }

        system("cls");
    } while(option);

    printf("Fim do programa");
    return 0;
}
