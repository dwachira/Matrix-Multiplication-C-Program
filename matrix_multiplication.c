
 /*************************************************************************
 *                   Mureithi David Wachira                               *
 *                   P15/2204/2011                                        *
 *                                                                        *
 *                   University of Nairobi                                *
 *                   School of Computing & Informatics                    *
 *                                                                        *
 *                   Date: Thursday 28th February 2013                    *
 *                                                                        *
 *                   An exercise on matrix multiplication		          *
 *                                                                        *
 *************************************************************************/

#include <stdio.h>

/*  In order to multiply matrices,

    Step 1: Make sure that the the number of columns in the 1st one equals the number of rows in the 2nd one. (The pre-requisite to be able to multiply)
    Step 2: Multiply the elements of each row of the first matrix by the elements of each column in the second matrix.
    Step 3: Add the products.
*/

   //Variable declaration and initialization
  int first_matrix_rows, first_matrix_columns;
  int second_matrix_rows, second_matrix_columns;
  int matrix_rows_counter, matrix_columns_counter;
  int matrix_calculation_counter;
  int matrix_calculation_holder = 0;
  int first_matrix_array[20][20];
  int second_matrix_array[20][20];
  int product_matrix_array[20][20];

int main(void)//Main method
{

  //Just a brief title of the exercise showing my name, registration number, school, date, and the exercise
  printf(" /*************************************************************************\n *                   Mureithi David Wachira                               *\n *                   P15/2204/2011                                        *\n *                                                                        *\n *                   University of Nairobi                                *\n *                   School of Computing & Informatics                    *\n *                                                                        *\n *                   Date: Thursday 28th February 2013                    *\n *                                                                        *\n *                   An exercise on matrix multiplication		  *\n *                                                                        *\n *************************************************************************/\n");

  //Prompt user to enter the rows of the first matrix and its capture and storage
  printf("Please enter the number of rows of the first matrix\n");
  scanf("%d", &first_matrix_rows);

  //Prompt user to enter the columns of the first matrix and its capture and storage
  printf("Please enter the number of columns of the first matrix\n");
  scanf("%d", &first_matrix_columns);

  //Prompt user to enter the elements of the first matrix
  printf("Enter the elements of the first matrix\n");

  //Capture and storage of the elements of the first matrix through and array called first_matrix_array[][]
  for (matrix_rows_counter = 0 ; matrix_rows_counter < first_matrix_rows ; matrix_rows_counter++ )
    {  for ( matrix_columns_counter = 0 ; matrix_columns_counter < first_matrix_columns ; matrix_columns_counter++ )
         {
          scanf("%d", &first_matrix_array[matrix_rows_counter][matrix_columns_counter]);
         }
    }

  //Prompt user to enter the rows of the second matrix and its capture and storage
  printf("Enter the number of rows of second matrix\n");
  scanf("%d", &second_matrix_rows);

  //Prompt user to enter the columns of the second matrix and its capture and storage
  printf("Enter the number of columns of second matrix\n");
  scanf("%d", &second_matrix_rows, &second_matrix_columns);

  //Test the prerequisite for matrix multiplication. Make sure that the the number of columns in the 1st one equals the number of rows in the 2nd one.
  if ( first_matrix_columns != second_matrix_rows )
    printf("Matrix 1 and 2 cannot be multiplied together because the number of columns in 1 does not equal the number of rows in 2. In this case, the multiplication of these two matrices is not defined. \n");
  else
  {
    //Prompt user to enter the elements of the second matrix
    printf("Enter the elements of second matrix\n");

    //Capture and storage of the elements of the second matrix through and array called first_matrix_array[][]
    for ( matrix_rows_counter = 0 ; matrix_rows_counter < second_matrix_rows ; matrix_rows_counter++ )
      for ( matrix_columns_counter = 0 ; matrix_columns_counter < second_matrix_columns ; matrix_columns_counter++ )
        scanf("%d", &second_matrix_array[matrix_rows_counter][matrix_columns_counter]);

    //Multiply the elements of the matrix, row by column, one after the other and storage into a third matrix known as product_matrix_array[][]
    for ( matrix_rows_counter = 0 ; matrix_rows_counter < first_matrix_rows ; matrix_rows_counter++ )
    {
      for ( matrix_columns_counter = 0 ; matrix_columns_counter < second_matrix_columns ; matrix_columns_counter++ )
      {
        for ( matrix_calculation_counter = 0 ; matrix_calculation_counter< second_matrix_rows ; matrix_calculation_counter++ )
        {
          matrix_calculation_holder = matrix_calculation_holder + first_matrix_array[matrix_rows_counter][matrix_calculation_counter]*second_matrix_array[matrix_calculation_counter][matrix_columns_counter];
        }

        product_matrix_array[matrix_rows_counter][matrix_columns_counter] = matrix_calculation_holder;
        matrix_calculation_holder = 0;
      }
    }

    //A simple output segment preceeding the product of the multiplication
    printf("The product of the matrix multiplication is:\n");

    //Display of the elements of the third array named product_matrix_array[][]
    for ( matrix_rows_counter = 0 ; matrix_rows_counter < first_matrix_rows ; matrix_rows_counter++ )
    {
      for ( matrix_columns_counter = 0 ; matrix_columns_counter < second_matrix_columns ; matrix_columns_counter++ )
        printf("%d\t", product_matrix_array[matrix_rows_counter][matrix_columns_counter]);

      printf("\n");
    }
  }

  return 0;
}

