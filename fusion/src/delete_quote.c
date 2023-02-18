#include "minishell.h"


static char *delete_quote(char *line, char *new_line, t_quote quote, int *j)
{
    int j_copy;

    quote.i= quote.i - 1;
    while ((quote.old_i + 1) != quote.i)
    {
        new_line[(*j)] = line[quote.old_i+ 1];
        (*j)++;
        quote.old_i++;
    }
    j_copy = (*j);
    if (line && line [quote.old_i+ 1] != '\0')
    {
        j_copy++;
        quote.old_i++;
    }
    while (line[quote.old_i+ 1] != '\0')
    {
        new_line[j_copy - 1] = line[quote.old_i+ 1];
        j_copy++;
        quote.old_i++;
    }
    new_line[j_copy - 1] = line[quote.old_i+ 1];
    return (new_line);
}

static int skip_inside(char *line, int i)
{
    if (line[i] == '"' && line [i + 1] == '"')
        return (i + 1);
    if (line[i] != '"')
        return (i);
    else
        i++;
    while (line && line [i] != '\0' && line[i] != '"')
        i++;
    return (i + 1);
}

char *delete_the_quote(char *line, int j, int len)
{
    char *new_line;
    t_quote quote;

    quote.i = 0;
    len = ft_strlen(line);
    new_line = malloc ( len * sizeof(char));
    while (line && line [quote.i])
    {
        quote.old_i= quote.i;
        quote.i = skip_inside(line, quote.i);// si i n'est pa different de i ou juste de 1 ca depend si il fait avancer meme de 1 quand il trouve rinie
        if (quote.i == (quote.old_i + 1))
            quote.i = quote.i + 1;
        else if (quote.i != quote.old_i)
            new_line = delete_quote(line, new_line, quote, &j);
        else if (line && line [quote.i] != '\0')
        {
            new_line[j] = line[quote.i];
            j++;
            quote.i++;
        }
    }
    new_line[j] = line[quote.i];
    free (line);
    return (new_line);
}