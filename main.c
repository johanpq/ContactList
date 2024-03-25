#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 9887

typedef struct {
    char nome[100];
    char telefone[20];
    char email[100];
} Contato;

typedef struct No {
    Contato contato;
    struct No *prox;
} No;

No *TabelaHash[TABLE_SIZE];

void Menu();

int main() {

    int choice = 0;  

    char nameFile[30];
    int phoneFile;
    char emailFile[100];

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
                system("cls");
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