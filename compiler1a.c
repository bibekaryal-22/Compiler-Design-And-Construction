#include<stdio.h>

int main()
{
    char a[100],b[100];
    int i,j,count=0;
    do
    {    
    printf("Enter the line:");
    fgets(a, sizeof(a), stdin);
    for(i=0;i<100;i++)
    {
        if((a[i]=='/' && a[i+1]=='/'))
        {
            count++;
        }
        else if((a[i]=='/' && a[i+1]=='*'))
        {
            for(j=i+2;j<100;j++)
            {
                if((a[j]=='*' && a[j+1]=='/'))
                {
                    count=2;
                    break;
                }
            }
        }
    }
    if(count==1)
    {
        printf("The line is comment");
    }
    else if(count ==2)
    {
        printf("The line is multi line comment");
    }
    else
    {
        printf("this is not comment:");
    }
    printf("\nCONTINUE??? Y/N:");
    fgets(b, sizeof(b), stdin);
  } while (b[0]=='Y' || b[0]=='y');
    return 0;
}

