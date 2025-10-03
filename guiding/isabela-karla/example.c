#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Questão 01*/
int anagrama(char *str1, char *str2)
{
    int count[256] = {0};

    for (int i = 0; str1[i]; i++)
        count[(unsigned char)str1[i]]++;

    for (int i = 0; str2[i]; i++)
        count[(unsigned char)str2[i]]--;

    for (int i = 0; i < 256; i++)
        if (count[i] != 0)
            return 0;

    return 1;
}

/* Questão 02 */
int swap_maior(int *p1, int *p2, int *p3)
{
    int *maior = (*p2 > *p1) ? p2 : p1;
    if (*p3 > *maior)
        maior = p3;

    if (maior != p1)
    {
        int temp = *p1;
        *p1 = *maior;
        *maior = temp;
        return 1;
    }
    return 0;
}

/* Questão 03 */
int media_vetor(float *vet, int n, float *resultado)
{
    if (n <= 0)
        return 0;

    float soma = 0.0;
    for (int i = 0; i < n; i++)
    {
        soma += vet[i];
    }

    *resultado = soma / n;
    return 1;
}

/* Questão 04 */
int inverter_palavras(char *frase)
{
    if (!frase)
        return 0;

    int len = strlen(frase);
    if (len == 0)
        return 1;

    for (int i = 0, j = len - 1; i < j; i++, j--)
    {
        char temp = frase[i];
        frase[i] = frase[j];
        frase[j] = temp;
    }

    for (int i = 0; i < len;)
    {
        while (i < len && frase[i] == ' ')
            i++;
        int inicio = i;
        while (i < len && frase[i] != ' ')
            i++;
        int fim = i - 1;

        while (inicio < fim)
        {
            char temp = frase[inicio];
            frase[inicio] = frase[fim];
            frase[fim] = temp;
            inicio++;
            fim--;
        }
    }

    return 1;
}

/* Questão 05 */
int remover_substring(char *texto, char *padrao)
{
    int len_texto = strlen(texto);
    int len_padrao = strlen(padrao);

    if (len_padrao == 0 || len_texto == 0 ||
        len_padrao > len_texto)
        return 0;

    for (int i = 0; i <= len_texto - len_padrao;)
    {
        if (strncmp(&texto[i], padrao, len_padrao) == 0)
        {
            memmove(&texto[i], &texto[i + len_padrao],
                    len_texto - i - len_padrao + 1);
            len_texto -= len_padrao;
        }
        else
        {
            i++;
        }
    }
    return 1;
}

/* Questão 06 */
int maior_prefixo_comum(char *s1, char *s2,
                        char *resultado)
{
    if (!s1 || !s2 || !resultado)
        return 0;

    int count = 0;
    while (s1[count] && s2[count] &&
        s1[count] == s2[count])
    {
        count++;
    }

    for (int i = 0; i < count; i++)
    {
        resultado[i] = s1[i];
    }
    resultado[count] = '\0';

    return count;
}

/* Questão 07 */
int substituir_char(char *str, char alvo, char novo)
{
    if (!str)
        return 0;

    int count = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == alvo)
        {
            str[i] = novo;
            count++;
        }
    }

    return count;
}

/* Questão 08 */
int contar_palavras_unicas(char *texto)
{
    if (!texto)
        return 0;

    char palavras[100][50];
    int num_palavras = 0;
    int len = strlen(texto);

    for (int i = 0; i < len;)
    {
        while (i < len && texto[i] == ' ')
            i++;
        if (i >= len)
            break;

        char palavra[50];
        int j = 0;
        while (i < len && texto[i] != ' ' && j < 49)
        {
            palavra[j++] = texto[i++];
        }
        palavra[j] = '\0';

        int existe = 0;
        for (int k = 0; k < num_palavras; k++)
        {
            if (strcmp(palavras[k], palavra) == 0)
            {
                existe = 1;
                break;
            }
        }

        if (!existe && j > 0 && num_palavras < 100)
        {
            strcpy(palavras[num_palavras++], palavra);
        }
    }

    return num_palavras;
}

int main()
{
    /* Questão 01 */
    anagrama("roma", "amor")
        ? printf("-> são anagramas.\n")
        : printf("-> não são anagramas.\n");

    /* Questão 02 */
    int a = 3, b = 5, c = 1;
    int result = swap_maior(&a, &b, &c);
    printf(
        "swap_maior: resultado = %d, valores após swap: a "
        "= %d, b = %d, c = %d\n",
        result, a, b, c);

    /* Questão 03 */
    float vetor[] = {1.0, 2.0, 3.0, 4.0, 5.0};
    float media;
    if (media_vetor(vetor, 5, &media))
        printf("%.2f\n", media);
    else
        printf("Erro ao calcular a média do vetor.\n");

    /* Questão 04 */
    char frase[] = "Eu gosto de C";
    inverter_palavras(frase);
    printf("%s\n", frase);

    /* Questão 05 */
    char texto[] = "ababcabc";
    char padrao[] = "abc";
    if (remover_substring(texto, padrao))
        printf("%s\n", texto);
    else
        printf("Erro ao remover a substring.\n");

    /* Questão 06 */
    const char *str1 = "programacao";
    const char *str2 = "programador";
    char resultado[100];
    int prefixo_comum = maior_prefixo_comum(
        (char *)str1, (char *)str2, resultado);
    printf("Maior prefixo comum: '%s' (tamanho: %d)\n",
            resultado, prefixo_comum);

    /* Questão 07 */
    char texto_sub[] = "Olá mundo! Como vai?";
    int substituicoes =
        substituir_char(texto_sub, 'o', 'O');
    printf(
        "Texto após substituição: '%s' (%d "
        "substituições)\n",
        texto_sub, substituicoes);

    /* Questão 08 */
    char texto_palavras[] = "ola ola mundo mundo C";
    int palavras_unicas =
        contar_palavras_unicas(texto_palavras);
    printf("Número de palavras únicas: %d\n",
            palavras_unicas);

    return 0;
}