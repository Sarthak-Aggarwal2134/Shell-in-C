#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <pwd.h>
#include <time.h>
#include <grp.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/wait.h>

struct pid_datapoint
{
    int id;
    char cmd[1000];
};
struct job
{
    int pid,status,id;
    char command[1000];
    char lol[1000];
};


struct job jobs[1000];
struct job foreground_job;
int job_seq_no, hist_len;
char lwd[10000];
char history_data[30][1000];
void redirection();
void piping();
void jobs_func();
void sigg();
void child_killed();
void fg();
void bg();
void overkill();
void signal_control();
void pinfo();
void display();
void input();
void echo();
void cd();
void pwd();
void ls();
void sys_cmd();
void add_history();
void history();
void fetch_history();
void save_history();
void repeat(char * input_str);
void command_selector();
char * trim();
void child_killed();
void signal_control();
