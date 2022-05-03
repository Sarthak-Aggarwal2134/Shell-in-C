Files:-
allheaders.h
cd.c
display.c
echo.c
exec.c
history.c
input.c
ls.c
pinfo.c
pwd.c
repeat.c
shell.c
signal.c
sys_cmd.c
jobs.c
overkill.c
kjob.c
piping.c
redirection.c
bg.c
fg.c

compilation:-
1. make
2. ./shell

files description;-
allheaders.h :- contains all the required headers and functions specified.
shell.c :- mian shell file for managing all the different functions.
display.c :- for displaying prompt to the user
input.c :- fetches the inpur and tokenize it
pwd.c :- c file to implement pwd command
cd.c :- c file to implement cd command
echo.c :- c file to implement echo command
ls.c :- c file to implement ls =[la] command
pinfo.c :- mimicking pinfo command
sys_cmd.c :- for foreground/background processing of system commands
history.c :- c file for history command(bonus)
signal.c:- signal handling file
exec.c :- for input to funciton redirection
repeat.c:- for repeat command execution
jobs.c:- to list the jobs in a sorted order
overkill.c:- overkill to kill all background processes
kjob.c:- kjob to kill a command
piping.c:- for handling piping 
redirection.c:- for handling redirections
bg.c:- for running stopped background processes
fg.c:- for bringing background processes to the foreground


functions:-
cd (path to new directory) - Changes directory to the given path. Changes to shell home if no directory is provided
pwd - displays present working directory.
echo (text) - prints the (text) in the terminal. 
jobs - print the list of all the jobs that are currently running with their job ids , pid, in particular, background jobs, in sorted order(by name) along with their state – Running or Stopped.
kjob:- take job id of a running job and signal to that process
​fg ​- changes a running or a stopped background job with given job number to be foreground job.
​bg ​- changes from a stopped background job to a running background job.
overkill:- kills all the jobs in background at once
ls -[al] - list all the files w.r.t mentioned flags
jobs [-r] list all the running processes
jobs [-s] lists all the stopped processes
jobs      lists all the processes
pinfo [pid] - prints related info about the given pid of shell if no id is provided.
repeat (int) (command) - repeat the command given integer number of times.
history (n) - prints history of n (20 max)
CTRL-Z - changes the status tto stop of a running job and move it to the background. if not foreground job(it will have no effect).
CTRL-C - causes a SIGINT signal to be sent to the current foreground job of the shell​. If there is noforeground job, then the signal has no effect.
CTRL-D,quit,q,exit - exits the shell
Any process can be run to Background by adding '&' in the command.
cd can handle [~ .  .. -] special symbols. 
$'cd -' takes user to last working directory.
ls can handle [~ . ..] special symbols.
