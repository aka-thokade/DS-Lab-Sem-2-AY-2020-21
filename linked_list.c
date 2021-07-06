#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct node{
    int data;
    struct node* link;
};

struct node* head1 = NULL;
struct node* head2 = NULL;
struct node* add_res = NULL;
struct node* sub_res = NULL;

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

void push(struct node** list, int data){
    struct node* temp;
    temp = (struct node*) malloc(sizeof(struct node));
    temp->data = data;
    temp->link = (*list);
    (*list) = temp;
}

void display_list(struct node *show_node){

    struct node* p;
    p = show_node;    

    do{
        printf("\nAddress: %p \tData: %d \tLink: %p", p, p->data, p->link);
        p = p->link;
    } while (p->link != NULL);
    printf("\nAddress: %p \tData: %d \tLink: %p", p, p->data, p->link);

}

void show_num(struct node* show_node){
    printf("\nAnswer = ");
    struct node* p = show_node;
    while (p->link != NULL)
    {
        printf("%d", p->data);
        p = p->link;
    }
    printf("%d", p->data); 
    
}

void add(int n1, int n2, struct node* head1, struct node* head2){

    struct node* p1 = head1;
    struct node* p2 = head2;

    int digit1, digit2, carry = 0, sum = 0;


    while(p1->link != NULL || p2->link != NULL){
        
        digit1 = p1->data;
        digit2 = p2->data;

        if(carry != 0){
            sum = carry + (digit1 + digit2)%10;
        }

        else{
            sum = (digit1 + digit2)%10;
        }
        
        carry = (digit1 + digit2)/10;

        /* if(carry != 0){
            sum = (carry + (p1 ? p1->data : 0) + (p2 ? p2->data : 0))%10;
        }

        else{
            sum = ((p1 ? p1->data : 0) + (p2 ? p2->data : 0))%10;
        }
        
        carry = (carry + (p1 ? p1->data : 0) + (p2 ? p2->data : 0))/10; */

        push(&add_res, sum);

        p1 = p1->link;
        p2 = p2->link;

    }
    
    //if it's the last node, do the following once
    digit1 = p1->data;
    digit2 = p2->data;

    if(carry != 0){
        sum = carry + (digit1 + digit2)%10;
    }

    else{
        sum = (digit1 + digit2)%10;
    }
        
    carry = (digit1 + digit2)/10;
    
    push(&add_res, sum);
    carry == 0 ? " " : push(&add_res, carry);
    
}

void sub(int n1, int n2, struct node* head1, struct node* head2){
    
    struct node* p1 = head1;
    struct node* p2 = head2;

    int digit1, digit2, borrow = 0, diff = 0;

    while(p1->link != NULL || p2->link != NULL){
        digit1 = p1->data;
        digit2 = p2->data;

        if(borrow == 0){
            if (digit1 > digit2){
                diff =  digit1 - digit2;
            }
            
            else{
                borrow = 1;
                diff = ((digit1 + 10) - digit2);
            }
            
        }

        else{
            if (digit1 > digit2){
                diff =  digit1 - (digit2 + 1);
            }
            
            else{
                borrow = 1;
                diff = ((digit1 + 10) - (digit2 + 1));
            }
        }

        push(&sub_res, diff);

        p1 = p1->link;
        p2 = p2->link;

    }

        // if it's the last node, do the following once
        digit1 = p1->data;
        digit2 = p2->data;

        if(borrow == 0){
            if (digit1 > digit2){
                diff =  digit1 - digit2;
            }
            
            else{
                borrow = 1;
                diff = ((digit1 + 10) - digit2);
            }
            
        }

        else{
            if (digit1 > digit2){
                diff =  digit1 - (digit2 + 1);
            }
            
            else{
                borrow = 1;
                diff = ((digit1 + 10) - (digit2 + 1));
            }
        }

        push(&sub_res, diff);
    
}

int main(){
    
    int n1, n2, digit;

    printf("How many digits are the first number?");
    scanf("%d", &n1);
    printf("How many digits are the second number?");
    scanf("%d", &n2);

    printf("Enter digits for first number starting from unit's place: ");
    for (int i = 0; i < n1; ++i)
    {
        scanf("%d", &digit);
        append(&head1, digit);
    }

    printf("Enter digits for second number starting from unit's place: ");
    for (int i = 0; i < n2; ++i)
    {
        scanf("%d", &digit);
        append(&head2, digit);
    }

    // take_num(n1, n2, head1, head2);
    
    printf("\nList 1: ");
    display_list(head1);
    printf("\n\nList 2: ");
    display_list(head2);
    
    printf("\n\nAddition: ");
    add(n1, n2, head1, head2);
    show_num(add_res);
    printf("\nResult List: ");
    display_list(add_res);

    printf("\n\nSubtraction: ");
    sub(n1, n2, head1, head2);
    show_num(sub_res);
    printf("\nResult List: ");
    display_list(sub_res);
   
    
    return 0;

}