//Name- Daksh Joshi   Enrollment number-01414002026
//9. Implement recursive algorithm for performing following operations on Binary Search Tree-
//(CO2)
//a. Insertion
//b. Search

#include <stdio.h>
#include <stdlib.h>

struct N {
    int data;
    struct N* left;
    struct N* right;
};

struct N* cn(int key) {
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

struct N* search(struct N* root, int key) {
    if (root == NULL || root->data == key)
        return root;
    if (key < root->data)
        return search(root->left, key);
    return search(root->right, key);
}

int main() {
    struct N* root = NULL;
    root = insert(root, 0);
    insert(root, 1);
    insert(root, 2);
    insert(root, 3);
    insert(root, 4);
    insert(root, 5);
    insert(root, 6);

    int key;

    while(1){
    printf("\n\nEnter the number to be searched:");
    scanf("%d",&key);

    struct N* result = search(root, key);

    if (result != NULL)
        printf("Found\n");
    else
        printf("Not Found\n");
    }

    return 0;
}
