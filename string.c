#include "shell.h"


/**
 * _strlen - it always returns the length of a string
 * @s: it is the string whose length to check
 *
 * Return: always integer length of string
 */
int _strlen(char *s)
{
        int i = 0;


        if (!s)
                return (0);


        while (*s++)
                i++;
        return (i);
}


/**
 * _strcmp - it performs lexicogarphic comparison of two strangs.
 * @s1: this is the first strang
 * @s2: the second strang
 *
 * Return: always negative if s1 < s2, positive if s1 > s2, zero if s1 == s2
 */
int _strcmp(char *s1, char *s2)
{
        while (*s1 && *s2)
        {
                if (*s1 != *s2)
                        return (*s1 - *s2);
                s1++;
                s2++;
        }
        if (*s1 == *s2)
                return (0);
        else
                return (*s1 < *s2 ? -1 : 1);
}


/**
 * starts_with - it checks if needle starts with haystack
 * @haystack: this is the string to search
 * @needle: the substring to find
 *
 * Return: this is the address of next char of haystack or NULL
 */
char *starts_with(const char *haystack, const char *needle)
{
        while (*needle)
                if (*needle++ != *haystack++)
                        return (NULL);
        return ((char *)haystack);
}


/**
 * _strcat - it  concatenates two strings
 * @dest: this is the the destination buffer
 * @src: this is the source buffer
 *
 * Return: the pointer to destination buffer
 */
char *_strcat(char *dest, char *src)
{
        char *ret = dest;


        while (*dest)
                dest++;
        while (*src)
                *dest++ = *src++;
        *dest = *src;
        return (ret);
}

