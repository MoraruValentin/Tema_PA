int main ()
{
	int currency_no , coin_list[100] , good_picks[100] , i , owed ;

    start:
	printf("\nEnter the amount owed : ") ;
	scanf("%d" , &owed);

	printf("Enter number of denominations : ") ;
	scanf("%d" , &currency_no);

	printf("\nEnter the denominations in descending order: ") ;
	for(i = 0 ; i < currency_no ; i++)
    {
        scanf("%d" , &coin_list[i]) ;
	}

	for(i = 0 ; i < currency_no ; i++)
	{
		if(coin_list[i] == 0)
		{
			printf("\nA coin with no value is not permited, try again:\n");
			goto start;
		}
	}

	for(i = 0 ; i < currency_no ; i++)
    {
		good_picks[i] = owed / coin_list[i] ;
		owed = owed % coin_list[i] ;
	}

	if(owed == 0)
	{
		printf("\nSolution: \n") ;
		for(i = 0 ; i < currency_no ; i++)
   		{

		printf("%dx%d " , coin_list[i] , good_picks[i]) ;

		}

	}	
}
