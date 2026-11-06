#include <stdio.h>
#include <stdlib.h>

struct Term {
    float coeff;
    int exp;
};

void displayPolynomial(struct Term *p, int n) {
    for (int i = 0; i < n; i++) {
        if (i > 0 && p[i].coeff >= 0) printf(" + ");
        else if (p[i].coeff < 0) printf(" ");
        printf("%.1fx^%d", p[i].coeff, p[i].exp);
    }
    printf("\n");
}

void addPolynomial(struct Term *p1, int n1, struct Term *p2, int n2) {
    struct Term *res = (struct Term *)malloc((n1 + n2) * sizeof(struct Term));
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2) {
        if (p1[i].exp > p2[j].exp) res[k++] = p1[i++];
        else if (p1[i].exp < p2[j].exp) res[k++] = p2[j++];
        else {
            res[k].exp = p1[i].exp;
            res[k++].coeff = p1[i++].coeff + p2[j++].coeff;
        }
    }
    while (i < n1) res[k++] = p1[i++];
    while (j < n2) res[k++] = p2[j++];
    printf("Addition: ");
    displayPolynomial(res, k);
    free(res);
}

void multiplyPolynomial(struct Term *p1, int n1, struct Term *p2, int n2) {
    struct Term *res = (struct Term *)calloc(n1 * n2, sizeof(struct Term));
    int k = 0;
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            float c = p1[i].coeff * p2[j].coeff;
            int e = p1[i].exp + p2[j].exp, found = 0;
            for (int m = 0; m < k; m++) {
                if (res[m].exp == e) { res[m].coeff += c; found = 1; break; }
            }
            if (!found) { res[k].coeff = c; res[k++].exp = e; }
        }
    }
    printf("Multiplication: ");
    displayPolynomial(res, k);
    free(res);
}

int main() {
    int n1 = 4, n2 = 3;
    struct Term *P = (struct Term *)malloc(n1 * sizeof(struct Term));
    struct Term *Q = (struct Term *)malloc(n2 * sizeof(struct Term));

    P[0].coeff = 5.5; P[0].exp = 3; P[1].coeff = 3.2; P[1].exp = 2; P[2].coeff = -4.5; P[2].exp = 1; P[3].coeff = 7.8; P[3].exp = 0;
    Q[0].coeff = 2.5; Q[0].exp = 2; Q[1].coeff = -6.0; Q[1].exp = 1; Q[2].coeff = -3.5; Q[2].exp = 0;

    printf("P(x) = "); displayPolynomial(P, n1);
    printf("Q(x) = "); displayPolynomial(Q, n2);
    
    addPolynomial(P, n1, Q, n2);
    multiplyPolynomial(P, n1, Q, n2);
    free(P); free(Q);
    return 0;
}