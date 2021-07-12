# Introduction

<!-- TODO -->
O presente projeto é uma implementação em formato de texto do jogo Keno. O Keno é um jogo de apostas popular que possui similaridade com uma loteria ou bingo. Nele, os jogadores fazem apostas e escolhem de um a vinte números entre 1 e 80, inclusive. Após a seleção desses números pelos jogadores, o Keno sorteia vinte números aleatórios dentro da faixa de 1 a 80. 

Após isso, é feita uma comparação entre os números selecionados pelos jogadores e os sorteados pelo Keno. Então, os jogadores recebem um pagamento com base na quantidade de números que eles escolheram que coincidiram com os sorteados. 

Para jogar esta versão, é necessário que o usuário crie seu arquivo de aposta e o coloque dentro da pasta "data" com a extensão ".dat". Nele, deve conter o valor a ser apostado (valor até 100000), a quantidade de rounds (rodadas a serem jogadas) e os números selecionados (até 15 números de 1 a 80).

# Author(s)

<!-- TODO -->
Gregorio Pinheiro Cunha e Thiago de Oliveira Cordeiro.

# Problems found or limitations

<!-- TODO -->
Lista aqui os problemas encontrados (se houve algum) e as
possíveis limitações do programa.

Não foram encontrados problemas ou limitações do programa.

# Grading

<!-- TODO -->
Preencha os itens que você implementou.

- [ X ] Receives input data via command line (5 credits);
- [ X ] Correctly handles the input bet file, treating both regular and problematic cases accordingly (20 credits);
- [ X ] Codes correctly the KenoBet class, according to the description provided in Code 1 (25 credits);
- [ X ] Executes correctly the amount of rounds defined in the input bet file (15 credits);
- [ X ] Identifies correctly the hits and the player’s payoff for every round (20 credits);
- [ X ] Displays correctly the information requested in Section 2.2 (15 credits).


# Compiling and Running

<!-- TODO -->
Indique aqui como compilar e executar seu programa.
```bash
# Acesse a pasta source do projeto 
$ cd source

# Acesse a pasta core do projeto 
$ cd core

# Compilar
$ g++ main.cpp keno_bet.cpp keno_game.cpp enter.cpp  -Wall -std=c++11 -o keno 

# Execução (exemplo)
$ ./keno bet_04.dat
```
