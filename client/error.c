/*
** error.c for client in /home/zanard_a/rendu/Projets_TEK1/PSU_2014_minitalk/client
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Wed Feb 25 14:31:36 2015 Antoine Zanardi
** Last update Wed Mar 18 13:53:33 2015 Antoine Zanardi
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	"my.h"
#include	"client.h"

void		usage(void)
{
  my_putstr("The client needs two arguments: PID_server & string\n");
  exit(0);
}

void		my_putstr_error(int error)
{
  if (error == 1)
    my_putstr("This PID is not a valid number\n");
  else if (error == 2)
    my_putstr("PID can't be equal to 0\n");
  else if (error == 3)
    my_putstr("The string is not valid\n");
  exit(1);
}
