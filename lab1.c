#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CARS 10

struct Car {
    char brand[50];
    char model[50];
    float pret;
};

void adauga_masina(struct Car masini[MAX_CARS], int *nr_masini) {
    if (*nr_masini >= MAX_CARS) {
        printf("Stocul este plin.\n");
        return;
    }

    printf("Introduceti marca masinii: ");
    scanf("%s", masini[*nr_masini].brand);
    printf("Introduceti modelul masinii: ");
    scanf("%s", masini[*nr_masini].model);
    printf("Introduceti pretul masinii: ");
    scanf("%f", &masini[*nr_masini].pret);

    (*nr_masini)++;
}

void afiseaza_masinile(struct Car masini[MAX_CARS], int nr_masini) {
    if (nr_masini == 0) {
        printf("Stocul este gol.\n");
        return;
    }

    printf("Masinile din stoc:\n");
    printf("Marca\tModel\tPret\n");
    for (int i = 0; i < nr_masini; ++i) {
        printf("%s\t%s\t%.2f\n", masini[i].brand, masini[i].model, masini[i].pret);
    }
}

int main() {
    struct Car masini[MAX_CARS];
    int nr_masini = 0;
    int optiune;

    do {
        printf("\n--== Meniu Principal ==--\n");
        printf("1. Adauga masina in stoc\n");
        printf("2. Afiseaza masinile din stoc\n");
        printf("3. Iesire\n");
        printf("Optiunea dumneavoastra: ");
        scanf("%d", &optiune);

        switch (optiune) {
            case 1:
                adauga_masina(masini, &nr_masini);
                break;
            case 2:
                afiseaza_masinile(masini, nr_masini);
                break;
            case 3:
                printf("Meniul se inchide.\n");
                break;
            default:
                printf("Optiune invalida. Va rugam sa alegeti din nou.\n");
        }
    } while (optiune != 3);

    return 0;
}
