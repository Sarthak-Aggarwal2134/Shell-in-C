#include "allheaders.h"
typedef long long ll;
void sys_cmd(char * input_str)
{
    ll i,j,k,cnt,flag_and=0,pid;
    char * command[1000];
    ll child_pid,exe_stat,child_child_pid;
    char * arg_list[1000];
    char* cmd=(char*)malloc(sizeof(char)*1000);
    i=0;
    while(i<1000)
    {
        arg_list[i] = (char*)malloc(sizeof(char)*1000);
        i++;
    }

    char * token = strtok(input_str, " ");
    cnt=0;
    for(int x=1;x>0;x++){
    if (token!=NULL)
    {
        if(strcmp(token,"&")==0)
        {
            flag_and=1;
        }
        else
        {
            arg_list[cnt]=token;
            cnt++;
        }
        token = strtok(NULL," ");
    }else{
        break;
    }
    }
    arg_list[cnt] = NULL;

    child_pid = fork();
    if(child_pid>=0)
    {
        
    }else{
        perror("ERROR");
        return;
    }
    
    if(child_pid!=0)
    {
        
    }else{
        exe_stat = execvp(arg_list[0],arg_list);
        if(exe_stat==-1)
        {
            printf("Please enter a Valid Command\n");
        }
        exit(0);
    }
    int inelse=0,inif=0;
    if(child_pid>0)
    {
        if(flag_and!=0)
        {
            printf("%s with process pid %lld started",arg_list[0],child_pid);
            printf("\n");
            int tp=child_pid;
            jobs[job_seq_no].pid = tp;
            inif++;
            strcpy(jobs[job_seq_no].command,arg_list[0]);
            jobs[job_seq_no].status = 1;
            int lol=job_seq_no;
            jobs[job_seq_no].id = lol;
            //jobs[job_seq_no].id;
            job_seq_no++;
            job_seq_no%=1000;
        
        }
        else
        {
            int status;
            int tp=child_pid;
            foreground_job.pid =tp;
            strcpy(foreground_job.command,arg_list[0]);
            foreground_job.id = 0;
            inelse++;
            waitpid(child_pid,&status, WUNTRACED);
            foreground_job.pid = -1;
        
        }
    }else{

    }
}
