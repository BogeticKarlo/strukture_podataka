#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct osoba Osoba;

struct osoba {

    char ime[20];
    char prezime[20];
    int god_rod;
    Osoba* next;

};

int UnosP(Osoba* p) {

    Osoba* q = (Osoba*)malloc(sizeof(Osoba));
    printf("Unos: ime prezime god_rod: ");
    scanf("%s %s %d", q->ime, q->prezime, &q->god_rod);

    if (p->next != NULL) {

        q->next = p->next;
        p->next = q;

    }

    else {

        p->next = q;
        q->next = NULL;

    }

    return 1;
}

int ispis(Osoba* p) {

    while (p->next != NULL) {

        printf("%s %s %d\n", p->ime, p->prezime, p->god_rod);

        p = p->next;

    }

    printf("%s %s %d\n", p->ime, p->prezime, p->god_rod);

    return 1;
}

int UnosK(Osoba* p) {

    while (p->next != NULL) {

        p = p->next;

    }

    Osoba* q = (Osoba*)malloc(sizeof(Osoba));

    printf("Unos: ime prezime god_rod: ");
    scanf("%s %s %d", q->ime, q->prezime, &q->god_rod);

    p->next = q;
    q->next = NULL;


    return 1;
}



int main() {

    Osoba* head = (Osoba*)malloc(sizeof(Osoba));
    head->next = NULL;

    UnosP(head);
    UnosP(head);
    UnosK(head);

    ispis(head->next);


    return 1;
}