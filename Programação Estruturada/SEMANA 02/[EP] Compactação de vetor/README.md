# Enunciado

Implemente a função compactar_vetor, que recebe um vetor de inteiros v e um valor n que representa o tamanho do vetor v. A função deve realizar a compactação dos valores seguindo um conceito similar à compressão Runlength. A compactação deve substituir cada valor no vetor por dois números: um com o valor e outro com a quantidade de vezes que o valor aparece de forma consecutiva.

Observação: Nesse processo de compactação, considere apenas os valores positivos. As posições com valores -1 serão consideradas como posições livres no vetor. Também considere que sempre haverá espaço disponível no vetor para armazenar o resultado da compactação.

Por exemplo, ao receber o vetor [10 10 10 10 10 50 50 90 -1 -1], o vetor compactado seria [10 5 50 2 90 1 -1 -1 -1 -1 ]. O número 10 aparece 5 vezes de forma consecutiva. Por isso, os primeiros números no vetor compactado são o 10 (valor) e o 5 (quantidade de vezes que o valor 10 aparece de forma consecutiva). Depois, o número 50 aparece duas vezes de forma consecutiva. Então o vetor compactado possui os números 50 (valor) e 2 (quantidade). No final, o número 90 aparece apenas uma vez e, por isso, os próximos números no vetor compactado são 90 (valor) e 1 (quantidade). O restante do vetor é preenchido com -1, pois esse valor é usado para indicar posições livres no vetor.


__Protótipo da função:__

```void compactar_vetor(int v[], int n);```

Importante: submeta apenas a função. Não use variáveis globais. Não inclua o main. Não use printf/fprintf/puts/gets/fgets/scanf/fscanf e headers adicionais (por exemplo, stdio.h e stdlib.h).


Formato do caso de teste: esse é o formato dos casos de teste que aparecem ao avaliar a atividade; não inclua impressão de dados no código, essa impressão é feita automaticamente pelo sistema de correção de acordo com o retorno da função submetida.

Entrada:

- quantidade de valores no vetor
- valores do vetor

Saída:

- vetor de entrada
- vetor após chamar a função compactar_vetor