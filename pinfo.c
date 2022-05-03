#include "allheaders.h"
typedef long long ll;
void pinfo(char *input_str, char *add_root)
{
    ll i, j, k, len;
    char path_stat[10000] = "/proc/";
    char* pid_str = (char*)malloc(sizeof(char) * 10000);
    char path_exe[10000] = "/proc/";
    char* buffer = (char*)malloc(sizeof(char) * 10000);
    char* status = (char*)malloc(sizeof(char) * 10000);
    len = strlen(input_str);
    char* memory = (char*)malloc(sizeof(char) * 10000);
    char* print_path = (char *)malloc(sizeof(char) * 10000);
    ll pid, cnt, fd;
    char *token = strtok(input_str, " ");
    token = strtok(NULL, " ");
    cnt = 0;
    for (int x = 1; x > 0; x++)
    {
        if (token != NULL)
        {
            cnt++;
            // printf("%s",token);
            if (cnt == 1)
            {
                strcpy(pid_str, token);
            }
            else
            {
                printf("Extra arguments");
                printf("\n");
                return;
            }
            token = strtok(NULL, " ");
        }
    }
    if (cnt != 0)
    {
        
    }else{
        pid = getpid();
        sprintf(pid_str, "%lld", pid);
    }
    strcat(path_exe, pid_str);
    strcat(path_stat, pid_str);
    strcat(path_stat, "/stat");
    strcat(path_exe, "/exe");

    fd = open(path_stat, O_RDONLY);
    read(fd, buffer, 10000);
    int inif=0,inelif=0;
    if (fd > 0)
    {
        token = strtok(buffer, " ");
        cnt = 0;
        for (int x = 1; x > 0; x++)
        {
            if (token != NULL)
            {
                if (cnt == 22)
                {
                    inif++;
                    strcpy(memory, token);
                }
                else if (cnt == 2)
                {
                    inelif++;
                    strcpy(status, token);
                }
                cnt++;
                token = strtok(NULL, " ");
            }
            else
            {
                break;
            }
        }

        char* real_path = (char *)malloc(sizeof(char) * 10000);
        realpath(path_exe, real_path);
        len = strlen(add_root);
        i=0;
        while(i < len)
        {
            if (real_path[i] != add_root[i])
            {
                i++;break;
            }i++;
        }

        if (i == len)
        {
            print_path[0] = '~';
            j = 1;
            while (i < strlen(real_path))
            {
                print_path[j++] = real_path[i];
                i++;
            }
            print_path[j] = '\0';
            
        }
        else
        {
            strcpy(print_path, real_path);
        }

        printf("pid -- %s", pid_str);
        printf("\n");
        printf("Process Status -- {%s}", status);
        printf("\n");
        printf("memory ​ -- %s", memory);
        printf("\n");
        printf("Executable Path -- %s", print_path);
        printf("\n");
    }
    else
    {
        printf("Error: could not open info file ");
        printf("\n");
    }
}
