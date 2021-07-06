// AVL Tree to implement following operations: (For nodes as integers). Insertion: Test program for all cases (LL, RR, RL, LR rotation).

#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	int height;
};

// to find greater of two
int max(int a, int b)
{
	return (a > b)? a : b;
}

// to get the height of the tree
int height(struct Node *N)
{
	if (N == NULL)
		return 0;
	return N->height;
}

// new node with empty left and right trees
struct Node* newNode(int data)
{
	struct Node* node = (struct Node*)malloc(sizeof(struct Node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	node->height = 1; // because it is at leaf first
	return(node);
}

struct Node *LL(struct Node *z)
{
	struct Node *T = z->left;
	struct Node *temp = T->right;

	T->right = z;
	z->left = temp;

	// Update heights
	z->height = max(height(z->left), height(z->right))+1;
	T->height = max(height(T->left), height(T->right))+1;

	return T;
}

struct Node *RR(struct Node *z)
{
	struct Node *T = z->right;
	struct Node *temp = T->left;

	T->left = z;
	z->right = temp;

	// Update heights
	z->height = max(height(z->left), height(z->right))+1;
	T->height = max(height(T->left), height(T->right))+1;

	return T;
}

int getBalance(struct Node *N)
{
	if (N == NULL)
		return 0;
	return height(N->left) - height(N->right);
}

struct Node* insert(struct Node* node, int data)
{
	// normal BST insertion
	if (node == NULL)
		return(newNode(data));
    
    else {
        // left tree
        if (data < node->data)
		    node->left = insert(node->left, data);
	    
        // right tree
        else 
		    node->right = insert(node->right, data);
    }

	node->height = 1 + max(height(node->left), height(node->right));

	int balance = getBalance(node);

	// balance is more than 1 for LL, and data is added to left of left.
	if (balance > 1 && data < node->left->data)
		return LL(node);

	// balance is less than 1 for RR, and data is added to right of right.
	if (balance < -1 && data > node->right->data)
		return RR(node);

	// balance is more than 1 for LR, and data is added to right of left.
	if (balance > 1 && data > node->left->data)
	{
		node->left = RR(node->left);        //RR on left of node then LL on node
		return LL(node);
	}

	// balance is less than 1 for RL, and data is added to left of right.
	if (balance < -1 && data < node->right->data)
	{
		node->right = LL(node->right);      //LL on right of node then RR on node
		return RR(node);
	}

	// return the (unchanged) node pointer
	return node;
}

void preOrder(struct Node *root)
{
	if(root != NULL)
	{
		printf("%d ", root->data);
		preOrder(root->left);
		preOrder(root->right);
	}
}

int main()
{
    struct Node *root = NULL;

    int numNodes, nodeData;

    printf("How many nodes do you want to enter? ");
    scanf("%d", &numNodes);
    for(int i = 0; i < numNodes; ++i){
        printf("Enter node %d: ", i+1);
        scanf("%d", &nodeData);
		root = insert(root, nodeData);
    }	

    printf("Preorder traversal of the constructed AVL tree is \n");
    preOrder(root);

    return 0;
}
