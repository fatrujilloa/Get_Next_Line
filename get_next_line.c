/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 20:45:56 by ftrujill          #+#    #+#             */
/*   Updated: 2018/12/03 11:27:09 by ftrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

ssize_t read_until_char(const int fd, char *str, size_t nbyte)
{
    size_t  i;
    ssize_t r;

    i = 0;
    while(i < nbyte)
    {
        r = read(fd, str, 1);
        if (r == -1)
            return (-1);
        if (r == 0)
            return (i);
        i++;
        if (*str == '\n')
            return (i);
        str++;
    }
    return (i);
}

int     get_next_line(const int fd, char **line)
{
	size_t	size;
    ssize_t  bytsrd;
    size_t  nlindex;
    char    *str1;
    char    *str2;

    if (fd < 0 || !(str1 = (char*)malloc(BUFF_SIZE + 1))
                || (bytsrd = read_until_char(fd, str1, BUFF_SIZE)) == -1)
        return (-1);
    nlindex =  ft_memindex('\n', str1, bytsrd);
    if(!(*line = ft_realloc(str1, nlindex + 1)))
        return (-1);
    line[0][nlindex] = 0;
    if (bytsrd == 0)
        return (0);
    size = 0;
    while (nlindex == BUFF_SIZE)
        {
            str1 = *line;
            size += nlindex;
            if (!(str2 = (char*)malloc(BUFF_SIZE + 1))
                || (bytsrd = read_until_char(fd, str2, BUFF_SIZE)) == -1 )
                return (-1);
            nlindex =  ft_memindex('\n', str2, bytsrd);
            str2[nlindex] = 0;
            if (!(*line = ft_memjoin_allocf(str1, str2, size, nlindex + 1)))
                return (-1);
        }
    return (1);
}