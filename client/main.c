/*
** main.c for server in /home/zanard_a/rendu/Projets_TEK1/PSU_2014_minitalk/server
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Wed Feb 25 14:13:57 2015 Antoine Zanardi
** Last update Wed Mar 18 13:49:22 2015 Antoine Zanardi
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	<signal.h>
#include	<sys/types.h>
#include	"client.h"
#include	"my.h"

void		init_pid_str(char *str1, char *str2, int *nb)
{
  if (str_is_num(str1) == 1)
    my_putstr_error(1);
  if ((*nb = my_getnbr(str1)) <= 0)
    my_putstr_error(2);
  if (str2[0] == '\0')
    my_putstr_error(3);
}

void		put_enter(int *compt_bit, int nb, char *bit)
{
  *compt_bit = 0;
  while (*compt_bit < 8)
    {
      *bit = ('\n' >> *compt_bit) & 1;
      if (*bit == 0)
	kill(nb, SIGUSR1);
      else if (*bit == 1)
	kill(nb, SIGUSR2);
      (*compt_bit)++;
      usleep(200);
    }
}

void		send_str(char *str, int nb)
{
  char		bit;
  int		compt_str;
  int		compt_bit;

  compt_str = 0;
  while (str[compt_str] != '\0')
    {
      compt_bit = 0;
      while (compt_bit < 8)
	{
	  bit = ((str[compt_str]) >> compt_bit) & 1;
	  if (bit == 0)
	    kill(nb, SIGUSR1);
	  else if (bit == 1)
	    kill(nb, SIGUSR2);
	  compt_bit++;
	  usleep(200);
	}
      compt_str++;
    }
  put_enter(&compt_bit, nb, &bit);
}

int		main(int argc, char **argv)
{
  int		nb;

  if (argc < 3)
    usage();
  init_pid_str(argv[1], argv[2], &nb);
  send_str(argv[2], nb);
  return (0);
}
