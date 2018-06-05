///\file functions.h
///\brief C library implementation for a library used to solve change making problem in two selected methods .
///
/// Created by Moraru Teodor Valentin on 01/06/18.
/// Implements greedy and dynamic methods used to solve the change making problem.

int dynamic_method(const int *coins_list, int coins_no, int owed, int **solution,double *time_dyn);
void greedy_method(int owed ,int coins_no ,int coins_list[100],int good_picks[100]);