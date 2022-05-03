#include "allheaders.h"
typedef long long ll;

void ls(char * input_str, char * add_root)
{
    ll i,j,k,len;
    char * token  = strtok(input_str, " "),dirs[100][1000];
    struct stat info;
    ll flag_l = 0,flag_a = 0,num_dirs=0,curr_dir=0,cnt=0,blocks=0; 
    struct group * grp;
    time_t now = time (NULL);
    struct passwd * passwd;
    struct tm timefl;
    struct tm timenow;
    struct dirent * file;
    char* time_str=(char*)malloc(sizeof(char)*10000);
    DIR *DIR_dir;
    char* add_curr_dir=(char*)malloc(sizeof(char)*1000);
    token = strtok(NULL, " ");

    while(token!=NULL)
    {
        if(token[0]=='-')
        {
            len = strlen(token);
            i=1;
            while(i<len)
            {
                if(token[i]!='a' && token[i]!='l')
                {
                    printf("Flag not found : %c",token[i]);
                    printf("\n");
                    return;
                }
                else
                {
                    if(token[i] == 'l')
                    {
                        flag_l = 1;
                    }
                    else if(token[i] == 'a')
                    {
                        flag_a = 1;
                    }
                }i++;

            }
        }
        else
        {
            strcpy(dirs[num_dirs],token);
            num_dirs=num_dirs+1; 
        }
        token = strtok(NULL," ");
    }
    int numdirsif=0;
    if(num_dirs==0)
    {
        numdirsif++;
        strcpy(dirs[num_dirs++],".");
    }
    curr_dir=0;
    while(curr_dir<num_dirs)
    {
        if(dirs[curr_dir][0]=='~')
        {
            strcpy(add_curr_dir,add_root);
            len = strlen(dirs[curr_dir]);
            j=strlen(add_root);
            i=1;
            while(i<len)
            {
                add_curr_dir[j++]=dirs[curr_dir][i];
                i++;
            }
            add_curr_dir[j]='\0';
            curr_dir++;
        }
        else
        {
            strcpy(add_curr_dir,dirs[curr_dir]);
            curr_dir++;
        }

        DIR_dir = opendir(add_curr_dir);
        if(num_dirs>1)
        {
            if(curr_dir >=1)
            {   printf("\n");
                printf("\033[1;35m%s :\033[0m",dirs[curr_dir]);
                printf("\n");
            }
            else
            {
                printf("\033[1;35m%s :\033[0m",dirs[curr_dir]);
                printf("\n");
            }
        }
        if (DIR_dir==0)
        {
            printf("No such file or directory");
            printf("\n");
        }
        else
        {
            if(flag_l==0)
            {
                cnt=0;
                    while(file = readdir(DIR_dir))
                    {
                        char *name = file->d_name;
                        
                        if(flag_a!=0)
                        {
                            printf("%15s  ",name);
                            cnt++;
                        }
                        else
                        {
                            if(name[0]!='.')
                            {
                                printf("%15s  ",name);
                                cnt++;
                            } 
   
                        }

                        if(cnt%6==0)
                        {
                            if(cnt!=0){
                                printf("\n");}
                        }
                    }
                    if(cnt%6!=0)
                    {
                        if(cnt!=0){
                        printf("\n");}
                    }
            }
            else if(flag_l!=0)
            {
                blocks=0;
                int inwhile=0;
                    while(file = readdir(DIR_dir))
                    {
                        stat(file->d_name, &info);
                        inwhile++;
                        char *name = file->d_name;
                        if(flag_a==0)
                        {
                            if(name[0] != '.')
                            {
                                int add=info.st_blocks;
                                blocks = add+blocks;
                            }
                        }
                        else
                        {
                            blocks = info.st_blocks+blocks; 
                        }
                    }
                    printf("total %lld",blocks/2);
                    printf("\n");
                    closedir(DIR_dir);
                    inwhile=0;
                    DIR_dir = opendir(add_curr_dir);
                    while(file = readdir(DIR_dir))
                    {   int inif=0;
                        char *name = file->d_name;
                        char* file_path_name=(char*)malloc(sizeof(char)*10000);
                        strcpy(file_path_name,add_curr_dir);
                        strcat(file_path_name,"/");
                        int inelse=0;
                        strcat(file_path_name,name);
                        stat(file_path_name, &info);
                        inwhile++;
                        localtime_r(&info.st_mtime, &timefl);
                        localtime_r(&now, &timenow);

                        if(timefl.tm_year == timenow.tm_year)
                        {
                            strftime(time_str, 10000 , "%b %e %H:%M", &timefl);
                            inif++;
                            
                        }
                        else
                        {
                            strftime(time_str, 10000 , "%b %e  %Y",&timefl);
                            inelse++;
                        }

                        if(flag_a==0 && name[0]=='.')
                        {
                            continue;
                        }
                        
                        passwd = getpwuid(info.st_uid);
                        //printf("%d %d\n",inif,inelse);
                        grp = getgrgid(info.st_gid);
                        

                        printf((S_ISDIR(info.st_mode))?"d":"-");
                        printf((info.st_mode & S_IRUSR)?"r":"-");
                        printf((info.st_mode & S_IWUSR)?"w":"-");
                        printf((info.st_mode & S_IXUSR)?"x":"-");
                        printf((info.st_mode & S_IRGRP)?"r":"-");
                        printf((info.st_mode & S_IWGRP)?"w":"-");
                        printf((info.st_mode & S_IXGRP)?"x":"-");
                        printf((info.st_mode & S_IROTH)?"r":"-");
                        printf((info.st_mode & S_IWOTH)?"w":"-");
                        printf((info.st_mode & S_IXOTH)?"x ":"- ");
                        
                        printf("%ld ", info.st_nlink);
                        printf("%s",passwd->pw_name);
                        printf(" ");
                        printf("%s ",grp->gr_name);
                        printf("%10ld ", info.st_size);
                        printf("%s ",time_str);
                        printf("%s\n",name);
                    }
            }
        closedir(DIR_dir);
        }
    }    
}