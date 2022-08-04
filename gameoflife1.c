  /* This C Program is a code for Game of life which uses file handling for both inout and output. And It also runs for 500 generations.
   * Mukesh J
   * 25/08/2021
   * ***/


  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>

  int** board;
  int** board1;
  int rows=0, cols=0;

  // This function Allocates memory space to both Board and Board1. It also takes input from file and stores into board matrix.
  void initialize(FILE *fp)
  {  
	int i=0,j=0; 
        //printf("Enter Number of Rows and Columns:  ");
        //scanf("%d %d", &rows, &cols);  
        while(1)
        {
             board = malloc(sizeof(int*)*rows);
             for(i=0; i<rows; i++)
		      board[i] = malloc(sizeof(int)*cols);
             if(board!= NULL)
                 break;
             else{
                 printf("\nBoard is not Allocated !!!\n");
                 return;     }
        }
        while(1)
        {
             board1 = malloc(sizeof(int*)*rows);
             for(i=0; i<rows; i++)
		      board1[i] = malloc(sizeof(int)*cols);
             if(board1!= NULL)
                 break;
             else{
                 printf("\nTemporary Board is not Allocated !!!\n");
                 return;     }
        }
	rewind(fp);
        for(i=0; i<rows; i++)
	      for(j=0; j<cols; j++)
              {
		     fscanf(fp,"%1d", &board[i][j]);
              }  
  }

  // This Function is used to Deallocate memory space of the board and board1 matrix.
  void free_Space()
  {
        for(int i=0; i<rows; i++)
		free(board1[i]);
	free(board1);

	for(int i=0; i<rows; i++)
		free(board[i]);
	free(board);
  }

  // This function is used to find number of alive neighbours for given cell and returns count.
  int find_neighbour(int r, int s)
  {
        int count=0;
        if ( (s+1)<cols && board1[r][s+1] ) 
	        count++;
        if ( (r+1)<rows && board1[r+1][s] ) 
	        count++;
	if ( (r+1)<rows && (s+1)<cols && board1[r+1][s+1] ) 
		count++;
	if ( (r-1)>=0 && (s-1)>=0 && board1[r-1][s-1])
		count++;
	if ( (s-1)>=0 && board1[r][s-1]) 
		count++;
	if ( (r-1)>=0 && board1[r-1][s] ) 
		count++;
	if ( (r+1)<rows && (s-1)>=0 && board1[r+1][s-1] ) 
		count++;
        if ( (r-1)>=0 && (s+1)<cols && board1[r-1][s+1] ) 
		count++;
        return count;
  }

   // This function is used to copy board matrix to board1 matrix.
   void copy(int** board, int** board1)
   {
      int i=0, j=0;
      for(i=0; i<rows; i++)
             for(j=0; j<cols; j++)
	            board1[i][j] = board[i][j];
   }

  // This function is used to find new generation using all four given conditions.
  void new_generation() 
  {
	int i=0, j=0;
        int count = 0;
        copy(board, board1);
        for(i=0; i < rows; i++) 
        {  
	    for(j = 0; j < cols; j++) 
	    {
                count = find_neighbour(i,j);	        
	        if(count < 2 && board1[i][j])  
		{   board[i][j]=0;    }
		if((count == 2 || count == 3) && board1[i][j]) 
			board[i][j]=1;
		if(count > 3 && board1[i][j])  
			board[i][j]=0;
		if(count == 3 && board1[i][j] == 0) 
			board[i][j]=1;
	    }
	}
  }

  // This function is used to print game board in both Screen and output File.
  void print_game(FILE *fp) 
  {
	  int i, j;
	  printf("\n");
	  fprintf(fp,"\n");
          for(i=0; i<rows; i++)
	  {
		  for(j=0; j<cols; j++)
		  {
	        	fprintf(fp,"%d ",board[i][j]);
                        printf("%d ",board[i][j]);
                  }
		  fprintf(fp,"\n");
		  printf("\n");
	  }
          fprintf(fp,"\n");
          printf("\n");
    }

   // This function is used to check whether given Generation is same as the previous Generation. If Same returns 1, otherwise returns 0.
   int checking_board()
   {
	int i=0, j=0;
	for(i=0; i<rows; i++)
		for(j=0; j<cols; j++)
			if(board[i][j]!= board1[i][j])   //   Comparing each elements in the board.
				return 0;
	return 1;
   }

  // This is the Main function which takes care of file handling both for input and output file. And It goes for 500 generations and outputs board matrix.
  void main()
  {
	FILE *fp; 
        FILE *fq;
  
        fp = fopen("Gameoflife input1", "r");      // Input file is opened in Read mode.
	if (fp != NULL)
		printf("File found....!\n");
        else 
	{
		printf("Input file is not found.....\n");
		return ;
        }
	int row_count= 0;
	char* number =malloc(sizeof(char)*1024);   // Allocating memory space for string which is used to get input from file.

        while(fscanf(fp,"%s", number)!=EOF)
		row_count++;
        int i=0, j=0;
	rows= row_count;
	cols= strlen(number);
	printf("%d %d", rows, cols);    // displays rows and cols in screen.
        fq = fopen("Gameoflifeoutput", "w");   //  Output file is opened in write mode.
        if (fq != NULL) 
	  {
            fprintf(fq,"\n\t\tOutput File of Game Of Life \n");
            printf("\n\t\tOutput File of Game Of Life \n");
        }
        else {
            printf("Failed to create a Writing file...\n");
            return ;
        }

        initialize(fp);
        fprintf(fq,"\n Given Input data of Game of Life : \n");
        printf("\n Given Input data of Game of Life : \n");
        print_game(fq);
        int generation =0;
	do
	{
		generation++;
		new_generation();
	}while(!checking_board() && generation < 500);

	if(generation >= 500)
		fprintf(fq,"\nExcedded generation. limit.\n");
	else{
		fprintf(fq,"\nAfter %d generation, The population is stable.\n",generation-1);
           printf("\nAfter %d generation, The population is stable.\n",generation-1);
          }
        print_game(fq);
        free_Space();
	fclose(fp);
	fclose(fq);
  }
 

