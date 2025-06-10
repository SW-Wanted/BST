#include "bst.h"

struct node {
    int chave;
    struct node* esquerda;
    struct node* direita;
};

BST* criar() {
    BST *arvore = (BST*)malloc(sizeof(BST));
    if (arvore == NULL) {
        fprintf(stderr, "Erro ao alocar memória para a árvore.\n");
        exit(EXIT_FAILURE);
    }
    arvore->chave = 0;
    arvore->esquerda = NULL;
    arvore->direita = NULL;
    return arvore;
}

BST* inserir(BST* arvore, int chave) {
    if (arvore == NULL)
    {
        arvore = criar();
        arvore->chave = chave;
        return arvore;
    }
    else if (chave < arvore->chave)
        arvore->esquerda = inserir(arvore->esquerda, chave);    

    else if (chave > arvore->chave)
        arvore->direita = inserir(arvore->direita, chave);

    return arvore;
}

int min(BST* arvore)
{
    if (arvore->esquerda == NULL)
        return arvore->chave;   

    return min(arvore->esquerda);
}

int max(BST* arvore)
{
    if (arvore->direita == NULL)
        return arvore->chave;
    
    return max(arvore->direita);
}

BST* remover(BST* arvore, int chave)
{
     // Se a árvore é nula, retorna nulo
    if (arvore == NULL)
        return NULL;

    // Se chave < Raiz -> Procurar a esquerda
    if (chave < arvore->chave)
    {
        arvore->esquerda = remover(arvore->esquerda, chave);
    }
    // Se chave > Raiz -> Procurar a direita
    else if (chave > arvore->chave)
    {
        arvore->direita = remover(arvore->direita, chave);
    }
    // Se a chave for igual a Raiz
    else
    {
        // Se o nó não tiver filhos, simplesmente remove o nó
        if (!arvore->esquerda && !arvore->direita)
        {
            free(arvore);
            return NULL;
        }
        // Se o nó tiver um filho, o seu pai passa a apontar para este filho e o nó é removido
        else if (!arvore->esquerda || !arvore->direita)
        {
            BST* temp = arvore->esquerda ? arvore->esquerda : arvore->direita;
            free(arvore);
            return temp;
        }
        // Se o nó tiver dois filhos, o nó deve ser substituído pelo:
            // nó mais à esquerda da subárvore direita ou pelo nó mais a direita da subárvore esquerda. 
            // De seguida proceder de acordo com o ponto 1 ou 2, na subárvore onde o nó foi substituído.
        else
        {
            int no_mais_a_esquerda = min(arvore->direita);
            arvore->chave = no_mais_a_esquerda;
            arvore->direita = remover(arvore->direita, no_mais_a_esquerda);
        }
    }
    return arvore;
}

BST* procurar(BST* arvore, int chave)
{
    // Se a árvore é nula, retorna NULL
    if (arvore == NULL) {
        return NULL;
    }
    // Se chave < Raiz -> Procurar a esquerda
    if (chave < arvore->chave)
    {
        return procurar(arvore->esquerda, chave);
    }
    // Se chave > Raiz -> Procurar a direita
    else if (chave > arvore->chave)
    {
        return procurar(arvore->direita, chave);
    }
    // Se a chave for igual a Raiz retorna a raiz
    else
    {
        return arvore;
    }
}

int sucessor(BST* arvore, int chave)
{
    BST* no = procurar(arvore, chave);
    if (no == NULL) {
        return -1;
    }
    
    //  1. Se a subárvore direita de um nó X existe, então o sucessor de X é o elemento mais a esquerda da subárvore direita
    if (no->direita != NULL) {
        return min(no->direita);
    }
    //  2. Por outro lado, se a subárvore direita não existir e X tiver um sucessor Y, então Y é o menor valor, maior que X que se encontra no caminho da raiz até X.
    else {
        BST* sucessor = NULL;
        
        while (arvore) {
            if (chave < arvore->chave) {
                sucessor = arvore;
                arvore = arvore->esquerda;
            } else if (chave > arvore->chave)
                arvore = arvore->direita;
            else
                break;
        }
        return sucessor ? sucessor->chave : -1;
    }
}

int antecessor(BST* arvore, int chave)
{
    BST* no = procurar(arvore, chave);
    if (no == NULL) {
        return -1;
    }
    
    //  1. Se a subárvore esquerda de um nó X existe, então o antecessor de X é o elemento mais a direita da subárvore esquerda
    if (no->esquerda != NULL) {
        return max(no->esquerda);
    }
    //  2. Por outro lado, se a subárvore esquerda não existir e X tiver um antecessor Y, então Y é o maior valor, menor que X que se encontra no caminho da raiz até X.
    else {
        BST* antecessor = NULL;
        BST* atual = arvore;
        
        while (atual != NULL) {
            if (chave < atual->chave) {
                atual = atual->esquerda;
            } else if (chave > atual->chave) {
                antecessor = atual;
                atual = atual->direita;
            } else {
                break;
            }
        }
        return antecessor ? antecessor->chave : -1;
    }
}

void bst_preorder(BST* arvore)
{
    if (arvore != NULL) {
        printf("%d ", arvore->chave);
        bst_preorder(arvore->esquerda);
        bst_preorder(arvore->direita);
    }
}

void bst_inorder(BST* arvore)
{
    if (arvore != NULL) {
        bst_inorder(arvore->esquerda);
        printf("%d ", arvore->chave);
        bst_inorder(arvore->direita);
    }
}

void bst_postorder(BST* arvore)
{
    if (arvore != NULL) {
        bst_postorder(arvore->esquerda);
        bst_postorder(arvore->direita);
        printf("%d ", arvore->chave);
    }
}

void destruir(BST* arvore)
{
    // A arvore é nula?
    if (arvore != NULL) {
        // Destruir todos os filhos à esquerda
        destruir(arvore->esquerda);

        // Destruir todos os filhos à direita
        destruir(arvore->direita);

        // Destruir o nó atual
        free(arvore);
    }
}