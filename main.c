#include <stdio.h>
#include <stdlib.h>

#define PosicaoDoVetor 9887

/* contatos =  5000 */

typedef struct listaDecontatos {
    char nome[30];
    int telefone;
    char email[100];
} ListaContatos;

void Menu();

int main() {
    int choice = 0;  

    char nome[30];
    int telefone;
    char email[100];

    char BuscarNome[30];
    char RemoverNome[30];

    do {
        Menu();
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Nome: ");
                scanf(" %[^\n]", nome);
                printf("Telefone: ");
                scanf("%d", &telefone);
                printf("Email: ");
                scanf(" %[^\n]", email);
                break;

            case 2:
                printf("Buscar por: ");
                scanf(" %[^\n]", BuscarNome);
                system("cls");
                break;

            case 3:
                printf("Insira o nome da pessoa para remover: ");
                scanf(" %[^\n]", RemoverNome);
                system("cls");
                break;
            case 4:
                printf("Saindo...");
                break;
            default: 
                printf("Erro!\n");
        }
    } while(choice != 4);

    return 0 ;
}

void Menu() {
    printf("===== Lista de Contatos =====\n");
    printf("      1. Inserir             \n");
    printf("      2. Buscar              \n");
    printf("      3. Remover             \n");
    printf("      4. Sair                \n");
    printf("=============================\n");
}