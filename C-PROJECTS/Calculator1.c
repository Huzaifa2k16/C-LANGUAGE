#include <stdio.h>
int main()
{
	float num1, num2, result;
	char op;
	
	printf("====== CALCULATOR ======\n");
	
	printf("Enter first number: ");
	scanf("%f", &num1);
	
	printf("Enter an operator (+,-,*,/): ");
	scanf(" %c", &op);
	
	printf("Enter second number: ");
	scanf("%f", &num2);
	
	switch(op)
	{
		case '+':
			result = num1 + num2;
			printf("\nResult %.3f\n", result);
			break;
			
		case '-':
			result = num1 - num2;
			printf("\nResult %.3f\n", result);
			break;
			
		case '*':
			result = num1 * num2;
			printf("\nResult %.3f\n", result);
			break;
			
		case '/':
			if(num2 != 0)
			{
			result = num1 / num2;
			printf("\nResult %.3f\n", result);
		    }
		    else{
		    	printf("\nError! Division by zero is not allowed. \n");
			    }
			    break;
			   
			default:
				printf("\nInvalid Operator.\n");		
	}
	return 0;
}
