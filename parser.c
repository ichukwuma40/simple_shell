#include "shell.h"


/**
 * is_cmd - this determines if a file is an executable command
 * @info: this is the info struct
 * @path: it is the path to the file
 *
 * Return: it always 1 if true, 0 otherwise
 */
int is_cmd(info_t *info, char *path)
{
        struct stat st;


        (void)info;
        if (!path || stat(path, &st))
                return (0);


        if (st.st_mode & S_IFREG)
        {
                return (1);
        }
        return (0);
}


/**
 * dup_chars - the duplicates characters
 * @pathstr: this is the PATH string
 * @start: the starting index
 * @stop: this is the stopping index
 *
 * Return: it points to new buffer
 */
char *dup_chars(char *pathstr, int start, int stop)
{
        static char buf[1024];
        int i = 0, k = 0;


        for (k = 0, i = start; i < stop; i++)
                if (pathstr[i] != ':')
                        buf[k++] = pathstr[i];
        buf[k] = 0;
        return (buf);
}


/**
 * find_path - it finds this cmd in the PATH string
 * @info: this is the info struct
 * @pathstr: this is the PATH string
 * @cmd: this is the cmd to find
 *
 * Return: full path of cmd if found or NULL
 */
char *find_path(info_t *info, char *pathstr, char *cmd)
{
        int i = 0, curr_pos = 0;
        char *path;


        if (!pathstr)
                return (NULL);
        if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
        {
                if (is_cmd(info, cmd))
                        return (cmd);
        }
        while (1)
        {
                if (!pathstr[i] || pathstr[i] == ':')
                {
                        path = dup_chars(pathstr, curr_pos, i);
                        if (!*path)
                                _strcat(path, cmd);
                        else
                        {
                                _strcat(path, "/");
                                _strcat(path, cmd);
                        }
                        if (is_cmd(info, path))
                                return (path);
                        if (!pathstr[i])
                                break;
                        curr_pos = i;
                }
                i++;
        }
        return (NULL);
}
