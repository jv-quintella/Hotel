#include <stdio.h>
#include <iostream>



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
        if(SemResCheckIn[i][j] != '.')
        {
            printf("Este apartamento já está ocupado\n");
            system("pause");
            continue;
        }
		SemResCheckIn[i][j] = 'O';
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
