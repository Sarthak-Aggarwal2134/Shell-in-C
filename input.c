#include "allheaders.h"
typedef long long ll;
void input(char *add_root)
{
    ll i,j,k;
    char input_str[10000], tokens[100][10000];
    ll len;
    ll cnt_token=0;
    char* trimmed_str=(char*)malloc(sizeof(char)*10000);
    
    if(fgets(input_str,10000,stdin)==NULL)
    {
        printf("\n");exit(0);
        
    }
    add_history(input_str);
    char * token = strtok(input_str, ";");
    while(token!=NULL)
    {
        for(j=strlen(token)-1;j>=0;j--)
        {
            if(token[j]!='\n')
            {if(token[j]!=' '){
                break;}
            }
        }
        len = strlen(token);
        i=0;
        while(i<len)
        {   
            if(token[i]!=' ')
            {
                break;
            }i++;
        }

        if(j!=-1)
        {     
            k=0;
            while(i<=j)
            {
                tokens[cnt_token][k++]=token[i];
                i++;     
            }
            tokens[cnt_token][k]='\0';
            cnt_token++;
        }
        token=strtok(NULL, ";");
    }

   
    for(ll t=0;t<cnt_token;t++)
    {
        piping(tokens[t],add_root);
    }
}
