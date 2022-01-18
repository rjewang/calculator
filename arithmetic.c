#include <stdio.h>
#include <ctype.h>

//main function: special calculator                                             
int main() {

  char operator; //store operator input                                         
  float number; //store number input                                            
  float ans; //temporary answer holder                                          


  printf("Please enter an arithmetic expression using * and / only: \n");

  //a valid input should start with a number,                                   
  //and then an opeartor(either * or /) and a number,                           
  //and follow the same pattern (operator, then number).                        
  //read in the first number input, and store in the answer variable            
  //if there is no input at all, report malformed error message                 
  if (scanf("%f", &number) == -1) {
    printf("malformed expression\n");
    return 1;
  }
  else {
    ans = number;
  }
  //use scanf to read in the operator / number input                            
  //a valid opeartor input should be a char type                                
  //a valid number input should be a float type                                 
  //use inputcount to keep track of valid inputs                                
  //inputcount should return 2 when inputs are valid                            
  int inputcount = scanf(" %c %f", &operator, &number);

  //run the calculator when there is input                                      
  while (inputcount != -1) {

    //if inputs are valid    
    if (inputcount  == 2) {

      //switch cases for operator * and /                                       
      switch(operator) {
      case '*':
        ans = ans * number;
        break;
      case '/':
        if (number == 0) {
          //report zero-division error message                                  
          printf("division by zero\n");
          return 2;
        }
        else {
          ans = ans / number;
        }
        break;

      default://all other operators are not valid in this program               
        printf("malformed expression\n");
        return 1;
      }
      else {
      //report malformed error message when input is not valid                  
      printf("malformed expression\n");
      return 1;
    }

    //read in the next group of operator and number, if any                     
    inputcount = scanf(" %c %f", &operator, &number);
  }

  //output the answer                                                           
  printf("%f\n", ans);

  return 0;
}
