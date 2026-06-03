#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição das estruturas no escopo global
struct stender {
    char ender[40];
    char munic[20];
    char cep[9];
};

struct sthospedes {
    char nome[40];
    char CPF[20];
    struct stender endereco;
    char cll[20];
    char email[40];
};

struct ststatus {
    char status; // Alterado para char simples ('R', 'O', '.')
    struct sthospedes hospedes;
};

// Matriz do hotel e matriz de dados dos hospedes sincronizadas
char hotel[20][14];
struct ststatus cadastro_hotel[20][14]; 

// Protótipos das funções
void fclear();
void fTaxaOcupacao();
void fTaxaReserva();
void fTaxaLivre();
void fInicializarHotel();
void fMapa();
void fReserva();
void fSemResCheckIn();
void fComResCheckIn();
void fCancelarRes();
void fCheckOut();
void fCadastrarHospede(int andar, int apto);

int main() {
    int op, op2;
    
    fInicializarHotel();

    do {
        // No Windows usa "cls", no Linux/Mac usa "clear". Adaptável:
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif

        printf("================ QUARTOS ================\n");
        fTaxaLivre();
        fTaxaOcupacao();
        fTaxaReserva();
        printf("-----------------------------------------\n");
        fMapa();

        printf("\nSelecione uma das opcoes:\n");
        printf("(1) - Criar Reserva\n");
        printf("(2) - Fazer Check-in\n");
        printf("(3) - Fazer Check-out\n");
        printf("(4) - Cancelar reserva existente\n");
        printf("(0) - Sair do Programa\n");
        printf("Opcao: ");
        
        if (scanf("%d", &op) != 1) {
            fclear();
            op = -1; // Força opção inválida se não for número
        } else {
            fclear();
        }

        if (op == 0) {
            break;
        }

        switch (op) {
            case 1:
                fReserva();
                break;
            case 2:
                printf("\nO cliente possui uma reserva?\n");
                printf("(1) Sim\n(2) Nao\n");
                printf("Opcao: ");
                scanf("%d", &op2);
                fclear();
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
                printf("Pressione Enter para continuar...");
                getchar();
                break;
        }
    } while (op != 0);

    printf("\nPrograma encerrado com sucesso. Ate logo!\n");
    return 0;
}

// Remove o '\n' que o fgets deixa no final da string
void remove_newline(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

// Centraliza o cadastro para não repetir código na main
void fCadastrarHospede(int andar, int apto) {
    int i = andar - 1;
    int j = apto - 1;

    printf("\n--- CADASTRO DO HOSPEDE (Quarto %d-%d) ---\n", andar, apto);
    
    printf("Nome: ");
    fgets(cadastro_hotel[i][j].hospedes.nome, 40, stdin);
    remove_newline(cadastro_hotel[i][j].hospedes.nome);

    printf("Email: ");
    fgets(cadastro_hotel[i][j].hospedes.email, 40, stdin);
    remove_newline(cadastro_hotel[i][j].hospedes.email);

    printf("CPF: ");
    fgets(cadastro_hotel[i][j].hospedes.CPF, 20, stdin);
    remove_newline(cadastro_hotel[i][j].hospedes.CPF);

    printf("Celular: ");
    fgets(cadastro_hotel[i][j].hospedes.cll, 20, stdin);
    remove_newline(cadastro_hotel[i][j].hospedes.cll);

    printf("Endereco: ");
    fgets(cadastro_hotel[i][j].hospedes.endereco.ender, 40, stdin);
    remove_newline(cadastro_hotel[i][j].hospedes.endereco.ender);

    printf("Municipio: ");
    fgets(cadastro_hotel[i][j].hospedes.endereco.munic, 20, stdin);
    remove_newline(cadastro_hotel[i][j].hospedes.endereco.munic);

    printf("CEP: ");
    fgets(cadastro_hotel[i][j].hospedes.endereco.cep, 9, stdin);
    remove_newline(cadastro_hotel[i][j].hospedes.endereco.cep);
}

void fInicializarHotel() {
    int andar, apto;
    for (andar = 1; andar <= 20; andar++) {
        for (apto = 1; apto <= 14; apto++) {
            hotel[andar - 1][apto - 1] = '.';
            cadastro_hotel[andar - 1][apto - 1].status = '.';
        }   
    }
}

void fMapa()

{

    int andar, apto;

    printf("Apartamentos->  ");

    for(apto = 1; apto < 15; apto++){

        printf("%3d", apto);

    }
    printf("\n\n");
    for (andar = 20; andar >= 1; andar--){
        printf("Andar%3d\t", andar);

        for(apto = 1; apto < 15; apto++){
            printf("%3c", hotel[andar - 1][apto - 1]);
        }
        printf("\n");
    }
}

void fReserva() {
    int andar, apto;
    printf("\n--- Nova Reserva ---\n");
    printf("Escolha o andar (1-20) ou (0 para sair): ");
    scanf("%d", &andar);
    fclear();
    
    if (andar == 0) return;

    printf("Escolha o apartamento (1-14): ");
    scanf("%d", &apto);
    fclear();

    if (andar >= 1 && andar <= 20 && apto >= 1 && apto <= 14) {
        if (hotel[andar - 1][apto - 1] == '.') {
            fCadastrarHospede(andar, apto); // Chama o cadastro antes de confirmar
            hotel[andar - 1][apto - 1] = 'R';
            cadastro_hotel[andar - 1][apto - 1].status = 'R';
            printf("\nReserva realizada com sucesso!\n");
        } else if (hotel[andar - 1][apto - 1] == 'R') {
            printf("Quarto ja esta reservado.\n");
        } else if (hotel[andar - 1][apto - 1] == 'O') {
            printf("Quarto ja esta ocupado.\n");
        }
    } else {
        printf("Quarto nao encontrado (Coordenadas invalidas).\n");
    }
    printf("Pressione Enter para continuar...");
    getchar();
}

void fComResCheckIn() {
    int andar, apto;
    printf("\n--- Check-In com Reserva ---\n");
    printf("Escolha o andar (1-20) ou (0 para sair): ");
    scanf("%d", &andar);
    fclear();
    
    if (andar == 0) return;

    printf("Escolha o apartamento (1-14): ");
    scanf("%d", &apto);
    fclear();

    if (andar < 1 || andar > 20 || apto < 1 || apto > 14) {
        printf("Apartamento invalido.\n");
        printf("Pressione Enter para continuar...");
        getchar();
        return;
    }
    
    if (hotel[andar - 1][apto - 1] != 'R') {
        printf("Este apartamento nao possui reserva ativa.\n");
        printf("Pressione Enter para continuar...");
        getchar();
        return;
    }
    
    hotel[andar - 1][apto - 1] = 'O';
    cadastro_hotel[andar - 1][apto - 1].status = 'O';
    // Exibe o nome de quem estava reservado
    printf("Bem-vindo de volta, %s!\n", cadastro_hotel[andar - 1][apto - 1].hospedes.nome);
    printf("Check-in realizado com sucesso! Quarto agora esta OCUPADO.\n");
    printf("Pressione Enter para continuar...");
    getchar();
}

void fSemResCheckIn() {
    int andar, apto;
    printf("\n--- Check-In Sem Reserva ---\n");
    printf("Escolha o andar (1-20) ou (0 para sair): ");
    scanf("%d", &andar);
    fclear();
    
    if (andar == 0) return;

    printf("Escolha o apartamento (1-14): ");
    scanf("%d", &apto);
    fclear();

    if (andar < 1 || andar > 20 || apto < 1 || apto > 14) {
        printf("Apartamento invalido.\n");
        printf("Pressione Enter para continuar...");
        getchar();
        return;
    }
    
    if (hotel[andar - 1][apto - 1] != '.') {
        printf("Este apartamento ja esta ocupado ou reservado.\n");
        printf("Pressione Enter para continuar...");
        getchar();
        return;
    }
    
    fCadastrarHospede(andar, apto);
    hotel[andar - 1][apto - 1] = 'O';
    cadastro_hotel[andar - 1][apto - 1].status = 'O';
    printf("\nCheck-in imediato realizado com sucesso!\n");
    printf("Pressione Enter para continuar...");
    getchar();
}

void fCancelarRes() {
    int andar, apto;
    printf("\n--- Cancelar Reserva ---\n");
    printf("Escolha o andar (1-20) ou (0 para sair): ");
    scanf("%d", &andar);
    fclear();
    
    if (andar == 0) return;

    printf("Escolha o apartamento (1-14): ");
    scanf("%d", &apto);
    fclear();

    if (andar < 1 || andar > 20 || apto < 1 || apto > 14) {
        printf("Apartamento invalido.\n");
        printf("Pressione Enter para continuar...");
        getchar();
        return;
    }

    if (hotel[andar - 1][apto - 1] != 'R') {
        printf("Este apartamento nao possui uma reserva para ser cancelada.\n");
        printf("Pressione Enter para continuar...");
        getchar();
        return;
    }

    hotel[andar - 1][apto - 1] = '.';
    cadastro_hotel[andar - 1][apto - 1].status = '.';
    printf("Reserva de %s cancelada com sucesso.\n", cadastro_hotel[andar - 1][apto - 1].hospedes.nome);
    printf("Pressione Enter para continuar...");
    getchar();
}

void fCheckOut() {
    int andar, apto;
    printf("\n--- Check-Out ---\n");
    printf("Escolha o andar (1-20) ou (0 para sair): ");
    scanf("%d", &andar);
    fclear();
    
    if (andar == 0) return;

    printf("Escolha o apartamento (1-14): ");
    scanf("%d", &apto);
    fclear();

    if (andar < 1 || andar > 20 || apto < 1 || apto > 14) {
        printf("Apartamento invalido.\n");
        printf("Pressione Enter para continuar...");
        getchar();
        return;
    }
    
    if (hotel[andar - 1][apto - 1] != 'O') {
        printf("Apartamento nao ocupado, impossivel realizar o checkout.\n");
        printf("Pressione Enter para continuar...");
        getchar();
        return;
    }
    
    hotel[andar - 1][apto - 1] = '.';
    cadastro_hotel[andar - 1][apto - 1].status = '.';
    printf("Checkout realizado com sucesso! Quarto liberado.\n");
    printf("Pressione Enter para continuar...");
    getchar();
}

void fTaxaOcupacao() {
    float ocupados = 0, total = 280;
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 14; j++) {
            if (hotel[i][j] == 'O') ocupados++;
        }
    }
    printf("Taxa de Ocupacao: %.2f%%\n", (ocupados / total) * 100);
}

void fTaxaReserva() {
    float reservados = 0, total = 280;
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 14; j++) {
            if (hotel[i][j] == 'R') reservados++;
        }
    }
    printf("Taxa de Reservas: %.2f%%\n", (reservados / total) * 100);
}

void fTaxaLivre() {
    float livres = 280, total = 280;
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 14; j++) {
            if (hotel[i][j] == 'R' || hotel[i][j] == 'O') livres--;
        }
    }
    printf("Taxa de Livres:   %.2f%%\n", (livres / total) * 100);
}

void fclear() {
    char carac;
    while ((carac = fgetc(stdin)) != EOF && carac != '\n') {}
}