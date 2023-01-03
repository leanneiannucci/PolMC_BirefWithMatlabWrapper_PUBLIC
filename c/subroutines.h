//
// Created by Leanne Iannucci on 10/11/22.
//

#ifndef IQUV_POLMC_BIREFRINGENCE_SUBROUTINES_H
#define IQUV_POLMC_BIREFRINGENCE_SUBROUTINES_H

/* Declare Subroutines */
void 	rotSphi(double* S, double phi, double* S2);
double	RandomGen(char Type, long Seed, long *Status);
void 	multS(double* S, double theta, double* S2);
void 	rotateXXYY(double* XX, double* YY,double* ZZ, double phi, double theta, double* XX2, double* YY2,double* ZZ2);
void 	updateU(double* U, double phi, double theta, double* U2);
double  sincos(double *x);

#endif //IQUV_POLMC_BIREFRINGENCE_SUBROUTINES_H
