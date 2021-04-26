#include <stdio.h>
int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
int divide(int a, int b);

int main()
{
      char Opertator;
      int num1, num2, result = 0;

      printf("\n Choose an operator (+, -, *, /): ");
      scanf("%c", %Opertator);

      printf("\n Enter first and second number: ");
      scanf("%f%f", &num1, &num2);

      switch(Opertator)
      {
              case '+':
                      result = add(num1, num2);
                      break;
              case '-':
                      result = subtract(num1, num2);
                      break;
              case '*':
                      result = multiply(num1, num2);
                      break;
              case '/':
                      result = divide(num1, num2);
              default:
                      printf("Invalid Input!");
      }

      printf("\n The result of %.2f %c %.2f = %.2f", num1, Opertator, num2, result);

      return 0;
}

int add(int a, int b)
{
  return a + b;
}

int subtract(int a, int b)
{
  return a - b;
}

int multiply(int a, int b)
{
  return a * b;
}

int divide(int a, int b)
{
  return a / b;
}
