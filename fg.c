#include "allheaders.h"
void fg(char * input_str)
{
    int i,token_cnt=0,id,status;
    char * token = strtok(input_str," ");
    for(int k=1;k>0;k++){
    if(token!=NULL)
    {
        if(token_cnt==1)
        {
            id = atoi(token);
        }
        token = strtok(NULL," ");
        token_cnt++;
    }else{
        break;
    }}
    // printf("%d",token_cnt);
    if(token_cnt==1||token_cnt>=3)
    {
        printf("Incorrect number of arguments");
        printf("\n");
        return;
    }
    else
    {
        if(id>=job_seq_no)
        {
            printf("No job\n");
            return;
        }
        else
        {   kill(jobs[id].pid , SIGCONT);
            printf("%s In Foreground",jobs[id].command);
            printf("\n");
            waitpid(jobs[id].pid, &status, WUNTRACED);
            if(WIFSTOPPED(status)==0){
                jobs[id].status = 0;}
        
        }
    }
}