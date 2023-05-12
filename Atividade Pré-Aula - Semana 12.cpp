/*
Aluno: Luiz Filipe Neuwirth - 2111287
Data: 12/05/2023
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// Fun��o auxiliar para criar um novo n�
TreeNode* createNewNode(int data) {
    TreeNode* newNode = (TreeNode*) malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Fun��o para inserir um novo n� na �rvore
TreeNode* insertNode(TreeNode* root, int data) {
    // Caso base: �rvore vazia ou chegou em uma folha
    if (root == NULL) {
        root = createNewNode(data);
        return root;
    }

    // Inserir na sub�rvore esquerda se o valor � menor que o n� atual
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    }
    // Inserir na sub�rvore direita se o valor � maior que o n� atual
    else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }
    // N�o permitir valores duplicados
    else {
        printf("Valor duplicado: %d\n", data);
    }

    return root;
}

// Fun��o para imprimir a �rvore em ordem (in-order traversal)
void printInOrder(TreeNode* root) {
    if (root != NULL) {
        printInOrder(root->left);
        printf("%d ", root->data);
        printInOrder(root->right);
    }
}

// Fun��o principal para testar a implementa��o
int main() {
	
	setlocale(LC_ALL,"Portuguese");
    int values[] = {53, 30, 14, 39, 9, 23, 34, 49, 72, 61, 84, 79, 2, 3, 27, 31};
    int size = sizeof(values) / sizeof(int);

    TreeNode* root = NULL;
    for (int i = 0; i < size; i++) {
        root = insertNode(root, values[i]);
    }

    printf("�rvore bin�ria em ordem:\n");
    printInOrder(root);

    return 0;
}