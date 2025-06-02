# Push_swap - Radix Sort Binaire

## Table des matières
1. [Introduction](#introduction)
2. [Comprendre push_swap](#comprendre-push_swap)
3. [Qu'est-ce que le radix sort ?](#quest-ce-que-le-radix-sort)
4. [Pourquoi utiliser la représentation binaire ?](#pourquoi-utiliser-la-représentation-binaire)
5. [Préparation des données](#préparation-des-données)
6. [Algorithme radix sort binaire](#algorithme-radix-sort-binaire)
7. [Implémentation détaillée](#implémentation-détaillée)
8. [Optimisations](#optimisations)
9. [Complexité](#complexité)
10. [Exemple complet](#exemple-complet)

## Introduction

Ce guide explique comment résoudre le projet push_swap de l'École 42 en utilisant l'algorithme **radix sort en binaire**. Cette approche est particulièrement efficace pour trier de grandes quantités de nombres avec un nombre d'opérations prévisible et relativement faible.

## Comprendre push_swap

### Le problème
- Vous avez deux piles : **pile A** (contient les nombres à trier) et **pile B** (vide au début)
- **Objectif** : trier la pile A par ordre croissant avec le minimum d'opérations
- **Contrainte** : vous ne pouvez utiliser que les opérations autorisées

### Opérations autorisées
- `sa` : swap les 2 premiers éléments de la pile A
- `sb` : swap les 2 premiers éléments de la pile B
- `ss` : `sa` et `sb` en même temps
- `pa` : push le premier élément de B vers A
- `pb` : push le premier élément de A vers B
- `ra` : rotate A (le premier élément devient le dernier)
- `rb` : rotate B
- `rr` : `ra` et `rb` en même temps
- `rra` : reverse rotate A (le dernier élément devient le premier)
- `rrb` : reverse rotate B
- `rrr` : `rra` et `rrb` en même temps

## Qu'est-ce que le radix sort ?

Le **radix sort** est un algorithme de tri qui fonctionne en triant les éléments chiffre par chiffre, en commençant par le chiffre le moins significatif.

### Principe général
1. On examine chaque "chiffre" de tous les nombres
2. On groupe les nombres selon la valeur de ce chiffre
3. On répète pour chaque position de chiffre
4. À la fin, les nombres sont triés

### Exemple avec des nombres décimaux
Pour trier [170, 45, 75, 2, 802, 24, 66] :

**Étape 1** - Trier par unités (chiffre le moins significatif) :
- 0 : [170]
- 2 : [2, 802]
- 4 : [24]
- 5 : [45, 75]
- 6 : [66]
→ Résultat temporaire : [170, 2, 802, 24, 45, 75, 66]

**Étape 2** - Trier par dizaines :
- 0 : [2]
- 2 : [24]
- 4 : [45]
- 6 : [66]
- 7 : [170, 75]
- 0 : [802]
→ Résultat temporaire : [2, 24, 45, 66, 170, 75, 802]

**Étape 3** - Trier par centaines :
- 0 : [2, 24, 45, 66, 75]
- 1 : [170]
- 8 : [802]
→ Résultat final : [2, 24, 45, 66, 75, 170, 802]

## Pourquoi utiliser la représentation binaire ?

### Avantages du binaire
1. **Simplicité** : seulement 2 états possibles (0 ou 1)
2. **Efficacité** : facile à implémenter avec les opérations de push_swap
3. **Prévisibilité** : nombre d'étapes fixe basé sur le nombre de bits

### Comment ça marche
Au lieu d'examiner chaque chiffre décimal, on examine chaque **bit** de la représentation binaire des nombres.

### Exemple de conversion
```
Nombre : 5
Binaire : 101
Bits : [1, 0, 1] (de droite à gauche : bit 0, bit 1, bit 2)
```

## Préparation des données

### 1. Normalisation des nombres
Avant d'appliquer radix sort, il faut **normaliser** les nombres pour qu'ils soient tous positifs et consécutifs.

**Pourquoi normaliser ?**
- Les nombres peuvent être négatifs
- Les nombres peuvent avoir de gros écarts
- On veut optimiser le nombre de bits nécessaires

**Comment normaliser ?**
1. Trier les nombres par ordre croissant
2. Remplacer chaque nombre par son rang (position dans le tri)

### Exemple de normalisation
```
Entrée : [-10, 3, 1, 42, -5]
Tri : [-10, -5, 1, 3, 42]
Rang : [0, 1, 2, 3, 4]
Mapping : -10→0, -5→1, 1→2, 3→3, 42→4
Pile A normalisée : [0, 3, 2, 4, 1]
```

### 2. Calculer le nombre de bits nécessaires
```c
int get_max_bits(int size)
{
    int bits = 0;
    while ((1 << bits) < size)
        bits++;
    return bits;
}
```

Pour 5 éléments : `get_max_bits(5) = 3` (car 2³ = 8 ≥ 5)

## Algorithme radix sort binaire

### Vue d'ensemble
```
Pour chaque bit (du moins significatif au plus significatif) :
    1. Parcourir tous les éléments de la pile A
    2. Si le bit actuel est 0 : pousser vers pile B
    3. Si le bit actuel est 1 : faire un rotate et passer au suivant
    4. Une fois tous les éléments traités, remettre tous les éléments de B vers A
```

### Algorithme détaillé
```
fonction radix_sort(pile_a, pile_b):
    max_bits = calculer_nombre_bits_max()
    
    pour bit_position de 0 à max_bits-1 :
        taille_pile = taille(pile_a)
        
        pour i de 0 à taille_pile-1 :
            element = sommet(pile_a)
            bit_actuel = (element >> bit_position) & 1
            
            si bit_actuel == 0 :
                pb()  // pousser vers pile B
            sinon :
                ra()  // rotate pile A
        
        // Remettre tous les éléments de B vers A
        tant que pile_b n'est pas vide :
            pa()
```

### Pourquoi ça marche ?
- **Bit 0** : sépare les nombres pairs (bit=0) des impairs (bit=1)
- **Bit 1** : sépare selon les groupes de 2
- **Bit 2** : sépare selon les groupes de 4
- etc.

À chaque étape, on maintient l'ordre relatif des éléments dans chaque groupe, ce qui garantit un tri stable.

## Implémentation détaillée

### Structure de données
```c
typedef struct s_stack
{
    int *array;
    int size;
    int capacity;
} t_stack;
```

### Fonctions utilitaires
```c
// Vérifier si un bit spécifique est activé
int get_bit(int number, int bit_position)
{
    return (number >> bit_position) & 1;
}

// Calculer le nombre maximum de bits nécessaires
int get_max_bits(int max_number)
{
    int bits = 0;
    while ((1 << bits) <= max_number)
        bits++;
    return bits;
}

// Normaliser les nombres (les remplacer par leur rang)
void normalize_numbers(int *array, int size)
{
    // Créer une copie et la trier
    int *sorted = malloc(sizeof(int) * size);
    memcpy(sorted, array, sizeof(int) * size);
    sort_array(sorted, size);
    
    // Remplacer chaque nombre par son rang
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (array[i] == sorted[j])
            {
                array[i] = j;
                break;
            }
        }
    }
    free(sorted);
}
```

### Implémentation principale
```c
void radix_sort(t_stack *stack_a, t_stack *stack_b)
{
    int max_bits = get_max_bits(stack_a->size - 1);
    
    for (int bit = 0; bit < max_bits; bit++)
    {
        int size = stack_a->size;
        
        for (int i = 0; i < size; i++)
        {
            int current_element = stack_a->array[stack_a->size - 1];
            
            if (get_bit(current_element, bit) == 0)
            {
                pb(stack_a, stack_b);
            }
            else
            {
                ra(stack_a);
            }
        }
        
        // Remettre tous les éléments de B vers A
        while (stack_b->size > 0)
        {
            pa(stack_a, stack_b);
        }
    }
}
```

## Optimisations

### 1. Arrêt anticipé
Si à un moment donné la pile A est déjà triée, on peut arrêter l'algorithme.

```c
int is_sorted(t_stack *stack)
{
    for (int i = stack->size - 1; i > 0; i--)
    {
        if (stack->array[i] > stack->array[i-1])
            return 0;
    }
    return 1;
}
```

### 2. Optimisation pour les petites piles
Pour les piles de moins de 6 éléments, il peut être plus efficace d'utiliser des algorithmes spécialisés plutôt que radix sort.

### 3. Gestion des cas particuliers
- Pile déjà triée : 0 opération
- Pile de 2 éléments : au maximum 1 opération (`sa`)
- Pile de 3 éléments : algorithme spécialisé plus efficace

## Complexité

### Complexité temporelle
- **O(d × n)** où :
  - `d` = nombre de bits = O(log n)
  - `n` = nombre d'éléments
- **Donc O(n log n)** dans le cas général

### Complexité en nombre d'opérations push_swap
- **Maximum théorique** : `n × log₂(n) × 2` opérations
  - `n × log₂(n)` pour les `pb` et `ra`
  - `n × log₂(n)` pour les `pa`
- **En pratique** : beaucoup moins grâce aux optimisations

### Comparaison avec autres algorithmes
- **Quick sort adapté** : plus rapide en moyenne mais imprévisible
- **Tri par insertion** : O(n²) dans le pire cas
- **Radix sort** : prévisible et efficace pour de gros volumes

## Exemple complet

### Données d'entrée
```
Pile A : [4, 2, 8, 1, 3]
Pile B : []
```

### Étape 1 : Normalisation
```
Tri des valeurs : [1, 2, 3, 4, 8]
Mapping : 1→0, 2→1, 3→2, 4→3, 8→4
Pile A normalisée : [3, 1, 4, 0, 2]
```

### Étape 2 : Calcul du nombre de bits
5 éléments → 3 bits nécessaires (2³ = 8 ≥ 5)

### Étape 3 : Représentation binaire
```
0 → 000
1 → 001  
2 → 010
3 → 011
4 → 100
```

### Étape 4 : Tri bit par bit

**Bit 0 (moins significatif) :**
```
État initial : A=[3,1,4,0,2] B=[]
                  011,001,100,000,010

3 (011) → bit 0 = 1 → ra() → A=[1,4,0,2,3] B=[]
1 (001) → bit 0 = 1 → ra() → A=[4,0,2,3,1] B=[]  
4 (100) → bit 0 = 0 → pb() → A=[0,2,3,1] B=[4]
0 (000) → bit 0 = 0 → pb() → A=[2,3,1] B=[4,0]
2 (010) → bit 0 = 0 → pb() → A=[3,1] B=[4,0,2]

Remettre B vers A :
pa() → A=[2,3,1] B=[4,0]
pa() → A=[0,2,3,1] B=[4]  
pa() → A=[4,0,2,3,1] B=[]

État après bit 0 : A=[4,0,2,3,1] B=[]
```

**Bit 1 :**
```
État : A=[4,0,2,3,1] B=[]
       100,000,010,011,001

4 (100) → bit 1 = 0 → pb() → A=[0,2,3,1] B=[4]
0 (000) → bit 1 = 0 → pb() → A=[2,3,1] B=[4,0]
2 (010) → bit 1 = 1 → ra() → A=[3,1,2] B=[4,0]
3 (011) → bit 1 = 1 → ra() → A=[1,2,3] B=[4,0]
1 (001) → bit 1 = 0 → pb() → A=[2,3] B=[4,0,1]

Remettre B vers A :
État après bit 1 : A=[1,0,4,2,3] B=[]
```

**Bit 2 (plus significatif) :**
```
État : A=[1,0,4,2,3] B=[]
       001,000,100,010,011

1 (001) → bit 2 = 0 → pb() → A=[0,4,2,3] B=[1]
0 (000) → bit 2 = 0 → pb() → A=[4,2,3] B=[1,0]  
4 (100) → bit 2 = 1 → ra() → A=[2,3,4] B=[1,0]
2 (010) → bit 2 = 0 → pb() → A=[3,4] B=[1,0,2]
3 (011) → bit 2 = 0 → pb() → A=[4] B=[1,0,2,3]

Remettre B vers A :
État final : A=[3,2,0,1,4] B=[]
```

### Vérification
```
Pile A finale normalisée : [3,2,0,1,4]
Conversion inverse : [4,3,1,2,8]
Est-ce trié ? [1,2,3,4,8] ✓
```

## Conseils d'implémentation

### 1. Gestion des erreurs
- Vérifier les arguments d'entrée
- Gérer les doublons
- Vérifier les débordements de pile

### 2. Optimisation mémoire
- Utiliser des tableaux plutôt que des listes chaînées
- Réutiliser les structures de données

### 3. Tests
- Tester avec différentes tailles de pile
- Tester avec des cas limites (pile triée, inversée)
- Vérifier le nombre d'opérations généré

### 4. Debugging
- Afficher l'état des piles à chaque étape
- Tracer les opérations effectuées
- Vérifier que la pile est bien triée à la fin

## Conclusion

Le radix sort binaire est une excellente solution pour push_swap car :
- **Prévisible** : le nombre d'opérations est borné
- **Efficace** : O(n log n) en complexité
- **Simple** : logique claire et facile à déboguer
- **Scalable** : fonctionne bien même avec de gros volumes

Cette approche vous permettra de réussir push_swap avec un nombre d'opérations raisonnable et un code maintenable.