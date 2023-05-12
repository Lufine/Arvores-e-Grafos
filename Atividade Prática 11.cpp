/*
Aluno: Luiz Filipe Neuwirth - 2111287
Data: 12/05/2023
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define MAX_SIZE 100

typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

typedef struct BinaryTree {
    TreeNode* nodes[MAX_SIZE];
    int size;
} BinaryTree;

// Fun��o auxiliar para criar um novo n�
TreeNode* createNewNode(int data) {
    TreeNode* newNode = (TreeNode*) malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Fun��o para criar uma �rvore bin�ria vazia
BinaryTree* createBinaryTree() {
    BinaryTree* newBinaryTree = (BinaryTree*) malloc(sizeof(BinaryTree));
    newBinaryTree->size = 0;
    return newBinaryTree;
}

// Fun��o para inserir um novo n� na �rvore
void insertNode(BinaryTree* binaryTree, int data) {
    if (binaryTree->size == MAX_SIZE) {
        printf("A �rvore est� cheia.\n");
        return;
    }

    TreeNode* newNode = createNewNode(data);
    binaryTree->nodes[binaryTree->size] = newNode;
    binaryTree->size++;

    // Verifica se a �rvore � vazia
    if (binaryTree->size == 1) {
        return;
    }

    // Encontra o n� pai para inserir o novo n�
    int parentIndex = (binaryTree->size - 2) / 2;
    TreeNode* parentNode = binaryTree->nodes[parentIndex];

    // Insere o novo n� como filho do n� pai
    if (parentIndex % 2 == 0) {
        parentNode->left = newNode;
    } else {
        parentNode->right = newNode;
    }
}

// Fun��o para construir uma �rvore bin�ria a partir de uma lista de n�meros
// Esta fun��o retorna todos os elementos repetidos na lista
int* buildBinaryTreeFromList(int* list, int size, BinaryTree* binaryTree, int* repeatedElements) {
    int i, j, k;
    for (i = 0; i < size; i++) {
        int data = list[i];
        int isRepeated = 0;

        // Verifica se o elemento j� existe na �rvore
        for (j = 0; j < binaryTree->size; j++) {
            if (binaryTree->nodes[j]->data == data) {
                repeatedElements[k] = data;
                k++;
                isRepeated = 1;
                break;
            }
        }

        // Insere o elemento na �rvore
        if (!isRepeated) {
            insertNode(binaryTree, data);
        }
    }

    return repeatedElements;
}

// Fun��o principal para testar a implementa��o
int main() {
	
	setlocale(LC_ALL,"Portuguese");
    int list[] = {4, 2, 6, 3, 8, 2, 5, 7, 8, 1};
    int size = sizeof(list) / sizeof(int);

    BinaryTree* binaryTree = createBinaryTree();
    int repeatedElements[MAX_SIZE];
    int* repeated = buildBinaryTreeFromList(list, size, binaryTree, repeatedElements);

    printf("�rvore bin�ria:\n");
    for (int i = 0; i < binaryTree->size; i++)
	{
	printf("%d ", binaryTree->nodes[i]->data);
	}
	printf("\n");
	if (repeated[0] != 0) {
    	printf("Elementos repetidos na lista:");
    int i = 0;
    while (repeated[i] != 0) {
        printf("\n %d", repeated[i]);
        i++;
    }
    printf("\n");
    }

    return 0;

}