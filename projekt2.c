#include <stdio.h>
#include <math.h>

void rozwiazania(float a, float b, float c);

int main() {
    float a, b, c, x;

    printf("a*x^2 + b*x + c = 0\n\n");

    printf("a = ");
    if (scanf_s("%f", &a) == 1) { //jezeli a nie bedzie liczba program sie zakonczy
        printf("b = ");
        if (scanf_s("%f", &b) == 1) {
            printf("c = ");
            scanf_s("%f", &c);
            if (scanf_s("%f", &c) == 1) {
                if (a != 0) { //co je¿eli a bêdzie ró¿ne od 0
                    rozwiazania(a, b, c);
                }
                else {
                    if (b != 0) { //co je¿eli a=0 ale b!=0
                        if (c == 0) x = 0; //dodatkowy if bo bez tego x = -0.0000
                        else x = -1 * c / b;
                        printf("\nx = %f", x);
                    }
                    else { //co gdy a=0 i b=0
                        if (c == 0) printf("\nx jest dowolna liczba rzeczywista");
                        else printf("\nx nalezy do zbioru pustego");
                    }
                }
            }
            else printf("Dozwolone sa tylko liczby!");
           
        }
        else printf("Dozwolone sa tylko liczby!");
    }
        
    else printf("Dozwolone sa tylko liczby!");

}

void rozwiazania(float a, float b, float c) {
    float delta = b * b - 4 * a * c;

    if (delta > 0) {

        float x1 = (-b + sqrt(delta)) / (2 * a);
        float x2 = (-b - sqrt(delta)) / (2 * a);
        printf("\nx1 = %f, x2 = %f", x1, x2);
    }
    else if (delta == 0) {
        float x = -b / (2 * a);
        printf("\nx = %f", x);
    }
    else {
        printf("\nx nalezy do zbioru pustego");
    }
}