# ContactList
# Introdução 
Este é um exemplo de um código em linguagem C desenvolvido para armazenar contatos em uma tabela hash. A tabela hash é uma estrutura de dados eficiente para armazenar e recuperar informações com base em chaves. Neste programa, a tabela hash é utilizada para gerenciar uma lista de contatos, onde os nomes dos contatos são usados como chaves para indexar a tabela. A implementação da tabela hash permite uma inserção, busca e remoção eficientes de contatos.
# Descrição 
O código em questão consiste na utilização da tabela para esse armazenamento de contatos e também o método da dobra para a função de espalhamento na tabela. Além disso, o código inclui funções para inserção, busca e remoção de contatos na tabela hash. A função de inserção permite ao usuário adicionar novos contatos à lista, enquanto a função de busca permite encontrar um contato específico com base em seu nome. Por fim, a função de remoção possibilita ao usuário remover um contato existente da lista de contatos armazenada na tabela hash.
# Funções utilizadas
* <strong> int HashDobra; </strong>  esta função calcula um valor hash para uma chave de string usando o método de dobra, que visa distribuir uniformemente as chaves na tabela hash.

* <strong> void inserir </strong> serve para adicionar um novo contato à tabela hash de contatos. Onde, aloca memória para armazenar as informações e utiliza o metódo da dobra.

* <strong> void buscar </strong> tem como objetivo encontrar um contato na tabela hash com base no nome fornecido como parâmetro.

* <strong> void RemoverContato </strong>  é responsável por remover um contato da tabela hash com base no nome fornecido como parâmetro. 

# vantagens e desvantagens de usar a tabela hash
## vantagens 
* <strong> Acesso rápido: </strong> Em média, a busca, inserção e remoção em uma tabela hash têm complexidade de tempo O(1), o que significa que essas operações são muito rápidas, independentemente do tamanho da tabela.

* <strong> Flexibilidade de chaves: </strong> As chaves em uma tabela hash podem ser de vários tipos de dados, não se limitando apenas a inteiros. 

## Desvantagens 
* <strong> Colisões:</strong> As colisões ocorrem quando duas chaves diferentes são mapeadas para o mesmo índice na tabela hash

* <strong> Consumo de Memória:</strong> Em algumas implementações, especialmente quando a tabela hash não está bem dimensionada em relação ao número de elementos armazenados, pode ocorrer um desperdício de memória devido a slots vazios na tabela ou a uma sobrecarga devido a técnicas de tratamento de colisões.