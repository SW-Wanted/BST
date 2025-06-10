#include "bst.h"

int main() {
	BST* arvore = NULL;

	arvore = inserir(arvore, 10);
	arvore = inserir(arvore, 5);
	arvore = inserir(arvore, 15);
	arvore = inserir(arvore, 3);
	arvore = inserir(arvore, 7);
	arvore = inserir(arvore, 12);
	arvore = inserir(arvore, 18);
	arvore = inserir(arvore, 1);

	printf("Arvore em pre-ordem: ");
	bst_preorder(arvore);
	printf("\n");

	printf("Arvore em in-ordem: ");
	bst_inorder(arvore);
	printf("\n");

	printf("Arvore em pos-ordem: ");
	bst_postorder(arvore);
	printf("\n");

	if (procurar(arvore, 7) != NULL)
		printf("Elemento 7 encontrado na arvore.\n");
	else 
		printf("Elemento 7 não encontrado na arvore.\n");

	arvore = remover(arvore, 7);
	printf("7 foi removido!\n");

	printf("Arvore em in-ordem: ");
	bst_inorder(arvore);
	printf("\n");

	printf("Minimo: %d\n", min(arvore));
	printf("Maximo: %d\n", max(arvore));
	
	printf("Sucessor de 5: %d\n", sucessor(arvore, 5));
	printf("Antecessor de 15: %d\n", antecessor(arvore, 15));

	destruir(arvore);
	return 0;
}
