/*
** fc_base.c for minitalk in /home/zanard_a/rendu/Projets_TEK1/PSU_2014_minitalk/client
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Wed Feb 25 14:42:16 2015 Antoine Zanardi
** Last update Wed Feb 25 14:46:29 2015 Antoine Zanardi
*/

#include	"client.h"
#include	"my.h"

int		str_is_num(char *str)
{
  int		compt_str;

  compt_str = 0;
  if (str[compt_str] == '\0')
    return (1);
  while (str[compt_str] != '\0')
    {
      if (str[compt_str] >= '0' && str[compt_str] <= '9')
	compt_str++;
      else
	return (1);
    }
  return (0);
}
