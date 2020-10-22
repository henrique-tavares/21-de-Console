# 21-de-Console
 Projeto de Estrutura de Dados que implementa o jogo 21 (blackjack) em C.

## Divisão de arquitetura
 - [X] objetos
 - [X] estruturas
 - [X] entidades

## Implementações de estruturas
 - [X] lista encadeada simples dinâmica
 - [x] pilha dinâmica

---
## Usando Make (Recomendado):
Caso não tenha o comando ```make``` instalado. Pode-se instalá-lo com o seguinte comando:

```sudo apt-get install make```

### Compilação:
Na raiz do projeto onde está localizado o arquivo Makefile, execute o seguinte comando no terminal:

```make build``` ou apenas ```make```.

### Execução:
Da mesma forma que compilamos o projeto, no mesmo diretório, ou seja, onde está o arquivo Makefile, execute o seguinte comando:

```make run```

Ou execute o binário compilado, que deve estar na raiz do projeto.

---
## Usando Comandos Bash:
Caso tenha tido problemas na utilização do Make, ou não queira utilizá-lo.

### Compilação:
Na raiz, execute o seguinte comando

```gcc $(ls src/*) -o 21-de-console```


### Execução:
Execute o arquivo gerado na raiz

```./21-de-console```

---
**Obs**: testado apenas em ambiente Linux, não recomendamos executar este projeto em ambiente Windows.
