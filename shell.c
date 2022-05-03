# include "allheaders.h"
typedef long long ll;
int main(int argc, char * argv[])
{
    ll i,j,k;
    int status;
    //char add_curd[10000],add_root[10000],cmd[100];
    char* add_curd=(char*)malloc(sizeof(char)*10000);
    char* add_root=(char*)malloc(sizeof(char)*10000);
    char* cmd=(char*)malloc(sizeof(char)*100);
    ll pid;
    getcwd(add_curd,sizeof(add_curd));
    i=strlen(argv[0])-1;
    while(i>=0)
    {
        if(argv[0][i] == '/')
        {
            break;
        }i--;
    }
    argv[0][i]='\0';
    // printf("%s\n",argv[0]);

    chdir(argv[0]);

    getcwd(add_root,sizeof(add_root));
    // printf("%s",add_root);

    fetch_history();
    chdir(add_curd);
    strcpy(lwd,add_root);
    while(1)
    {
        signal(SIGCHLD, child_killed);
        display(add_root);
        signal(SIGINT, signal_control);
        signal(SIGTSTP, signal_control);
        input(add_root);

    }
}