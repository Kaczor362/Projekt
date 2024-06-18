#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *plik;
    char filename[100];
    char text[256]; //maksymalna wielkość chara to 256 bitów
    int choice;

    while (1) {
        printf("\nChoose:\n");
        printf("1. Save to file\n");
        printf("2. Read from the file\n");
        printf("3. End : )\n");
        scanf("%d", &choice);
        getchar();

        if (choice == 1) {
            printf("Enter filename: ");
            fgets(filename, sizeof(filename), stdin);
            filename[strcspn(filename, "\n")] = 0; // Usunięcie znaku nowej linii

            plik = fopen(filename, "w");
            if (plik == NULL) {
                perror("Error while trying to save");
                continue; // Powrót do menu
            }

            printf("Enter text (end with empty line):\n");
            while (fgets(text, sizeof(text), stdin) != NULL && text[0] != '\n') { //stdin odczyt z klawiatury 'n' to sprawdzenie czy nie jest to nowa linia (jesli tak to petla sie konczy)
                fputs(text, plik); //zapisz tekst do pliku plik
            }
            fclose(plik);
            printf("Saved to file: %s\n", filename);

        } else if (choice == 2) {
            printf("Enter file name: ");
            fgets(filename, sizeof(filename), stdin);
            filename[strcspn(filename, "\n")] = 0; // Usunięcie znaku nowej linii

            plik = fopen(filename, "r");
            if (plik == NULL) {
                perror("No such file.");
                continue; // Powrót do menu
            }

            printf("\nContent:\n");
            while (fgets(text, sizeof(text), plik) != NULL) {
                printf("%s", text);
            }
            fclose(plik);

        } else if (choice == 3) {
            break; // Zakończenie programu
        } else {
            printf("Wrong option\n");
        }
    }
    return 0;
}
