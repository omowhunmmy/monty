#include <stdlib.h>


char *get_int(int num);
unsigned int _abs(int);
int get_numbase_len(unsigned int num, unsigned int base);
void fill_numbase_buff(unsigned int num, unsigned int base,
               char *buff, int buff_size);


/**
 * get_int - gets a character that points to new string containing int
 * @num: the number to be converted to string
 *
 * Return: character points to a newly created string. NULL if malloc fails.
 */
char *get_int(int num)
{
    unsigned int temp;
    int length = 0;
    long num_l = 0;
    char *ret;


    temp = _abs(num);
    length = get_numbase_len(temp, 10);


    if (num < 0 || num_l < 0)
        length++; /* negative sign */
    ret = malloc(length + 1); /* create new string */
    if (!ret)
        return (NULL);


    fill_numbase_buff(temp, 10, ret, length);
    if (num < 0 || num_l < 0)
        ret[0] = '-';


    return (ret);
}


/**
 * _abs - gets the absolute value of the integer
 * @i: the integer to get absolute value of
 *
 * Return: unsigned integer abs rep of i
 */
unsigned int _abs(int i)
{
    if (i < 0)
        return (-(unsigned int)i);
    return ((unsigned int)i);
}


/**
 * get_numbase_len - gets the length of buffer needed for an unsigned int
 * @num: number to get the length needed for
 * @base: a base of number representation used by buffer
 *
 * Return: the integer that contains length of buffer needed (doesn't contain null bt)
 */
int get_numbase_len(unsigned int num, unsigned int base)
{
    int len = 1; /* all numbers contains atleast one digit */


    while (num > base - 1)
    {
        len++;
        num /= base;
    }
    return (len);
}


/**
 * fill_numbase_buff - fills the buffer with the correct numbers up to base 36
 * @num: the number to convert to string given base
 * @base: base of the number used in conversion, only works up to base 36
 * @buff: the buffer to fill with result of conversion
 * @buff_size: The size of buffer in bytes
 *
 * Return: always void.
 */
void fill_numbase_buff(unsigned int num, unsigned int base,
            char *buff, int buff_size)
{
    int rem, i = buff_size - 1;


    buff[buff_size] = '\0';
    while (i >= 0)
    {
        rem = num % base;
        if (rem > 9) /* return lowercase ascii val representation */
            buff[i] = rem + 87; /* 10 will be a, 11 = b, ... */
        else
            buff[i] = rem + '0';
        num /= base;
        i--;
    }
}
