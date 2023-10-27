#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int dado;
    struct no *prox;
} No;

typedef struct fila
{
    No *frente;
    No *tras;
} Fila;

typedef No *NoPtr;
typedef Fila *FilaPtr;

NoPtr criarNo(int);
FilaPtr criarFila();
void enfileirarRecursivo(FilaPtr, int);
void removerElementoFila(FilaPtr);
void imprimirFila(FilaPtr);
void menu();

int main()
{
    FilaPtr fila = criarFila();
    int valor;
    int opcao = -1;
    while (opcao != 0)
    {
        menu();
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            system("cls");
            printf("Digite [0] para sair.\nDigite o valor a ser enfileirado: ");
            scanf("%d", &valor);
            getchar();
            if (valor != 0)
            {
                enfileirarRecursivo(fila, valor);
            }
            break;
        case 2:
            imprimirFila(fila);
            system("pause");
            break;
        case 3:
            removerElementoFila(fila);
            system("pause");
            break;
        case 0:
            printf("Saindo...\n");
            break;
        default:
            printf("Opcao invalida!\n");
            break;
        }
    }
    return 0;
}

NoPtr criarNo(int valor)
{
    NoPtr novoNo = (NoPtr)malloc(sizeof(No));
    novoNo->dado = valor;
    novoNo->prox = NULL;
    return novoNo;
}

FilaPtr criarFila()
{
    FilaPtr novaFila = (FilaPtr)malloc(sizeof(Fila));
    novaFila->frente = NULL;
    novaFila->tras = NULL;
    return novaFila;
}

void enfileirarRecursivo(FilaPtr fila, int valor)
{
    NoPtr novoNo = criarNo(valor);
    if (fila->frente == NULL)
    {
        fila->frente = novoNo;
        fila->tras = novoNo;
    }
    else
    {
        fila->tras->prox = novoNo;
        fila->tras = novoNo;
    }
    printf("Elemento enfileirado com sucesso!\n");
    system("pause");
    system("cls");
    printf("Digite [0] para sair.\nDigite o proximo valor a ser enfileirado: ");
    scanf("%d", &valor);
    getchar();
    if (valor != 0)
    {
        enfileirarRecursivo(fila, valor);
    }
}

void removerElementoFila(FilaPtr fila)
{
    if (fila->frente != NULL)
    {
        NoPtr aux = fila->frente;
        fila->frente = fila->frente->prox;
        free(aux);
        system("cls");
        printf("Elemento removido com sucesso!\n");
        imprimirFila(fila);
    }
    else
    {
        printf("A fila atual esta vazia!\n");
    }
}

void imprimirFila(FilaPtr fila)
{
    NoPtr atual = fila->frente;
    if (fila->frente != NULL)
    {
        printf("Fila atual: ");
        while (atual != NULL)
        {
            printf("%d ", atual->dado);
            atual = atual->prox;
        }
        printf("\n");
    }
    else
    {
        printf("A fila atual esta vazia.\n");
    }
}

void menu()
{
    system("cls");
    printf("1 - Enfileirar elementos");
    printf("\n2 - Imprimir a fila atual");
    printf("\n3 - Retirar elemento da fila atual");
    printf("\n0 - Sair");
    printf("\nEscolha uma opcao: ");
}
