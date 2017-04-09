/*
** my_receive.c for my_receive.c in /home/brunne_s/rendu/Communaute_du_C/minitalk/tp/stress_tests
** 
** Made by brunner steeven
** Login   <brunne_s@epitech.net>
** 
** Started on  Wed Mar 19 09:56:40 2014 brunner steeven
** Last update Sun Mar 30 23:49:40 2014 brunner steeven
*/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>
#include "global_talk.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

int	my_put_nbr(int nb)
{
  if (nb < 0)
    {
      nb = nb * -1;
      my_putchar('-');
    }
  if (nb >= 10)
    {
      my_put_nbr(nb / 10);
      my_putchar(nb % 10 + '0');
    }
  if (nb >= 0 && nb <= 9)
    {
      my_putchar(nb + '0');
    }
  return (0);
}

void	receive_usr1(int toto)
{
  global_struct.rank = global_struct.rank * 2;
  return ;
}

void	receive_usr2(int toto)
{
  global_struct.letter_binary = global_struct.rank + global_struct.letter_binary;
  global_struct.rank = global_struct.rank * 2;
  return ;
}

int	main()
{
  my_put_nbr(getpid());
  my_putchar('\n');
  global_struct.rank = 1;
  global_struct.letter_binary = 0;
  while (global_struct.rank < 256)
    { 
      signal(SIGUSR1, receive_usr1);
      signal(SIGUSR2, receive_usr2);
      if (global_struct.rank == 256)
	{
	  my_putchar(global_struct.letter_binary);
	  global_struct.rank = 1;
	  global_struct.letter_binary = 0;
	}
    }
}
