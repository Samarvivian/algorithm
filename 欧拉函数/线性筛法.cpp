#include <iostream>
#include <vector>

std::vector<int> euler_totient_sieve(int n) {
    std::vector<int> phi(n + 1);  // Initialize phi vector with size n+1

    // Initialize phi[i] = i
    for (int i = 0; i <= n; ++i) {
        phi[i] = i;
    }

    // Apply sieve to compute Euler's Totient function
    for (int p = 2; p <= n; ++p) {
        if (phi[p] == p) {  // p is a prime
            for (int multiple = p; multiple <= n; multiple += p) {
                phi[multiple] -= phi[multiple] / p;
            }
        }
    }

    return phi;
}

int main() {
    int n = 20;  // Example input
    std::vector<int> phi = euler_totient_sieve(n);

    // Print the results
    std::cout << "Euler's Totient function values from 1 to " << n << ":\n";
    for (int i = 1; i <= n; ++i) {
        std::cout << "phi(" << i << ") = " << phi[i] << "\n";
    }

    return 0;
}