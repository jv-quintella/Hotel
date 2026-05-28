#include <stdio.h>
#include <stdlib.h>

char hotel[20][14];

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

void fInicializarHotel()
{
    int andar, apt;
    for(andar = 1; andar <= 20; andar++)
    {
        for(apt = 1; apt <= 14; apt++)
        {
            hotel[andar - 1][apt - 1] = '.';
        }   
    }
}

void fMapa()
{
    int andar, apt;
    printf("Apartamentos->  ");
    for(apt = 1; apt < 15; apt++)
    {
        printf("%3d", apt);
    }
    printf("\n\n");
    
    for (andar = 20; andar >= 1; andar--)
    {
        printf("Andar%3d\t", andar);
        for(apt = 1; apt < 15; apt++)
        {
            printf("%3c", hotel[andar - 1][apt - 1]);
        }
        printf("\n");
    }
}

void fReserva() 
{
    int andar, apartamento;
    printf("\nReserva: \n");
    printf("Escolha o andar (1-20) ou (0 para sair): ");
    scanf("%d" , &andar);
    
    if (andar == 0) {
        printf("Operacao cancelada.\n");
        system("pause");
        return;
    }

    printf("Escolha o apartamento (1-14): ");
    scanf("%d", &apartamento);

    if (andar >= 1 && andar <= 20 && apartamento >= 1 && apartamento <= 14)
    {
        if(hotel[andar - 1][apartamento - 1] == '.')
        {
            hotel[andar - 1][apartamento - 1] = 'R';
            printf("Reserva realizada com sucesso!\n");
        }
        else if(hotel[andar - 1][apartamento - 1] == 'R')
        {
            printf("Quarto ja esta reservado.\n");
        }
        else if(hotel[andar - 1][apartamento - 1] == 'O')
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

void fComResCheckIn()
{
    int andar, apt;
    printf("\nCheck-In com reserva\n");
    printf("Escolha o andar (1-20) ou (0 para sair): ");
    scanf("%d" , &andar);
    
    if (andar == 0) {
        printf("Operacao cancelada.\n");
        system("pause");
        return;
    }

    printf("Escolha o apartamento (1-14): ");
    scanf("%d", &apt);

    if(andar < 1 || andar > 20 || apt < 1 || apt > 14)
    {
        printf("Apt. invalido\n");
        system("pause");
        return;
    }
    
    if(hotel[andar - 1][apt - 1] != 'R')
    {
        printf("Este apartamento nao possui reserva ativa.\n");
        system("pause");
        return;
    }
    
    hotel[andar - 1][apt - 1] = 'O';
    printf("Check-in realizado com sucesso! Quarto agora esta OCUPADO.\n");
    system("pause");
}

void fSemResCheckIn()
{
int andar, apt;
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
    scanf("%d", &apt);

    if(andar < 1 || andar > 20 || apt < 1 || apt > 14)
    {
        printf("Apt. invalido\n");
        system("pause");
        return;
    }
    
    if(hotel[andar - 1][apt - 1] != '.')
    {
        printf("Este apartamento ja esta ocupado ou reservado.\n");
        system("pause");
        return;
    }
    
    hotel[andar - 1][apt - 1] = 'O';
    printf("Check-in imediato realizado com sucesso!\n");
    system("pause");
}

void fCancelarRes()
{
    int andar, apt;
    printf("\nCancelar Reserva\n");
    printf("Escolha o andar (1-20) ou (0 para sair): ");
    scanf("%d" , &andar);
    
    if (andar == 0) {
        printf("Operacao cancelada.\n");
        system("pause");
        return;
    }

    printf("Escolha o apartamento (1-14): ");
    scanf("%d", &apt);

    if(andar < 1 || andar > 20 || apt < 1 || apt > 14)
    {
        printf("Apt. invalido\n");
        system("pause");
        return;
    }

    if(hotel[andar - 1][apt - 1] != 'R')
    {
        printf("Este apartamento nao possui uma reserva para ser cancelada.\n");
        system("pause");
        return;
    }

    hotel[andar - 1][apt - 1] = '.';
    printf("Reserva cancelada com sucesso.\n");
    system("pause");
}

void fCheckOut()
{
    int andar, apt;
    printf("\nCheck-Out\n");
    printf("Escolha o andar (1-20) ou (0 para sair): ");
    scanf("%d" , &andar);
    
    if (andar == 0) {
        printf("Operacao cancelada.\n");
        system("pause");
        return;
    }

    printf("Escolha o apartamento (1-14): ");
    scanf("%d", &apt);

    if(andar < 1 || andar > 20 || apt < 1 || apt > 14)
    {
        printf("Apt. invalido\n");
        system("pause");
        return;
    }
    
    if(hotel[andar - 1][apt - 1] != 'O')
    {
        printf("Apt. nao ocupado, impossivel realizar o checkout.\n");
        system("pause");
        return;
    }
    
    hotel[andar - 1][apt - 1] = '.';
    printf("Checkout realizado com sucesso! Quarto liberado.\n");
    system("pause");
}
