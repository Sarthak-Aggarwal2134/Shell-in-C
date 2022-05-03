#include "allheaders.h"
typedef long long ll;
void command_selector(char * input_str,char * add_root)
{
    char* command=(char*)malloc(sizeof(char)*1000);
    char* temp=(char*)malloc(sizeof(char)*1000);
    strcpy(temp,input_str);
    char * token = strtok(temp," ");
    strcpy(command,token);
    
    if(strcmp(command,"cd")==0)
    {
        cd(input_str,add_root);
    }
    else if(strcmp(command,"echo")==0)
    {
        echo(input_str);
    }
    else if(strcmp(command,"quit")==0)
    {
        save_history();
        exit(1);
    }
    else if(strcmp(command,"pwd")==0)
    {
        pwd();
    }
    else if(strcmp(command,"history")==0)
    {
        history(input_str);
    }
    else if(strcmp(command,"ls")==0)
    {
        ls(input_str,add_root);
    }
    else if(strcmp(command,"pinfo")==0)
    {
        pinfo(input_str,add_root);
    }
    else if(strcmp(command,"bg")==0)
    {
        bg(input_str);
    }
    else if(strcmp(command,"repeat")==0){
        repeat(input_str);
    }
    else if(command==NULL)
    {
        exit(0);
    }
    else if(strcmp(command,"jobs")==0){
        jobs_func(input_str);
    }
    else if(strcmp(command,"sig")==0){
        sigg(input_str);
    }
    else if(strcmp(command,"overkill")==0){
        overkill();
    }
    else if(strcmp(command,"fg")==0)
    {
        fg(input_str);
    }
    else if(strcmp(command,"q")==0){
        save_history();
        exit(1);
    }
    else if(strcmp(command,"exit")==0){
        save_history();
        exit(1);
    }
    else
    {
        sys_cmd(input_str);
    }
}

char * trim(char * input_str)
{
    ll i,j,k,len=strlen(input_str);
    //char output_str[1000];
    char * output_str = (char*)malloc(sizeof(char)*1000);
    j=len-1;
    while(j>=0)
    {
        if(input_str[j]!='\n' && input_str[j]!=' ')
           { break;}
           j--;
    }
    i=0;
    while(i<len)
    {
        if(input_str[i]!=' ')
            {break;}
            i++;
    }
    
    if(j!=-1)
    {   k=0;
        while(i<=j)
        {
            output_str[k++]=input_str[i];
            i++;
        }
        output_str[k]='\0';
    }

    return output_str;
}

void child_killed()
{
    ll i;
    ll j;
    ll exit_status;
    int status;
    long long int pid = waitpid(-1, &status, WNOHANG | WUNTRACED);
    if(pid > 0)
    {
        if (WIFEXITED(status))
        {	i=0;
            while(i<job_seq_no)
            {
                if(jobs[i].pid == pid)
                {
                    exit_status = WEXITSTATUS(status);
                    if (exit_status == 0)
                    {
                        printf("Process %s with pid %lld exited normally", jobs[i].command, pid);
                        printf("\n");
                    }
                    else
                    {
                       printf("Process %s with pid %lld exited with exit status %lld", jobs[i].command, pid, exit_status);
                    printf("\n");
                    }
                    
                    jobs[i].status = 0;
                    printf("Press [ENTER] to continue");
                    printf("\n");
                }i++;
            }

        }                                                       
    }
}
