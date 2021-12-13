# Enunciado

Um palíndromo é uma sequência de unidades que podem ser lido igualmente da esquerda para direita ou o inverso. Exemplos de palíndromos: ARARA, REVER, RADAR, 13531, 7283827, 1234554321.

Neste exercício, implemente as funções a seguir:

- void converte_numero_para_vetor_de_digitos(int n, int v[]): esta função deve converter um número inteiro para um vetor contendo em cada item os dígitos deste número, do mais significativo para o menos significativo. Após último dígito, inclua o valor -1 para indicar o fim da sequência. Assuma que o vetor possui espaço suficiente para todos os dígitos. Por exemplo, para o número n = 246, o vetor será preenchido da seguinte forma: [2, 4, 6, -1].
- int eh_palindromo(int v[]): recebe um vetor e indica se é palíndromo (0: não, 1: sim). O vetor passado é resultado do uso do processo descrito no item anterior. Portanto, a função deverá procurar o final da sequência (valor -1) antes de realizar a verificação. A sequência [1, 2, 3, -1] não é palíndromo, mas a sequência [2, 6, 2, -1] é palíndromo.
- int maior_palindromo(int m, int fatores[2]): a função deve procurar o maior inteiro palíndromo P resultado do produto P = A x B. Neste produto, A <= m e B <= m (m é parâmetro da função). A e B são números naturais. Por exemplo, para m=25, o maior palíndromo é 575, sendo A=25 e B=23. Nesse caso, o retorno da função será 575 e os elementos no parâmetro fatores deverão ser preenchidos da seguinte forma: fatores[0]=25 e fatores[1]=23. Assuma que o vetor passado para a função possui duas posições (índices 0 e 1).


Importante: submeta apenas a função. Não use printf/fprintf/puts/gets/fgets/scanf/fscanf e headers adicionais (por exemplo, stdio.h e stdlib.h).

Formato da entrada no caso de teste (que aparece ao avaliar a atividade):<br>
```[numero] [tipo] (o tipo é a função testada: C (converte_numero_para_vetor_de_digitos), P (eh_palindromo) e M (maior_palindromo).```
