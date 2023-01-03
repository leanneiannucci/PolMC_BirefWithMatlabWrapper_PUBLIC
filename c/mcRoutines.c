//
// Created by Leanne Iannucci on 10/11/22.
//

#include "mcRoutines.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "array.h"
#include "complex.h"
#include "mie.h"
#include "nrutil.h"
#include <time.h>
#include "subroutines.h"


#define ALIVE      	1
#define DEAD       	0
#define	NN      	100
#define THRESHOLD   0.01                /* used in roulette */
#define CHANCE      0.1                 /* used in roulette */

#define RandomNum (double) RandomGen(1, 0, NULL)


void refFrame(double* U, double* S, double* phi, double* S2, double* IR_1, double* QR_1, double* UR_1, double* VR_1, short* photon_status, double thick,
              double* IT_1, double* QT_1, double* UT_1, double* VT_1, double x, double y, double z, double W, double pi, double MM, int ix, int iy, double length, double width,
              double dx, double dy,
              double** IR, double** QR, double** UR, double** VR, double** IT, double** QT, double** UT, double** VT){
    if ( z<=0) {

        /*return to detector reference frame*/

        *phi = atan2(U[1],U[0]);

        rotSphi(S, *phi, S2);

        *IR_1 += S2[0];
        *QR_1 += S2[1];
        *UR_1 += S2[2];
        *VR_1 += S2[3];

        if (x >= -length)
            ix = (int)(fabs(x + length)/dx);

        if (y >= -width)
            iy = (int)(fabs(y + width)/dy);

        if (ix > MM) ix = MM;

        if (iy > MM) iy = MM;

        IR[iy][ix] += S2[0];

        QR[iy][ix] += S2[1];

        UR[iy][ix] += S2[2];

        VR[iy][ix] += S2[3];

        *photon_status = DEAD;

    } else if ( z>=thick) {

        *phi = -atan2(U[1],U[0]);

        rotSphi(S, *phi, S2);

        /*phi=acos(U[2]);
        */
       // if ((*phi <= 14*pi/180) && (*phi >- 14*pi/180)){

         //   if ((x<=0.1)&&(x>=-0.1)){

           //     if ((y<=0.1)&&(y>=-0.1)){

                    *IT_1 += S2[0] * W;
                    *QT_1 += S2[1] * W;
                    *UT_1 += S2[2] * W;
                    *VT_1 += S2[3] * W;

         //       }
         //   }
        //}


        if (x >= -length)
            ix = (int)(fabs(x + length)/dx);

        if (y >= -width)
            iy = (int)(fabs(y + width)/dy);

        if (ix > MM) ix = MM;

        if (iy > MM) iy = MM;

        IT[iy][ix] += S2[0];

        QT[iy][ix] += S2[1];

        UT[iy][ix] += S2[2];

        VT[iy][ix] += S2[3];


        *photon_status = DEAD;

    }/*z>slab size*/
}

void doBiref(double lambda, double no, double dn, double* U, double s, double pi, double* S, double* S2) {
  // removed at request of jessica ramella-roman
  // see "A new approach for optical assessment of directional anisotropy in turbid media" by Ghassemi et al
  // https://doi.org/10.1002/jbio.201400124
  // for implementation details
}

void doAbsorb(double albedo, double x, double y, double width, double length, double dx, double dy, int* iy, int* ix, double* W) {
   int  MM = NN - 1;

    double absorb = (*W) * (1-albedo);
        *W -= absorb;

        if (x >= -length)
        *ix = (int)(fabs(x + length)/dx);

        if (y >= -width)
        *iy = (int)(fabs(y + width)/dy);



        if (*ix > MM) *ix = MM;

        if (*iy > MM) *iy = MM;
}

void doSpin(double theta, double* s11, double* s12, double* s33, double* s43, double* S, double nangles, double pi, double* U, double* U2, double* S2)	 {

    double phi, I0, I, costheta, temp, cosi, cos22, sini, sin22;
    int ithedeg, i;
    /* REJECTION METHOD to choose azimuthal angle phi and deflection angle theta */

    do{
    theta 	= acos(2*RandomNum-1);

    phi = RandomNum*2.0*pi;

    I0=s11[0]*S[0]+s12[0]*(S[1]*cos(2*phi)+S[2]*sin(2*phi));

    ithedeg = floor(theta*nangles/pi);

    I=s11[ithedeg]*S[0]+s12[ithedeg]*(S[1]*cos(2*phi)+S[2]*sin(2*phi));

    }while(RandomNum * I0 >= I);

    /*------------------------------------------------------------------------------
     Scattering : rotate to meridian plane	then scatter
    ------------------------------------------------------------------------------*/

    updateU(U, phi, theta, U2);  /* update photon trajectory vector */

    costheta=cos(theta);

    rotSphi(S, phi, S2);

    S[0]= s11[ithedeg]*S2[0]+s12[ithedeg]*S2[1];

    S[1]= s12[ithedeg]*S2[0]+s11[ithedeg]*S2[1];

    S[2]= s33[ithedeg]*S2[2]+s43[ithedeg]*S2[3];

    S[3]= -s43[ithedeg]*S2[2]+s33[ithedeg]*S2[3];

    temp=(sqrt(1-costheta*costheta)*sqrt(1-U2[2]*U2[2]));

    if ( temp==0){
    cosi=0;}
    else{

    if ((phi>pi) && (phi<2*pi))
    cosi=(U2[2]*costheta-U[2])/temp;
    else
    cosi=-(U2[2]*costheta-U[2])/temp;
    }

    if(cosi > 1) cosi=1;

    if(cosi <-1) cosi=-1;


    sini = sqrt(1-cosi*cosi);

    cos22=2*cosi*cosi-1;

    sin22=2*sini*cosi;

    S2[0]=S[0];

    S2[1]=(S[1]*cos22-S[2]*sin22);

    S2[2]=(S[1]*sin22+S[2]*cos22);

    S2[3]=S[3];


    S[1]= S2[1]/S2[0];
    S[2]= S2[2]/S2[0];
    S[3]= S2[3]/S2[0];
    S[0]= 1.0;

    for (i=0; i<3; i++) U[i] = U2[i]; /* update U */
}

void doHop(double mus, double mua, double* s, double* x, double* y, double* z, double* U){
        double rnd = 0; while (rnd == 0) rnd = RandomNum;  /* choose a step size */

        *s = -log(rnd)/(mus+mua);
        *x += U[0]*(*s);
        *y += U[1]*(*s);
        *z += U[2]*(*s);
}

void doRoulette(short* photon_status, double* W) {
        double rnd=0; while(rnd==0) rnd=RandomNum;

        if (*W < THRESHOLD){
            if (rnd <= CHANCE)
                *W /= CHANCE;
            else *photon_status = DEAD;
        }
}

void genPhotonType_withPrint(int jjj) {
        if (jjj == 1) {
            printf("launch H\n");
        }

        if (jjj == 2) {
            printf("launch V\n");
        }

        if (jjj == 3) {
            printf("launch P\n");
        }

        if (jjj == 4) {
            printf("launch R\n");
        }
        if (jjj = 5) {
            printf("launch U\n");
        }
}

void genPhotonType(int jjj, double* S0) {
        if (jjj == 1){

            S0[0] = 1;
            S0[1] = 1;
            S0[2] = 0;
            S0[3] = 0;
            }

        if (jjj == 2){

            S0[0] = 1;
            S0[1] =	-1;
            S0[2] = 0;
            S0[3] = 0;
            }

        if (jjj == 3){

            S0[0] = 1;
            S0[1] =	0;
            S0[2] = 1;
            S0[3] = 0;
            }

        if (jjj == 4){

            S0[0] = 1;
            S0[1] =	0;
            S0[2] = 0;
            S0[3] = 1;
            }

        if (jjj == 5){

            S0[0] = 1;
            S0[1] =	0;
            S0[2] = 0;
            S0[3] = 0;
        }
}

void initPhoton(double* x, double* y, double* z, double* U, double* S, double* S0, double* S2, double* W, short* photon_status, int jjj, double beamRad, double length, double width, double pi, double azi, double pol) {
    int i;

    genPhotonType(jjj, S0);
     if (beamRad == 0.0) { /*pencil beam	*/

        *x = 0.0;
        *y = 0.0;
        *z = 0.0;
    } else { /* uniform beam of radius beamRad [cm] */
         /* adapted from mcxyz.m */
        // set launch point and width of beam
        double r, phi, rnd;
        int satisfied = 0;
        while (satisfied == 0) {
            while ((rnd = RandomGen(1, 0, NULL)) <= 0.0); // avoids rnd = 0
            r = beamRad * sqrt(rnd); // radius of beam at launch point
            while ((rnd = RandomGen(1, 0, NULL)) <= 0.0); // avoids rnd = 0
            phi = rnd * 2.0 * pi;
            *x = r * cos(phi);
            *y = r * sin(phi);
            *z = 0;

            if (*x < length) {
                if (*x > -length) {
                    if (*y < width) {
                        if (*y > -width) {
                            satisfied = 1; // phot is starting within bounds of tissue, else re-initialize
                        }
                    }
                }
            }


        } // satisfied loop

     } // if beam type

    /* photon direction cosines */
        U[0] = -1*sin(pol)*cos(azi);
        U[1] = -1*sin(pol)*sin(azi);
        U[2] = cos(pol);


        for (i=0; i<4; i++) S[i] = S0[i]; /* set incident Stokes vector to S0 */
        for (i=0; i<4; i++) S2[i] = 0.0; /* set incident Stokes vector to S0 */

        *photon_status = ALIVE;
        *W	= 1; /* photon weight */
};
