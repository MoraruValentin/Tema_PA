
///\file functions.c
///\brief C library implementation for a library used to solve change making problem in two selected methods .
///
/// Created by Moraru Teodor Valentin on 01/06/18.
/// Implements greedy and dynamic methods used to solve the change making problem.
#include <stdlib.h>
#include <stdio.h>

///\var struct change_entry is a structure used to ease the readability of the solution.
struct change_entry
{   
    int count;
    int coin;
    struct change_entry *prev;
};

typedef struct change_entry change_entry;

 int dynamic_method(const int *coins_list, int coins_no, int owed, int **solution)
{///\fn int dynamic_method()
	///\brief solves the change making problem with a dynamic algorith implementation.
	///
    int i, j;
    change_entry **table;
    int result;

    /// Allocate the memory for the table.
    ///
    table = malloc((coins_no + 1) * sizeof(change_entry *));
    for (i = 0; i <= coins_no; i++)
    {
        table[i] = malloc((owed + 1) * sizeof(change_entry));
    }

    /// Calculate the oweds and build chains.
    ///
    for (i = 0; i <= coins_no; i++)
    {
        for (j = 0; j <= owed; j++)
        {
            if (i == 0)
            {
                /// Initialising the first row.
                ///
                table[i][j].count = j;
                table[i][j].coin = -1;
                table[i][j].prev = NULL;
            }
            else if (j == 0)
            {
                /// Initialising the first column.
                ///
                table[i][j].count = 0;
                table[i][j].coin = -1;
                table[i][j].prev = NULL;
            }
            else if (coins_list[i - 1] == j)
            {
                /// Can use a specific coin.
                ///
                table[i][j].count = 1;
                table[i][j].coin = i - 1;
                table[i][j].prev = NULL;
            }
            else if (coins_list[i - 1] > j)
            {
                /// Can't use a specific coin.
                ///
                table[i][j].count = table[i - 1][j].count;
                table[i][j].coin = -1;
                table[i][j].prev = &table[i - 1][j];
            }
            else
            {
                /// If the coin is usable -> choose best solution.
                ///
                if (table[i - 1][j].count < table[i][j - coins_list[i - 1]].count + 1)
                {
                    /// Don't use the coin .
                    ///
                    table[i][j].count = table[i - 1][j].count;
                    table[i][j].coin = -1;
                    table[i][j].prev = &table[i - 1][j];
                }
                else
                {
                    /// Use the coin.
                    ///
                    table[i][j].count = table[i][j - coins_list[i - 1]].count + 1;
                    table[i][j].coin = i - 1;
                    table[i][j].prev = &table[i][j - coins_list[i - 1]];
                }
            }
        }
    }

    result = table[coins_no][owed].count;

    /// Read back the solution.
    ///
    *solution = calloc(coins_no, sizeof(int));
    if (*solution)
    {
        change_entry *head;
        for (head = &table[coins_no][owed];head != NULL;head = head->prev)
        {
            if (head->coin != -1)
            {
                (*solution)[head->coin]++;
            }
        }
    }
    else
    {
        result = 0;
    }

    for (i = 0; i <= coins_no; i++)
    {
        free(table[i]);
    }

    free(table);

    return result;
}
void greedy_method(int owed ,int coins_no ,int coins_list[100])
{///\fn void greedy_method()
    ///\brief solves the change making problem with a greedy algorith implementation
    ///
    ///\var int good_picks[100] is an array used to store coins that are being used for the solution
    int i , good_picks[100];
    
    /// greedy method implies repetitive division of the owed sum and the hightest value coin .
    ///
    for(i = 0 ; i < coins_no ; i++)
    {
        good_picks[i] = owed / coins_list[i] ;
        owed = owed % coins_list[i] ;
    }


    if(owed == 0)
    {
        /// if the owed sum is 0 it means there is no change left.
        ///
        printf("\nSolution: \n") ;
        printf("Coins used:\n");
        for(i = 0 ; i < coins_no ; i++)
        {

        printf("%d x %d \n" , good_picks[i],coins_list[i]) ;

        }
    }
    else
	{      
        ///if the owed sum is not 0 it means there is a remainder value left that cannot be unchanged.
        ///
		printf("\nSolution: \n");
		printf("Coins used:\n");
		for(i = 0 ; i < coins_no ; i++)
        {
            printf(" %d x %d ", good_picks[i],coins_list[i]);
		}
		printf("\nRemaider value that could not be changed is :\n %d",owed);
	}
}