#include <stdlib.h>

char *sieve(long long upto) {
    int i, j;
    char *primes;
    primes = malloc(sizeof(char) * (upto + 1)); 

    primes[0] = 0;
    primes[1] = 0;

    for(i=2; i <= upto; i++) {
        primes[i] = 1;
    }

    for(i=2; (i * i) <= upto; i++) {
        if(primes[i]) {
            for(j=2; j <= (upto / i); j++) {
                primes[i * j] = 0;
            }
        }
    }

    return primes;
}
