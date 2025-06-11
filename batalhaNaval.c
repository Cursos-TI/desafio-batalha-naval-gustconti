#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

void clonarTabuleiro(int tabuleiroBase[10][10], int tabuleiroClone[10][10])
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            tabuleiroClone[i][j] = tabuleiroBase[i][j];
        }
    }
}

void aplicarHabilidade(int tabuleiro[10][10], int habilidade[3][5])
{
    // definir coordenadas alvo
    int pontoX = 2;
    int pontoY = 5;

    // aplicar habilidade
    for (int i = pontoY, y = 0; i < 10 && y < 3; i++, y++)
    {
        // 10x
        for (int j = pontoX, x = 0; j < 10 && x < 5; j++, x++)
        {
            if (habilidade[y][x] == 1)
                tabuleiro[i][j] = habilidade[y][x];
        }
    }
}

void exibirTabuleiro(int tabuleiro[10][10])
{
    int linhas[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    char colunas[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

    printf("   "); // Primeira celula

    // Cabeçalho
    for (int i = 0; i < 10; i++)
    {
        printf("%c ", colunas[i]);
    }

    printf("\n");

    // 1x
    for (int i = 0; i < 10; i++)
    {
        printf("%c%i ", i < 9 ? ' ' : '\0', linhas[i]);

        // 10x
        for (int j = 0; j < 10; j++)
        {
            printf("%i ", tabuleiro[i][j]);
        }

        printf("\n");
    }
}

int main()
{
    int tabuleiro[10][10] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

    // Barco na horizontal
    tabuleiro[5][2] = tabuleiro[5][3] = 3;
    // Barco na vertical
    tabuleiro[7][2] = tabuleiro[7][3] = 3;
    // Barco na diagonal 1
    tabuleiro[8][8] = tabuleiro[7][7] = 3;
    // Barco na diagonal 2
    tabuleiro[1][8] = tabuleiro[2][7] = 3;

    // Habilidades
    int cone[3][5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
    };
    int cruz[3][5] = {
        {0, 0, 1, 0, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 1, 0, 0},
    };
    int octaedro[3][5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0},
    };

    // Exibir Tabuleiro
    exibirTabuleiro(tabuleiro);

    // Criar tabuleiros afetados
    int tabuleiroCruz[10][10] = {0};
    int tabuleiroCone[10][10] = {0};
    int tabuleiroOctaedro[10][10] = {0};
    clonarTabuleiro(tabuleiro, tabuleiroCone);
    clonarTabuleiro(tabuleiro, tabuleiroCruz);
    clonarTabuleiro(tabuleiro, tabuleiroOctaedro);

    // Aplicando Habilidades
    aplicarHabilidade(tabuleiroCone, cone);
    aplicarHabilidade(tabuleiroCruz, cruz);
    aplicarHabilidade(tabuleiroOctaedro, octaedro);
    
    // Exibir Habilidade Cone
    printf("\n----------------");
    printf("\nHABILIDADE CONE\n");
    printf("\n----------------\n");
    exibirTabuleiro(tabuleiroCone);
    
    // Exibir Habilidade Cruz
    printf("\n----------------");
    printf("\nHABILIDADE CRUZ\n");
    printf("\n----------------\n");
    exibirTabuleiro(tabuleiroCruz);
    
    // Exibir Habilidade Octaedro
    printf("\n----------------");
    printf("\nHABILIDADE CRUZ\n");
    printf("\n----------------\n");
    exibirTabuleiro(tabuleiroOctaedro);

    
}

