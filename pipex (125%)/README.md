# Pipex - Guide Complet avec Bonus

## Table des matières
1. [Introduction](#introduction)
2. [Comprendre les pipes en shell](#comprendre-les-pipes-en-shell)
3. [Partie obligatoire](#partie-obligatoire)
4. [Bonus : Multiple pipes](#bonus--multiple-pipes)
5. [Bonus : Here_doc](#bonus--here_doc)
6. [Architecture du projet](#architecture-du-projet)
7. [Gestion des processus](#gestion-des-processus)
8. [Gestion des fichiers et redirections](#gestion-des-fichiers-et-redirections)
9. [Parsing et validation](#parsing-et-validation)
10. [Gestion d'erreurs](#gestion-derreurs)
11. [Implémentation complète](#implémentation-complète)
12. [Tests et debugging](#tests-et-debugging)

## Introduction

**Pipex** est un projet de l'École 42 qui consiste à reproduire le comportement des pipes (`|`) du shell. Le programme doit exécuter des commandes en chaînant leurs entrées/sorties, exactement comme le ferait le shell bash.

### Objectifs du projet
- Comprendre les processus Unix (fork, exec, wait)
- Maîtriser les redirections de fichiers (dup, dup2)
- Gérer les pipes inter-processus
- Appliquer la gestion d'erreurs système

## Comprendre les pipes en shell

### Qu'est-ce qu'un pipe ?
Un **pipe** (`|`) connecte la sortie standard d'une commande à l'entrée standard de la commande suivante.

### Exemple simple
```bash
cat file1.txt | grep "hello" | wc -l
```

**Ce qui se passe :**
1. `cat file1.txt` lit le fichier et écrit sur sa sortie standard
2. `grep "hello"` lit depuis son entrée standard et filtre les lignes
3. `wc -l` compte les lignes reçues
4. Le résultat final s'affiche à l'écran

### Équivalent avec redirections
```bash
cat file1.txt > temp1
grep "hello" < temp1 > temp2
wc -l < temp2
rm temp1 temp2
```

### Ce que pipex doit reproduire

**Commande shell :**
```bash
< file1 cmd1 | cmd2 > file2
```

**Votre programme :**
```bash
./pipex file1 cmd1 cmd2 file2
```

## Partie obligatoire

### Prototype
```c
int main(int argc, char **argv, char **envp)
```

### Arguments
```
./pipex infile cmd1 cmd2 outfile
```

- `infile` : fichier d'entrée
- `cmd1` : première commande avec ses arguments
- `cmd2` : deuxième commande avec ses arguments  
- `outfile` : fichier de sortie

### Exemple d'utilisation
```bash
# Commande shell équivalente
< input.txt grep "hello" | wc -l > output.txt

# Votre programme
./pipex input.txt "grep hello" "wc -l" output.txt
```

### Schéma du processus

```
┌─────────────┐    ┌─────────────┐    ┌─────────────┐
│   infile    │───▶│    cmd1     │───▶│    cmd2     │───▶│   outfile   │
│ input.txt   │    │ grep hello  │    │   wc -l     │    │ output.txt  │
└─────────────┘    └─────────────┘    └─────────────┘    └─────────────┘
```

### Algorithme de base

```
1. Vérifier les arguments (argc == 5)
2. Créer un pipe
3. Fork pour créer le premier processus enfant :
   - Rediriger stdin vers infile
   - Rediriger stdout vers l'écriture du pipe
   - Exécuter cmd1
4. Fork pour créer le deuxième processus enfant :
   - Rediriger stdin vers la lecture du pipe
   - Rediriger stdout vers outfile
   - Exécuter cmd2
5. Fermer tous les descripteurs de fichiers
6. Attendre la fin des processus enfants
```

## Bonus : Multiple pipes

### Objectif
Gérer un nombre arbitraire de commandes, comme :
```bash
./pipex file1 cmd1 cmd2 cmd3 ... cmdN file2
```

Équivalent shell :
```bash
< file1 cmd1 | cmd2 | cmd3 | ... | cmdN > file2
```

### Exemple
```bash
# 4 commandes chaînées
./pipex input.txt "cat" "grep hello" "sort" "uniq" output.txt

# Équivalent shell
< input.txt cat | grep hello | sort | uniq > output.txt
```

### Algorithme pour multiple pipes

```
1. Calculer le nombre de commandes : nb_cmds = argc - 3
2. Créer (nb_cmds - 1) pipes
3. Pour chaque commande i :
   - Fork un processus enfant
   - Configurer les redirections :
     * Si première commande : stdin = infile
     * Si dernière commande : stdout = outfile
     * Sinon : stdin = pipe[i-1][0], stdout = pipe[i][1]
   - Fermer tous les autres pipes
   - Exécuter la commande
4. Processus parent : fermer tous les pipes et attendre tous les enfants
```

### Schéma multiple pipes

```
┌─────────┐   ┌─────┐   ┌─────┐   ┌─────┐   ┌─────┐   ┌──────────┐
│ infile  │──▶│cmd1 │──▶│cmd2 │──▶│cmd3 │──▶│cmd4 │──▶│ outfile  │
└─────────┘   └─────┘   └─────┘   └─────┘   └─────┘   └──────────┘
                  │       │       │       │
                pipe[0] pipe[1] pipe[2] pipe[3]
```

## Bonus : Here_doc

### Objectif
Implémenter l'équivalent du here_doc (`<<`) du shell.

### Syntaxe
```bash
./pipex here_doc LIMITER cmd1 cmd2 outfile
```

### Équivalent shell
```bash
cmd1 << LIMITER | cmd2 >> outfile
```

### Comportement
1. Lire l'entrée standard ligne par ligne
2. S'arrêter quand on rencontre la ligne contenant exactement `LIMITER`
3. Passer tout ce qui a été lu comme entrée de `cmd1`
4. **Important** : utiliser `>>` (append) pour le fichier de sortie

### Exemple d'utilisation
```bash
./pipex here_doc EOF "grep hello" "wc -l" output.txt
hello world
this is a test
hello 42
EOF
```

### Algorithme here_doc

```
1. Vérifier les arguments (argc == 6)
2. Créer un pipe temporaire pour stocker l'input
3. Lire stdin ligne par ligne jusqu'à trouver LIMITER
4. Écrire chaque ligne dans le pipe temporaire
5. Continuer avec l'algorithme normal en utilisant le pipe temporaire comme source
```

## Architecture du projet

### Structure des fichiers
```
pipex/
├── Makefile
├── includes/
│   └── pipex.h
├── src/
│   ├── main.c
│   ├── parsing.c
│   ├── processes.c
│   ├── pipes.c
│   ├── files.c
│   ├── commands.c
│   ├── errors.c
│   └── bonus/
│       ├── multiple_pipes.c
│       └── here_doc.c
└── libft/ (si autorisé)
```

### Structure principale

```c
typedef struct s_pipex
{
    int     argc;
    char    **argv;
    char    **envp;
    
    char    *infile;
    char    *outfile;
    char    **commands;
    int     nb_commands;
    
    int     **pipes;
    pid_t   *pids;
    
    int     here_doc;
    char    *limiter;
} t_pipex;
```

## Gestion des processus

### Fork et exec

```c
pid_t create_process(void)
{
    pid_t pid;
    
    pid = fork();
    if (pid == -1)
        error_exit("Fork failed");
    return (pid);
}

void execute_command(char *cmd, char **envp)
{
    char **args;
    char *path;
    
    args = parse_command(cmd);
    path = find_command_path(args[0], envp);
    
    if (execve(path, args, envp) == -1)
    {
        free_args(args);
        error_exit("Command execution failed");
    }
}
```

### Attendre les processus enfants

```c
void wait_for_children(t_pipex *data)
{
    int i;
    int status;
    
    i = 0;
    while (i < data->nb_commands)
    {
        waitpid(data->pids[i], &status, 0);
        i++;
    }
}
```

## Gestion des fichiers et redirections

### Ouvrir les fichiers

```c
int open_infile(char *filename)
{
    int fd;
    
    fd = open(filename, O_RDONLY);
    if (fd == -1)
    {
        perror(filename);
        exit(1);
    }
    return (fd);
}

int open_outfile(char *filename, int here_doc)
{
    int fd;
    int flags;
    
    if (here_doc)
        flags = O_WRONLY | O_CREAT | O_APPEND;
    else
        flags = O_WRONLY | O_CREAT | O_TRUNC;
        
    fd = open(filename, flags, 0644);
    if (fd == -1)
    {
        perror(filename);
        exit(1);
    }
    return (fd);
}
```

### Redirections avec dup2

```c
void setup_redirections(t_pipex *data, int cmd_index)
{
    // Première commande : stdin = infile
    if (cmd_index == 0)
    {
        int infd = open_infile(data->infile);
        dup2(infd, STDIN_FILENO);
        close(infd);
    }
    else
    {
        // Commandes intermédiaires : stdin = pipe précédent
        dup2(data->pipes[cmd_index - 1][0], STDIN_FILENO);
    }
    
    // Dernière commande : stdout = outfile
    if (cmd_index == data->nb_commands - 1)
    {
        int outfd = open_outfile(data->outfile, data->here_doc);
        dup2(outfd, STDOUT_FILENO);
        close(outfd);
    }
    else
    {
        // Commandes intermédiaires : stdout = pipe suivant
        dup2(data->pipes[cmd_index][1], STDOUT_FILENO);
    }
}
```

## Parsing et validation

### Parser une commande

```c
char **parse_command(char *cmd)
{
    char **args;
    int i;
    
    // Diviser la commande en mots (attention aux guillemets)
    args = split_command(cmd);
    
    // Vérifier que la commande n'est pas vide
    if (!args || !args[0])
        error_exit("Empty command");
        
    return (args);
}
```

### Trouver le chemin d'une commande

```c
char *find_command_path(char *cmd, char **envp)
{
    char **paths;
    char *full_path;
    int i;
    
    // Si le chemin est absolu ou relatif
    if (cmd[0] == '/' || cmd[0] == '.')
    {
        if (access(cmd, X_OK) == 0)
            return (strdup(cmd));
        return (NULL);
    }
    
    // Chercher dans PATH
    paths = get_paths_from_env(envp);
    i = 0;
    while (paths[i])
    {
        full_path = create_full_path(paths[i], cmd);
        if (access(full_path, X_OK) == 0)
        {
            free_paths(paths);
            return (full_path);
        }
        free(full_path);
        i++;
    }
    
    free_paths(paths);
    return (NULL);
}

char **get_paths_from_env(char **envp)
{
    int i;
    char *path_env;
    
    i = 0;
    while (envp[i])
    {
        if (strncmp(envp[i], "PATH=", 5) == 0)
        {
            path_env = envp[i] + 5;
            return (ft_split(path_env, ':'));
        }
        i++;
    }
    return (NULL);
}
```

## Gestion d'erreurs

### Types d'erreurs à gérer

1. **Erreurs d'arguments**
   - Nombre d'arguments incorrect
   - Arguments vides ou invalides

2. **Erreurs de fichiers**
   - Fichier d'entrée inexistant ou non lisible
   - Impossible de créer/écrire le fichier de sortie
   - Permissions insuffisantes

3. **Erreurs de commandes**
   - Commande introuvable
   - Commande non exécutable
   - Échec de l'exécution

4. **Erreurs système**
   - Échec de fork()
   - Échec de pipe()
   - Échec des redirections

### Implémentation de la gestion d'erreurs

```c
void error_exit(char *message)
{
    perror(message);
    exit(1);
}

void cleanup_and_exit(t_pipex *data, char *message)
{
    cleanup_pipex(data);
    error_exit(message);
}

void cleanup_pipex(t_pipex *data)
{
    if (data->pipes)
        close_all_pipes(data);
    if (data->pids)
        free(data->pids);
    if (data->commands)
        free_commands(data->commands);
}
```

## Implémentation complète

### main.c

```c
#include "pipex.h"

int main(int argc, char **argv, char **envp)
{
    t_pipex data;
    
    // Initialisation et validation
    init_pipex(&data, argc, argv, envp);
    validate_arguments(&data);
    
    // Gestion des bonus
    if (argc >= 6 && strcmp(argv[1], "here_doc") == 0)
        handle_here_doc(&data);
    else
        handle_regular_pipex(&data);
        
    // Nettoyage
    cleanup_pipex(&data);
    return (0);
}

void init_pipex(t_pipex *data, int argc, char **argv, char **envp)
{
    data->argc = argc;
    data->argv = argv;
    data->envp = envp;
    data->pipes = NULL;
    data->pids = NULL;
    data->here_doc = 0;
    
    if (argc >= 6 && strcmp(argv[1], "here_doc") == 0)
    {
        data->here_doc = 1;
        data->limiter = argv[2];
        data->commands = &argv[3];
        data->nb_commands = argc - 5;
        data->outfile = argv[argc - 1];
    }
    else
    {
        data->infile = argv[1];
        data->commands = &argv[2];
        data->nb_commands = argc - 4;
        data->outfile = argv[argc - 1];
    }
}
```

### processes.c

```c
void handle_regular_pipex(t_pipex *data)
{
    create_pipes(data);
    create_processes(data);
    close_all_pipes(data);
    wait_for_children(data);
}

void create_processes(t_pipex *data)
{
    int i;
    
    data->pids = malloc(sizeof(pid_t) * data->nb_commands);
    if (!data->pids)
        error_exit("Malloc failed");
        
    i = 0;
    while (i < data->nb_commands)
    {
        data->pids[i] = fork();
        if (data->pids[i] == -1)
            error_exit("Fork failed");
        else if (data->pids[i] == 0)
            child_process(data, i);
        i++;
    }
}

void child_process(t_pipex *data, int cmd_index)
{
    setup_redirections(data, cmd_index);
    close_all_pipes(data);
    execute_command(data->commands[cmd_index], data->envp);
}
```

### pipes.c

```c
void create_pipes(t_pipex *data)
{
    int i;
    int nb_pipes;
    
    nb_pipes = data->nb_commands - 1;
    if (nb_pipes <= 0)
        return;
        
    data->pipes = malloc(sizeof(int*) * nb_pipes);
    if (!data->pipes)
        error_exit("Malloc failed");
        
    i = 0;
    while (i < nb_pipes)
    {
        data->pipes[i] = malloc(sizeof(int) * 2);
        if (!data->pipes[i])
            error_exit("Malloc failed");
        if (pipe(data->pipes[i]) == -1)
            error_exit("Pipe failed");
        i++;
    }
}

void close_all_pipes(t_pipex *data)
{
    int i;
    int nb_pipes;
    
    nb_pipes = data->nb_commands - 1;
    i = 0;
    while (i < nb_pipes)
    {
        close(data->pipes[i][0]);
        close(data->pipes[i][1]);
        i++;
    }
}
```

### here_doc.c

```c
void handle_here_doc(t_pipex *data)
{
    int temp_pipe[2];
    
    if (pipe(temp_pipe) == -1)
        error_exit("Pipe failed");
        
    read_here_doc(data->limiter, temp_pipe[1]);
    
    // Remplacer stdin par le pipe temporaire
    dup2(temp_pipe[0], STDIN_FILENO);
    close(temp_pipe[0]);
    close(temp_pipe[1]);
    
    // Continuer avec l'algorithme normal
    create_pipes(data);
    create_processes(data);
    close_all_pipes(data);
    wait_for_children(data);
}

void read_here_doc(char *limiter, int write_fd)
{
    char *line;
    size_t len = 0;
    
    write(STDOUT_FILENO, "pipe heredoc> ", 14);
    while (getline(&line, &len, stdin) != -1)
    {
        if (strncmp(line, limiter, strlen(limiter)) == 0 && 
            line[strlen(limiter)] == '\n')
        {
            free(line);
            break;
        }
        write(write_fd, line, strlen(line));
        write(STDOUT_FILENO, "pipe heredoc> ", 14);
    }
    close(write_fd);
}
```

## Tests et debugging

### Tests de base

```bash
# Test simple
echo "hello world" > input.txt
./pipex input.txt "cat" "wc -w" output.txt
cat output.txt  # Devrait afficher "2"

# Comparaison avec shell
< input.txt cat | wc -w  # Devrait donner le même résultat
```

### Tests d'erreurs

```bash
# Fichier inexistant
./pipex nonexistent.txt "cat" "wc -l" output.txt

# Commande inexistante  
./pipex input.txt "invalidcmd" "wc -l" output.txt

# Permissions
chmod 000 input.txt
./pipex input.txt "cat" "wc -l" output.txt
```

### Tests bonus

```bash
# Multiple pipes
./pipex input.txt "cat" "grep hello" "sort" "uniq" output.txt

# Here_doc
./pipex here_doc EOF "grep hello" "wc -l" output.txt
hello world
test line
hello 42
EOF
```

### Debugging avec strace

```bash
# Voir tous les appels système
strace -f ./pipex input.txt "cat" "wc -l" output.txt

# Se concentrer sur les pipes et redirections
strace -e trace=pipe,dup2,fork,execve ./pipex input.txt "cat" "wc -l" output.txt
```

### Vérification des fuites mémoire

```bash
valgrind --leak-check=full --track-fds=yes ./pipex input.txt "cat" "wc -l" output.txt
```

## Conseils d'implémentation

### 1. Commencer simple
- Implémentez d'abord la version basique avec 2 commandes
- Testez exhaustivement avant d'ajouter les bonus
- Gérez les erreurs dès le début

### 2. Gestion des processus
- Toujours fermer les descripteurs de fichiers inutilisés
- Utiliser `waitpid()` pour éviter les processus zombies
- Attention aux conditions de course

### 3. Parsing robuste
- Gérer les espaces multiples dans les commandes
- Attention aux guillemets et caractères spéciaux
- Valider toutes les entrées utilisateur

### 4. Gestion d'erreurs
- Utiliser `perror()` pour les erreurs système
- Nettoyer la mémoire avant de quitter
- Retourner les codes de sortie appropriés

### 5. Tests
- Comparer systématiquement avec le comportement du shell
- Tester tous les cas d'erreur
- Utiliser des outils comme `strace` et `valgrind`

## Conclusion

Pipex est un excellent projet pour apprendre :
- La programmation système Unix
- La gestion des processus et de la communication inter-processus
- Les redirections et la manipulation des descripteurs de fichiers
- La robustesse et la gestion d'erreurs

La clé du succès est de bien comprendre le comportement du shell avant d'implémenter, et de tester exhaustivement chaque fonctionnalité.