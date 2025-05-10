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

long long int factorial(float a) {
    if ((int)a < 0 || (int)a > 20) 
    {
        printf("Liczba niezdefiniowana lub wieksza od 20!\n");
        return 1;
    } else {
        long long int fact = 1;
        for (int i = 1; i <= (int)a; i++) 
        {
            fact *= i;
        }
        return fact;
    }
}

int main() {
    float a, b, result;
    long long int fact_result;
    char op;
    char choice;

    do {
        printf("\n-----Kalkulator-----\n");
        
        do {
            printf("\nWprowadz liczbe a: ");
            if (scanf(" %f", &a) != 1)          // Jezeli nie zostala wprowadzona zmienna float
            {
                printf("To nie liczba");
                while (getchar () != '\n'); // Czysci bufor wejsciowy
            } else break;   // Znak sie zgadza, wyjscie z petli
                
        } while (1);

        // Petla do ponownego pytania o znak w przypadku bledu
        do {
            printf("Wprowadz znak dzialania (+, -, *, /, ^, %%, !): "); 
            scanf(" %c", &op);
        } while ((op == '+' || op == '-' || op == '*' ||              // Powtarzaj pytanie, 
                  op == '/' || op == '^' || op == '%' || op == '!')   // jeśli wpisany jest
                  ? 0 : (printf("Bledny znak, sprobuj ponownie\n"), 1));// zly operator

        
        if (op == '!') 
        {
            if (a > 20)
            {
                printf("Wprowadzenie liczby wiekszej od 20 spowoduje przepelnienie");
                return 1;
            } else {
                b = 0;
            }
        }
        else {
            do{
                printf("Wprowadz liczbe b: "); 
                if (scanf(" %f", &b) != 1)          // Jezeli nie zostala wprowadzona zmienna float
                {
                    printf("To nie liczba");
                    while (getchar () != '\n'); // Czysci bufor wejsciowy
                } else break;   // Znak sie zgadza, wyjscie z petli
            } while(1);
        } 

        if (op == '!') 
        {
            fact_result = factorial(a);
            printf("\n%.0f%c = %lld\n", a, op, fact_result);
        } else {
            result = calculations(a, b, op);
            printf("\n%.2f %c %.2f = %.02f\n", a, op, b, result);
        }

        // Pytanie o kolejne oblczenie
        printf("\nCzy chcesz wykonac kolejne obliczenie? (T/N): ");
        while (getchar() != '\n');
        scanf(" %c", &choice);

    } while (choice == 'T' || choice == 't');

    printf("Koniec programu\n");
    
    return 0;
}
