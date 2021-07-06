#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct node{
    int data;
    struct node* link;
};

struct node* head = NULL;

void append(struct node** list, int data){
    struct node* temp;
    temp = (struct node*) malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;

    // if list1 is empty
    if ((*list) == NULL){ 
        (*list) = temp;
    }
    else{
        struct node* p;
        p = (*list);
        
        // till we reach the link which is pointing to NULL
        while (p->link != NULL)
        {
            p = p->link;
        }

        p->link = temp; //temp node connected at the end
    }
}

void display(struct node *show_node){

    struct node* p;
    p = show_node;

    do{
        printf("\nAddress: %p \tData: %d \tLink: %p", p, p->data, p->link);
        p = p->link;
    } while (p->link != NULL);
    printf("\nAddress: %p \tData: %d \tLink: %p", p, p->data, p->link);

}

void add(int n1, int n2){
    struct node* p = head;

    int digit, digit1, digit2, carry = 0, sum = 0;
    long long num1 = 0, num2 = 0;

    for (int i = 0; i < n1; ++i)
    {
        digit = p->data;
        p = p->link;
        num1 = num1 + digit*(pow(10, i));
    }

    for (int i = 0; i < n2; ++i)
    {
        digit = p->data;
        p = p->link;
        num2 = num2 + digit*(pow(10, i));
    }

    printf("\n%lld + %lld = %lld", num1, num2, num1 + num2);
        
}

void sub(int n1, int n2){
    struct node* p = head;

    int digit;
    long long num1 = 0, num2 = 0;

    for (int i = 0; i < n1; ++i)
    {
        digit = p->data;
        p = p->link;
        num1 = num1 + digit*(pow(10, i));
    }

    for (int i = 0; i < n2; ++i)
    {
        digit = p->data;
        p = p->link;
        num2 = num2 + digit*(pow(10, i));
    }

    printf("\n%lld - %lld = %lld", num1, num2, num1 - num2);
    
}

void mul(int n1, int n2){
    struct node* p = head;

    int digit;
    long long num1 = 0, num2 = 0;

    for (int i = 0; i < n1; ++i)
    {
        digit = p->data;
        p = p->link;
        num1 = num1 + digit*(pow(10, i));
    }

    for (int i = 0; i < n2; ++i)
    {
        digit = p->data;
        p = p->link;
        num2 = num2 + digit*(pow(10, i));
    }

    printf("\n%lld * %lld = %lld", num1, num2, num1 * num2);
    
}

void divide(int n1, int n2){
    struct node* p = head;

    int digit;
    long long num1 = 0, num2 = 0;

    for (int i = 0; i < n1; ++i)
    {
        digit = p->data;
        p = p->link;
        num1 = num1 + digit*(pow(10, i));
    }

    for (int i = 0; i < n2; ++i)
    {
        digit = p->data;
        p = p->link;
        num2 = num2 + digit*(pow(10, i));
    }

    printf("\n%lld / %lld = %lld", num1, num2, num1 / num2);
    
}

void remain(int n1, int n2){
    struct node* p = head;

    int digit;
    long long num1 = 0, num2 = 0;

    for (int i = 0; i < n1; ++i)
    {
        digit = p->data;
        p = p->link;
        num1 = num1 + digit*(pow(10, i));
    }

    for (int i = 0; i < n2; ++i)
    {
        digit = p->data;
        p = p->link;
        num2 = num2 + digit*(pow(10, i));
    }

    printf("\n%lld %% %lld = %lld", num1, num2, num1 % num2);
    
}

int main(){
    
    int n1, n2, digit;

    printf("How many digits is the first number?");
    scanf("%d", &n1);
    printf("How many digits is the second number?");
    scanf("%d", &n2);

    printf("Enter digits for first number starting from unit's place: ");
    for (int i = 0; i < n1; ++i)
    {
        scanf("%d", &digit);
        append(&head, digit);
    }

    printf("Enter digits for second number starting from unit's place: ");
    for (int i = 0; i < n2; ++i)
    {
        scanf("%d", &digit);
        append(&head, digit);
    }

    display(head);
    printf("\n\nArithmetic Operations:");
    add(n1, n2);
    sub(n1, n2);
    mul(n1, n2);
    divide(n1, n2);
    remain(n1, n2);
    
    return 0;

}