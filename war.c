#include <stdio.h>
#include <string.h>

#define TAM_STRING 30
#define MAX_TERRITORIO 5
#define MAX_COR 10

struct Territorio
{
    char nome[TAM_STRING];
    char cor[MAX_COR];
    int tropas;
};

void LimparBufferEntrada()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main()
{
    struct Territorio territorio[MAX_TERRITORIO];

    printf("Vamos cadastrar os 5 territorios iniciais do nosso mundo.\n\n");
    //Loop for para entrada de dados.
    for (int i = 0; i < MAX_TERRITORIO; i++)
    {
        printf("--- Cadastrando territorio %d ---\n", i + 1);

        printf("Nome do Territorio: ");
        fgets(territorio[i].nome, TAM_STRING, stdin);

        printf("Cor do Exercito (ex: Azul, verde...): ");
        fgets(territorio[i].cor, MAX_COR, stdin);

        territorio[i].nome[strcspn(territorio[i].nome, "\n")] = '\0';
        territorio[i].cor[strcspn(territorio[i].cor, "\n")] = '\0';

        printf("Numeros de tropas: ");
        scanf("%d", &territorio[i].tropas);
        LimparBufferEntrada();
    }

    printf("\nCadastro inicial concluido com sucesso!\n");
    printf("========================================\n");
    printf("MAPA DO MUNDO - ATUAL\n");
    printf("========================================\n");
    //Loop for para saida de dados.
    for (int i = 0; i < MAX_TERRITORIO; i++)
    {
        printf("\nTerritorio %d\n", i + 1);
        printf("- Nome: %s\n", territorio[i].nome);
        printf("- Dominado por: Exercito %s\n", territorio[i].cor);
        printf("- Tropas: %d\n", territorio[i].tropas);
    }

    return 0;
}
