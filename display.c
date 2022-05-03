#include "allheaders.h"
typedef long long ll;
void display(char *add_root)
{
    ll i,j,k,len_root,len_curd;
    char * add_curd,* add_display,* host,* user;
    add_curd=(char*)malloc(sizeof(char)*10000);
    add_display=(char*)malloc(sizeof(char)*10000);
    host=(char*)malloc(sizeof(char)*10000);
    char c;
    user = (char*)malloc(sizeof(char)*10000);
    len_root = strlen(add_root);
    int elsenest=0;
    int if1=0;
    int if2=0;
    getcwd(add_curd,10000);
    len_curd = strlen(add_curd);
    if(len_curd<len_root)
    {
        strcpy(add_display, add_curd);
        if1++;
    }
    else
    {
        for(i=0;i<len_root;i++)
        {
            if(add_curd[i]!=add_root[i])
            {
                strcpy(add_display,add_curd);
                if2++;
                break;
            }else{
                continue;
            }
        }

        if(i >= len_root)
        {
            add_display[0]='~';
            j=1;
            for(;i<len_curd;i++)
            {   c=add_curd[i];
                add_display[j++] = c;
            }
            add_display[j]='\0';
        }else{
            elsenest++;
        }
    }

    user = getlogin();
    gethostname(host,10000);

    printf("\033[1;31m%s@%s\033[0m:",user,host);
    printf("\033[1;34m%s\033[0m$ ",add_display);
}