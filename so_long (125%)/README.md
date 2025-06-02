# so_long

Un jeu 2D simple développé en C utilisant la bibliothèque graphique MiniLibX, où le joueur contrôle un personnage qui doit collecter tous les objets sur la carte avant de pouvoir s'échapper.

## 📋 Table des matières

- [Description](#description)
- [Fonctionnalités](#fonctionnalités)
- [Installation](#installation)
- [Utilisation](#utilisation)
- [Architecture du projet](#architecture-du-projet)
- [Logique de résolution](#logique-de-résolution)
- [Bonus implémentés](#bonus-implémentés)
- [Structure des fichiers](#structure-des-fichiers)

## 📖 Description

so_long est un projet de l'école 42 qui consiste à créer un petit jeu 2D. Le joueur incarne un personnage qui doit naviguer dans un labyrinthe, collecter tous les objets collectables, puis atteindre la sortie pour gagner.

## ✨ Fonctionnalités

### Fonctionnalités de base
- **Mouvement du joueur** : Déplacement avec les touches WASD ou les flèches directionnelles
- **Collecte d'objets** : Le joueur doit ramasser tous les collectables avant de pouvoir sortir
- **Gestion des collisions** : Impossible de traverser les murs
- **Compteur de mouvements** : Affichage du nombre de mouvements dans le terminal
- **Validation de carte** : Vérification de la validité de la carte au lancement

### Fonctionnalités bonus
- **Animations de sprites** : Personnages et objets animés
- **Ennemis** : Patrouilles d'ennemis avec IA simple
- **Interface graphique** : Compteur de mouvements affiché à l'écran
- **Effets visuels** : Transitions et animations fluides

## 🚀 Installation

```bash
# Cloner le repository
git clone [votre-repo-url] so_long
cd so_long

# Compiler le projet
make

# Pour compiler avec les bonus
make bonus
```

## 🎮 Utilisation

```bash
# Lancer le jeu avec une carte
./so_long maps/map.ber

# Ou avec la version bonus
./so_long_bonus maps/map.ber
```

### Contrôles
- **W/↑** : Déplacement vers le haut
- **A/←** : Déplacement vers la gauche  
- **S/↓** : Déplacement vers le bas
- **D/→** : Déplacement vers la droite
- **ESC** : Quitter le jeu

## 🏗 Architecture du projet

```
src/
├── main.c              # Point d'entrée du programme
├── game/
│   ├── game_init.c     # Initialisation du jeu
│   ├── game_loop.c     # Boucle principale du jeu
│   └── game_exit.c     # Gestion de la sortie
├── player/
│   ├── player_move.c   # Gestion des mouvements
│   └── player_utils.c  # Utilitaires du joueur
├── map/
│   ├── map_parser.c    # Analyse et validation des cartes
│   ├── map_checker.c   # Vérifications de validité
│   └── map_utils.c     # Utilitaires de carte
├── graphics/
│   ├── render.c        # Rendu graphique
│   ├── sprites.c       # Gestion des sprites
│   └── animations.c    # Système d'animations (bonus)
└── utils/
    ├── error.c         # Gestion des erreurs
    └── memory.c        # Gestion mémoire
```

## 🧠 Logique de résolution

### 1. Parsing et validation de la carte

Le programme commence par analyser le fichier `.ber` fourni :

```c
// Étapes de validation
1. Lecture du fichier ligne par ligne
2. Vérification des caractères valides (0, 1, P, E, C)
3. Contrôle de la forme rectangulaire
4. Validation des bordures (doivent être des murs '1')
5. Vérification des éléments obligatoires :
   - Exactement 1 joueur (P)
   - Exactement 1 sortie (E)  
   - Au moins 1 collectable (C)
```

**Algorithme de pathfinding** : Utilisation d'un flood-fill pour s'assurer que tous les collectables et la sortie sont accessibles depuis la position du joueur.

### 2. Initialisation du jeu

```c
// Structure principale du jeu
typedef struct s_game {
    void    *mlx;           // Pointeur MLX
    void    *window;        // Fenêtre de jeu
    t_map   *map;          // Structure de la carte
    t_player *player;      // Structure du joueur
    int     moves;         // Compteur de mouvements
    int     collectables;  // Nombre de collectables restants
} t_game;
```

### 3. Boucle de jeu principale

La logique suit ce schéma :

1. **Capture d'événements** : Détection des touches pressées
2. **Validation du mouvement** : Vérification des collisions
3. **Mise à jour de l'état** : 
   - Position du joueur
   - Collecte d'objets
   - Compteur de mouvements
4. **Vérification des conditions de victoire/défaite**
5. **Rendu graphique** : Affichage de tous les éléments

### 4. Gestion des mouvements

```c
int move_player(t_game *game, int new_x, int new_y)
{
    // 1. Vérifier si la case de destination est valide
    if (game->map->grid[new_y][new_x] == '1')
        return (0); // Mur - mouvement invalide
    
    // 2. Gérer les collectables
    if (game->map->grid[new_y][new_x] == 'C') {
        game->collectables--;
        game->map->grid[new_y][new_x] = '0'; // Supprimer le collectable
    }
    
    // 3. Gérer la sortie
    if (game->map->grid[new_y][new_x] == 'E') {
        if (game->collectables == 0)
            win_game(game); // Victoire !
        else
            return (0); // Sortie bloquée
    }
    
    // 4. Mettre à jour la position
    game->player->x = new_x;
    game->player->y = new_y;
    game->moves++;
    
    return (1);
}
```

### 5. Système de rendu

Le rendu suit une logique de couches :

1. **Couche de fond** : Sol et murs
2. **Couche d'objets** : Collectables et sortie
3. **Couche d'entités** : Joueur et ennemis (bonus)
4. **Couche d'interface** : HUD et compteurs (bonus)

## 🎯 Bonus implémentés

### Animations de sprites
- **Système de frames** : Chaque sprite a plusieurs frames d'animation
- **Timer d'animation** : Changement de frame basé sur le temps
- **États d'animation** : Idle, marche, collecte

```c
typedef struct s_sprite {
    void    **frames;      // Tableau des frames
    int     frame_count;   // Nombre de frames
    int     current_frame; // Frame actuelle
    int     frame_timer;   // Timer pour l'animation
} t_sprite;
```

### Intelligence artificielle des ennemis
- **Patrouilles** : Mouvements prédéfinis ou aléatoires
- **Détection de collision** : Les ennemis ne traversent pas les murs
- **Interaction avec le joueur** : Game over au contact

### Interface graphique améliorée
- **Compteur de mouvements à l'écran** : Affichage en temps réel
- **Barre de collectables** : Progression visuelle
- **Messages d'état** : Victoire, défaite, instructions

## 📁 Structure des fichiers

```
so_long/
├── Makefile
├── README.md
├── includes/
│   └── so_long.h
├── libs/
│   └── minilibx/
├── maps/
│   ├── valid_map.ber
│   ├── invalid_map.ber
│   └── bonus_map.ber
├── sprites/
│   ├── player/
│   ├── collectables/
│   ├── walls/
│   └── enemies/
└── src/
    └── [fichiers source]
```

## 🎮 Format des cartes

Les cartes utilisent l'extension `.ber` et suivent ces règles :

- `0` : Espace vide
- `1` : Mur
- `P` : Position de départ du joueur
- `E` : Sortie
- `C` : Collectable
- `X` : Ennemi (bonus)

Exemple de carte valide :
```
1111111111111
10010000000C1
1000011111001
1P0011E000001
1111111111111
```

## 🏆 Conseils de développement

1. **Commencer simple** : Implémentez d'abord la version de base
2. **Tester régulièrement** : Validez chaque fonctionnalité avant d'avancer
3. **Gérer la mémoire** : Libérez toujours les ressources allouées
4. **Optimiser le rendu** : Ne redessinez que ce qui a changé
5. **Documenter le code** : Commentez les parties complexes

## 🐛 Gestion des erreurs

Le programme gère ces erreurs courantes :
- Fichier de carte inexistant ou illisible
- Format de carte invalide
- Carte non résoluble (éléments inaccessibles)
- Erreurs d'allocation mémoire
- Erreurs d'initialisation MLX

---

**Note** : Ce projet fait partie du cursus de l'école 42 et vise à approfondir la compréhension de la programmation en C, de la gestion graphique et des algorithmes de base.