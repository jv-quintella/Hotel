#include <stdio.h>
#include <iostream>

char hotel[20][14];

void fCheckOut[i][j] //Função parte 5 checkout.
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


void fSemResCheckIn(int q[i][j])  //Função parte 4 checkin sem reserva.
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


void fComResCheckIn(char apt[i][j])
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

void ResCheckIn() //codigo para check in com reserva
{
    int andar, apartamento;
    printf("Qual andar e apartamento foram reservados? "); 
    scanf("%d %d", &andar, &apartamento);
    if (andar == 0 || apartamento == 0)
        return;

    if (andar >= 0 && andar =< 19 && apartamento >= 0 && apartamento =< 14)
    {
        if (hotel[andar][apartamento] == 'R') 
        {
            printf("Check-in realizado com sucesso.\n");
            hotel[andar][apartamento] = 'O';
        } 
        else
        {
            printf("Reserva nao encontrada.\n");
        }
    }
    else 
        {
            printf("Quarto nao encontrado");
        }
}
