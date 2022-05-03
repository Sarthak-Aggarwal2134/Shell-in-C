#include "allheaders.h"
typedef long long ll;
void fetch_history()
{
    ll i=0,j,k;
    size_t len = 1000;
    char * history_datapoint;
    ll flag;
    FILE *file;
    file = fopen("history.txt","ab+");
    if(!file)
    {
        printf("Error in history.txt");
        printf("\n");
        return;
    }
    
    while(1)
    {
        flag=getline(&history_datapoint,&len,file);
        if(flag==-1)
        {
            break;
        }
        j=strlen(history_datapoint);
        while(j>=0)
        {
            if(history_datapoint[j]!=' ')
            {
                if(history_datapoint[j]!='\n'){break;}
            }j--;
        }
        history_datapoint[j]='\0';
        strcpy(history_data[i%20],history_datapoint);
        i++;
        // printf("%s",history_datapoint);
    }
    hist_len = i;
}

void add_history(char * input_str)
{
    ll i;
    if(input_str[0]!=' ' && input_str[0]!='\n')
    {
        if(hist_len<20)
        {
            strcpy(history_data[hist_len],input_str);
            hist_len++;
        }
        else
        {   i=0;
            while(i<19)
            {
                strcpy(history_data[i],history_data[i+1]);
                i++;
            }
            strcpy(history_data[i],input_str);
        }
    }
}

void history(char * input_str)
{
    ll i,j,k;
    int hist_count=10;
    ll flag=0;
    ll start;
    char * history_datapoint;

    char * token = strtok(input_str," ");
    token = strtok(NULL," ");
    if(token != NULL)
    {
        hist_count = atoi(token);
    }
    else
    {
        hist_count=10;
    }

    if(hist_count>20)
    {
        hist_count=20;
    }
    
    if( hist_len-hist_count < 0)
    {
        start = 0;
    }
    else
    {
        start = hist_len-hist_count;
    }
    j=start;
    while(j<20)
    {
        printf("%s",history_data[j]);
        j++;
    }
}

void save_history()
{
    ll i;
    size_t len = 1000;
    ll j,k;
    char * history_datapoint;
    FILE *file;
    
    file = fopen("history.txt","w");
    if(!file)
    {
        printf("Error in history.txt");
        printf("\n");
        return;
    }
    i=0;
    while(i<hist_len)
    {
        fprintf(file,"%s",history_data[i]);
        i++;
    }
    fclose(file);
}