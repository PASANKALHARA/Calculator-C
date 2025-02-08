#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Function declarations
void display_menu();
double perform_operation(char operation, double num1, double num2);
double factorial(double n);

// Main function
int main() {
    char operation;
    double num1, num2, result;
    int keep_running = 1;

    printf("Scientific Calculator in C\n");
    printf("===========================\n");

    while (keep_running) {
        display_menu();

        printf("\nEnter your operation: ");
        scanf(" %c", &operation);

        if (operation == 'q') {
            keep_running = 0;
            printf("Exiting the calculator. Goodbye!\n");
            break;
        }

        if (operation == 'n' || operation == 's' || operation == 'c' || operation == 't' || 
            operation == 'l' || operation == 'L' || operation == 'r' || operation == 'd') {
            printf("Enter a number: ");
            scanf("%lf", &num1);
            result = perform_operation(operation, num1, 0);
        } else if (operation == '+' || operation == '-' || operation == '*' || 
                   operation == '/' || operation == '^' || operation == 'm') {
            printf("Enter first number: ");
            scanf("%lf", &num1);
            printf("Enter second number: ");
            scanf("%lf", &num2);
            result = perform_operation(operation, num1, num2);
        } else {
            printf("Invalid operation! Please try again.\n");
            continue;
        }

        printf("Result: %.10lf\n", result);
    }

    return 0;
}

// Function definitions
void display_menu() {
    printf("\nAvailable Operations:");
    printf("\n+ : Addition");
    printf("\n- : Subtraction");
    printf("\n* : Multiplication");
    printf("\n/ : Division");
    printf("\n^ : Power");
    printf("\nm : Modulus");
    printf("\ns : Sine");
    printf("\nc : Cosine");
    printf("\nt : Tangent");
    printf("\nl : Logarithm (base 10)");
    printf("\nL : Natural Logarithm");
    printf("\nr : Square Root");
    printf("\nd : Degrees to Radians");
    printf("\nn : Factorial");
    printf("\nq : Quit");
    printf("\n===========================\n");
}

double perform_operation(char operation, double num1, double num2) {
    switch (operation) {
        case '+': return num1 + num2;
        case '-': return num1 - num2;
        case '*': return num1 * num2;
        case '/': 
            if (num2 != 0) return num1 / num2;
            printf("Error: Division by zero!\n");
            exit(EXIT_FAILURE);
        case '^': return pow(num1, num2);
        case 'm': return fmod(num1, num2);
        case 's': return sin(num1);
        case 'c': return cos(num1);
        case 't': return tan(num1);
        case 'l': 
            if (num1 > 0) return log10(num1);
            printf("Error: Logarithm of non-positive number!\n");
            exit(EXIT_FAILURE);
        case 'L': 
            if (num1 > 0) return log(num1);
            printf("Error: Logarithm of non-positive number!\n");
            exit(EXIT_FAILURE);
        case 'r': 
            if (num1 >= 0) return sqrt(num1);
            printf("Error: Square root of negative number!\n");
            exit(EXIT_FAILURE);
        case 'd': return num1 * M_PI / 180.0;
        case 'n': 
            if (num1 >= 0) return factorial(num1);
            printf("Error: Factorial of negative number!\n");
            exit(EXIT_FAILURE);
        default: 
            printf("Error: Invalid operation!\n");
            exit(EXIT_FAILURE);
    }
}

double factorial(double n) {
    if (n == 0 || n == 1) return 1;
    return n * factorial(n - 1);
}
