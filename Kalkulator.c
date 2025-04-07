#include <stdio.h>
#include <math.h>

double calculations(float a, float b, char op)
{
    switch (op) {
        case '+':   return a + b;
        case '-':   return a - b;
        case '*':   return a * b;
        case '/':   return (b !=0) ? a / b : 0; //Obsluga dzielenia przez 0
        case '^':   return pow(a, b);
        case '%':   return (int)a % (int)b;     //Rzutowanie na int

        default:
        printf("\nZly operator, sprobuj ponownie\n");
        return NAN;         // Zwracam NaN jako sygnal bledu
    }
}

int main() {
    float a, b, result;
    char op;
    char choice;

    do {
        printf("\n-----Kalkulator-----\n");
        printf("\nWprowadz liczbe a: ");
        scanf(" %f", &a);

        // Petla do ponownego pytania o znak w przypadku bledu
        do {
            printf("Wprowadz znak dzialania (+,-,*,/,^,%%): "); 
            scanf(" %c", &op);
        } while ((op == '+' || op == '-' || op == '*' ||              // Powtarzaj pytanie, 
                  op == '/' || op == '^' || op == '%')                // jeśli wpisany jest
                  ? 0 : (printf("Bledny znak, sprobuj ponownie\n"), 1));// zly operator

        printf("Wprowadz liczbe b: "); 
        scanf(" %f", &b);

        result = calculations(a, b, op);
        printf("\n%.2f %c %.2f = %.02f\n", a, op, b, result);

        // Pytanie o kolejne oblczenie
        printf("\nCzy chcesz wykonac kolejne obliczenie? (T/N): ");
        while (getchar() != '\n');
        scanf(" %c", &choice);

    } while (choice == 'T' || choice == 't');

    printf("Koniec programu\n");
    
    return 0;
}