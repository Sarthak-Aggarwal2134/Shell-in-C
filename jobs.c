#include "allheaders.h"
/*void merge(struct job jobs[], int p, int q, int r)
{

    int n1 = q - p + 1;
    int n2 = r - q;

    struct job L[n1], M[n2];

    for (int i = 0; i < n1; i++)
        L[i] = jobs[p + i];
    for (int j = 0; j < n2; j++)
        M[j] = jobs[q + 1 + j];

    int i, j, k;
    i = 0;
    j = 0;
    k = p;

    while (i < n1 && j < n2)
    {
        if(strcmp(L[i].command,M[j].command)<=0)
        {
            jobs[k] = L[i];
            i++;
        }
        else
        {
            jobs[k] = M[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        jobs[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        jobs[k] = M[j];
        j++;
        k++;
    }
}
void mergeSort(struct job jobs[], int l, int r)
{
    if (l < r)
    {

        // m is the point where the array is divided into two subarrays
        int m = l + (r - l) / 2;

        mergeSort(jobs, l, m);
        mergeSort(jobs, m + 1, r);

        // Merge the sorted subarrays
        merge(jobs, l, m, r);
    }
}*/
void printArray(struct job jobs[], int size, int flaglol,int flagr,int flags)
{
   // int i;
    if (flaglol == 0)
    {
        for (int i = 0; i < size; i++)
        {
            printf("[%d] %s %s [%d]", jobs[i].id, jobs[i].lol, jobs[i].command, jobs[i].pid);
            printf("\n");
        }
    }
    if (flaglol == 1)
    {
        for (int i = 0; i < size; i++)
        {
            if ((strcmp(jobs[i].lol, "Running") == 0) && flagr==1)
            {
                printf("[%d] %s %s [%d]", jobs[i].id, jobs[i].lol, jobs[i].command, jobs[i].pid);
                printf("\n");
            }
            else if ((strcmp(jobs[i].lol, "Stopped") == 0) && flags==1)
            {
                printf("[%d] %s %s [%d]", jobs[i].id, jobs[i].lol, jobs[i].command, jobs[i].pid);
                printf("\n");
            }
        }
    }
}
typedef long long ll;
void jobs_func(char *input_str)
{
    ll i = 0, j;
    //struct job jobs[1000];
    char file[10000];
    ll job_cnt = 0;
    char pid_str[100];
    char state[100];
    ll fd_file;
    int flagr=0;
    int flags=0;
    int status = 0;
    int token_cnt = 0, id;
    int flaglol = 0;
    //printf("%s\n",input_str);
    if((strcmp(input_str,"jobs -r")==0) ||(strcmp(input_str,"jobs -s")==0) ){
        char *token = strtok(input_str, " ");
    token = strtok(NULL, " ");
   // printf("%s\n",token);
    if(strcmp(token,"-r")==0){
        flaglol=1;
        flagr=1;
    }
    else if(strcmp(token,"-s")==0){
        flaglol=1;
        flags=1;
    }
    }
    
    while (i < job_seq_no)
    {
        if (jobs[i].status == 1)
        {
            jobs[i].id = i + 1;
            char file_path[1000] = "/proc/";
            sprintf(pid_str, "%d", jobs[i].pid);
            status++;
            strcat(file_path, pid_str);
            //printf("%d\n",status);
            strcat(file_path, "/stat");
            fd_file = open(file_path, O_RDONLY);
            if (fd_file >= 0)
            {
                job_cnt++;
                read(fd_file, file, 10000);
                char *token = strtok(file, " ");
                j = 0;
                for (;;)
                {
                    if (token == NULL || j == 2)
                    {
                        break;
                    }
                    else
                    {
                        token = strtok(NULL, " ");
                        j++;
                    }
                }
                int stop = 0, run = 0;
                if (strcmp(token, "T") == 0)
                {
                    strcpy(jobs[i].lol, "Stopped");
                    stop = 1;
                }
                else
                {
                    strcpy(jobs[i].lol, "Running");
                    run = 1;
                }
                //printf("[%d] %s %s [%d]", jobs[i].id, jobs[i].lol, jobs[i].command, jobs[i].pid);
                //printf("\n");
                //printf("%d %d\n",stop,run);
            }
            else
            {
                jobs[i].status = 0;
            }
        }
        i++;
    }
    //mergeSort(jobs, 0, job_cnt - 1);
    printArray(jobs, job_cnt, flaglol,flagr,flags);
    if (job_cnt == 0)
    {
        printf("No jobs active currently\n");
    }
}





