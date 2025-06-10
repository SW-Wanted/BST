#  BST - Binary Search Tree
## O que é uma BST?

Uma **BST** (*Binary Search Tree* ou Árvore Binária de Busca) é uma estrutura de dados em árvore onde, para cada nó, os valores à esquerda são menores e à direita, maiores. Não é necessariamente balanceada.

**Árvore balanceada**: diferença de altura entre subárvores de qualquer nó é pequena (máx. 1), garantindo operações eficientes ($O(\log n)$). Exemplos: [AVL](https://github.com/SW-Wanted/AVL), Red-Black Tree.

## Complexidade (Análise Assintótica)

A **complexidade** ou **análise assintótica** descreve o custo das operações em função do tamanho da entrada ($n$):

- **$O(1)$**: tempo constante, independente do tamanho da árvore.
- **$O(\log n)$**: tempo logarítmico, típico de árvores balanceadas.
- **$O(n)$**: tempo linear, ocorre em árvores desbalanceadas (pior caso).

A eficiência das operações depende da altura da árvore ($h$):

- Árvores balanceadas: $h \approx \log n$
- Árvores desbalanceadas: $h \approx n$

Por isso, balancear a árvore é fundamental para garantir boas performances.

- BSTs desbalanceadas podem ter desempenho ruim ($O(n)$).
- Para garantir eficiência $O(\log n)$, use árvores balanceadas ([AVL](https://github.com/SW-Wanted/AVL), Red-Black).


## Estrutura do Nó

```c
typedef struct node {
    int chave;
    struct node* esquerda;
    struct node* direita;
} BST;
```

## Implementações

### Criar uma BST
```c
BST* criar() {
    // Aloca memória para a árvore
    // Inicializa os ponteiros esquerda e direita como NULL
    // Inicializa a chave (opcional)
    // Retorna o ponteiro para a nova árvore
}
```
**Complexidade:** $O(1)$

### Inserir uma chave
```c
BST* inserir(BST* arvore, int chave) {
    // Se a árvore estiver vazia
        // Criar um novo nó
        // Atribua a nova chave
    
    // Se a chave existir, e for menor que a chave do nó atual
        // insere à esquerda  

    // Se a chave existir, e for maior que a chave do nó atual
        // insere à direita

    // Retorna a arvore
}
```
**Complexidade:** $O(h)$, onde $h$ é a altura da árvore ($O(\log n)$ para árvores balanceadas, $O(n)$ no pior caso)

### Procurar uma chave
```c
BST* procurar(BST* arvore, int chave)
{
    // Se a árvore é nula, retorna NULL

    // Se chave < Raiz -> Procurar à esquerda

    // Se chave > Raiz -> Procurar à direita

    // Se a chave for igual à Raiz retorna a raiz
}
```
**Complexidade:** $O(h)$

### Remover uma chave
```c
BST* remover(BST* arvore, int chave)
{
    // Se a árvore é nula, retorna nulo

    // Se chave < Raiz -> Procurar à esquerda

    // Se chave > Raiz -> Procurar à direita

    // Se a chave for igual à Raiz:
        // Caso 1: Nó folha (sem filhos)
            // Remove o nó
        // Caso 2: Nó com um filho
            // Substitui o nó pelo filho
        // Caso 3: Nó com dois filhos
            // Substitui o nó pelo menor valor da subárvore direita
            // Remove o nó substituído recursivamente

    // Retorna a árvore
}
```
**Complexidade:** $O(h)$

### Imprimir
#### pre-order: raiz - esquerda - direita
```c
void bst_preorder(BST* arvore)
{
    // Se a árvore não for nula
        // Imprime a chave da raiz
        // Percorre a subárvore esquerda em pré-ordem
        // Percorre a subárvore direita em pré-ordem
}
```
**Complexidade:** $O(n)$

#### in-order: esquerda - raiz - direita
```c
void bst_inorder(BST* arvore)
{
    // Se a árvore não for nula
        // Percorre a subárvore esquerda em ordem
        // Imprime a chave da raiz
        // Percorre a subárvore direita em ordem
}
```
**Complexidade:** $O(n)$

#### post-order: esquerda - direita - raiz
```c
void bst_postorder(BST* arvore)
{
    // Se a árvore não for nula
        // Percorre a subárvore esquerda em pós-ordem
        // Percorre a subárvore direita em pós-ordem
        // Imprime a chave da raiz
}
```
**Complexidade:** $O(n)$

### Obter
#### **Mínimo**: Elemento mais a esquerda da árvore
```c
int min(BST* arvore)
{
    // Percorre a subárvore esquerda até encontrar o nó mais à esquerda
    // Retorna a chave desse nó
}
```
**Complexidade:** $O(h)$

#### **Máximo**: Elemento mais a direita da árvore
```c
int max(BST* arvore)
{
    // Percorre a subárvore direita até encontrar o nó mais à direita
    // Retorna a chave desse nó
}
```
**Complexidade:** $O(h)$

#### **Sucessor**: é o **Mínimo** da subárvore à direita do nó ou o menor elemento maior que o nó.
```c
int sucessor(BST* arvore, int chave)
{
    // Procura o nó com a chave
    // Se o nó tem subárvore direita:
        // O sucessor é o menor valor da subárvore direita
    // Caso contrário:
        // O sucessor é o ancestral mais próximo para o qual o nó está na subárvore esquerda
    // Retorna o valor do sucessor ou -1 se não existir
}
```
**Complexidade:** $O(h)$

#### **Antecessor**: é o **Máximo** da subárvore à esquerda do nó ou o maior elemento menor que o nó.
```c
int antecessor(BST* arvore, int chave)
{
    // Procura o nó com a chave
    // Se o nó tem subárvore esquerda:
        // O antecessor é o maior valor da subárvore esquerda
    // Caso contrário:
        // O antecessor é o ancestral mais próximo para o qual o nó está na subárvore direita
    // Retorna o valor do antecessor ou -1 se não existir
}
```
**Complexidade:** $O(h)$

### Destruir uma BST
```c
void destruir(BST* arvore)
{
    // Se a árvore não for nula
        // Destruir todos os filhos à esquerda
        // Destruir todos os filhos à direita
        // Destruir a arvore
}
```
**Complexidade:** $O(n)$