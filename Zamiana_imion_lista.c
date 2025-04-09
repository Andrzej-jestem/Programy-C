#include <stdio.h>
#include <string.h>

void startView(char list[5][20], int size)
{
    char name[20];
    int found = 0;

    printf("---Lista osob--- \n");

    for(int i = 0; i < size; i++)
        {
           printf("%s\n", list[i]);  
        }

    do {
        printf("Ktore imie chcesz zmienic?: ");
        scanf(" %s", name);

        for(int i = 0; i < size; i++)
        {
            if(strcmp(name, list[i]) == 0)
            {
                char newName[20];
                printf("Podaj nowe imie dla %s: ", list[i]);
                scanf(" %s", newName);

                strcpy(list[i], newName);

                printf("\nAktualna lista:\n");
                for(int j = 0; j < size; j++)
                {
                    printf("%s\n", list[j]);  
                }

                found = 1;
                break;
            } 
        }

        if(!found)
        { 
            printf("Nie ma takiego imienia na liscie\n");
        }
        
    } while (!found);   // Powtarzaj dopoki nie znajdziesz imienia

}

int main() 
{
    char list[5][20] = {"Andrzej", "Anna", "Maksymilian", "Tomasz", "Mateusz"};
    int size = sizeof(list) / sizeof(list[0]);

    startView(list, size);


    return 0;
}