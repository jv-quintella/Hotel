#include <stdio.h>
#include <iostream>



void AGA[i][j] //Função parte 5 checkout.
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
        if(AGA[i][j] != 'O')
        {
            printf("Apt. não ocupado, impossivel realizar o checkout\n");
            system("pause");
            continue;
        }
		AGA[i][j] = '.';
}
