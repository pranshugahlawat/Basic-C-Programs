#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* create() {
    int x;
    scanf("%d", &x);
    if (x == -1) return NULL;
    struct Node *n = (struct Node*)malloc(sizeof(struct Node));
    n->data = x;
    printf("Enter left child of %d (-1 for NULL): ", x); n->left = create();
    printf("Enter right child of %d (-1 for NULL): ", x); n->right = create();
    return n;
}

void inorder(struct Node *r) { if (r) { inorder(r->left); printf("%d ", r->data); inorder(r->right); } }
void preorder(struct Node *r) { if (r) { printf("%d ", r->data); preorder(r->left); preorder(r->right); } }
void postorder(struct Node *r) { if (r) { postorder(r->left); postorder(r->right); printf("%d ", r->data); } }

int search(struct Node *r, int k) {
    if (!r) return 0;
    if (r->data == k) return 1;
    return search(r->left, k) || search(r->right, k);
}

int totalNodes(struct Node *r) { return r ? 1 + totalNodes(r->left) + totalNodes(r->right) : 0; }
int leafNodes(struct Node *r) {
    if (!r) return 0;
    if (!r->left && !r->right) return 1;
    return leafNodes(r->left) + leafNodes(r->right);
}

int height(struct Node *r) {
    if (!r) return 0;
    int l = height(r->left), rt = height(r->right);
    return (l > rt ? l : rt) + 1;
}

int countLevelNodes(struct Node *r, int level) {
    if (!r) return 0;
    if (level == 1) return 1;
    return countLevelNodes(r->left, level - 1) + countLevelNodes(r->right, level - 1);
}

void mirrorTree(struct Node *r) {
    if (!r) return;
    mirrorTree(r->left); mirrorTree(r->right);
    struct Node *t = r->left; r->left = r->right; r->right = t;
}

void deleteTree(struct Node *r) {
    if (!r) return;
    deleteTree(r->left); deleteTree(r->right);
    free(r);
}

int main() {
    printf("Enter root data (-1 for NULL): ");
    struct Node *root = create();

    printf("\nInorder: "); inorder(root);
    printf("\nPreorder: "); preorder(root);
    printf("\nPostorder: "); postorder(root);

    int tot = totalNodes(root), leaves = leafNodes(root);
    printf("\nTotal Nodes: %d | Leaf Nodes: %d | Internal Nodes: %d\n", tot, leaves, tot - leaves);
    printf("Height of Tree: %d\n", height(root));
    printf("Nodes at Level 2: %d\n", countLevelNodes(root, 2));
    printf("Search for 20: %s\n", search(root, 20) ? "Found" : "Not Found");

    mirrorTree(root);
    printf("Inorder of Mirror Tree: "); inorder(root); printf("\n");

    deleteTree(root);
    return 0;
}