//Name- Daksh Joshi   Enrollment number-01414002026
//10. Implement recursive algorithm for BST traversal- In-order, Pre-order and Post-order. (CO2)


//Name- Daksh Joshi   Enrollment number-01414002026
//10. Implement recursive algorithm for BST traversal- In-order, Pre-order and Post-order. (CO2)

#include <stdio.h>
#include <stdlib.h>

struct N {
    int data;
    struct N* left;
    struct N* right;
};

struct N *cn(int key) {
    struct N* newn = (struct N*)malloc(sizeof(struct N));
    newn->data = key;
    newn->left = NULL;
    newn->right = NULL;
    return newn;
}

struct N* insert(struct N* root, int key) {
    if (root == NULL)
        return cn(key);
    if (key < root->data)
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);
    return root;
}

void inorder(struct N* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct N* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct N* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    struct N* root = NULL;

    root = insert(root, 50);
    insert(root, 37);
    insert(root, 76);
    insert(root, 22);
    insert(root, 11);
    insert(root, 60);
    insert(root, 42);
    insert(root, 23);
    insert(root, 75);
    insert(root, 47);
    insert(root, 52);
    insert(root, 53);

    printf("Inorder: ");
    inorder(root);

    printf("\nPreorder: ");
    preorder(root);

    printf("\nPostorder: ");
    postorder(root);

    return 0;
}
