/*
Define a new type for representing the fractions. The use it to write a manipulation program.
This program must have the following functionalities:
- Input for an array of fraction.
- Print the content of the fraction array.
- Inverse all the fraction in the array.
- Compare two fractions.
*/

#include<stdio.h>
#include<stdlib.h>

#define MAX_Size 100

typedef struct{
    int numerator;
    int denominator;
} fraction;

// Function to enter the fraction
void fraction_Input (fraction *ps){
    int n, d;
    printf("Numerator: "); scanf("%d", &n);
    ps->numerator = n;
    do{
        printf("Denominator: "); scanf("%d", &d);
    } while (d==0);
    ps->denominator = d;
}

// Function to print out the fraction
void fraction_Output (fraction ps){
    printf("%d/%d ", ps.numerator, ps.denominator);
}

// Function to enter the array of fractions
void fraction_Array_Input (fraction dsps[], int n){
    int i;
    for (i=0; i<n; i++){
        printf("Data input for the i-th fraction:\n");
        fraction_Input(&dsps[i]);
    }
}

// Function to print out the array of fractions
void fraction_Array_Output (fraction dsps[], int n){
    int i;
    printf("Data output for the array of fractions:\n");
    for (i=0; i<n; i++){
        fraction_Output(dsps[i]);
    }
    printf("\n");
}

// Function to inverse the fraction
fraction Inverse (fraction ps){
    fraction tmp;
    if (ps.numerator == 0){
        printf("Can not have an inverse fraction of 0\n");
        exit(1);
    }
    tmp.numerator = ps.denominator;
    tmp.denominator = ps.numerator;
    return tmp;
}

// Function to inverse the array of fractions
void inverse_Array (fraction dsps[], int n){
    int i;
    for (i=0; i<n; i++){
        dsps[i] = Inverse(dsps[i]);
    }
}

// Function to compare two fractions
int fraction_Compare (fraction ps1, fraction ps2){
    long smd = (ps1.numerator*ps2.denominator - ps2.numerator*ps1.denominator)*ps1.denominator*ps2.denominator;
    if (smd>0) return 1;
    else if (smd<0) return -1;
    else return 0;
}

int main ()
