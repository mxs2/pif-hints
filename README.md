# pif-hints
Introdução a paradigmas de linguagem de programação imperativa e funcional. Introdução a linguagem de programação C: comandos de
entrada e saída; estrutura de decisão e repetição; matrizes, strings e tipos de dados estruturados; subprogramas, arquivos, conjuntos,
ponteiros; alocação dinâmica de memória; introdução à programação modular. Introdução a linguagem de programação Haskell: listas,
tuplas, tipos, classes, polimorfismo, funções de alta ordem, recursão.

Contato: dfb2@cesar.school

## Links Úteis

### Materiais de Estudo
- [Beecrowd - Exercícios Práticos](https://www.github.com/mxs2/emb-pif)
- [Guia da AV1-PARTE-1](./docs/AV1-PARTE-1.md)
- [Guia da AV1-PARTE-2](./docs/AV1-PARTE-2.md)
- [Lista de Revisão AV1-PARTE-2](./docs/AV1-PARTE-2-REVISAO.pdf)
- [Materiais de Monitoria](./guiding/README.md)

## Pasta Guiding

A pasta `/guiding/` contém materiais de apoio individual para estudantes e monitoria.

### Como Usar
1. **Para Estudantes**: Cada estudante pode ter sua pasta personalizada com:
   - Exercícios resolvidos em dupla/individual
   - Códigos comentados de dúvidas específicas
   - Anotações personalizadas de monitoria

2. **Para Monitores**: Use o `README.md` como guia para:
   - Preparar conversas 1:1 eficientes
   - Fazer check-ins estruturados
   - Acompanhar progresso individual

### Como Contribuir
Para adicionar sua pasta individual:
1. Crie uma pasta com seu nome: `/guiding/seu-nome/`
2. Adicione seus arquivos `.c` com comentários explicativos
3. Documente dúvidas e soluções encontradas

## Para Provas e Avaliações

### Formato das Provas
A prova pode ter os seguintes formatos:
- **ME** - Múltipla Escolha
- **VF** - Verdadeiro ou Falso (com justificativa para as falsas)
- **CS** - Compilação e Saída 
- **Algoritmos** - Construção de algoritmos

### Conteúdo por Avaliação
- **AV1:** Contar números pares/ímpares e inversão (swap) de array; somas laterais e operações com diagonais de uma matriz
- **AV2:** Construtores e domínio da lib string.h, conceitos como structs, unions, enums e ponteiros.

### Material Adicional
- [Lista de Revisão Exemplo](./docs/AV1-PARTE-2-REVISAO.pdf)


### Recursos Externos
- **Livro:** [Computação Científica - UFRGS](https://www.ufrgs.br/reamat/ComputacaoCientifica/livro/livro.pdf)

### Tutoriais Interativos
- [Free Interactive Tutorial](https://www.learn-c.org/)  
- [Learning C Programming](https://www.tutorialspoint.com/cprogramming/index.htm)  
- [W3School](https://www.w3schools.com/c/index.php)  
- [Geeks for Geeks](https://www.geeksforgeeks.org/c-programming-language/)  
- [Code Academy](https://www.codecademy.com/catalog/language/c)  
- [Plus (YouTube Playlist)](https://www.youtube.com/playlist?list=PLa75BYTPDNKZWYypgOFEsX3H2Mg-SzuLW)

## Projeto CLI-Lib (Jogo)

### Estrutura Recomendada
```
/projeto
├── src/         # Código-fonte (.c)
├── include/     # Cabeçalhos (.h)
├── build/       # Saídas de compilação
├── README.md    # Descrição do projeto
├── Makefile     # Arquivo de build
└── LICENSE      # Licença
```

### Requisitos do README
O arquivo README.md deverá conter:
1. **Equipe:** Nome e sobrenome dos membros e usuários GitHub (@fulano, @beltrano)
2. **Disciplina:** Programação Imperativa e Funcional - 2025.1
3. **Instituição:** CESAR School
4. **Nome do jogo:** Seja criativo!
5. **Instruções:** Como compilar e executar o jogo
6. **Descrição:** Regras e interação do jogo

### Configuração
- **Makefile:** Opcional, mas fortemente recomendado
- **Licença:** Opcional (MIT e BSD são recomendadas)
- **Repositório:** Fork do [cli-lib](https://github.com/tgfb/cli-lib) 
- **Branch:** Criar uma branch `develop` para desenvolvimento

---

Feito com ❤️ por [Mateus Xavier](https://github.com/mxs2)
