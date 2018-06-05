///\file get_value.c
///\brief C library implementation for a library for reading input data from a file .
///
/// Created by Moraru Teodor Valentin on 01/06/18.

#include <stdlib.h>///>malloc(), calloc(), free()
#include <stdio.h>///>printf() , scanf()

void get_values(int *owed , int *coins_no , int coins_list[100])
{   
///\fn void get_values()
    ///\brief Read the file ,owed sum,number of coins ,list of coins
    ///
    ///\brief "input.txt" is used to read owed sum , number of coins and list of coins.
    /// 
    int i , hold_owed ,hold_no;

    FILE *input_file;
    input_file=fopen("input.txt","r");

    ///The first digit in the input.txt file represents the owed sum.
    ///
    fscanf( input_file, "%d", &hold_owed );
    *owed = hold_owed;
    ///The second digit in the input.txt file represents the coins number.
    ///
    fscanf( input_file, "%d", &hold_no );
    *coins_no = hold_no ;


    ///The other digits must be the coins values in a descending order ( meant for the greedy algorith and not necesary for the dynamic aproach).
    ///
    for ( i = 0 ; i < hold_no ; i++)
    {
        fscanf( input_file, "%d", &coins_list[i] );
    }

    fclose(input_file);
}