#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

typedef struct BST {
    TreeNode* root;
} BST;

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
    if (root == NULL) {
        return createNewNode(data);
    }

    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else {
        root->right = insertNode(root->right, data);
    }

    return root;
}

// Fun��o para realizar a travessia em pr�-ordem
void preOrderTraversal(TreeNode* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

// Fun��o para realizar a travessia em ordem
void inOrderTraversal(TreeNode* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

// Fun��o para realizar a travessia em p�s-ordem
void postOrderTraversal(TreeNode* root) {
    if (root != NULL) {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%d ", root->data);
    }
}

// Fun��o principal para testar a implementa��o
int main() {
	
	setlocale(LC_ALL,"Portuguese");
    int values[] = {53, 30, 14, 39, 9, 23, 34, 49, 72, 61, 84, 79, 2, 3, 27, 31};
    int size = sizeof(values) / sizeof(int);

    BST* bst = (BST*) malloc(sizeof(BST));
    bst->root = NULL;

    // Insere os valores iniciais na �rvore
    for (int i = 0; i < size; i++) {
        bst->root = insertNode(bst->root, values[i]);
    }

    // Realiza as travessias
    printf("Travessia em pr�-ordem: ");
    preOrderTraversal(bst->root);
    printf("\n\n");

    printf("Travessia em ordem: ");
    inOrderTraversal(bst->root);
    printf("\n\n");

    printf("Travessia em p�s-ordem: ");
    postOrderTraversal(bst->root);
    printf("\n\n");

    // Insere novos valores na �rvore
    int value;
    do {
    	system("pause");
    	system("cls");
        printf("Informe um valor para inserir na �rvore (ou -1 para sair): ");
        scanf("%d", &value);

        if (value != -1) {
            bst->root = insertNode(bst->root, value);

            printf("\nTravessia em pr�-ordem: ");
                    preOrderTraversal(bst->root);
        printf("\n\n");

        printf("Travessia em ordem: ");
        inOrderTraversal(bst->root);
        printf("\n\n");

        printf("Travessia em p�s-ordem: ");
        postOrderTraversal(bst->root);
        printf("\n\n");
    }
} while (value != -1);

    return 0;
}