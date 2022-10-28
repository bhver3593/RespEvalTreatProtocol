
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <iomanip>
#include "patient.h"
#include "treatment.h"

using std::cout;
using std::endl;
using std::setw;
using std::string;

int generateRandom(int, int);
int calcScore(int, int, int, int, int, int, int, int, int, int);
string calcFrequency(Treatment [], int);
string treatWheezing(int, int);
string treatCongestion(int, int, int);
string treatLowLungVolumes(int, int, int);
void printPatientData(Patient [], int);
void printTreatment(Treatment [], int);

#endif // FUNCTIONS_H
