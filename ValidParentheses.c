#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>



bool isValid(char* s) {

    char memory[100];
    int top=-1;

    for(int i=0; s[i]!='\0'; i++)
    {
        if(s[i]=='(' || s[i]=='{' || s[i]=='[')
        {
            top++;
            memory[top]=s[i];
        }
        else{
            if(top == -1)return false;

            char last=memory[top];
            top--;

            if((s[i]==')' && last!='(') || (s[i]=='}' && last!='{') || (s[i]==']' && last!='['))
            {
                return false;
            }
        }
    }
    
    return top == -1;
}

int main()
{
    printf("=============================================\n");
    printf("==Code to Check Valid Parentheses in Input:==\n");
    printf("=============================================\n\n");

    char vp[20];

    printf("Input:= ");
    fgets(vp, 20, stdin);

    vp[strcspn(vp, "\n")]='\0';
     
    if(isValid(vp)){
        printf("Valid parentheses!\n");
    }else{
        printf("Invalid parentheses!\n");
    }
    
    
    return 0;
    

}