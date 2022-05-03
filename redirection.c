#include "allheaders.h"
typedef long long ll;
void redirection(char *input_str, char *add_root)
{
    ll i, r_flag = 0, w_flag = 0, len, a_flag = 0, temp_var;
    len = strlen(input_str);
    char *command = (char *)malloc(sizeof(char) * 1000);
    char *temp = (char *)malloc(sizeof(char) * 1000);
    char read_file[1000] = "\0";
    char write_file[1000] = "\0";

    char *token;
    struct stat info;
    int fd_read;
    int fd_write;
    i = 0;
    while (i < len)
    {
        if (input_str[i] == '>')
        {
            if (input_str[i + 1] == '>')
            {
                a_flag = 1;
            }
            else
            {
                w_flag = 1;
            }
        }
        if (input_str[i] == '<')
        {
            r_flag = 1;
        }
        i++;
    }

    if (r_flag == 0 && w_flag == 0 && a_flag == 0)
    {
        command_selector(input_str, add_root);
    }
    else
    {
        i = 0;
        int in = dup(0), out = dup(1);
        while (input_str[i] != '<' && input_str[i] != '>')
        {
            command[i] = input_str[i];
            i++;
        }
        while (i > 0)
        {
            if (command[i] != ' ')
            {
                break;
            }
            i--;
        }
        command[i + 1] = '\0';

        if (r_flag != 0)
        {
            strcpy(temp, input_str);
            token = strtok(temp, " ");
            for (;;)
            {
                if (token == NULL)
                {
                    break;
                }
                else
                {
                    if (strcmp(token, "<") == 0)
                    {
                        token = strtok(NULL, " ");
                        if (token == NULL)
                        {
                            break;
                        }
                        else
                        {
                            strcpy(read_file, token);
                            break;
                        }
                    }
                }

                token = strtok(NULL, " ");
            }

            if (stat(read_file, &info) < 0)
            {
                fprintf(stderr, "file does not exist\n");
                return;
            }
            else
            {
                int openchk = 0;

                fd_read = open(read_file, O_RDONLY);
                if (fd_read < 0)
                {
                    fprintf(stderr, "Error while opening the file\n");
                    openchk = 1;
                    return;
                }
                temp_var = dup2(fd_read, 0);
                int dupfail = 0;
                if (temp_var < 0)
                {
                    dupfail = 1;
                    fprintf(stderr, "Failure of dup2\n");
                }
                close(fd_read);
            }
        }
        if (w_flag != 0)
        {
            strcpy(temp, input_str);
            token = strtok(temp, " ");
            for (;;)
            {
                if (token == NULL)
                {
                    break;
                }
                else
                {
                    if (strcmp(token, ">") == 0 || strcmp(token, ">>") == 0)
                    {
                        token = strtok(NULL, " ");
                        if (token == NULL)
                        {
                            break;
                        }
                        else
                        {
                            strcpy(write_file, token);
                            break;
                        }
                    }
                    token = strtok(NULL, " ");
                }
            }
                fd_write = open(write_file, O_WRONLY | O_APPEND | O_CREAT, 0644);
            
            int openchk = 0;
            if (fd_write < 0)
            {
                fprintf(stderr, "Error while opening the file\n");
                openchk=1;
                return;
            }
            int dupfail = 0;
            if (dup2(fd_write, 1) < 0)
            {
                fprintf(stderr, "Failure of dup2\n");
                dupfail=1;
            }
            close(fd_write);
        }
        command_selector(command, add_root);
        dup2(in, 0);
        dup2(out, 1);
        close(in);
        close(out);
    }
}