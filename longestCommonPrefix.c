#include <stdlib.h>
#include <string.h>
#include <stdio.h>


char* longestCommonPrefix(char** strs, int strsSize) {
    
    //finding the smallest string;
    int smallLength=strlen(strs[0]);
    for(int i=1; i<strsSize; i++)
    {
        int currentlen=strlen(strs[i]);
        if(smallLength<currentlen)
        {
            smallLength=currentlen;
        }
    }
    
    //create new char pointer for store prefix;;
    char *prefix=malloc((smallLength+1)*sizeof(char));

    int k=0;
    for(int j=0; j<smallLength; j++)
    {
        char currentch = strs[0][j];
        int i=1;
        for(; i<strsSize; i++)
        {
            if(currentch!=strs[i][j] || strs[i][j]=='\0')break;               
        }
        if(i<strsSize){
            break;
        }
        prefix[k++]=currentch; //storing prefix

    }
    prefix[k]='\0';

    return prefix;
  
 }

int main()
{
    int string;
    
    printf("Input number of strings: ");
    scanf("%d", &string);
    getchar();


    char *ptr[string];

    printf("Enter %d string (one per line)\n", string);
    for (int i = 0; i < string; i++)
    {
        char buffer[100];
        fgets(buffer, sizeof(buffer), stdin);

        buffer[strcspn(buffer, "\n")]='\0';

        ptr[i]=malloc(strlen(buffer)+1);
        strcpy(ptr[i], buffer);
    }

    printf("starting the string:\n");
    printf("\n===============================\n");

    int lenght= sizeof(ptr)/sizeof(ptr[0]);
    
    char *lg=longestCommonPrefix(ptr, lenght);
    printf("longest comman prefix is : %s", lg);
    printf("\n===============================\n");
    free(lg);

    for(int i=0; i<string; i++)
    {
        free(ptr[i]);
    }
    

}
