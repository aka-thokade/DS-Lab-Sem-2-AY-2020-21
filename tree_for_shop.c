/* You have to maintain information for a shop owner. For each of the products sold in his/hers shop the following information is kept: 
a unique code, a name, a price, amount in stock, date received, expiration date. For keeping track of its stock, the clerk would use 
a computer program based on a search tree data structure. Write a program to help this person, by implementing the following operations:
• Insert an item with all its associated data. 
• Find an item by its code, and support updating of the item found. 
• List valid items in lexicographic order of their names. */

//uses a key that is the first character of the name

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Stack{
    struct Node* tree_node;
    struct Stack* next;
};

struct Item {
    int uniqueCode;
    char name[30];
    float price;
    char dateReceived[10];
    int stockAmt;
    char expirationDate[10];
};

struct Node {
    char key;
    struct Item prod;
    struct Node* leftChild;
    struct Node* rightChild;
};

struct Node* root = NULL;

//stack functions
void push(struct Stack** top_ref, struct Node *t){
    //allocate treeNode
    struct Stack* new_treeNode = (struct Stack*) malloc(sizeof(struct Stack));
 
    if(new_treeNode == NULL){
        printf("Stack Overflow \n");
        getchar();
        exit(0);
    }            
 
    //put in the data
    new_treeNode->tree_node = t;
 
    //link the old list off the new treeNode
    new_treeNode->next = (*top_ref);   
 
    //move the head to point to the new treeNode
    (*top_ref) = new_treeNode;
}
 
//returns true if stack is empty, otherwise false
bool isEmpty(struct Stack *top){
    return (top == NULL)? true : false;
}
 
//Function to pop an item from stack
struct Node *pop(struct Stack** top_ref){
    struct Node *res;
    struct Stack *top;
 
    //If Stack is empty then error
    if(isEmpty(*top_ref)){
        printf("Stack Underflow \n");
        getchar();
        exit(0);
    }
    else{
        top = *top_ref;
        res = top->tree_node;
        *top_ref = top->next;
        free(top);
        return res;
    }
}

void insert(){
    struct Node *temp, *parent;
    temp = (struct Node*) malloc(sizeof(struct Node));
    
    //get product details
    printf("Enter unique code: ");
    scanf("%d" , &temp->prod.uniqueCode);
    printf("Enter name: ");
    scanf("%s", temp->prod.name);
    printf("Enter price: ");
    scanf("%f", &temp->prod.price);
    printf("Enter amount in stock: ");
    scanf("%d", &temp->prod.stockAmt);
    printf("Enter date received (dd/mm/yyyy): ");
    scanf("%s", temp->prod.dateReceived);
    printf("Enter expiration date (dd/mm/yyyy): ");
    scanf("%s", temp->prod.expirationDate);

    //assign key as first char of the name. done for lexicographical order
    temp->key = temp->prod.name[0];
    temp->leftChild = NULL;
    temp->rightChild = NULL;
    
    parent = root;

    //empty tree check
    if (root == NULL){
        root = temp;
    }
    else {
        struct Node* curr;
        curr = root;
        
        while(curr){

            parent = curr;

            if(temp->key > curr->key){
                //go to the right tree
                curr = curr->rightChild ;
            }
            else{
                //go to the left tree
                curr = curr->leftChild;
            }
        }

        //we have the parent node where we need to connect the temp node now
        //check left or right
        if(temp->key > parent->key){
            //connect to right
            parent->rightChild = temp;
        }
        else{
            //connect to left
            parent->leftChild = temp;
        }
    }
}

/* void search(struct Node* temp, int code)
{
    temp = root;
    //root is null
    if (temp == NULL){
        printf("\nTree is empty!");
    }

    //key is present at temp
    else if(temp->key == code){
        printf("\nItem found!");
    }
       
    //code is greater than curr node key, implies right tree
    else if (code > temp->key){
        search(temp->rightChild, code);
    }
       
    //code is less than curr node key, implies right tree
    else if (code < temp->key){
        search(temp->leftChild, code);
    }
    
    else
        printf ("Not found!");
} */

void search(struct Node* temp, int code){
    
    //left tree
    if (temp->leftChild){
        search(temp->leftChild, code);
    }
    
    if(temp->prod.uniqueCode == code){
        printf("\nItem found!\n\nProdcut Details: ");
        
        printf("Code: %d\nName: %s\nPrice: %f\nIn Stock: %d\nReceive Date: %s\nExp. Date: %s", temp->prod.uniqueCode, temp->prod.name, temp->prod.price, temp->prod.stockAmt, temp->prod.dateReceived, temp->prod.expirationDate);

        char choice;
        printf("\nDo you want to update these details? y/n ");
        scanf("%c ", &choice);

        if(choice == 'y' || choice == 'Y'){
            printf("Enter updated unique code: ");
            scanf("%d" , &temp->prod.uniqueCode);
            printf("Enter updated name: ");
            scanf("%s", temp->prod.name);
            printf("Enter updated price: ");
            scanf("%f", &temp->prod.price);
            printf("Enter upadted amount in stock: ");
            scanf("%d", &temp->prod.stockAmt);
            printf("Enter upadted date received (dd/mm/yyyy): ");
            scanf("%s", temp->prod.dateReceived);
            printf("Enter upadted expiration date (dd/mm/yyyy): ");
            scanf("%s", temp->prod.expirationDate);
            
            return;
        }
    }
    else{
        printf("Not quite there yet...");
        return;
    }

    //right tree
    if(temp->rightChild){
        search(temp->rightChild, code);
    }
}

/* void inOdrder(struct Node* temp){
    //left tree
    if (temp->leftChild){
        inOdrder(temp->leftChild);
    }
    printf("\t| %s \t| %d \t| %f \t| %d \t| %s \t| %s |\n", temp->prod.name, temp->prod.uniqueCode, temp->prod.price, temp->prod.stockAmt, temp->prod.dateReceived, temp->prod.expirationDate);
    
    //right tree
    if (temp->rightChild){
        inOdrder(temp->rightChild);
    }
} */

void inOrder(struct Node *temp){
    //set curr to root of binary tree
    struct Node *curr = temp;
    struct Stack *s = NULL;
    bool done = 0;
 
    while (!done){
        //Reach the left most Node of the curr Node 
        if(curr !=  NULL){
            //place pointer to a tree node on the stack before traversing the node's left subtree
            push(&s, curr);                                               
            curr = curr->leftChild;  
        }

        //backtrack from the empty subtree and visit the Node at the top of the stack
        //pop from the left tree when null is reached and print
        else{
            if (!isEmpty(s)){
                curr = pop(&s);
                printf("\t| %s \t| %d \t| %f \t| %d \t| %s \t| %s |\n", curr->prod.name, curr->prod.uniqueCode, curr->prod.price, curr->prod.stockAmt, curr->prod.dateReceived, curr->prod.expirationDate);
 
                //right tree
                curr = curr->rightChild;
            }
            
            //stack is empty now, so change status of done
            else
                done = 1; 
        }
    }
} 

int main(){
    
    int numProd, code, choice;

    while(1){
        printf("Menu: 1. Insert\t2. Search\t3. List All\t4. Exit\nYour choice?");
        scanf("%d", &choice);
        
        switch (choice)
        {
        case 1:
                printf("How many products do you want to enter?");
                scanf("%d", &numProd);

                for(int i = 0; i < numProd; ++i){
                    printf("For product %d, \n", i+1);
                    insert();
                }

                break;

        case 2:
                printf("\nEnter code to search for: ");
                scanf("%d", &code);
                search(root, code);
                break;

        case 3:
                printf("\n\t| Name \t\t| Code \t| Price \t| Stock | Receive Date \t| Exp. Date  |\n");
                inOrder(root);
                break;

        case 4:
                return 0;
        default:
                printf("\nInvalid Choice!\n\n");    
                break;
        }
    
    }
    
    return 0;
}