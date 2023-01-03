//
// Created by Leanne Iannucci on 10/11/22.
//

#include "saveDATs.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "array.h"
#include "complex.h"
#include "mie.h"
#include "nrutil.h"
#include <time.h>
#include "mcRoutines.h"


/* this is the base fn for saving data from an array into a DAT file */

void saveDatFile(int stokesParam, int inLight, int refVtrans, int NN, double** IR) {
    FILE *target;
    char stokesParamChoices[] = "IQUV";
    char inLightChoices[] = "HVPR";
    char refVtransChoices[] = "RT";
    int i, j;

    char saveName[12] = {};
    strcat(saveName, "out");
    //strncat(saveName, &(inLightChoices[inLight]),1);
    strncat(saveName, &(stokesParamChoices[stokesParam]),1);
    strcat(saveName, "_");
    strncat(saveName, &refVtransChoices[refVtrans],1);
    strcat(saveName, ".dat");


    target = fopen(&saveName,"w");

    for (i=0; i<NN; i++) {
        fprintf(target,"%5.5f", IR[i][0]);
        for (j=1; j<NN; j++)
            fprintf(target, "\t%5.5f", IR[i][j]);
        fprintf(target, "\n");
        }
    fclose(target);
   // free(&saveName);
}

/* big function saving all of the arrays into one *//*










if (jjj==1) {
    target = fopen("outHI.dat","w");

    for (i=0; i<NN; i++) {

        fprintf(target,"%5.5f", IR[i][0]);

        for (j=1; j<NN; j++)
            fprintf(target,"\t%5.5f", IR[i][j]);
            fprintf(target,"\n");
    }
    fclose(target);

    target = fopen("outHQ.dat","w");
    for (i=0; i<NN; i++) {
        fprintf(target,"%5.5f", QR[i][0]);
            for (j=1; j<NN; j++)
                fprintf(target,"\t%5.5f", QR[i][j]);
                fprintf(target,"\n");
    }
    fclose(target);

    target = fopen("outHU.dat","w");
    for (i=0; i<NN; i++) {
        fprintf(target,"%5.5f", UR[i][0]);
            for (j=1; j<NN; j++)
                fprintf(target,"\t%5.5f", UR[i][j]);
                fprintf(target,"\n");
    }
    fclose(target);

    target = fopen("outHV.dat","w");
    for (i=0; i<NN; i++) {
        fprintf(target,"%5.5f", VR[i][0]);
            for (j=1; j<NN; j++)
                fprintf(target,"\t%5.5f", VR[i][j]);
                fprintf(target,"\n");
    }
    fclose(target);


}
*/
/*111111111111111111111111111111111111111111111111111111111111111*//*


if (jjj==2) {

*/
/* save data to file *//*

target = fopen("outVI.dat","w");
for (i=0; i<NN; i++) {
fprintf(target,"%5.5f", IR[i][0]);
for (j=1; j<NN; j++)
fprintf(target,"\t%5.5f", IR[i][j]);
fprintf(target,"\n");
}
fclose(target);

target = fopen("outVQ.dat","w");
for (i=0; i<NN; i++) {
fprintf(target,"%5.5f", QR[i][0]);
for (j=1; j<NN; j++)
fprintf(target,"\t%5.5f", QR[i][j]);
fprintf(target,"\n");
}
fclose(target);

target = fopen("outVU.dat","w");
for (i=0; i<NN; i++) {
fprintf(target,"%5.5f", UR[i][0]);
for (j=1; j<NN; j++)
fprintf(target,"\t%5.5f", UR[i][j]);
fprintf(target,"\n");
}
fclose(target);

target = fopen("outVV.dat","w");
for (i=0; i<NN; i++) {
fprintf(target,"%5.5f", VR[i][0]);
for (j=1; j<NN; j++)
fprintf(target,"\t%5.5f", VR[i][j]);
fprintf(target,"\n");
}
fclose(target);
for (iy=0; iy<NN; iy++)
for (ix=0; ix<NN; ix++) {
IR[iy][ix] = 0.0;
QR[iy][ix] = 0.0;
UR[iy][ix] = 0.0;
VR[iy][ix] = 0.0;
}
}
*/
/* 222222222222222222222222222222222222222222222222222222222222222*//*


if (jjj==3) {

*/
/* save data to file *//*


target = fopen("outPI.dat","w");
for (i=0; i<NN; i++) {
fprintf(target,"%5.5f", IR[i][0]);
for (j=1; j<NN; j++)
fprintf(target,"\t%5.5f", IR[i][j]);
fprintf(target,"\n");
}
fclose(target);

target = fopen("outPQ.dat","w");
for (i=0; i<NN; i++) {
fprintf(target,"%5.5f", QR[i][0]);
for (j=1; j<NN; j++)
fprintf(target,"\t%5.5f", QR[i][j]);
fprintf(target,"\n");
}
fclose(target);

target = fopen("outPU.dat","w");
for (i=0; i<NN; i++) {
fprintf(target,"%5.5f", UR[i][0]);
for (j=1; j<NN; j++)
fprintf(target,"\t%5.5f", UR[i][j]);
fprintf(target,"\n");
}
fclose(target);

target = fopen("outPV.dat","w");
for (i=0; i<NN; i++) {
fprintf(target,"%5.5f", VR[i][0]);
for (j=1; j<NN; j++)
fprintf(target,"\t%5.5f", VR[i][j]);
fprintf(target,"\n");
}
fclose(target);
for (iy=0; iy<NN; iy++)
for (ix=0; ix<NN; ix++) {
IR[iy][ix] = 0.0;
QR[iy][ix] = 0.0;
UR[iy][ix] = 0.0;
VR[iy][ix] = 0.0;
}
}
*/
/* 33333333333333333333333333333333333333333333333333333333333333333333*//*


if (jjj==4) {
*/
/* save data to file *//*

target = fopen("outRI.dat","w");
for (i=0; i<NN; i++) {
fprintf(target,"%5.5f", IR[i][0]);
for (j=1; j<NN; j++)
fprintf(target,"\t%5.5f", IR[i][j]);
fprintf(target,"\n");
}
fclose(target);

target = fopen("outRQ.dat","w");
for (i=0; i<NN; i++) {
fprintf(target,"%5.5f", QR[i][0]);
for (j=1; j<NN; j++)
fprintf(target,"\t%5.5f", QR[i][j]);
fprintf(target,"\n");
}
fclose(target);

target = fopen("outRU.dat","w");
for (i=0; i<NN; i++) {
fprintf(target,"%5.5f", UR[i][0]);
for (j=1; j<NN; j++)
fprintf(target,"\t%5.5f", UR[i][j]);
fprintf(target,"\n");
}
fclose(target);

target = fopen("outRV.dat","w");
for (i=0; i<NN; i++) {
fprintf(target,"%5.5f", VR[i][0]);
for (j=1; j<NN; j++)
fprintf(target,"\t%5.5f", VR[i][j]);
fprintf(target,"\n");
}
fclose(target);

}*/
