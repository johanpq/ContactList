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

void Buscar(char* nome);

void LerArquivoEInserir(FILE *arquivo);

void RemoverContato(char* nome);

int main() {
    FILE *arquivo = fopen("contatos.txt", "r");
    if(arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

    for (int i = 0; i < TABLE_SIZE; i++) {
        TabelaHash[i] = NULL;
    }

    /* Lendo e inserindo os contatos do arquivo na tabela hash com encadeamento separado */
    LerArquivoEInserir(arquivo);

    int choice = 0;
    char nome[100];
    char telefone[20];
    char email[100];

    do {
        Menu();
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Nome: ");
                scanf(" %[^\n]", nome);
                printf("Telefone: ");
                scanf("%s", telefone);
                printf("Email: ");
                scanf(" %[^\n]", email);
                InserirContatos(nome, telefone, email);
                printf("Contato inserido com sucesso!\n");
                break;

            case 2:
                printf("Buscar por: ");
                scanf(" %[^\n]", nome);
                Buscar(nome);
                // system("cls");
                break;

            case 3:
               printf("Insira o nome da pessoa para remover: ");
                scanf(" %[^\n]", nome);
                RemoverContato(nome);
                printf("Contato removido com sucesso!\n");
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

    int totalContatos = 0;

    No* NovoNo = (No*)malloc(sizeof(No));
    NovoNo->contato = *novoContato;
    NovoNo->prox = NULL;
    /* Checa se há colizão */
    if (TabelaHash[index] == NULL) {
        TabelaHash[index] = NovoNo;
    } else {
        No* atual = TabelaHash[index];
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = NovoNo;
    }
}

void Buscar(char* nome) {
    unsigned int index = HashDobra(nome);
    No* atual = TabelaHash[index];
    while (atual != NULL) {
        if (strcmp(atual->contato.nome, nome) == 0) {
            printf("Telefone: %s\nEmail: %s\n", atual->contato.telefone, atual->contato.email);
            return;
        }
        atual = atual->prox;
    }
    printf("Contato nao encontrado\n");
}

void RemoverContato(char* nome) {
    unsigned int index = HashDobra(nome);
    No* anterior = NULL;
    No* atual = TabelaHash[index];
    while (atual != NULL) {
        if (strcmp(atual->contato.nome, nome) == 0) {
            // Remover o contato da lista encadeada
            if (anterior == NULL) {
                TabelaHash[index] = atual->prox;
            } else {
                anterior->prox = atual->prox;
            }
            free(atual);
            printf("Contato removido com sucesso!\n");
            return;
        }
        anterior = atual;
        atual = atual->prox;
    }
    printf("Contato nao encontrado\n");
}

void LerArquivoEInserir(FILE *arquivo) {
    char line[256];
    char nome[100];
    char telefone[20];
    char email[100];

    int contatosLidos = 0;

    while (fgets(line, sizeof(line), arquivo) != NULL && contatosLidos < 5000) {
        if (strstr(line, "Nome:") != NULL) {
            sscanf(line, "Nome: %[^\n]", nome);
        } else if (strstr(line, "Telefone:") != NULL) {
            sscanf(line, "Telefone: %[^\n]", telefone);
        } else if (strstr(line, "Email:") != NULL) {
            sscanf(line, "Email: %[^\n]", email);
            InserirContatos(nome, telefone, email);
            contatosLidos++;
        }
    }
    fclose(arquivo);
}

void Menu() {
    printf("===== Lista de Contatos =====\n");
    printf("      1. Inserir             \n");
    printf("      2. Buscar              \n");
    printf("      3. Remover             \n");
    printf("      4. Sair                \n");
    printf("=============================\n");
}
