#include <stdlib.h>
#include <unistd.h>
#include "./libft/ft_printf.h"
#include "libft/libft.h"

void check_for_char(char **tab) {
    int i = 0;
    while (tab[i] != NULL) {
        int j = 0;
        if (tab[i][0] == '+' || tab[i][0] == '-')
            j++;
        while (tab[i][j] != '\0') {
            if (ft_isdigit(tab[i][j])) {
                return ;
            }
            else
            {
                ft_printf("Error: Character detected in input.\n");
                exit(1);
            }
            j++;
        }
        i++;
    }
}



void check(char **tab)
{
    int i = 0;
    int j = 0;
    int count = 0;
    while (tab[i] != NULL)
    {
        j = 0;
        count = 0;
        if (tab[i][0] == '+' || tab[i][0] == '-')
                j++;
        while (tab[i][j] != '\0')
        {
            if (!ft_isdigit(tab[i][j]))
                count++;
            j++;
        }
        if (count >= 1)
        {
            ft_printf("Error: Invalid input.\n");
            exit(1);
        }
        i++;
    }
}

int	*convert_tab_to_int_array(char **tab)
{
    char **tabPtr = tab;
    int tabSize = 0;
    while (*tabPtr)
    {
        tabSize++;
        tabPtr++;
    }
    int *numArray = (int *)malloc(sizeof(int) * tabSize);
    if (!numArray)
    {
        return (NULL);
    }
    tabPtr = tab;
    int i = 0;
    while (*tabPtr)
    {
        numArray[i] = ft_atoi(*tabPtr);
        i++;
        tabPtr++;
    }
    return (numArray);
}

char **ft_concat_arrays(char **arr1, char **arr2) 
{
    int i = 0, j = 0;
    while (arr1[i] != NULL) 
      i++;
    while (arr2[j] != NULL) 
      j++;
    char **result = malloc((i + j + 1) * sizeof(char *));
    if (result == NULL) return NULL;
    int k = 0;
    while (k < i) {
        result[k] = arr1[k];
        k++;
    }
    k = 0;
    while (k < j) {
        result[i + k] = arr2[k];
        k++;
    }
    result[i + j] = NULL;
    return (result);
}

void check_duplicates(int *numArray) {
    int i = 0;
    int count = 0;
    while (numArray[count] != '\0') {
        count++;
    }
    while(i < count) {
        int j = i + 1;
        while(j < count) {
            if(numArray[i] == numArray[j]) {
                ft_printf("Error: Duplicate numbers found.\n");
                exit(1);
            }
            j++;
        }
        i++;
    }
}

int	main(int argc, char **argv)
{
  int i = 1;
  char **tab = NULL;
  char **temp = NULL;
  int *numArray = NULL;
  while (i < argc)
  {
      temp = ft_split(argv[i], ' ');
      if (tab == NULL)
      {
        tab = temp;
      }
      else
      {
        tab = ft_concat_arrays(tab, temp);
      }
      i++;
  }
  check_for_char(tab);
  check(tab);
  numArray = convert_tab_to_int_array(tab);
  check_duplicates(numArray);
  while (*numArray)
  {
    ft_printf("%d\n", *numArray);
    numArray++;
  }
  return (0);
}
