//
// Created by Leanne Iannucci on 10/11/22.
//

# ifndef IQUV_POLMC_BIREFRINGENCE_USERLAUNCHPARAMS_H
# define IQUV_POLMC_BIREFRINGENCE_USERLAUNCHPARAMS_H

const double pi = 3.1415926535897932384;

/* INPUT LIGHT TYPE */
int jjj = 4; /* 1 for s=(1, 1, 0, 1); 2 for s=(1, -1, 0, 1); 3 for s=(1, 0, 1, 0); 4 for s=(1, 0, 0, 1); */

/* max width/length in cm */
double hw = 1; /* [cm] , maximum range in x and y for output. */

double Nphotons	= 1e5;
double lambda 	= 0.632; // microns
double nangles 	= 1000;

/* CHOOSE MIE SCATTERING parameters */

double radius  	= 0.7; // 2.03/2 microns
double rho 		= 1.05e-3;// Dilution 1
double nre_p   	= 1.59;
double nim_p  	= 0;
double nre_med	= 1.393;/*1.393*/
double nim_med 	= 0.0;

double mus 	= 60;
double mua 	= 0.0;

/* CHOOSE BIREF PARAMS */
double no = 1.393;
double dn = 0.1235e-5;

/**** OLD IGNORE ME **********/

   /*
    *
    * delta[0:numBiref] = {0,0.1235,0.2732,0.4603,0.6624,0.8421,1.0217,1.2013,1.4034}; //,1.5681
    slabsize[0:numBiref]  = {1.0,0.9948,0.9906,0.9861,0.9825,0.9801,0.9777,0.9747,0.9714};
    dn[0:numBiref]  = {0.1235e-5,0.2957e-5,0.4903e-5,0.6924e-5,0.8870e-5,1.0666e-5,1.2537e-5,1.4484e-5,1.6280e-5};

    double delta[numBiref] ={0,0.1235,0.2732,0.4603,0.6624,0.8421,1.0217,1.2013,1.4034}; //,1.5681
    double slabsize[numBiref]= {1.0,0.9948,0.9906,0.9861,0.9825,0.9801,0.9777,0.9747,0.9714};
    double dn[numBiref]={0.1235e-5,0.2957e-5,0.4903e-5,0.6924e-5,0.8870e-5,1.0666e-5,1.2537e-5,1.4484e-5,1.6280e-5};

    double delta[9] ={0,0.1235,0.2732,0.4603,0.6624,0.8421,1.0217,1.2013,1.4034}; //,1.5681
    double slabsize[9]= {1.0,0.9948,0.9906,0.9861,0.9825,0.9801,0.9777,0.9747,0.9714};
    double dn[9]={0.1235e-5,0.2957e-5,0.4903e-5,0.6924e-5,0.8870e-5,1.0666e-5,1.2537e-5,1.4484e-5,1.6280e-5};

    double delta[numBiref] ={0.123,0.2763,0.4744,0.6598,0.8554,1.0367,1.2128,1.4014,1.5709};
    double slabsize[numBiref]= {1,0.9950,0.9910,0.9865,0.9829,0.9804,0.9778,0.9751,0.9720};
    double dn[numBiref]={0.0127e-4,0.0288e-4,0.0487e-4,0.0683e-4,0.0878e-4,0.1066e-4,0.1249e-4,0.1441e-4,0.1629e-4};

     double dn[numBiref]={0,0.1235e-5,0.2957e-5,0.4903e-5,0.6924e-5,0.8870e-5,1.0666e-5,1.2537e-5,1.4484e-5};

     */



#endif //IQUV_POLMC_BIREFRINGENCE_USERLAUNCHPARAMS_H
