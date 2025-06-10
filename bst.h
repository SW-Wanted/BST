#ifndef BST_H
#define BST_H

typedef struct node BST;

#include <stdio.h>
#include <stdlib.h>


// Cria uma nova árvore vazia
BST* criar();

// Insere um elemento
BST* inserir(BST* arvore, int chave);

// Remove um elemento
BST* remover(BST* arvore, int chave);

// Pesquisa um elemento
BST* procurar(BST* arvore, int chave);

// Imprime em ordem em 3 ordens: pre, in e pos
    // pré-ordem: Raiz -> Esquerda -> Direita
    void bst_preorder(BST* arvore);

    // in-ordem: Esquerda -> Raiz -> Direita
    void bst_inorder(BST* arvore);

    // pós-ordem: Esquerda -> Direita -> Raiz
    void bst_postorder(BST* arvore);

// Obtém o mínimo
int min(BST* arvore);

// Obtém o máximo
int max(BST* arvore);

// Obtém o sucessor de um elemento
int sucessor(BST* arvore, int chave);

// Obtém o antecessor de um elemento
int antecessor(BST* arvore, int chave);

// Destroi a árvore (libera memória)
void destruir(BST* arvore);

#endif