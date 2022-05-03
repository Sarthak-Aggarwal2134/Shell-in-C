#include "allheaders.h"
typedef long long ll;
void cd(char * input_str, char * add_root)
{
    ll i,j,k,len,status;
    char* new_dir=(char*)malloc(sizeof(char)*10000);
    char* temp=(char*)malloc(sizeof(char)*10000);
    len = strlen(input_str);
    for(i=2;i<len;i++)
    {
        if(input_str[i]!=' ')
        {
            break;
        }
        else{
            continue;
        }
    }
    if(input_str[i]=='-')
    {
        j=0;
        i=i+1;
        for(;i<len;i++)
        {
            if(input_str[i]!=' ')
            {
                printf("Extra arguments");
                printf("\n");
                return;
            }else{
                continue;
            }
        }

        strcpy(new_dir,lwd);
    }
    else if(input_str[i]=='~')
    {
        i=i+1;
        strcpy(new_dir,add_root);
        j=strlen(add_root);
        for(;i<len;i++)
        {
            if(input_str[i]==' ')
            {
                printf("Extra arguments");
                printf("\n");
                return;
            }
            else
            {
                new_dir[j++]=input_str[i];
                continue;
            }
        }
        new_dir[j]='\0';
    }
    else
    {
        j=0;
        for(;i<len;i++)
        {
            if(input_str[i]==' ')
            {
                printf("Extra arguments");
                printf("\n");
                return;
            }
            else
            {
                new_dir[j++]=input_str[i];
                continue;
            }
        }
        new_dir[j]='\0';
    }
    // printf("directory: %s\n",new_dir);
    getcwd(temp,10000);
    status=chdir(new_dir);

    if(status!=-1)
    {
        strcpy(lwd,temp);
        
    }
    else
    {
        printf("No such file or directory exists");
        printf("\n");
    }
}