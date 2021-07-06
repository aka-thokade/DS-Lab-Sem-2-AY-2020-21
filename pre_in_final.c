#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

char opd_stack[30][30], opt_stack[30];
int top_opt_stack = -1, top_opd_stack = -1;

int push_opt(char opt)
{
   opt_stack[++top_opt_stack] = opt;
}

int push_opd(char *opd)
{
   strcpy(opd_stack[++top_opd_stack], opd);
}

char pop_opt()
{
   return (opt_stack[top_opt_stack--]);
}

char *pop_opd()
{
   return (opd_stack[top_opd_stack--]);
}

bool empty(int t)
{
   if (t == 0)
      return true;
   else
      return false;
}

int main()
{
   char prefix[30], ch, temp[30], opd1[30], opd2[30], opt[2];
   int count = 0, opd_count = 0;

   printf("\nEnter a Prefix Expression: ");
   scanf("%s", prefix);

   while ((ch = prefix[count++]) != '\0'){
      
      // if it is num
      if (isalnum(ch)){
         
         // push the num onto stack
         temp[0] = ch;
         temp[1] = '\0';
         push_opd(temp);
         opd_count++;
         
         // if operand count becomes 2 or more, pop two operands
         if (opd_count >= 2){
            
            strcpy(opd2, pop_opd());
            strcpy(opd1, pop_opd());
            
            // push on stack: temp ---> (op1, opt, op2)
            strcpy(temp, "(");
            strcat(temp, opd1);
            ch = pop_opt();
            opt[0] = ch;
            opt[1] = '\0';
            strcat(temp, opt);
            strcat(temp, opd2);
            strcat(temp, ")");
            push_opd(temp);
            
            opd_count = opd_count - 1;
         }
      }

      // if it is opt
      else{
         push_opt(ch);
         
         if (opd_count == 1){
            opd_count = 0;
         }
      }
   }
   
   // for last operation
   if (!empty(top_opd_stack)){
      
      strcpy(opd2, pop_opd());
      strcpy(opd1, pop_opd());
      
      // push on stack: temp ---> (op1, opt, op2)
      strcpy(temp, "(");
      strcat(temp, opd1);
      ch = pop_opt();
      opt[0] = ch;
      opt[1] = '\0';
      strcat(temp, opt);
      strcat(temp, opd2);
      strcat(temp, ")");
      
      push_opd(temp);
   }
   
   printf("\nInfix Expression: %s\n", opd_stack[top_opd_stack]);
   return 0;
}