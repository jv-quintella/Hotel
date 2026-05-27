#include <stdio.h>
#include <iosteam>

char hotel[21][15];

void fMapa();
void fReserva();
void fSemResCheckIn();
void fComResCheckIn();
void fCancelarRes();
void fCheckOut();
void fClear();

main()
{
    int andar, apt, op, op2;

    do
    {
        printf("Mapa Do Hotel\n");
        fMapa();

        //Menu
        printf("\nSelecione uma das opicoes\n");
        printf("(1) - Criar Reserva\n");
        printf("(2) - Fazer Check-in\n");
        printf("(3) - Fazer Check-out\n");
        printf("(4) - Cancelar reserva existente\n");
        printf("(0) - Sair\n");
        scanf("%d", &op)

        if(op == 0;
            break;
        switch
        {
            case 1:
                fReserva();
                break;
            case 2:
                printf("\nO hospede tem uma reserva existente?\n")
                printf("(1) Sim\t(2)Nao\n");
                scanf("%d", &op2);
                if (op2 == 1)
                {
                    fComResCheckIn();
                    break;
                }
                else
                {
                    fSemResCheck();
                    break;
                }
            case 3:
                fCheckOut();
                break;
            case 4:
                fCancelarRes();
                break;
        }
    }while(op != 0);
}

void fMapa()
{
	int i, j;
	for(i = 20; i >= 1; i--)
	{
		for(j=14; j >= 1; j--)
		{
			AGA[i][j] = '.';
		}	
	}
	do
	{
		system("cls");
		printf("Apartamentos->  ");
		for(j=1; j < 15; j++)
		{
			printf("%3d", j);
		}
		printf("\n\n");
		for (i = 20; i >= 1; i--)
		{
			printf("Andar%3d\t", i);
			for(j=1; j < 15; j++)
			{
				printf("%3c", AGA[i][j]);
			}
			printf("\n");
		}
		printf("\nPor favor, informe qual andar e qual apartamento deseja hospedar/reservar, respectivamente: ");
		scanf("%d %d", &i, &j);
		if (i == -1 || j == -1)
			break;
		if(i <= 0 || i >20 || j <= 0 || j > 14)
		{
			printf("Andar ou Apartamento invalido, por favor tente novamente.\n");
			system("pause");
			continue;
		}
		AGA[i][j] = 'R';
	}while(i != -1 || j != -1);
}

void Reserva() //codigo p/ reservar quarto
{
    int andar, apartamento;
    printf("Escolha o andar e qual apartamento serao reservados");
    scanf("%d %d", &andar, &apartamento);
    if (andar == 0 || apartamento == 0)
        return;
    if (andar >= 0 && andar =< 19 && apartamento >= 0 && apartamento =< 14)
        {
            if(hotel[andar][apartamento] == '.')
            {
                printf("Reserva realizada com sucesso");
                hotel[andar][apartamento] = 'R';
            }
            else if(hotel[andar][apartamento] == 'R')
                {
                    printf("Quarto ja reservado");
                }
            else if(hotel[andar][apartamento] == 'O')
                {
                    printf("Quarto ocupado");
                }
        }
    else
        {
            printf("Quarto nao encontrado");
        }
}

void fComResCheckIn()
{

    printf("\nDigite o apartamento para o checkout (0 0 para sair): ");
		scanf("%d %d", &i, &j);
		if (i == 0 || j == 0)
			break;

		if(i < 1 || i > 20 || j < 1 || j > 14)
		{
			printf("Apt. invalida\n");
			system("pause");
			continue;
		}
        if(fComResCheckIn[i][j] != 'R')
        {
            printf("Este apartamento não esta reservado ou ja esta ocupado\n");
            system("pause");
            continue;
        }
		fComResCheckIn[i][j] = 'O';
}

void fSemResCheckIn()  //Função parte 4 checkin sem reserva.
{
    printf("\nDigite o apartamento para o check-in (0 0 para sair): ");
		scanf("%d %d", &i, &j);
		if (i == 0 || j == 0)
			break;

		if(i < 1 || i > 20 || j < 1 || j > 14)
		{
			printf("Apt. invalida\n");
			system("pause");
			continue;
		}
        if(fSemResCheckIn[i][j] != '.')
        {
            printf("Este apartamento já está ocupado\n");
            system("pause");
            continue;
        }
		fSemResCheckIn[i][j] = 'O';
}

void fCancelarRes (int q[i][j])     //Req04 cancelar reserva
{
    int i, j;
    printf("Qual o quarto da reserva que deseja cancelar?");
    scanf("%d %d", i, j);
    if (i == 0 || j == 0)
			break;

    if(i < 1 || i > 20 || j < 1 || j > 14)
		{
			printf("Apt. invalida\n");
			system("pause");
			continue;
		}
    	
    if(i < 1 || i > 20 || j < 1 || j > 14)
		{
			printf("Apt. invalida\n");
			system("pause");
			continue;
		}

    if(fCancelarRes[i][j] != 'R')
        {
            printf("Este apartamento já está ocupado\n");
            system("pause");
            continue;
        }
		fCancelarRes[i][j] = '.';
    

}

void fCheckOut() //Função parte 5 checkout.
{
    printf("\nDigite o apartamento para o checkout (0 0 para sair): ");
		scanf("%d %d", &i, &j);
		if (i == 0 || j == 0)
			break;

		if(i < 1 || i >20 || j < 1 || j > 14)
		{
			printf("Apt. invalida\n");
			system("pause");
			continue;
		}
        if(fCheckOut[i][j] != 'O')
        {
            printf("Apt. não ocupado, impossivel realizar o checkout\n");
            system("pause");
            continue;
        }
		fCheckOut[i][j] = '.';
}