/*
** my_send.c for my_send.C in /home/brunne_s/rendu/Communaute_du_C/minitalk/tp/stress_tests
** 
** Made by brunner steeven
** Login   <brunne_s@epitech.net>
** 
** Started on  Wed Mar 19 09:54:10 2014 brunner steeven
** Last update Sun Mar 30 23:51:56 2014 brunner steeven
*/

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "global_talk.h"

int     my_strlen(char *str)
{
  int   i;

  i = 0;
  while (str[i] != '\0')
    i++;
  return (i);
}

void	my_putstr(char *str)
{
  write(1, &str, my_strlen(str));
}


int	my_getnbr(char *str)
{
  int	i;
  long	s;
  int	c;

  i = 0;
  s = 0;
  c = 0;
  while (i < my_strlen(str))
    {
      if (str[i] != '+')
        if (str[i] <= '9' && str[i] >= '0')
          s = (s + (str[i] - '0')) * 10;
	else if (str[i] == '-' && s == 0)
          c = c + 1;
        else if (str[i] < '0' || str[i] > '9')
          i = my_strlen(str);
      i = i + 1;
    }
  s = s / 10;
  if ((c % 2) == 1)
    s = s * -1;
  if (s < -2147483648 || s > 2147483647)
    return (0);
  return (s);
}

void	binary_char(char c, int pid)
{
  int	i;
  char	carac;
  
  i = 7;
  while (i >= 0)
    {
      carac = (c & 1) + '0';
      if (carac == '0')
	{
	  usleep(300);
	  kill(pid, SIGUSR1);
	}
      else if (carac == '1')
	{
	  usleep(300);
	  kill(pid, SIGUSR2);
	}
      c >>= 1;
      i--;
    }
}

int	main(int argc, char **argv)
{
  char	**send;
  int	i;
  int	pid;

  i = 0;
  pid = getpid();
  if (argc < 3)
    {
      my_putstr("[Error] : more arguments expected\n");
      return (0);
    }
  while (argv[2][i] != '\0')
    {
      binary_char(argv[2][i], my_getnbr(argv[1]));
      i++;
    }
}
