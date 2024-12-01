#include "push_swap.h"

int get_max_bits(t_stack *s)
{
    int max = s->data[0];
    for (int i = 1; i < s->size; i++)
    {
        if (s->data[i] > max)
            max = s->data[i];
    }
    int bits = 0;
    while (max)
    {
        bits++;
        max >>= 1;  // Décalage à droite (divise par 2)
    }
    return bits;
}

void radix_sort_pass(t_stack *a, t_stack *b, int bit_pos)
{
    int size = a->size;
    int i = 0;
    // Passer les éléments de A vers B en fonction du bit
    while (i < size)
    {
        // Vérifie si le bit à la position bit_pos est 0 ou 1
        // On utilise un masque de bit à bit_pos et on vérifie si le bit est à 0 ou à 1
        if (((a->data[0] >> bit_pos) & 1) == 0)
        {
            pb(a, b);  // Déplacer l'élément de A vers B
        }
        else
        {
            ra(a);  // Rotation de A si le bit est 1
        }
        i++;  // Passe à l'élément suivant
    }
    // Remonter les éléments de B vers A
    while (b->size > 0)
    {
        pa(a, b);  // Pousser un élément de B vers A
    }
}

void radix_sort(t_stack *a, t_stack *b)
{
    int bits = get_max_bits(a);  // Trouver le nombre de bits du plus grand élément
    for (int i = 0; i < bits; i++)  // Faire un passage pour chaque bit
    {
        radix_sort_pass(a, b, i);  // Appeler la fonction de tri pour chaque bit
    }
}
