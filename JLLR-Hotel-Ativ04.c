// JLLR-Hotel-Ativ04.cpp
// JOAO VITOR CARVALHO MAGALHAES QUINTELLA
// LEOPOLDO ORTUZAL ZUCHIERI
// LUIS FELIPE FARINHA MARCHI
// RODRIGO CORRIO FERRER DOS SANTOS
/* Um hotel possui 20 andares com 14 apartamentos por andar. 
Conforme os hospedes vão chegando, eles escolhem o apartamento desejado. 
Se estiver livre, o apartamento é alocado e o hospede faz o registro. 
Ao deixar o hotel, o hospede faz o check-out e libera o apartamento. 
O gerente também precisa saber quais apartamentos estão livres e a taxa de 
ocupação do hotel.
*/

#include <stdio.h>
#include <stdlib.h>

// Matriz global representando o hotel. 
// Estados possiveis: '.' (Livre), 'R' (Reservado), 'O' (Ocupado)
char hotel[20][14];

// Prototipacao das funcoes
void fInicializarHotel();
void fMapa();
void fReserva();
void fSemResCheckIn();
void fComResCheckIn();
void fCancelarRes();
void fCheckOut();

int main()
{
    int op, op2;
    
    // Prepara a matriz com todos os quartos livres antes de iniciar o sistema
    fInicializarHotel();

    do
    {
        system("cls");
        printf("Ocupacao dos apartamentos: \n");
        fMapa();

        printf("\nSelecione uma das opcoes:\n");
        printf("(1) - Criar Reserva\n");
        printf("(2) - Fazer Check-in\n");
        printf("(3) - Fazer Check-out\n");
        printf("(4) - Cancelar reserva existente\n");
        printf("(0) - Sair do Programa\n");
        printf("Opcao: ");
        scanf("%d", &op);

        if(op == 0) {
            break;
        }

        switch(op)
        {
            case 1:
                fReserva();
                break;
            case 2:
                printf("\nO cliente possui uma reserva?\n");
                printf("(1) Sim\n(2) Nao\n");
                printf("Opcao: ");
                scanf("%d", &op2);
                
                if (op2 == 1) {
                    fComResCheckIn();
                } else {
                    fSemResCheckIn();
                }
                break;
            case 3:
                fCheckOut();
                break;
            case 4:
                fCancelarRes();
                break;
            default:
                printf("Opcao invalida!\n");
                system("pause");
                break;
        }
    } while(op != 0);

    printf("\nPrograma encerrado com sucesso. Ate logo!\n");
    return 0;
}

// Inicializa todos os elementos da matriz com o caractere '.', indicando quarto vazio
void fInicializarHotel()
{
    int andar, apto;
    for(andar = 1; andar <= 20; andar++)
    {
        for(apto = 1; apto <= 14; apto++)
        {
            hotel[andar - 1][apto - 1] = '.';
        }   
    }
}

// Imprime a matriz do hotel em formato de grade, com os andares em ordem decrescente (do 20o ao 1o)
void fMapa()
{
    int andar, apto;
    
    printf("Apartamentos->  ");
    for(apto = 1; apto < 15; apto++)
    {
        printf("%3d", apto);
    }
    printf("\n\n");
    
    for (andar = 20; andar >= 1; andar--)
    {
        printf("Andar%3d\t", andar);
        for(apto = 1; apto < 15; apto++)
        {
            printf("%3c", hotel[andar - 1][apto - 1]);
        }
        printf("\n");
    }
}

// Registra uma nova reserva caso o apartamento esteja vazio
void fReserva() 
{
    int andar, apto;
    
    printf("\nReserva: \n");
    printf("Escolha o andar (1-20) ou (0 para sair): ");
    scanf("%d" , &andar);
    
    if (andar == 0) {
        printf("Operacao cancelada.\n");
        system("pause");
        return;
    }

    printf("Escolha o apartamento (1-14): ");
    scanf("%d", &apto);

    // Valida se as coordenadas estao dentro dos limites do hotel
    if (andar >= 1 && andar <= 20 && apto >= 1 && apto <= 14)
    {
        if(hotel[andar - 1][apto - 1] == '.')
        {
            hotel[andar - 1][apto - 1] = 'R';
            printf("Reserva realizada com sucesso!\n");
        }
        else if(hotel[andar - 1][apto - 1] == 'R')
        {
            printf("Quarto ja esta reservado.\n");
        }
        else if(hotel[andar - 1][apto - 1] == 'O')
        {
            printf("Quarto ja esta ocupado.\n");
        }
    }
    else
    {
        printf("Quarto nao encontrado (Coordenadas invalidas).\n");
    }
    system("pause");
}

// Efetiva o check-in de um cliente que ja possui uma reserva ativa ('R' -> 'O')
void fComResCheckIn()
{
    int andar, apto;
    
    printf("\nCheck-In com reserva\n");
    printf("Escolha o andar (1-20) ou (0 para sair): ");
    scanf("%d" , &andar);
    
    if (andar == 0) {
        printf("Operacao cancelada.\n");
        system("pause");
        return;
    }

    printf("Escolha o apartamento (1-14): ");
    scanf("%d", &apto);

    if(andar < 1 || andar > 20 || apto < 1 || apto > 14)
    {
        printf("apto. invalido\n");
        system("pause");
        return;
    }
    
    // Garante que o check-in so ocorra se houver uma reserva previa
    if(hotel[andar - 1][apto - 1] != 'R')
    {
        printf("Este apartamento nao possui reserva ativa.\n");
        system("pause");
        return;
    }
    
    hotel[andar - 1][apto - 1] = 'O';
    printf("Check-in realizado com sucesso! Quarto agora esta OCUPADO.\n");
    system("pause");
}

// Aloca um cliente diretamente em um quarto livre, sem reserva previa ('.' -> 'O')
void fSemResCheckIn()
{
    int andar, apto;
    
    printf("\nCheck-In sem reserva\n");
    printf("Escolha o andar (1-20) ou (0 para sair): ");
    scanf("%d" , &andar);
    
    if (andar == 0)
    {
        printf("Operacao cancelada.\n");
        system("pause");
        return;
    }

    printf("Escolha o apartamento (1-14): ");
    scanf("%d", &apto);

    if(andar < 1 || andar > 20 || apto < 1 || apto > 14)
    {
        printf("apto. invalido\n");
        system("pause");
        return;
    }
    
    // Impede sobreposicao caso o quarto ja tenha um hospede ou esteja reservado para outro
    if(hotel[andar - 1][apto - 1] != '.')
    {
        printf("Este apartamento ja esta ocupado ou reservado.\n");
        system("pause");
        return;
    }
    
    hotel[andar - 1][apto - 1] = 'O';
    printf("Check-in imediato realizado com sucesso!\n");
    system("pause");
}

// Desfaz uma reserva, voltando o status do quarto para livre ('R' -> '.')
void fCancelarRes()
{
    int andar, apto;
    
    printf("\nCancelar Reserva\n");
    printf("Escolha o andar (1-20) ou (0 para sair): ");
    scanf("%d" , &andar);
    
    if (andar == 0) {
        printf("Operacao cancelada.\n");
        system("pause");
        return;
    }

    printf("Escolha o apartamento (1-14): ");
    scanf("%d", &apto);

    if(andar < 1 || andar > 20 || apto < 1 || apto > 14)
    {
        printf("apto. invalido\n");
        system("pause");
        return;
    }

    if(hotel[andar - 1][apto - 1] != 'R')
    {
        printf("Este apartamento nao possui uma reserva para ser cancelada.\n");
        system("pause");
        return;
    }

    hotel[andar - 1][apto - 1] = '.';
    printf("Reserva cancelada com sucesso.\n");
    system("pause");
}

// Realiza a desocupacao do quarto, voltando o status para livre ('O' -> '.')
void fCheckOut()
{
    int andar, apto;
    
    printf("\nCheck-Out\n");
    printf("Escolha o andar (1-20) ou (0 para sair): ");
    scanf("%d" , &andar);
    
    if (andar == 0) {
        printf("Operacao cancelada.\n");
        system("pause");
        return;
    }

    printf("Escolha o apartamento (1-14): ");
    scanf("%d", &apto);

    if(andar < 1 || andar > 20 || apto < 1 || apto > 14)
    {
        printf("apto. invalido\n");
        system("pause");
        return;
    }
    
    // Valida se ha realmente um hospede para fazer check-out
    if(hotel[andar - 1][apto - 1] != 'O')
    {
        printf("apto. nao ocupado, impossivel realizar o checkout.\n");
        system("pause");
        return;
    }
    
    hotel[andar - 1][apto - 1] = '.';
    printf("Checkout realizado com sucesso! Quarto liberado.\n");
    system("pause");
}
