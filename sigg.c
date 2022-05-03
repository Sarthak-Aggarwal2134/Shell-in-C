#include "allheaders.h"
typedef long long ll;
void sigg(char *input_str)
{
    ll token_cnt = 0, job_id, signal;
    char *token = strtok(input_str, " ");
    for (;;)
    {
        if (token == NULL)
        {
            break;
        }
        else
        {
            if (token_cnt == 1)
            {
                int tok= atoi(token);
                job_id = tok;
            }
            else
            {
                if (token_cnt == 2)
                {
                    int sig=atoi(token);
                    signal = sig;
                }
            }
            token = strtok(NULL, " ");
            token_cnt++;
        }
    }
    int killdone=0;
    // printf("%lld %lld",job_id,signal);
    if (token_cnt <= 2)
    {
        printf("Inconsistent number of arguments\n");
        return;
    }else if(  token_cnt >= 4){
        printf("Inconsistent number of arguments\n");
    }
    else
    {
        if (jobs[job_id].status == 1)
        {
            kill(jobs[job_id].pid, signal);
            killdone=1;
            jobs[job_id].status = 0;
        }
        else
        {
            printf("No job to kill \n");
            return;
        }
        //printf("%d\n",killdone);
    }
}
