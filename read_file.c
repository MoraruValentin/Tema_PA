void get_values(int *owed , int *coins_no , int coins_list[100])
{
    int i , hold_owed ,hold_no;

    FILE *input_file;
    input_file=fopen("input.txt","r");

    fscanf( input_file, "%d", &hold_owed );
    *owed = hold_owed;
    fscanf( input_file, "%d", &hold_no );
    *coins_no = hold_no ;

    for ( i = 0 ; i < hold_no ; i++)
    {
        fscanf( input_file, "%d", &coins_list[i] );
    }

    fclose(input_file);
}