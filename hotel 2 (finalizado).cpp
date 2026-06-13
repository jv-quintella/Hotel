#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stender
{
    char ender[40];
    char munic[20];
    char cep[9];
};

struct sthospedes
{
    char nome[40];
    char CPF[20];
    struct stender endereco;
    char cll[20];
    char email[40];
    float despesas;
};

struct ststatus
{
    char status;
    struct sthospedes hospedes;
};

struct ststatus hotel[20][14];

void fclear();
void fTaxaOcupacao(struct ststatus hotel[20][14]);
void fTaxaReserva(struct ststatus hotel[20][14]);
void fTaxaLivre(struct ststatus hotel[20][14]);
void fInicializarHotel(struct ststatus hotel[20][14]);
void fMapa(struct ststatus hotel[20][14]);
void fReserva(struct ststatus hotel[20][14]);
void fSemResCheckIn(struct ststatus hotel[20][14]);
void fComResCheckIn(struct ststatus hotel[20][14]);
void fCancelarRes(struct ststatus hotel[20][14]);
void fCheckOut(struct ststatus hotel[20][14]);
void fVisualizarApto(struct ststatus hotel[20][14]);
void fManutencao(struct ststatus hotel[20][14]);
void fRegistrarDespesa(struct ststatus hotel[20][14]);

int main()
{
    int op, op2;
    
    fInicializarHotel(hotel);
    
    do
    {
        system("cls");
        printf("Mapa dos quartos\n");
        
        fTaxaLivre(hotel);
        fTaxaOcupacao(hotel);
        fTaxaReserva(hotel);
        fMapa(hotel);
        
        printf("\nSelecione uma opcao:\n");
        printf("1 - Fazer Reserva\n");
        printf("2 - Fazer Check-in\n");
        printf("3 - Cancelar Reserva\n");
        printf("4 - Fazer Check-out\n");
        printf("5 - Visualizar Apartamento\n");
        printf("6 - Manutencao de Quarto\n");
        printf("7 - Registrar Despesa\n");
        printf("0 - Sair do Programa\n");
        scanf("%d", &op);
        
        fclear(); 

        switch(op)
        {
            case 1:
                fReserva(hotel);
                break;
                
            case 2:
                printf("\n1 - Check-in com reserva\n");
                printf("2 - Check-in sem reserva\n");
                scanf("%d", &op2);
                fclear();
                
                if (op2 == 1) 
                {
                    fComResCheckIn(hotel);
                } 
                else if (op2 == 2) 
                {
                    fSemResCheckIn(hotel);
                } 
                else 
                {
                    printf("Opcao invalida.\n");
                    system("pause");
                }
                break;
                
            case 3:
                fCancelarRes(hotel);
                break;
                
            case 4:
                fCheckOut(hotel);
                break;

            case 5:
                fVisualizarApto(hotel);
                break;

            case 6:
                fManutencao(hotel);
                break;

            case 7:
                fRegistrarDespesa(hotel);
                break;
                
            case 0:
                exit(0); 
                
            default:
                printf("Opcao invalida! Tente novamente.\n");
                system("pause");
                break;
        }
        
    } while(1); 
    
    return 0;
}

void fInicializarHotel(struct ststatus hotel[20][14])
{
    int i, j;
    for(i = 0; i < 20; i++)
    {
        for(j = 0; j < 14; j++)
        {
            hotel[i][j].status = '.';
            hotel[i][j].hospedes.despesas = 0.0;
        }   
    }
}

void fMapa(struct ststatus hotel[20][14])
{
    int i, j, andar, apto;
    
    printf("Apartamentos->  ");
    for(apto = 1; apto <= 14; apto++)
    {
        printf("%3d", apto);
    }
    printf("\n\n");
    
    for (i = 0; i < 20; i++)
    {
        andar = 20 - i; 
        printf("Andar%3d\t", andar);
        
        for(j = 0; j < 14; j++)
        {
            printf("%3c", hotel[i][j].status); 
        }
        printf("\n");
    }
}

void fReserva(struct ststatus hotel[20][14]) 
{
    int andar, apto, i, j;
    
    printf("\nReserva: \n");
    printf("Escolha o andar (1-20) ou (0 para sair): ");
    scanf("%d" , &andar);
    fclear();
    
    if (andar == 0) {
        printf("Operacao cancelada.\n");
        system("pause");
        return;
    }

    printf("Escolha o apartamento (1-14): ");
    scanf("%d", &apto);
    fclear();
    
    if (andar >= 1 && andar <= 20 && apto >= 1 && apto <= 14)
    {
        i = 20 - andar;
        j = apto - 1;
        
        if(hotel[i][j].status == '.' || hotel[i][j].status == 'L')
        {
            hotel[i][j].status = 'R';
            
            printf("\nPara continuar, informe os dados do hospede:\n");
            printf("Nome completo: ");
            fgets(hotel[i][j].hospedes.nome, 40, stdin);
            hotel[i][j].hospedes.nome[strcspn(hotel[i][j].hospedes.nome, "\n")] = '\0';
            
            printf("CPF: ");
            fgets(hotel[i][j].hospedes.CPF, 20, stdin);
            hotel[i][j].hospedes.CPF[strcspn(hotel[i][j].hospedes.CPF, "\n")] = '\0';
            
            printf("E-mail: ");
            fgets(hotel[i][j].hospedes.email, 40, stdin);
            hotel[i][j].hospedes.email[strcspn(hotel[i][j].hospedes.email, "\n")] = '\0';
            
            printf("Celular: ");
            fgets(hotel[i][j].hospedes.cll, 20, stdin);
            hotel[i][j].hospedes.cll[strcspn(hotel[i][j].hospedes.cll, "\n")] = '\0';
            
            printf("Endereco (Rua/Av): ");
            fgets(hotel[i][j].hospedes.endereco.ender, 40, stdin);
            hotel[i][j].hospedes.endereco.ender[strcspn(hotel[i][j].hospedes.endereco.ender, "\n")] = '\0';
            
            printf("Municipio: ");
            fgets(hotel[i][j].hospedes.endereco.munic, 20, stdin);
            hotel[i][j].hospedes.endereco.munic[strcspn(hotel[i][j].hospedes.endereco.munic, "\n")] = '\0';
            
            printf("CEP: ");
            fgets(hotel[i][j].hospedes.endereco.cep, 9, stdin);
            hotel[i][j].hospedes.endereco.cep[strcspn(hotel[i][j].hospedes.endereco.cep, "\n")] = '\0';
            
            printf("Reserva realizada com sucesso!\n");
        }
        else if(hotel[i][j].status == 'R')
        {
            printf("Quarto ja esta reservado.\n");
        }
        else if(hotel[i][j].status == 'O')
        {
            printf("Quarto ja esta ocupado.\n");
        }
        else if(hotel[i][j].status == 'M')
        {
            printf("Quarto em manutencao.\n");
        }
    }
    else
    {
        printf("Quarto nao encontrado (Coordenadas invalidas).\n");
    }
    system("pause");
}

void fCancelarRes(struct ststatus hotel[20][14])
{
    int andar, apto, i, j;
    
    printf("\nCancelar Reserva\n");
    printf("Escolha o andar (1-20) ou (0 para sair): ");
    scanf("%d" , &andar);
    fclear();
    
    if (andar == 0) {
        printf("Operacao cancelada.\n");
        system("pause");
        return;
    }

    printf("Escolha o apartamento (1-14): ");
    scanf("%d", &apto);
    fclear();
    
    if(andar < 1 || andar > 20 || apto < 1 || apto > 14)
    {
        printf("apto. invalido\n");
        system("pause");
        return;
    }

    i = 20 - andar;
    j = apto - 1;

    if(hotel[i][j].status != 'R')
    {
        printf("Este apartamento nao possui uma reserva para ser cancelada.\n");
        system("pause");
        return;
    }

    hotel[i][j].status = '.';
    printf("Reserva cancelada com sucesso.\n");
    system("pause");
}

void fComResCheckIn(struct ststatus hotel[20][14])
{
    int andar, apto, i, j;
    char cpf_conferir[20];
    
    printf("\nCheck-In com reserva\n");
    printf("Escolha o andar (1-20) ou (0 para sair): ");
    scanf("%d" , &andar);
    fclear();
    
    if (andar == 0) {
        printf("Operacao cancelada.\n");
        system("pause");
        return;
    }

    printf("Escolha o apartamento (1-14): ");
    scanf("%d", &apto);
    fclear();
    
    if(andar < 1 || andar > 20 || apto < 1 || apto > 14)
    {
        printf("apto. invalido\n");
        system("pause");
        return;
    }
    
    i = 20 - andar;
    j = apto - 1;
    
    if(hotel[i][j].status != 'R')
    {
        printf("Este apartamento nao possui reserva ativa.\n");
        system("pause");
        return;
    }
    
    printf("Digite o CPF do hospede para conferir: ");
    fgets(cpf_conferir, 20, stdin);
    cpf_conferir[strcspn(cpf_conferir, "\n")] = '\0';
    
    if(strcmp(hotel[i][j].hospedes.CPF, cpf_conferir) == 0)
    {
        hotel[i][j].status = 'O';
        hotel[i][j].hospedes.despesas = 0.0;
        printf("\nCheck-in realizado com sucesso! Quarto agora esta OCUPADO.\n");
    }
    else
    {
        printf("\nCPF nao confere com o hospede que fez a reserva.\n");
    }
    system("pause");
}

void fSemResCheckIn(struct ststatus hotel[20][14])
{
    int andar, apto, i, j;
    
    printf("\nCheck-In sem reserva\n");
    printf("Escolha o andar (1-20) ou (0 para sair): ");
    scanf("%d" , &andar);
    fclear();
    
    if (andar == 0)
    {
        printf("Operacao cancelada.\n");
        system("pause");
        return;
    }

    printf("Escolha o apartamento (1-14): ");
    scanf("%d", &apto);
    fclear();
    
    if(andar < 1 || andar > 20 || apto < 1 || apto > 14)
    {
        printf("apto. invalido\n");
        system("pause");
        return;
    }
    
    i = 20 - andar;
    j = apto - 1;
    
    if(hotel[i][j].status != '.' && hotel[i][j].status != 'L')
    {
        printf("Este apartamento ja esta ocupado, reservado ou em manutencao.\n");
        system("pause");
        return;
    }
    
    hotel[i][j].status = 'O';
    hotel[i][j].hospedes.despesas = 0.0;
    
    printf("\nPara continuar, informe os dados do hospede:\n");
    
    printf("Nome completo: ");
    fgets(hotel[i][j].hospedes.nome, 40, stdin);
    hotel[i][j].hospedes.nome[strcspn(hotel[i][j].hospedes.nome, "\n")] = '\0';
    
    printf("CPF: ");
    fgets(hotel[i][j].hospedes.CPF, 20, stdin);
    hotel[i][j].hospedes.CPF[strcspn(hotel[i][j].hospedes.CPF, "\n")] = '\0';
    
    printf("E-mail: ");
    fgets(hotel[i][j].hospedes.email, 40, stdin);
    hotel[i][j].hospedes.email[strcspn(hotel[i][j].hospedes.email, "\n")] = '\0';
    
    printf("Celular: ");
    fgets(hotel[i][j].hospedes.cll, 20, stdin);
    hotel[i][j].hospedes.cll[strcspn(hotel[i][j].hospedes.cll, "\n")] = '\0';
    
    printf("Endereco (Rua/Av): ");
    fgets(hotel[i][j].hospedes.endereco.ender, 40, stdin);
    hotel[i][j].hospedes.endereco.ender[strcspn(hotel[i][j].hospedes.endereco.ender, "\n")] = '\0';
    
    printf("Municipio: ");
    fgets(hotel[i][j].hospedes.endereco.munic, 20, stdin);
    hotel[i][j].hospedes.endereco.munic[strcspn(hotel[i][j].hospedes.endereco.munic, "\n")] = '\0';
    
    printf("CEP: ");
    fgets(hotel[i][j].hospedes.endereco.cep, 9, stdin);
    hotel[i][j].hospedes.endereco.cep[strcspn(hotel[i][j].hospedes.endereco.cep, "\n")] = '\0';
    
    printf("\nCheck-in imediato realizado com sucesso!\n");
    system("pause");
}

void fCheckOut(struct ststatus hotel[20][14])
{
    int andar, apto, i, j;
    
    printf("\nCheck-Out\n");
    printf("Escolha o andar (1-20) ou (0 para sair): ");
    scanf("%d" , &andar);
    fclear();
    
    if (andar == 0) {
        printf("Operacao cancelada.\n");
        system("pause");
        return;
    }

    printf("Escolha o apartamento (1-14): ");
    scanf("%d", &apto);
    fclear();
    
    if(andar < 1 || andar > 20 || apto < 1 || apto > 14)
    {
        printf("apto. invalido\n");
        system("pause");
        return;
    }
    
    i = 20 - andar;
    j = apto - 1;
    
    if(hotel[i][j].status != 'O')
    {
        printf("apto. nao ocupado, impossivel realizar o checkout.\n");
        system("pause");
        return;
    }
    
    printf("Total de despesas a pagar: R$ %.2f\n", hotel[i][j].hospedes.despesas);
    hotel[i][j].status = '.'; 
    hotel[i][j].hospedes.despesas = 0.0;
    printf("Checkout realizado com sucesso! Quarto liberado.\n");
    system("pause");
}

void fTaxaOcupacao(struct ststatus hotel[20][14])
{
    float ocupados = 0, total = 280;
    float taxaO;
    int i, j;
    
    for(i = 0; i < 20; i++)
    {
        for(j = 0; j < 14; j++)
        {
            if(hotel[i][j].status == 'O')
            {
                ocupados++;
            }
        }
    }
    taxaO = (ocupados / total) * 100;
    printf("Taxa de Ocupacao dos apartamentos: %.2f%%\n", taxaO);
}

void fTaxaReserva(struct ststatus hotel[20][14])
{
    float reservados = 0, total = 280;
    float taxaR;
    int i, j;
    
    for(i = 0; i < 20; i++)
    {
        for(j = 0; j < 14; j++)
        {
            if(hotel[i][j].status == 'R')
            {
                reservados++;
            }
        }
    }
    taxaR = (reservados / total) * 100;
    printf("Taxa de Reservas dos apartamentos: %.2f%%\n", taxaR);
}

void fTaxaLivre(struct ststatus hotel[20][14])
{
    float livres = 280, total = 280;
    float taxaL;
    int i, j;
    
    for(i = 0; i < 20; i++)
    {
        for(j = 0; j < 14; j++)
        {
            if(hotel[i][j].status == 'R' || hotel[i][j].status == 'O' || hotel[i][j].status == 'M')
            {
                livres--;
            }
        }
    }
    taxaL = (livres / total) * 100;
    printf("Taxa de quartos livres: %.2f%%\n", taxaL);
}

void fVisualizarApto(struct ststatus hotel[20][14])
{
    int andar, apto, i, j;

    printf("\nVisualizar Apartamento\n");
    printf("Escolha o andar (1-20) ou (0 para sair): ");
    scanf("%d" , &andar);
    fclear();

    if (andar == 0)
    {
        printf("Operacao cancelada.\n");
        system("pause");
        return;
    }

    printf("Escolha o apartamento (1-14): ");
    scanf("%d", &apto);
    fclear();

    if(andar < 1 || andar > 20 || apto < 1 || apto > 14)
    {
        printf("apto. invalido\n");
        system("pause");
        return;
    }

    i = 20 - andar;
    j = apto - 1;

    if(hotel[i][j].status == 'O')
    {
        printf("\nStatus: Ocupado\n");
        printf("Nome: %s\n", hotel[i][j].hospedes.nome);
        printf("CPF: %s\n", hotel[i][j].hospedes.CPF);
        printf("E-mail: %s\n", hotel[i][j].hospedes.email);
        printf("Celular: %s\n", hotel[i][j].hospedes.cll);
        printf("Endereco: %s, %s - CEP: %s\n", hotel[i][j].hospedes.endereco.ender, hotel[i][j].hospedes.endereco.munic, hotel[i][j].hospedes.endereco.cep);
        printf("Despesas: R$ %.2f\n", hotel[i][j].hospedes.despesas);
    }
    else if(hotel[i][j].status == 'R')
    {
        printf("\nStatus: Reservado\n");
        printf("Nome: %s\n", hotel[i][j].hospedes.nome);
        printf("CPF: %s\n", hotel[i][j].hospedes.CPF);
    }
    else if(hotel[i][j].status == 'M')
    {
        printf("\nStatus: Em Manutencao\n");
    }
    else
    {
        printf("\nStatus: Livre\n");
    }

    system("pause");
}

void fManutencao(struct ststatus hotel[20][14])
{
    int andar, apto, i, j;
    
    printf("\nBloqueio para Manutencao\n");
    printf("Escolha o andar (1-20) ou (0 para sair): ");
    scanf("%d" , &andar);
    fclear();
    
    if (andar == 0)
    {
        printf("Operacao cancelada.\n");
        system("pause");
        return;
    }

    printf("Escolha o apartamento (1-14): ");
    scanf("%d", &apto);
    fclear();
    
    if(andar < 1 || andar > 20 || apto < 1 || apto > 14)
    {
        printf("apto. invalido\n");
        system("pause");
        return;
    }
    
    i = 20 - andar;
    j = apto - 1;
    
    if(hotel[i][j].status == '.' || hotel[i][j].status == 'L')
    {
        hotel[i][j].status = 'M';
        printf("Quarto colocado em manutencao.\n");
    }
    else if(hotel[i][j].status == 'M')
    {
        hotel[i][j].status = '.';
        printf("Quarto retirado da manutencao.\n");
    }
    else
    {
        printf("Quarto ocupado ou reservado. Impossivel colocar em manutencao.\n");
    }
    system("pause");
}

void fRegistrarDespesa(struct ststatus hotel[20][14])
{
    int andar, apto, i, j;
    float valor;
    
    printf("\nRegistro de Despesas\n");
    printf("Escolha o andar (1-20) ou (0 para sair): ");
    scanf("%d" , &andar);
    fclear();
    
    if (andar == 0)
    {
        printf("Operacao cancelada.\n");
        system("pause");
        return;
    }

    printf("Escolha o apartamento (1-14): ");
    scanf("%d", &apto);
    fclear();
    
    if(andar < 1 || andar > 20 || apto < 1 || apto > 14)
    {
        printf("apto. invalido\n");
        system("pause");
        return;
    }
    
    i = 20 - andar;
    j = apto - 1;
    
    if(hotel[i][j].status == 'O')
    {
        printf("Digite o valor da despesa: ");
        scanf("%f", &valor);
        fclear();
        
        hotel[i][j].hospedes.despesas += valor;
        printf("Despesa de R$ %.2f registrada com sucesso. Total atual: R$ %.2f\n", valor, hotel[i][j].hospedes.despesas);
    }
    else
    {
        printf("Quarto nao esta ocupado. Despesa cancelado.\n");
    }
    system("pause");
}

void fclear()
{
    char carac;
    while ((carac = fgetc(stdin)) != EOF && carac!= '\n') {}
}
