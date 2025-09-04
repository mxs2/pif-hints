# AV1-PARTE-1
Isso aqui não reflete a prova real, é apenas especulações para a avaliação que será realizada no dia 04/09/2025 ADS2025.1_EMB e 05/09/2025 ADS2025.1_A; serve apenas de documento guia, perdão se não for elucidar o suficiente (resultado da monitoria só se deu dia 02/09/2025).

> Recomendo você ir exercitando até calejar a mão, usando uma caneta azul e folha(s) de papel A4.

## Antes de tudo
```c
#include <stdio.h> 

int main() {

    return 0; 
}
```
> Escreva no papel várias vezes, se for preciso, sonhe com isso...

## Exemplos de questões 
QUESTÃO 01 - Indique se as seguintes afirmações sobre variáveis, estruturas de decisão e
repetição em C são verdadeiras (V) ou falsas (F). Quando uma afirmação for indicada como
falsa, justifique.

( ) Em C, uma variável deve ser declarada (existir) antes de ser utilizada em qualquer
expressão ou função.

( ) O tipo char em C pode ser usado para armazenar um caractere ou um pequeno
número inteiro, e sua representação ocupa 2 bytes na memória.

( ) Em uma estrutura if-else em C, é possível ter múltiplas instruções dentro de cada
bloco sem a necessidade de usar chaves {}.

( ) No comando for em C, todas as partes (inicialização, condição e incremento) são
obrigatórias, e o loop não funciona se qualquer uma delas for omitida.

> VFFF


QUESTÃO 02 - Escreva um programa em C que recebe duas notas e calcula a média
ponderada, cujos pesos são 7.0 e 3.0 de dez alunos. Seu programa deve utilizar matrizes e as
estruturas de controle vistas até agora e atender às instruções a seguir:

A. Pedir que o usuário informe as duas notas;

B. Realizar a operação para calcular a média.

C. Imprimir uma mensagem indicando se cada aluno foi aprovado (caso a média seja maior
ou igual a 5) ou reprovado (caso contrário).

> Coloque essas duas questões numa IA e peça sugestões de perguntas semelhantes.

```c
#include <stdio.h>

int main() {
    float notas[10][2];
    float media;
    int i;

    for (i = 0; i < 10; i++) {

    	// A. 
        printf("Aluno %d:\n", i+1);
        printf("Digite a primeira nota: ");
        scanf("%f", &notas[i][0]);
        printf("Digite a segunda nota: ");
        scanf("%f", &notas[i][1]);

        // B.
        media = (notas[i][0] * 7.0 + notas[i][1] * 3.0) / 10.0;

        // C.
        if (media >= 5.0)
            printf("Media = %.2f -> Aprovado\n\n", media);
        else
            printf("Media = %.2f -> Reprovado\n\n", media);
    }

    return 0;
}
```

> Eu acredito que possa ter uma adaptação para um escopo diferente, como loja de carros/quantidade de produtos e vendas em mercado, etc.

## Algoritmos 
### Básico de vetor e matriz
```c
#include <stdio.h>

int main() {
    int n, m, i, j;
    int A[3][3];
    long long soma = 0;

    // Leitura
    scanf("%d %d", &n, &m);
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++) {
            scanf("%d", &A[i][j]);
            soma += A[i][j];               // 4) somar todos os elementos
        }

    // 1) diagonal principal (até o menor lado)
    int lim = n < m ? n : m;
    printf("Diagonal principal: ");
    for (i = 0; i < lim; i++) printf("%d ", A[i][i]);
    printf("\n");

    // 2) primeira e ultima linha
    if (n > 0) {
        printf("Primeira linha: ");
        for (j = 0; j < m; j++) printf("%d ", A[0][j]);
        printf("\n");
    }
    if (n > 1) {
        printf("Ultima linha: ");
        for (j = 0; j < m; j++) printf("%d ", A[n-1][j]);
        printf("\n");
    }

    // 3) ultima coluna
    if (m > 0) {
        printf("Ultima coluna: ");
        for (i = 0; i < n; i++) printf("%d ", A[i][m-1]);
        printf("\n");
    }

    // 4) soma total
    printf("Soma total: %lld\n", soma);
    return 0;
}
```

### Soma diagonal principal
```c
#include <stdio.h>

int main() {
    int N;
    printf("Digite o valor de N: ");
    scanf("%d", &N);

    int matriz[N][N];

    // Preenchendo a matriz
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("Número que ficará na posição [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    // Somando a diagonal principal (lembrar dessa regra de negócio)
    int somaDiagonal = 0;
    for (int i = 0; i < N; i++) {
        somaDiagonal += matriz[i][i];
    }

    printf("\nSoma da diagonal principal: %d\n", somaDiagonal);
    return 0;
}
```

### Soma diagonal secundária
```c
#include <stdio.h>

int main() {
    int N;
    printf("Digite o valor de N: ");
    scanf("%d", &N);

    int matriz[N][N];

    // Preenchendo a matriz
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("Número que ficará na posição [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    // Somando a diagonal secundária (lembrar dessa regra de négocio)
    int somaDiagonalSec = 0;
    for (int i = 0; i < N; i++) {
        somaDiagonalSec += matriz[i][N - 1 - i];
    }

    printf("\nSoma da diagonal secundária: %d\n", somaDiagonalSec);
    return 0;
}
```

### Contar números pares e ímpares de um array
```c
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int valores[n];
    int pares = 0, impares = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &valores[i]);
        (valores[i] % 2 == 0) ? pares++ : impares++;
    }

    printf("Quantidade de numeros pares: %d\n", pares);
    printf("Quantidade de numeros impares: %d\n", impares);

    return 0;
}
```

### Maior e menor de um array

```c
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int maior = arr[0], menor = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maior) maior = arr[i];
        if (arr[i] < menor) menor = arr[i];
    }

    printf("Maior: %d\n", maior);
    printf("Menor: %d\n", menor);

    return 0;
}
```

### Inversão de array (swap)
```c
#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    int vetor[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &vetor[i]);
    }

    // Regra de negócio, se lembrar
    for (int i = N - 1; i >= 0; i--) {
        printf("%d ", vetor[i]);
    }

    printf("\n");
    return 0;
}
```

## Especulação 1
2 (Duas) questões de construção de algoritmo (aberta)

1 (Uma) questão de CS (compilação-saída, output de um algoritmo) 

1 (Uma) questão de VF (verdadeiro-falso, pedindo justificativa para falsas)

## Especulação 2
2 (Duas) questões de VF (verdadeiro-falso, pedindo justificativa para falsas)

1 (Uma) questão de construção de algoritmo (aberta)

1 (Uma) questão de CS (compilação-saída, output de um algoritmo)

> Não tenho bola de cristal, boa prova!

![Imagem](https://pbs.twimg.com/media/Gzv0TwAWwAEGESo?format=jpg&name=900x900)

<hr>

Feito com ❤️ por [Mateus Xavier](https://github.com/mxs2)