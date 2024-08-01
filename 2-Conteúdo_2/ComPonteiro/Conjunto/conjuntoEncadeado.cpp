/*Escreva uma implementação de conjunto via lista duplamente encadeada, incorporando os elementos das 2 questões anteriores e mais, como segue:
Utilize uma lista duplamente encadeada;
Utilize um nó sentinela para marcar o início e o fim da lista, observando que um único nó sentinela é suficiente para marcar início e fim, pois ele pode ser simultaneamente o "anterior do primeiro" e o "próximo do último" (lista circular);
Observe que o nó sentinela não precisa ser alocado dinamicamente: ele pode ser um campo da estrutura do conjunto, assim como o ponteiro para o início da lista é um campo dessa estrutura;
Observe também que, se o nó sentinela for um campo da estrutura do conjunto, então o ponteiro "início" não é mais necessário, pois o início e o fim da lista são acessíveis diretamente a partir do nó sentinela;
Observe que, ao procurar um elemento, nós não precisamos fazer 2 testes por iteração. Mais especificamente, em cada iteração, ao invés de testar "1. chegamos ao final da lista (isto é, ao nó sentinela)?" e "2. Achamos o elemento procurado no nó atual?", basta testar "2. Achamos o elemento procurado no nó atual?", desde que, antes de iniciar o percurso, nós tenhamos copiado no nó sentinela o elemento a ser procurado. Observe que, nesse caso, o elemento procurado sempre vai ser encontrado, quer num nó da lista propriamente dito (caso o elemento procurado pertença ao conjunto), quer no nó sentinela (caso o elemento não esteja no conjunto), onde nós colocamos o elemento antes de iniciar o laço da busca; por essa razão, ao encontrar o elemento procurado, é necessário testar se ele foi encontrado no nó sentinela ou não, pois isso determinará se o elemento de fato está no conjunto ou não.
*/

#include <iostream>

using namespace std;

typedef int TipoItem;


