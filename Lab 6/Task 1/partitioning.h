#ifndef PARTITIONING
#define PARTITIONING

#include "person.h"

void swap(Person persons[], int pInd, int lo);

// HOARE PARTITIONING
int part(Person persons[], int lo, int hi, int pInd);

// LOMUTO PARTITIONING
int lomuto(Person persons[], int lo, int hi, int pInd);

// THREE-WAY PARTITIONING
int threePart(Person persons[], int lo, int hi, int pInd);

#endif