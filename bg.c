#include "allheaders.h"

void bg(char * input_str)
{
    int token_cnt=0,id;
    char * token = strtok(input_str," ");
    for(int i=1;i>0;i++){
    if(token!=NULL)
    {
        if(token_cnt==1)
        {
            id = atoi(token);
        }
        token = strtok(NULL," ");
        token_cnt++;
    }
    else{
        break;
    }}
    // printf("%d",token_cnt);
    if(token_cnt==1||token_cnt>=3)
    {
        printf("Incorrect number of arguments\n");
        return;
    }
    else
    {
        if(id>=job_seq_no)
        {

            printf("Job not found\n");
            return;
            
        }
        else
        {
            if(jobs[id].status==1)
            {
                kill(jobs[id].pid , SIGCONT);
                return;
            }
        }
    }
}