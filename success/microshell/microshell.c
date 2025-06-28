#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

// un putstr sur la sortie 2 (ou STDERR_FILENO)
void	print_error(char *str)
{
	while (*str)
	{
		write(2, str, 1);
		str++;
	}
}

// message d'erreur avant de quitter le programme
void	fatal(void)
{
	print_error("error: fatal\n");
	exit(1);
}

void	ft_cd(char **args, int count)
{
	if (count != 2)					// cd doit avoir 1 argument
		print_error("error: cd: bad arguments\n");
	else if (chdir(args[1])) 		// args[0] est "cd" et args[1] est l'argument de cd
	{
		print_error("error: cd: cannot change directory to ");
		print_error(args[1]);
		print_error("\n");
	}
}

// pour les commandes à envoyer dans execve
pid_t	launch_exec(char **args, char **env, int pipe_in, int pipe_out)
{
	pid_t	pid;
	
	// on forke un processus fils
	pid = fork();
	// si le fork echoue on quitte
	if (pid < 0)
		fatal();
	// processus enfant
	if (pid == 0)
	{
		// si on a un pipe d'entrée on redirige l'entrée
		if (pipe_in != -1)
		{
			if (dup2(pipe_in, STDIN_FILENO) == -1)
				fatal();
		}
		// si on a un pipe de sortie on redirige la sortie
		if (pipe_out != -1)
		{
			if (dup2(pipe_out, STDOUT_FILENO) == -1)
				fatal();
		}
		// on execute la commande
		execve(args[0], args, env);
		// si execve échoue on affiche un message d'erreur puis on quitte
		print_error("error: cannot execute ");
		print_error(args[0]);
		print_error("\n");
		exit(1);
	}
	// le parent retourne le pid du fils pour le waitpid
	return (pid);
}

pid_t	handle_command(char **argv, char **env, int start, int end, int *pipe_in)
{
	pid_t pid;

	// si la commande est cd on envoie dans ft_cd
	if (strcmp(argv[start], "cd") == 0)
	{
		ft_cd(&argv[start], end - start);
		// on retourne 0 pour ne pas faire de waitpid
		return (0);
	}
	// sinon on lance la commande dans execve
	else
	{
		pid = launch_exec(&argv[start], env, *pipe_in, -1);
		// si on a un pipe d'entrée on le ferme puis on le met à -1
		if (*pipe_in != -1)
			close(*pipe_in);
		*pipe_in = -1;
		// on retourne le pid du processus fils pour le waitpid
		return (pid);
	}
}

pid_t	handle_pipe(char **argv, char **env, int start, int *pipe_in)
{
	int		fd[2];
	pid_t	pid;

	// on crée le pipe et on quitte s'il renvoie -1
	if (pipe(fd) == -1)
		fatal();
	// on envoie la commande dans launch_exec en récupérant le pid
	pid = launch_exec(&argv[start], env, *pipe_in, fd[1]);
	close(fd[1]);
	if (*pipe_in != -1)
		close(*pipe_in);
	*pipe_in = fd[0];
	return (pid);
}

// attend la fin de tous les processus fils
void	wait_all(pid_t *pids, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (pids[i] > 0)
			waitpid(pids[i], NULL, 0);
		i++;
	}
}

int	main(int ac, char **av, char **env)
{
	int		start;
	int		end;
	int		pipe_in;
	pid_t	pid;
	pid_t	pids[1000];
	int		pid_count;

	start = 1;			// index du début de la prochaine commande à exécuter
	end = 1;			// on commence à 1 car av[0] est le nom du programme
	pipe_in = -1;		// -1 indique qu’il n’y a pas encore de pipe en entrée
	pid_count = 0;		// compteur pour stocker le nombre de pid enfants

	while (end <= ac)
	{
		// Si on est à la fin des arguments ou qu'on rencontre un point-virgule
		if (end == ac || strcmp(av[end], ";") == 0)
		{
			av[end] = NULL;  // on termine la commande en insérant un NULL à la place du séparateur
			if (start < end)   // s’il y a une commande entre start et i
			{
				// on exécute la commande, et on récupère éventuellement le pid
				pid = handle_command(av, env, start, end, &pipe_in);
				// si un processus a été forké, on le stocke
				if (pid > 0)
					pids[pid_count++] = pid;
			}
			// on attend tous les processus lancés avant ce point-virgule
			wait_all(pids, pid_count);
			// on réinitialise le compteur de pids
			pid_count = 0;
			// on passe à la commande suivante
			start = end + 1;
		}
		// Si on rencontre un pipe `|`
		else if (strcmp(av[end], "|") == 0)
		{
			av[end] = NULL;  // on coupe la commande actuelle à `i`
			// on exécute la commande avec redirection vers un pipe
			pids[pid_count++] = handle_pipe(av, env, start, &pipe_in);
			// on prépare le start pour la commande suivante
			start = end + 1;
		}
		end++;
	}
	return (0);
}

