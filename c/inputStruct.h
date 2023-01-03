//
// Created by Leanne Iannucci on 10/20/22.
//

#ifndef IQUV_POLMC_BIREFRINGENCE_INPUTSTRUCT_H
#define IQUV_POLMC_BIREFRINGENCE_INPUTSTRUCT_H




typedef struct {
    // INPUT LIGHT
    int jjj;

    // MAX SIZE IN CM.
    double hw;

    // LIGHT PARAMS
    double Nphotons;
    double lambda;
    double nangles;

    //MIE SCATTERING PARAMS
    double radius;
    double rho;
    double nre_p;
    double nim_p;
    double nre_med;
    double nim_med;
    double mus;
    double mua;

/* CHOOSE BIREF PARAMS */
    double no;
    double dn;
} InputStruct;

#endif //IQUV_POLMC_BIREFRINGENCE_INPUTSTRUCT_H
