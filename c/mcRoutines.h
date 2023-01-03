//
// Created by Leanne Iannucci on 10/11/22.
//

#ifndef IQUV_POLMC_BIREFRINGENCE_MCROUTINES_H
#define IQUV_POLMC_BIREFRINGENCE_MCROUTINES_H

void refFrame(double* U, double* S, double* phi, double* S2, double* IR_1, double* QR_1, double* UR_1, double* VR_1, short* photon_status, double thick,
              double* IT_1, double* QT_1, double* UT_1, double* VT_1, double x, double y, double z, double W, double pi, double MM, int ix, int iy, double length, double width,
              double dx, double dy,
              double** IR, double** QR, double** UR, double** VR, double** IT, double** QT, double** UT, double** VT);

void doBiref(double lambda, double no, double dn, double* U, double s, double pi, double* S, double* S2);

void doAbsorb(double albedo, double x, double y, double width, double length, double dx, double dy, int* iy, int* ix, double* W);

void doSpin(double theta, double* s11, double* s12, double* s33, double* s43, double* S, double nangles, double pi, double* U, double* U2, double* S2);

void doHop(double mus, double mua, double* s, double* x, double* y, double* z, double* U);

void doRoulette(short* photon_status, double* W);

void genPhotonType(int jjj, double* S0);

void genPhotonType_withPrint(int jjj);

void initPhoton(double* x, double* y, double* z, double* U, double* S, double* S0, double* S2, double* W, short* photon_status, int jjj, double beamRad, double length, double width, double pi, double azi, double pol);

#endif //IQUV_POLMC_BIREFRINGENCE_MCROUTINES_H
