
#include <stdio.h>
#define COUNT 18

float types[COUNT][COUNT] = {
    {1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 0.5, 0, 1, 1, 0.5, 1},
    {1, 0.5, 0.5, 1, 2, 2, 1, 1, 1, 1, 1, 2, 0.5, 1, 0.5, 1, 2, 1},
    {1, 2, 0.5, 1, 0.5, 1, 1, 1, 2, 1, 1, 1, 2, 1, 0.5, 1, 1, 1},
    {1, 1, 2, 0.5, 0.5, 1, 1, 1, 0, 2, 1, 1, 1, 1, 0.5, 1, 1, 1},
    {1, 0.5, 2, 1, 0.5, 1, 1, 0.5, 2, 0.5, 1, 0.5, 2, 1, 0.5, 1, 0.5, 1},
    {1, 0.5, 0.5, 1, 2, 0.5, 1, 1, 2, 2, 1, 1, 1, 1, 2, 1, 0.5, 1},
    {2, 1, 1, 1, 1, 2, 1, 0.5, 1, 0.5, 0.5, 0.5, 2, 0, 1, 2, 2, 0.5},
    {1, 1, 1, 1, 2, 1, 1, 0.5, 0.5, 1, 1, 1, 0.5, 0.5, 1, 1, 0, 2},
    {1, 2, 1, 2, 0.5, 1, 1, 2, 1, 0, 1, 0.5, 2, 1, 1, 1, 2, 1},
    {1, 1, 1, 0.5, 2, 1, 2, 1, 1, 1, 1, 2, 0.5, 1, 1, 1, 0.5, 1},
    {1, 1, 1, 1, 1, 1, 2, 2, 1, 1, 0.5, 1, 1, 1, 1, 0, 0.5, 1},
    {1, 0.5, 1, 1, 2, 1, 0.5, 0.5, 1, 0.5, 2, 1, 1, 0.5, 1, 2, 0.5, 0.5},
    {1, 2, 1, 1, 1, 2, 0.5, 1, 0.5, 2, 1, 2, 1, 1, 1, 1, 0.5, 1},
    {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 0.5, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 0.5, 0},
    {1, 1, 1, 1, 1, 1, 0.5, 1, 1, 1, 2, 2, 1, 2, 1, 0.5, 1, 0.5},
    {1, 0.5, 0.5, 0.5, 1, 2, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 0.5, 2},
    {1, 0.5, 1, 1, 1, 1, 2, 0.5, 1, 1, 1, 1, 1, 1, 2, 2, 0.5, 1}
};

typedef enum TYPES {
        NOR, FIR, WAT, 
        ELE, GRA, ICE, 
        FIG, POI, GRO, 
        FLY, PSY, BUG, 
        ROC, GHO, DRA, 
        DAR, STE, FAI
} type_t;

char* type_str(type_t t) {
    switch (t) {
        case NOR: return "normal";
        case FIR: return "fire";
        case WAT: return "water";
        case ELE: return "electric";
        case GRA: return "grass";
        case ICE: return "ice";
        case FIG: return "fighting";
        case POI: return "poison";
        case GRO: return "ground";
        case FLY: return "flying";
        case PSY: return "psychic";
        case BUG: return "bug";
        case ROC: return "rock";
        case GHO: return "ghost";
        case DRA: return "dragon";
        case DAR: return "dark";
        case STE: return "steel";
        case FAI: return "fairy";
        default: return "missing";
    }
}

char to_char(float f) {
    if (f == 0)   return '0';
    if (f == 0.5) return 'h';
    if (f == 1)   return '1';
    if (f == 2)   return '2';
    return '?';
}

int main() {
    printf("               ");
    for (size_t i = 0; i < COUNT; i++) {
        printf("%4d", i);
    }
    printf("\n");
    for (size_t i = 0; i < COUNT; i++) {
        printf("%9s (%2d) ", type_str(i), i);
        for (size_t j = 0; j < COUNT; j++) {
            printf("%4c", to_char(types[i][j]));
        }
        printf("\n");
    }
    return 0;
}

