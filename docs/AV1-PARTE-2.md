# AV1-PARTE-2

Lembre de checar [AV1-PARTE-1.md](./AV1-PARTE-1.md) para relembrar conceitos básicos.

As questões a seguir são baseadas na [lista de revisão oficial](./AV1-PARTE-2-REVISAO.pdf).

> Use caneta azul e papel A4 para praticar.
## Questão 121 - Maior Média
```c
int maiorMedia(struct Aluno alunos[], int n) {
    int melhor = 0;
    float maiorMed = (alunos[0].notas[0] + alunos[0].notas[1] + alunos[0].notas[2]) / 3;
    
    for (int i = 1; i < n; i++) {
        float media = (alunos[i].notas[0] + alunos[i].notas[1] + alunos[i].notas[2]) / 3;
        if (media > maiorMed) {
            maiorMed = media;
            melhor = i; // guarda o índice do melhor
        }
    }
    return melhor;
}
```

## Questão 122 - String para Maiúsculo
```c
void paraMaiusculo(char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 32; // diferença entre 'a' e 'A' = 32
        }
    }
}
```

## Questão 123 - MDC de N Números
```c
int mdc(int a, int b) {
    return b == 0 ? a : mdc(b, a % b); // recursivo: Euclides
}

int mdcVarios(int nums[], int n) {
    int resultado = nums[0];
    for (int i = 1; i < n; i++) {
        resultado = mdc(resultado, nums[i]); // MDC acumulativo
    }
    return resultado;
}
```

## Questão 124 - Enum Meses
```c
enum Mes { JAN=1, FEV, MAR, ABR, MAI, JUN, JUL, AGO, SET, OUT, NOV, DEZ };

void imprimeMes(int num) {
    char* nomes[] = {"", "Janeiro", "Fevereiro", "Março", "Abril", "Maio", 
                     "Junho", "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"};
    if (num >= 1 && num <= 12) {
        printf("%s\n", nomes[num]); // índice direto
    }
}
```

## Questão 125 - Diferença de Horas em Segundos
```c
struct Hora { int h, m, s; };

int main() {
    struct Hora h1, h2;
    
    scanf("%d:%d:%d", &h1.h, &h1.m, &h1.s); // lê HH:MM:SS
    scanf("%d:%d:%d", &h2.h, &h2.m, &h2.s);
    
    int seg1 = h1.h*3600 + h1.m*60 + h1.s; // converte para segundos
    int seg2 = h2.h*3600 + h2.m*60 + h2.s;
    
    printf("%d segundos\n", abs(seg2 - seg1)); // diferença absoluta
    return 0;
}
```

## Questão 126 - Union Valor
```c
union Valor {
    int i;
    float f;
    char c;
};

int main() {
    union Valor val;
    int tipo;
    
    printf("Tipo (1-int, 2-float, 3-char): ");
    scanf("%d", &tipo);
    
    switch(tipo) {
        case 1: scanf("%d", &val.i); printf("Int: %d\n", val.i); break;
        case 2: scanf("%f", &val.f); printf("Float: %.2f\n", val.f); break;
        case 3: scanf(" %c", &val.c); printf("Char: %c\n", val.c); break; // espaço antes %c
    }
    return 0;
}
```

## Questão 127 - Contar Caracteres
```c
void contaCaracteres(char str[], int *digitos, int *letras, int *outros) {
    *digitos = *letras = *outros = 0; // zera contadores
    
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= '0' && str[i] <= '9') (*digitos)++;
        else if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) (*letras)++;
        else (*outros)++;
    }
}
```

## Questão 128 - Palíndromo
```c
int ehPalindromo(char frase[]) {
    char limpa[1000];
    int j = 0;
    
    // remove espaços e converte para minúsculo
    for (int i = 0; frase[i] != '\0'; i++) {
        if (frase[i] != ' ') {
            limpa[j++] = (frase[i] >= 'A' && frase[i] <= 'Z') ? frase[i] + 32 : frase[i];
        }
    }
    limpa[j] = '\0';
    
    // verifica palíndromo
    int len = strlen(limpa);
    for (int i = 0; i < len/2; i++) {
        if (limpa[i] != limpa[len-1-i]) return 0; // não é palíndromo
    }
    return 1; // é palíndromo
}
```

## Questão 129 - Ordenar Horários
```c
struct Hora { int h, m, s; };

int compararHoras(struct Hora a, struct Hora b) {
    int segA = a.h*3600 + a.m*60 + a.s; // converte para segundos
    int segB = b.h*3600 + b.m*60 + b.s;
    return segA - segB; // retorna diferença
}

void ordenarHoras(struct Hora horas[], int n) {
    // bubble sort simples
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-1-i; j++) {
            if (compararHoras(horas[j], horas[j+1]) > 0) {
                struct Hora temp = horas[j];
                horas[j] = horas[j+1];
                horas[j+1] = temp; // troca
            }
        }
    }
}
```

## Questão 130 - String ao Contrário
```c
void imprimeContrario(char str[]) {
    int len = strlen(str);
    for (int i = len-1; i >= 0; i--) { // do fim para o início
        printf("%c", str[i]);
    }
    printf("\n");
}

// Versão recursiva (mais elegante)
void imprimeContrarioRec(char str[], int pos) {
    if (str[pos] != '\0') {
        imprimeContrarioRec(str, pos+1); // vai até o fim
        printf("%c", str[pos]); // imprime na volta
    }
}
```

## Questão 131 - Troca com Ponteiros
```c
void troca(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
```

## Questão 132 - Soma com Ponteiros
```c
int soma_vetor(int *v, int n) {
    int soma = 0;
    for (int i = 0; i < n; i++) {
        soma += *(v + i); // aritmética de ponteiros
    }
    return soma;
}
```

## Questão 133 - Cópia Dinâmica de String
```c
char* copia_string(const char *origem) {
    int len = strlen(origem);
    char *copia = (char*)malloc((len + 1) * sizeof(char)); // +1 para '\0'
    
    if (copia != NULL) {
        for (int i = 0; i <= len; i++) { // copia incluindo '\0'
            *(copia + i) = *(origem + i);
        }
    }
    return copia;
}
```

## Questão 134 - Inverter Vetor
```c
void inverte(int *v, int n) {
    int *inicio = v;
    int *fim = v + n - 1; // último elemento
    
    while (inicio < fim) {
        int temp = *inicio;
        *inicio = *fim;
        *fim = temp;
        inicio++; // avança
        fim--;    // recua
    }
}
```

## Questão 135 - Média sem Colchetes
```c
float media(float *valores, int n) {
    float soma = 0;
    for (int i = 0; i < n; i++) {
        soma += *(valores + i); // sem usar valores[i]
    }
    return soma / n;
}
```

## Questão 136 - Maiúsculo com toupper
```c
#include <ctype.h>

void maiusculo(char *s) {
    while (*s != '\0') {
        *s = toupper(*s); // converte char atual
        s++; // avança ponteiro
    }
}
```

## Questão 137 - Contar Substring
```c
int conta_substr(const char *texto, const char *sub) {
    int count = 0;
    int len_sub = strlen(sub);
    
    for (int i = 0; texto[i] != '\0'; i++) {
        if (strncmp(texto + i, sub, len_sub) == 0) { // compara n caracteres
            count++;
        }
    }
    return count;
}
```

## Questão 138 - Remover Espaços
```c
void remove_espacos(char *s) {
    char *write = s; // ponteiro para escrita
    char *read = s;  // ponteiro para leitura
    
    while (*read != '\0') {
        if (*read != ' ') {
            *write = *read; // copia se não for espaço
            write++;
        }
        read++;
    }
    *write = '\0'; // termina string
}
```

## Questão 139 - Concatenar sem strcat
```c
void concatena(char *dest, const char *orig) {
    // vai até o fim de dest
    while (*dest != '\0') {
        dest++;
    }
    
    // copia orig para o final de dest
    while (*orig != '\0') {
        *dest = *orig;
        dest++;
        orig++;
    }
    *dest = '\0'; // termina string
}

int main() {
    char palavra1[100], palavra2[50];
    scanf("%s %s", palavra1, palavra2);
    concatena(palavra1, palavra2);
    printf("%s\n", palavra1);
    return 0;
}
```

## Dicas de Memorização

121 - Média: Percorre array, calcula média, guarda índice do maior
122 - Maiúsculo: Percorre string, converte minúsculas subtraindo 32
123 - MDC: Função recursiva Euclides, acumula resultado em vetor
124 - Enum Meses: Define enum, array de strings, imprime por índice
125 - Diferença Horas: Lê HH:MM:SS, converte para segundos, diferença
126 - Union Valor: Lê tipo, usa union para armazenar e imprimir
127 - Contar Caracteres: Percorre string, conta dígitos, letras, outros
128 - Palíndromo: Limpa string, verifica simetria ignorando espaços
129 - Ordenar Horários: Converte para segundos, usa bubble sort
130 - String ao Contrário: Imprime do fim para o início (iterativo/recursivo)
131 - Troca com Ponteiros: Função simples que troca valores via ponteiros
132 - Soma com Ponteiros: Percorre vetor somando valores via aritmética de ponteiros
133 - Cópia Dinâmica de String: Aloca memória, copia caractere a caractere
134 - Inverter Vetor: Usa dois ponteiros, troca valores até se encontrarem
135 - Média sem Colchetes: Soma valores usando aritmética de ponteiros
136 - Maiúsculo com toupper: Percorre string, converte cada char com toupper
137 - Contar Substring: Percorre texto, compara n caracteres com strncmp
138 - Remover Espaços: Usa dois ponteiros, um para ler e outro para escrever
139 - Concatenar sem strcat: Vai até o fim de dest, copia orig para lá

## Compilação-saída (CS)

```c
char txt[20] = "Oi";
strcat(txt, "!");
printf("%s", txt);
```
```c
char a[] = "abc";
char b[] = "abc";
int r = strcmp(a, b);
printf("%d", r);
```
```c
char s[10] = "abc";
printf("%lu", sizeof(s));
```
```c
char x = 'a';
if(isdigit(x)) printf("digito\n");
else printf("nao\n");
```
```c
char p[10] = "C";
strncat(p, "ESAR", 2);
printf("%s\n", p);
```
```c
char s[] = "12345";
printf("%c", s[ strlen(s) - 1 ]);
```
```c
char c = '\n';
printf("%d", isspace(c));
```
```c
char s[] = "abc";
printf("%c", *(s+1));
```
```c
char t[4] = {'c','o','d','e'};
printf("%s", t);
```
```c
char *p = strchr("banana", 'n');
printf("%s", p);
```
```c
printf("%c", "ABC"[0]);
```
```c
int soma(int a,int b){return a+b;}
int main(){printf("%d", soma(3,4));}
```
```c
void inc(int *p){(*p)++;}
int main(){int x=5;inc(&x);printf("%d",x);}
```
```c
int f(){static int c=0;return ++c;}
int main(){printf("%d %d",f(),f());}
```
```c
void show(int n){printf("%d",n);}
int main(){printf("%d", show(3));}
```
```c
int x=10;
int soma(int a){return a+x;}
int main(){int x=5;printf("%d",soma(3));}
```
```c
void foo(){int x=1;}
int main(){foo();printf("ok");}
```
```c
int f(int n){if(n==0)return 1;return n*f(n-1);}
int main(){printf("%d",f(4));}
```
```c
int g(int a,int b){return a>b?a:b;}
int main(){printf("%d",g(2,7));}
```
```c
int add(int a,int b){return a+b;}
int main(){int (*p)(int,int)=add;printf("%d",p(1,2));}
```
```c
struct P{int x,y;}p={1,2};
printf("%d",p.y);
```
```c
typedef struct{int h,m,s;}Hora;
Hora t={1,2,3};
printf("%02d:%02d",t.h,t.m);
```
```c
union U{int a;char c;};
union U u;u.a=65;printf("%c",u.c);
```
```c
typedef union{float t;char st;}Sensor;
Sensor s; s.t=25.5; printf("%.1f",s.t);
```
```c
enum dia{SEG=1,TER,QUA};
printf("%d",QUA);
```
```c
struct S{int a;};
struct S s={.a=5};
printf("%d",s.a);
```
```c
struct P{int x;};
struct P *pp=NULL;
printf("%p",(void*)pp);
```
```c
enum mes{JAN=1,FEV}; printf("%d",FEV);
```
```c
struct A{char c;int i;};
printf("%zu",sizeof(struct A));
```
```c
void inc(int *p){(*p)++;}
int main(){int x=5;inc(&x);printf("%d",x);}
```
```c
int f(){static int c=0;return ++c;}
int main(){printf("%d %d",f(),f());}
```
```c
void show(int n){printf("%d",n);}
int main(){printf("%d", show(3));}
```
```c
int f(int n){if(n==0)return 1;return n*f(n-1);}
int main(){printf("%d",f(4));}
```
```c
int g(int a,int b){return a>b?a:b;}
int main(){printf("%d",g(2,7));}
```
```c
int add(int a,int b){return a+b;}
int main(){int (*p)(int,int)=add;printf("%d",p(1,2));}
```
```c
struct P{int x,y;}p={1,2};
printf("%d",p.y);
```
```c
union U{int a;char c;};
union U u;u.a=65;printf("%c",u.c);
```
```c
typedef union{float t;char st;}Sensor;
Sensor s; s.t=25.5; printf("%.1f",s.t);
```
```c
enum escape{TAB='\t',NL='\n'}; printf("%c",TAB);
```
```c
struct S{int a;};
struct S s={5};
printf("%d",s.a);
```
```c
struct P{int x;};
struct P *pp=NULL;
printf("%p",(void*)pp);
```
```c
struct A{char c;int i;};
printf("%zu",sizeof(struct A));
```
```c
int a = 5, b = 10;
int *p = &a;
*p = *p + b;
printf("%d", a);
```
```c
int v[3] = {2,4,6};
int *p = v;
printf("%d", *(p+1));
```
```c
int x = 10;
int *p = &x;
printf("%p %d", p, *p);
```
```c
int a = 4, b = 7;
int *p = &a, *q = &b;
*p = *q;
printf("%d %d", a, b);
```
```c
char s[] = "PIF";
char *p = s;
printf("%c", *(p+2));
```

--- 
Gabarito: [outputs/outputs.txt](./outputs/outputs.txt) 

## Especulação

1 (Uma) questão bem trabalhada de construção de algoritmo (aberta)

1 (Uma) questão de CS (compilação-saída, output de um algoritmo) 

1 (Uma) questão de VF (verdadeiro-falso, pedindo justificativa para falsas)

> Boa prova!

![Imagem](https://pbs.twimg.com/media/GRaY1WmWAAI17WI?format=jpg&name=large)

<hr>

Feito com ❤️ por [Mateus Xavier](https://github.com/mxs2)