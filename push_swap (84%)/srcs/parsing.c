/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   parsing.c										  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: bdenfir <bdenfir@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/12/09 13:53:39 by bdenfir		   #+#	#+#			 */
/*   Updated: 2024/12/09 16:44:35 by bdenfir		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "push_swap.h"

// Updated parse_value function to handle long integers up to LONG_MAX
int	parse_value(char *arg, long *parsed, int *count)
{
	char	buffer[21];
	char	*end;
	long	value;

	end = arg;
	while (*end && *end != ' ')
		end++;
	ft_memset(buffer, 0, sizeof(buffer));
	ft_strncpy(buffer, arg, end - arg);
	if (!ft_isdigit(buffer[0]) && buffer[0] != '-')
		return (-1);
	if (ft_strlen(buffer) == 1 && buffer[0] == '-')
		return (-1);
	value = ft_atol(arg);
	if (value > LONG_MAX || value < LONG_MIN)
		return (-1);
	parsed[*count] = value;
	(*count)++;
	return (end - arg);
}

int	process_arg(char **arg_ptr, long *parsed, int *count)
{
	char	*arg;
	int		offset;

	arg = *arg_ptr;
	offset = parse_value(arg, parsed, count);
	if (offset < 0)
		return (offset);
	*arg_ptr += offset;
	return (0);
}

int	process_argv(char *arg, long *parsed, int *count)
{
	int	result;

	while (*arg)
	{
		while (*arg == ' ')
			arg++;
		if (!*arg)
			break ;
		result = process_arg(&arg, parsed, count);
		if (result < 0)
			return (result);
	}
	return (0);
}

void	copy_elements(long *parsed, long **elements, int count)
{
	long	*output;
	int		i;

	output = malloc(sizeof(long) * count);
	if (!output)
	{
		free(parsed);
		error_exit();
	}
	i = -1;
	while (++i < count)
		output[i] = parsed[i];
	*elements = output;
}

int	parse_arguments(int argc, char *argv[], long **elements)
{
	long	*parsed;
	int		count;
	int		i;

	parsed = malloc(sizeof(long) * 1000);
	if (!parsed)
		error_exit();
	if (validate_arguments(argc, argv) < 0)
	{
		free(parsed);
		error_exit();
	}
	count = 0;
	i = 0;
	while (++i < argc)
	{
		if (process_argv(argv[i], parsed, &count) < 0)
		{
			free(parsed);
			error_exit();
		}
	}
	copy_elements(parsed, elements, count);
	free(parsed);
	return (count);
}
/*
** Fonction : parse_arguments
** ---------------------------
** Cette fonction analyse les arguments de la ligne de commande, les vérifie,
** les convertit en nombres entiers longs et les stocke dans un tableau pour 
** une utilisation ultérieure.
**
** Étapes principales :
** 1. `parsed` : Un tableau temporaire est alloué pour stocker les nombres au
** fur et à mesure qu'ils sont validés.
** 2. `validate_arguments` : Vérifie que les arguments ne contiennent que des
** caractères valides pour des nombres.
**    Si une erreur est détectée, le programme s'arrête avec une erreur.
** 3. `process_argv` : Analyse chaque chaîne (argument) de `argv`.
**    - Ignore les espaces initiaux.
**    - Utilise `process_arg` pour extraire chaque nombre dans l'argument.
** 4. `process_arg` : Pour chaque sous-chaîne de chiffres dans un argument :
**    - Appelle `parse_value` pour convertir la chaîne en nombre long.
**    - Si la conversion échoue (valeur non valide, dépassement de limites), 
** retourne une erreur.
**    - Ajoute le nombre au tableau `parsed`.
** 5. `parse_value` : Effectue la conversion d'une sous-chaîne en nombre long 
** vec
**  `ft_atol`.
**    - Vérifie si la valeur dépasse les limites de `INT_MIN` à `INT_MAX`.
**    - Retourne la longueur de la chaîne lue pour passer au nombre suivant.
** 6. Gestion des erreurs : Si un argument est invalide, libère les ressources
**  et 
** quitte avec une erreur.
** 7. Copie finale : Copie les nombres validés de `parsed` vers le tableau final
** `elements`, qui est retourné.
** 8. Nettoyage : Libère la mémoire temporaire de `parsed`.
**
** Résultat : Retourne le nombre de valeurs valides stockées dans `elements`.
*/
