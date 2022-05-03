#include "allheaders.h"

void signal_control(int signal)
{
    if(foreground_job.pid>0)
    {   
        int lol;
        lol=foreground_job.pid;
        jobs[job_seq_no].pid = lol;
        //printf("%d",lol);
        strcpy(jobs[job_seq_no].command,foreground_job.command);
        int var;
        var=job_seq_no;
        jobs[job_seq_no].id=var;
        //printf("%d",var);
        var=0;
        jobs[job_seq_no].status = 1;
        job_seq_no++;
        lol=0;
  		kill(foreground_job.pid , signal);
        foreground_job.pid=-1;
        printf("\n");
    }
    else
    {   printf("\n");
        printf("No foreground process found");
        printf("\n");
        printf("Press [ENTER] to continue");
        printf("\n");
    }
}





