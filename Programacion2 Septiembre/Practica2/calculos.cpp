#include <iostream>
#include "calculos.hpp"
using namespace std;

// Pre:  n >= 0 ∧ 2 <= b <= 10
// Post: (n = 0 -> numCifras(n,b) = 1) ∧
//       (n > 0 -> numCifras(n,b) = NC ∧  n >= b^(NC-1) ∧ n < b^NC)
int numCifras(const int n, const int b) {
    if (n < 10) {
        return 1;
    }
    else {
        return 1 + numCifras(n / 10, b);
    }
}

// Pre:  n >= 0 ∧ i >= 1 ∧ 2 <= b <= 10
// Post: cifra(n,b,i) = (n / b^(i-1)) % b
int cifra(const int n, const int i, const int b) {
    if (i == 1) {
        return n % b;
    }
    else {
        return cifra(n / 10, i - 1, b);
    }
}

// Pre:  n >= 0 ∧ 2 <= b <= 10
// Post: cifraMayor(n,b) = (Max α∊[1,∞].cifra(n,α,b))
int cifraMayor(const int n, const int b) {
    int digitos;
    if (n < 10) {
        return n;
    }
    else {
        digitos = n % 10;
        int nuevoMayor = cifraMayor(n / 10, b);
        if (nuevoMayor > digitos) {
            digitos = nuevoMayor;
        }
        return digitos;
    }
}

// Pre:  n >= 0 ∧ 2 <= b <= 10
// Post: cifraMasSignificativa(n) = n / b^(NC-1)
//       ∧ (n >= b^(NC-1) ∧ n < b^NC)
int cifraMasSignificativa(const int n, const int b) {
    if (n <10) {
        return n;
    }
    else {
        return cifraMasSignificativa (n / 10, b);
    }
}


// Pre:  n >= 0 ∧ 2 <= b <= 10
// Post: sumaCifras(n,b) = (∑ α∊[1,∞].cifra(n,α,b))
int sumaCifras(const int n, const int b) {
    if (n < 10) {
        return n;
    }
    else {
        return (n % 10) + sumaCifras(n / 10, b);
    }
}