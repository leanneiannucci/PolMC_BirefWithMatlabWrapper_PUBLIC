//
// Created by Leanne Iannucci on 10/20/22.
//

#ifndef IQUV_POLMC_BIREFRINGENCE_DATAIN_H
#define IQUV_POLMC_BIREFRINGENCE_DATAIN_H

# include <stdio.h>

void GetFnameFromArgv(int argc, char * argv[], char * input_filename);

void getInputParams(FILE* File_Ptr, char* fileOut, int* jjj, double* thick, double* width, double* length, long* Nphotons,
                    double* lambda, long* nangles, double* radius,
                    double* nre_p, double* nim_p, double* nre_med, double* nim_med,
                    double* mus, double* mua, double* no, double* dn, double* beamRad,
                    double* pol, double* azi);

FILE *GetFile(char *Fname);

#endif //IQUV_POLMC_BIREFRINGENCE_DATAIN_H
