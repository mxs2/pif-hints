# AV1-PARTE-2

Lembre de checar [AV1-PARTE-1.md](./AV1-PARTE-1.md) para relembrar conceitos básicos.

As questões a seguir são baseadas na [lista de revisão oficial](./docs/AV1-PARTE-2-REVISAO.pdf).

> Use caneta azul e papel A4 para praticar.

## Questão 99 - Maior Média
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

## Questão 100 - String para Maiúsculo
```c
void paraMaiusculo(char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 32; // diferença entre 'a' e 'A' = 32
        }
    }
}
```

## Questão 101 - MDC de N Números
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

## Questão 102 - Enum Meses
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

## Questão 103 - Diferença de Horas em Segundos
```c
int main() {
    int h1, m1, s1, h2, m2, s2;
    
    scanf("%d:%d:%d", &h1, &m1, &s1); // lê HH:MM:SS
    scanf("%d:%d:%d", &h2, &m2, &s2);
    
    int seg1 = h1*3600 + m1*60 + s1; // converte para segundos
    int seg2 = h2*3600 + m2*60 + s2;
    
    printf("%d segundos\n", abs(seg2 - seg1)); // diferença absoluta
    return 0;
}
```

## Questão 104 - Union Valor
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

## Questão 105 - Contar Caracteres
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

## Questão 106 - Palíndromo
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

## Questão 107 - Ordenar Horários
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

## Questão 108 - String ao Contrário
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

## Dicas de Memorização

1. **Conversão char**: 'a'-'A' = 32 (decorar!)
2. **Segundos**: h*3600 + m*60 + s
3. **MDC**: Algoritmo de Euclides recursivo
4. **Union**: Todos membros compartilham mesmo espaço
5. **Palíndromo**: Comparar início com fim
6. **Ordenação**: Bubble sort é o mais simples
7. **String reversa**: strlen(str)-1 até 0

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

## Especulação

1 (Uma) questão bem trabalhada de construção de algoritmo (aberta)

1 (Uma) questão de CS (compilação-saída, output de um algoritmo) 

1 (Uma) questão de VF (verdadeiro-falso, pedindo justificativa para falsas)

> Boa prova!

![Imagem](https://pbs.twimg.com/media/GRaY1WmWAAI17WI?format=jpg&name=large)

<hr>

Feito com ❤️ por [Mateus Xavier](https://github.com/mxs2)