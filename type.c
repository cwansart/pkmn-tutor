#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BUF_SIZ 1024

#define TYPE_COUNT 18
typedef enum TYPES {
        NOR, FIR, WAT, 
        ELE, GRA, ICE, 
        FIG, POI, GRO, 
        FLY, PSY, BUG, 
        ROC, GHO, DRA, 
        DAR, STE, FAI
} type_t;

// matrix contains strengths and weaknesses of each type
// each line represents one of the types defined in enum TYPES
float type_chart[TYPE_COUNT][TYPE_COUNT] = {
    //NOR   FIR   WAT   ELE   GRA   ICE   FIG   POI   GRO   FLY   PSY   BUG   ROC   GHO   DRA   DAR   STE   FAI 
    { 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 2.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.5f, 0.0f, 1.0f, 1.0f, 0.5f, 1.0f },
    { 1.0f, 0.5f, 0.5f, 1.0f, 2.0f, 2.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 2.0f, 0.5f, 1.0f, 0.5f, 1.0f, 2.0f, 1.0f },
    { 1.0f, 2.0f, 0.5f, 1.0f, 0.5f, 1.0f, 1.0f, 1.0f, 2.0f, 1.0f, 1.0f, 1.0f, 2.0f, 1.0f, 0.5f, 1.0f, 1.0f, 1.0f },
    { 1.0f, 1.0f, 2.0f, 0.5f, 0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 2.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.5f, 1.0f, 1.0f, 1.0f },
    { 1.0f, 0.5f, 2.0f, 1.0f, 0.5f, 1.0f, 1.0f, 0.5f, 2.0f, 0.5f, 1.0f, 0.5f, 2.0f, 1.0f, 0.5f, 1.0f, 0.5f, 1.0f },
    { 1.0f, 0.5f, 0.5f, 1.0f, 2.0f, 0.5f, 1.0f, 1.0f, 2.0f, 2.0f, 1.0f, 1.0f, 1.0f, 1.0f, 2.0f, 1.0f, 0.5f, 1.0f },
    { 2.0f, 1.0f, 1.0f, 1.0f, 1.0f, 2.0f, 1.0f, 0.5f, 1.0f, 0.5f, 0.5f, 0.5f, 2.0f, 0.0f, 1.0f, 2.0f, 2.0f, 0.5f },
    { 1.0f, 1.0f, 1.0f, 1.0f, 2.0f, 1.0f, 1.0f, 0.5f, 0.5f, 1.0f, 1.0f, 1.0f, 0.5f, 0.5f, 1.0f, 1.0f, 0.0f, 2.0f },
    { 1.0f, 2.0f, 1.0f, 2.0f, 0.5f, 1.0f, 1.0f, 2.0f, 1.0f, 0.0f, 1.0f, 0.5f, 2.0f, 1.0f, 1.0f, 1.0f, 2.0f, 1.0f },
    { 1.0f, 1.0f, 1.0f, 0.5f, 2.0f, 1.0f, 2.0f, 1.0f, 1.0f, 1.0f, 1.0f, 2.0f, 0.5f, 1.0f, 1.0f, 1.0f, 0.5f, 1.0f },
    { 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 2.0f, 2.0f, 1.0f, 1.0f, 0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.5f, 1.0f },
    { 1.0f, 0.5f, 1.0f, 1.0f, 2.0f, 1.0f, 0.5f, 0.5f, 1.0f, 0.5f, 2.0f, 1.0f, 1.0f, 0.5f, 1.0f, 2.0f, 0.5f, 0.5f },
    { 1.0f, 2.0f, 1.0f, 1.0f, 1.0f, 2.0f, 0.5f, 1.0f, 0.5f, 2.0f, 1.0f, 2.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.5f, 1.0f },
    { 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 2.0f, 1.0f, 1.0f, 2.0f, 1.0f, 0.5f, 1.0f, 1.0f },
    { 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 2.0f, 1.0f, 0.5f, 0.0f },
    { 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.5f, 1.0f, 1.0f, 1.0f, 2.0f, 2.0f, 1.0f, 2.0f, 1.0f, 0.5f, 1.0f, 0.5f },
    { 1.0f, 0.5f, 0.5f, 0.5f, 1.0f, 2.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 2.0f, 1.0f, 1.0f, 1.0f, 0.5f, 2.0f },
    { 1.0f, 0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 2.0f, 0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 2.0f, 2.0f, 0.5f, 1.0f },
};

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

float to_float(char c) {
    if (c == '0') return 0;
    if (c == 'h') return 0.5;
    if (c == '1') return 1;
    if (c == '2') return 2;
    return -1;
}

char to_char(float f) {
    if (f == 0)   return '0';
    if (f == 0.5) return 'h';
    if (f == 1)   return '1';
    if (f == 2)   return '2';
    return '?';
}

int main() {
    unsigned int success  = 0,
                 failure  = 0,
                 attempts = 0;
    char buf[BUF_SIZ];

    srand(time(NULL));

    printf("Type Tutor\n");
    printf("Gen 6\n\n");

    printf("Type:\n");
    printf("0 for no effect\n");
    printf("h for not effective\n");
    printf("1 for normal\n");
    printf("2 for super effective\n");
    printf("exit to end program\n\n");

    printf("What is the relation from type to another type?\n");

    while (1) {
        attempts++;
        type_t t1 = rand() % TYPE_COUNT,
               t2 = rand() % TYPE_COUNT;
        printf("%9s to %9s: ", type_str(t1), type_str(t2));

        if (fgets(buf, BUF_SIZ, stdin) == NULL) {
            break;
        }

        buf[BUF_SIZ-1] = '\0';
        if (buf[strnlen(buf, BUF_SIZ) -1] == '\n') {
            buf[strnlen(buf, BUF_SIZ) -1] = '\0';
        }

        if (strnlen(buf, BUF_SIZ) < 1) {
            printf("invalid input, must not be empty\n");
            continue;
        }

        if (strncmp(buf, "exit", BUF_SIZ) == 0) {
            break;
        }

        float multiplier = to_float(buf[0]);
        float correct_answer = type_chart[t1][t2];
        if (multiplier == correct_answer) {
            success++;
            printf(" CORRECT\n");
        } else {
            failure++;
            printf(" WRONG, correct answer: %c\n", to_char(correct_answer));
        }
    }

    printf("\nResults:\n");
    printf("Attempts: %d\n", attempts);
    printf("Success: %d\n", success);
    printf("Failure: %d\n", failure);

    return 0;
}

