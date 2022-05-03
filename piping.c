#include "allheaders.h"
typedef long long ll;
void piping(char *input_str, char *add_root)
{
    ll token_cnt = 0, token_no, status, pid;
    char *trimmed_str;
    char temp[10000];
    int stat;
    strcpy(temp, input_str);
    char *token = strtok(temp, "|");
    for (;;)
    {
        if (token == NULL)
        {
            break;
        }
        else
        {
            token_cnt++;
            token = strtok(NULL, "|");
        }
    }
    if (token_cnt == 1)
    {
        trimmed_str = trim(input_str);
        redirection(trimmed_str, add_root);
    }
    else if (token_cnt == 0)
    {
        return;   
    }
    else
    {
        int p[2];
        int in = dup(0);
        int out = dup(1);
        token_no = 0;
        int dup2chk=1;
        token = strtok(input_str, "|");
        for (;;)
        {
            if (token == NULL)
            {
                break;
            }
            else
            {
              

                if (token_no < token_cnt - 1)
                {
                    pipe(p);
                    status = dup2(p[1], 1);
                    if (status <= -1)
                    {
                        dup2chk=0;     
                        fprintf(stderr, "failure of dup2\n");
                    }
                    close(p[1]);
                    //printf("%d\n",dup2chk);
                }
                
                if (token_no >= 1)
                {
                    status = dup2(p[0], 0);
                    if (status <= -1)
                    {
                        fprintf(stderr, "failure of dup2\n");
                    }
                    close(p[0]);
                }
                trimmed_str = trim(token);
                pid = fork();
                int finalpidcheck=0;
                if (pid >= 1)
                {
                    waitpid(pid, &stat, WUNTRACED);
                    finalpidcheck=1;
                    dup2(in, 0);
                    dup2(out, 1);
                }
                else if (pid < 0)
                {
                     perror("Forking ERROR\n");
                     finalpidcheck=-1;
                    dup2(in, 0);
                    dup2(out, 1);
                    return;
                    
                }
                else
                {
                   redirection(trimmed_str, add_root);
                    finalpidcheck=0;
                    exit(0);
                }
                token = strtok(NULL, "|");
                token_no++;
                //printf("%d\n",finalpidcheck);
            }
        }
    }
}