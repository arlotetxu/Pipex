//
// Created by Jose Manuel Florido Pereña on 22/6/23.
//
#include <stdio.h>
#include "../libft/libft.h"

char	*ft_get_path(char **env)
{
	//char	*path;
	int		i;

	i = 0;
	//path = NULL;
	printf("Entro en la funcion.\n");
	while(env[i]) {
		if (ft_strncmp(env[i], "PATH", 4) == 0) {
			printf("valor de i: %d\n", i);
			printf("Cadena retornada: %s\n", env[i]);
			return (env[i]);
		}
		i++;
	}
	return (0);
}

int main(int argc, char **argv, char **env)
{
	argv[0] = "Test";
	if (argc == 2)
		ft_get_path(env);
	return (0);
}