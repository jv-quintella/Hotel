#include <stdio.h>
#include <stdlib.h> // Necessário para o system("cls") e system("pause")

// Matriz global: 21 andares (1 a 20) e 15 apartamentos (1 a 14)
char hotel[21][15];

// Protótipos das funções
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
    
    // Inicializa o hotel com '.' apenas uma vez no começo do programa
    fInicializarHotel();

    do
    {
        system("cls"); // Limpa a tela a cada iteração do menu principal
        printf("=== MAPA ATUAL DO HOTEL ===\n");
        fMapa();

        // Menu Principal
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
                printf("\nO hospede tem uma reserva existente?\n");
                printf("(1) Sim\t(2) Nao\n");
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

// Preenche todo o hotel com '.' (vazio)
void fInicializarHotel()
{
    int i, j;
    for(i = 1; i <= 20; i++)
    {
        for(j = 1; j <= 14; j++)
        {
            hotel[i][j] = '.';
        }   
    }
}

// Apenas exibe a situação atual dos quartos
void fMapa()
{
    int i, j;
    printf("Apartamentos->  ");
    for(j = 1; j < 15; j++)
    {
        printf("%3d", j);
    }
    printf("\n\n");
    
    for (i = 20; i >= 1; i--)
    {
        printf("Andar%3d\t", i);
        for(j = 1; j < 15; j++)
        {
            printf("%3c", hotel[i][j]);
        }
        printf("\n");
    }
}

// Função para reservar quarto
void fReserva() 
{
    int andar, apartamento;
    printf("\n--- CRIAR RESERVA ---\n");
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
        if(hotel[andar][apartamento] == '.')
        {
            hotel[andar][apartamento] = 'R';
            printf("Reserva realizada com sucesso!\n");
        }
        else if(hotel[andar][apartamento] == 'R')
        {
            printf("Quarto ja esta reservado.\n");
        }
        else if(hotel[andar][apartamento] == 'O')
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

// Check-in para quem já tem reserva ('R' -> 'O')
void fComResCheckIn()
{
    int i, j;
    printf("\n--- CHECK-IN COM RESERVA ---\n");
    printf("Escolha o andar (1-20) ou (0 para sair): ");
    scanf("%d" , &i);
    
    if (i == 0) {
        printf("Operacao cancelada.\n");
        system("pause");
        return;
    }

    printf("Escolha o apartamento (1-14): ");
    scanf("%d", &j);

    if(i < 1 || i > 20 || j < 1 || j > 14)
    {
        printf("Apt. invalido\n");
        system("pause");
        return;
    }
    
    if(hotel[i][j] != 'R')
    {
        printf("Este apartamento nao possui reserva ativa.\n");
        system("pause");
        return;
    }
    
    hotel[i][j] = 'O';
    printf("Check-in realizado com sucesso! Quarto agora esta OCUPADO.\n");
    system("pause");
}

// Check-in sem reserva direta ('.' -> 'O')
void fSemResCheckIn()
{
    int i, j;
    printf("\n--- CHECK-IN SEM RESERVA ---\n");
    printf("Escolha o andar (1-20) ou (0 para sair): ");
    scanf("%d" , &i);
    
    if (i == 0) {
        printf("Operacao cancelada.\n");
        system("pause");
        return;
    }

    printf("Escolha o apartamento (1-14): ");
    scanf("%d", &j);

    if(i < 1 || i > 20 || j < 1 || j > 14)
    {
        printf("Apt. invalido\n");
        system("pause");
        return;
    }
    
    if(hotel[i][j] != '.')
    {
        printf("Este apartamento ja esta ocupado ou reservado.\n");
        system("pause");
        return;
    }
    
    hotel[i][j] = 'O';
    printf("Check-in imediato realizado com sucesso!\n");
    system("pause");
}

// Cancelar uma reserva ativa ('R' -> '.')
void fCancelarRes()
{
    int i, j;
    printf("\n--- CANCELAR RESERVA ---\n");
    printf("Escolha o andar (1-20) ou (0 para sair): ");
    scanf("%d" , &i);
    
    if (i == 0) {
        printf("Operacao cancelada.\n");
        system("pause");
        return;
    }

    printf("Escolha o apartamento (1-14): ");
    scanf("%d", &j);

    if(i < 1 || i > 20 || j < 1 || j > 14)
    {
        printf("Apt. invalido\n");
        system("pause");
        return;
    }

    if(hotel[i][j] != 'R')
    {
        printf("Este apartamento nao possui uma reserva para ser cancelada.\n");
        system("pause");
        return;
    }
    
    hotel[i][j] = '.';
    printf("Reserva cancelada com sucesso.\n");
    system("pause");
}

// Fazer Check-out ('O' -> '.')
void fCheckOut()
{
    int i, j;
    printf("\n--- CHECK-OUT ---\n");
    printf("Escolha o andar (1-20) ou (0 para sair): ");
    scanf("%d" , &i);
    
    if (i == 0) {
        printf("Operacao cancelada.\n");
        system("pause");
        return;
    }

    printf("Escolha o apartamento (1-14): ");
    scanf("%d", &j);

    if(i < 1 || i > 20 || j < 1 || j > 14)
    {
        printf("Apt. invalido\n");
        system("pause");
        return;
    }
    
    if(hotel[i][j] != 'O')
    {
        printf("Apt. nao ocupado, impossivel realizar o checkout.\n");
        system("pause");
        return;
    }
    
    hotel[i][j] = '.';
    printf("Checkout realizado com sucesso! Quarto liberado.\n");
    system("pause");
}
