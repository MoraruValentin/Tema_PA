///\file main.c
///\brief C program for solving the change making problem.
///
/// Created by Moraru Teodor Valentin on 01/06/18.
#include <stdlib.h>///>malloc(), calloc(), free()
#include <stdio.h>///>printf() , scanf()
#include "functions.h" ///> int dynamic_method(),void greedy_method()
#include "get_value.h" ///> void get_values()
#include <windows.h>///>system()

int main()
{///\brief Main function.
    ///
    ///Function calls of get_values , greedy_method , dynamic_method
    int owed=0 , coins_no=0 , coins_list[100],i,good_picks[100];
    double time_dyn;
    get_values(&owed,&coins_no,coins_list);
    int *solution;
    int result = dynamic_method(coins_list, coins_no, owed, &solution,&time_dyn);
    printf("Dynamic solution:\n");
    printf("Number of coins: %u\n", result);
    printf("Coins used:\n");
    for (i = 0; i < coins_no; i++)
    {
        if (solution[i] > 0)
        {
            printf("%u x %u\n",solution[i],coins_list[i]);
        }
    }
    printf("Execution time of the dynamic function: %lf\n", time_dyn);
    free(solution);

    greedy_method(owed , coins_no , coins_list,good_picks);
    system("pause");



    
}
