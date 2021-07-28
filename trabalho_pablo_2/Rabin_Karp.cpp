#include "Rabin_Karp.h"

#define ll long long

const int maxn = 1e6 * 7 + 10;

const ll m = 1e9 + 7;

const ll base = 157;

// tem precomputado as potências de 131
ll power[maxn];

// tem precomputado os hash dos prefixos do texto
ll prefix_hash[maxn];

// memoriza as potências pra usar em O(1)
void precompute_power(int n) {
    power[0] = 1;
    for(int i = 1; i < n; i++) {
        power[i] = power[i-1] * base % m;
    }
}

void init(const char* S) {
    int len = strlen(S);
    static int start;

    // só calcula as potencias uma única vez
    if(start == 0) {
        precompute_power(len), start = 1;
    }

    prefix_hash[0] = S[0];

    // memoria via recorrência o hash dos prefixos do texto.
    // com isso é possível comparar qualquer substring do texto, de tamanho pattern_len,
    // com o padrãoe O(1)
    for(int i = 1; i < len; i++) {
        prefix_hash[i] = (prefix_hash[i-1] + S[i] * power[i]) % m;
    }
}

void Rabin_Karp(const char* P, const char* S, int* o, int type) {
    int pattern_len = strlen(P);
    int text_len    = strlen(S);

    ll hash_pattern = 0;

    // esse trecho do código é uma adaptação
    // aos requesitos do trabalho
    if(type == 1) {
        // calcula o hash do texto uma única vez, pro
        // caso onde os casos reais estejam sendo calculados
        static int start;
        if(start == 0) {
            init(S), start = 1;
        }
    } else {
        // sempre calcula o hash do texto, pro caso
        // onde os casos aleatórios estão sendo calculados
        init(S);
    }

    // calcula o hash do padrão, pra comparar posteriormente.
    for(int i = 0; i < pattern_len; i++) {
        hash_pattern = (hash_pattern + P[i] * power[i]) % m;
    }

    int idx = 0;

    if(prefix_hash[pattern_len-1] == hash_pattern) {
        o[idx] = 0;
        idx++;
    }

    //compara as janelas/substrings de tamanho pattern_len
    for(int i = 1; i < text_len - pattern_len+1; i++) {
        ll hs = (prefix_hash[i+pattern_len-1]-prefix_hash[i-1]+m)%m;
        if((hash_pattern*power[i])%m == hs) {
            o[idx] = i;
            idx++;
        }
    }

    o[idx] = -1;
}