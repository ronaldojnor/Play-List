#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int menu();
void inserir();
void listar();

struct Lista {
    char musica[40], artista[40];
    float duracao;
    struct Lista* prox;
} *Head;

int main() {
    int continuar = 1;
    Head = NULL;
    do {
        printf("1.Inserir musica no inicio  da lista \n");
        printf("2.Listar Musicas\n");
        printf("0.Sair\n");

        scanf_s("%d", &continuar);
        system("cls || clear"); //limpar    

        switch (continuar) {
        case 1:
            inserir();
            break;
        case 2:
            listar();
            break;
        case 0:
            return 0;
            break;
        default:
            printf("Digite  uma opcao valida \n");
        }
    } while (continuar);
}

int menu() {
    int op, c;
    system("Cls");
    printf("1.Inserir no inicio da  lista \n");
    printf("2.Listar\n");
    printf("0.Sair\n");
    printf("Digite sua escolha: ");
    scanf_s("%d", &op);
    while ((c = getchar()) != '\n' && c != EOF) {} // limpar o buffer do teclado.    
    system("Cls");
    return op;
}

void inserir() {
    Lista*NovoElemento;
    NovoElemento = (struct Lista*)malloc(sizeof(struct Lista)); //  aloca espaço para um bloco       
    printf("\nInserir nome da musica:");
    scanf_s("%s", NovoElemento->musica);
    system("Cls");
    printf("\nInserir nome do artista:");
    scanf_s("%s", NovoElemento->artista);
    system("Cls");
    printf("Inserir duracao da musica?");
    scanf_s("%f", &NovoElemento->duracao);
    system("Cls");
    if (Head == NULL) { //se  nulo insere na primeira posição    
        Head = NovoElemento;
        Head->prox = NULL;
    }
    else {//move o head para o proximo e inserir  o novo na primeira posição        
        NovoElemento->prox = Head;
        Head = NovoElemento;
    }
}

void listar() { //listar    
    Lista* ElementoVarredura;
    ElementoVarredura = (struct Lista*)malloc(sizeof(struct Lista));
    ElementoVarredura = Head;
    if (ElementoVarredura == NULL) {
        printf("\n Lista vazia!");
        return;
    }
    while (ElementoVarredura != NULL) {
        while (ElementoVarredura != NULL) {
            printf("musica:%s\n ", ElementoVarredura->musica);
            printf("artista: %s \n", ElementoVarredura->artista);
            printf("duracao: %f \n", ElementoVarredura->duracao);
            ElementoVarredura = ElementoVarredura->prox;
        }
        printf("\n");
        system("pause");
        system("cls || clear");
        return;
    }
}