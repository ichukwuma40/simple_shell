#include "shell.h"


/**
 * shell_interactive - UNIX command line interpreter
 *
 * Return: void
*/

void shell_interactive(void)
{
        char *line;
        char **args;
        int status = -1;
        size_t n = 0;
        char *buf = NULL;
        char *lineptr;

        do {

                printf("#cisfun$ "); /* print prompt symbol */
                line = read_line(); /* read line from stdin */
                  args = split_line(line); /* tokenize line  */
                  getline(&lineptr, &n, stdin);
                  getline(&buf, &n, stdin);
                  printf(" %s", buf);
                 /* printf("Buffer size :  %ld\n", n); */
free(buf);

                status = execute_args(args);
                /* avoid memory leaks */
                free(line);
                free(lineptr);
                free(args);
                /* exit with status */
                if (status >= 0)
                {
                        exit(status);
                }
        } while (status == -1);

}
