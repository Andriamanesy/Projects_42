/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briandri <briandri@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:09:12 by briandri          #+#    #+#             */
/*   Updated: 2025/12/24 01:56:45 by briandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	function_atoi(char *str)
{
	unsigned long long	res;
	int					i;
	int					sign;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	sign = 1;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign = -1;
	res = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return ((int)((res * sign) % 256));
}

static int	check_space(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			count++;
		i++;
	}
	return (count);
}

static int	check_valid(char *str)
{
	int	i;

	i = 0;
	str = ft_strtrim(str, " ");
	while (str[i])
	{
		if ((str[i] >= '0' && str[i] <= '9') || str[i] == '-' || str[i] == '+')
			i++;
		else
			return (0);
	}
	return (1);
}

static int	check_long(char *str)
{
	unsigned long long	res;
	int					i;
	int					sign;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	sign = 1;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign = -1;
	res = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		if ((sign == 1 && res > LONG_MAX) || (sign == -1
				&& res > (unsigned long long)LONG_MAX + 1))
			return (0);
		i++;
	}
	return (1);
}

void	ft_exit(t_data *data, char **args)
{
	int	ret;

	ret = data->exit_code;
	if (args[1] && args[2])
	{
		print_error("exit: too many arguments\n");
		data->exit_code = 1;
		return ;
	}
	if (args[1])
	{
		args[1] = ft_strtrim (args[1], " ");
		if (((args[1][0] == '-' || args[1][0] == '+') && args[1][1] == '\0')
			|| !check_long(args[1]) || !check_valid(args[1])
			|| args[1][0] == '\0' || check_space(args[1])
			- ft_strlen(args[1]) == 0)
		{
			print_error("exit: ");
			print_error(args[1]);
			print_error(": numeric argument required\n");
			free_all(data, NULL, 2);
		}
		ret = function_atoi(args[1]);
	}
	printf("exit\n");
	free_all(data, NULL, ret);
}
