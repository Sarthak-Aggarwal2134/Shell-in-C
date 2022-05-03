#include "allheaders.h"
typedef long long ll;
void overkill()
{
    ll i=0;
    ll cnt=0;
    while(i<job_seq_no)
    {
        if(jobs[i].status==1)
        {
            kill(jobs[i].pid,SIGKILL);
            cnt=cnt+1;
        }i++;
    }

    if(cnt==0)
    {
        printf("No Background processes to kill");
        printf("\n");
    }
}