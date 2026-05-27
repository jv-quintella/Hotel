// Matriz para Atividade-Hotel
 
#include <stdio.h>
#include <iostream>
int main()
{
	char AGA[21][15];
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
