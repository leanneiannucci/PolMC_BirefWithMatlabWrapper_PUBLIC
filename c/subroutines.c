//
// Created by Leanne Iannucci on 10/11/22.
//

#include "subroutines.h"
#include <stdio.h>
#include <math.h>
#include "math.h"
#include <stdlib.h>
#include "array.h"
#include "complex.h"
#include "mie.h"
#include "nrutil.h"
#include <time.h>

#define SIGN(x) ((x)>=0 ? 1:-1)

/*************************************************************/
/* SUBROUTINES */
/**************************************************************************
 *	RandomGen
 *      A random number generator that generates uniformly
 *      distributed random numbers between 0 and 1 inclusive.
 *      The algorithm is based on:
 *      W.H. Press, S.A. Teukolsky, W.T. Vetterling, and B.P.
 *      Flannery, "Numerical Recipes in C," Cambridge University
 *      Press, 2nd edition, (1992).
 *      and
 *      D.E. Knuth, "Seminumerical Algorithms," 2nd edition, vol. 2
 *      of "The Art of Computer Programming", Addison-Wesley, (1981).
 *
 *      When Type is 0, sets Seed as the seed. Make sure 0<Seed<32000.
 *      When Type is 1, returns a random number.
 *      When Type is 2, gets the status of the generator.
 *      When Type is 3, restores the status of the generator.
 *
 *      The status of the generator is represented by Status[0..56].
 *
 *      Make sure you initialize the seed before you get random
 *      numbers.
 ****/
#define MBIG 1000000000
#define MSEED 161803398
#define MZ 0
#define FAC 1.0E-9

double
RandomGen(char Type, long Seed, long *Status){
    static long i1, i2, ma[56];   /* ma[0] is not used. */
    long        mj, mk;
    short       i, ii;

    if (Type == 0) {              /* set seed. */
        mj = MSEED - (Seed < 0 ? -Seed : Seed);
        mj %= MBIG;
        ma[55] = mj;
        mk = 1;
        for (i = 1; i <= 54; i++) {
            ii = (21 * i) % 55;
            ma[ii] = mk;
            mk = mj - mk;
            if (mk < MZ)
                mk += MBIG;
            mj = ma[ii];
        }
        for (ii = 1; ii <= 4; ii++)
            for (i = 1; i <= 55; i++) {
                ma[i] -= ma[1 + (i + 30) % 55];
                if (ma[i] < MZ)
                    ma[i] += MBIG;
            }
        i1 = 0;
        i2 = 31;
    } else if (Type == 1) {       /* get a number. */
        if (++i1 == 56)
            i1 = 1;
        if (++i2 == 56)
            i2 = 1;
        mj = ma[i1] - ma[i2];
        if (mj < MZ)
            mj += MBIG;
        ma[i1] = mj;
        return (mj * FAC);
    } else if (Type == 2) {       /* get status. */
        for (i = 0; i < 55; i++)
            Status[i] = ma[i + 1];
        Status[55] = i1;
        Status[56] = i2;
    } else if (Type == 3) {       /* restore status. */
        for (i = 0; i < 55; i++)
            ma[i + 1] = Status[i];
        i1 = Status[55];
        i2 = Status[56];
    } else
        puts("Wrong parameter to RandomGen().");
    return (0);
}
#undef MBIG
#undef MSEED
#undef MZ
#undef FAC


/************************************************************************************
 *	rotSphi(S,phi,S)
 *		Rotate S by phi [radians] and return as S
 *      multiply S for the rotational matrix of Chandrasekar or Boheren and Hoffman
 *		Uses invtan()
 ****/
void 	rotSphi(double* S, double phi, double* S2) {
    double	cos2phi, sin2phi;

    cos2phi = cos(2*phi);
    sin2phi = sin(2*phi);

    S2[0] = S[0];
    S2[1] = S[1]*cos2phi+S[2]*sin2phi;
    S2[2] = -S[1]*sin2phi+S[2]*cos2phi;
    S2[3] = S[3];

}


/**************************************************************************
 *	updateU(U,U2)
 ****/
void 	updateU(double* U, double phi, double theta, double* U2) {
    double	ux, uy, uz, uxx, uyy, uzz, temp, sintheta, costheta, sinphi, cosphi;
    double 	pi = 3.14159265358979;

    ux = U[0];
    uy = U[1];
    uz = U[2];

    costheta = cos(theta);
    sintheta = sqrt(1.0 - costheta*costheta);
    cosphi   = cos(phi);
    if (phi < pi)
        sinphi = sqrt(1.0 - cosphi*cosphi);
    else
        sinphi = -sqrt(1.0 - cosphi*cosphi);

    /* New directional cosines. */
    if (1 - fabs(uz) <= 1.0E-12) {      /* close to perpendicular. */
        uxx = sintheta * cosphi;
        uyy = sintheta * sinphi;
        uzz = costheta * SIGN(uz);   /*  SIGN(x) is faster than division. */
    }
    else {					/* usually use this option */
        temp = sqrt(1.0 - uz * uz);
        uxx = sintheta * (ux * uz * cosphi - uy * sinphi) / temp + ux * costheta;
        uyy = sintheta * (uy * uz * cosphi + ux * sinphi) / temp + uy * costheta;
        uzz = -sintheta * cosphi * temp + uz * costheta;
    }
    /* Update directional cosines */
    U2[0] = uxx;
    U2[1] = uyy;
    U2[2] = uzz;
}

