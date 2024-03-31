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

void InserirContatos(char* nome, char *telefone, char *email);

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
                InserirContatos(nome, telefone, email);
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

int HashDobra(char* key) {
    unsigned int hash = 0;
    int i;
    for (i = 0; key[i] != '\0'; i++) {
        hash = hash * 17 + key[i];
    }
    return hash % TABLE_SIZE;
}

void InserirContatos(char* nome, char *telefone, char *email) {
    Contato* novoContato = (Contato*)malloc(sizeof(Contato));
    strcpy(novoContato->nome, nome);
    strcpy(novoContato->telefone, telefone);
    strcpy(novoContato->email, email);

    unsigned int index = HashDobra(nome);

    while (TabelaHash[index] != NULL) {
        index = (index + 1) % TABLE_SIZE;
    }

    No* NovoNo = (No*)malloc(sizeof(No));
    NovoNo->contato = *novoContato;
    NovoNo->prox = NULL;

    TabelaHash[index] = NovoNo;
    printf("Contato inserido com sucesso!\n");
}

void Menu() {
    printf("===== Lista de Contatos =====\n");
    printf("      1. Inserir             \n");
    printf("      2. Buscar              \n");
    printf("      3. Remover             \n");
    printf("      4. Sair                \n");
    printf("=============================\n");
}