/*
** main.c for server in /home/zanard_a/rendu/Projets_TEK1/PSU_2014_minitalk/server
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Wed Feb 25 14:13:57 2015 Antoine Zanardi
** Last update Wed Feb 25 18:51:09 2015 Antoine Zanardi
*/

#include	<signal.h>
#include	<sys/types.h>
#include	<unistd.h>
#include	"client.h"

void			receive_bit(int sig)
{
  static unsigned char	bit = 0;
  static int		compt_bit = 0;

  if (sig == SIGUSR1)
    bit &= ~(1 << compt_bit);
  else if (sig == SIGUSR2)
    bit |= (1 << compt_bit);
  compt_bit++;
  if (compt_bit == 8)
    {
      my_putchar(bit);
      bit = 0;
      compt_bit = 0;
    }
}

int		main()
{
  int		pid;

  pid = getpid();
  my_putstr("PID server is : ");
  my_put_nbr(pid);
  my_putchar('\n');
  signal(SIGUSR1, &receive_bit);
  signal(SIGUSR2, &receive_bit);
  while (42);
}
