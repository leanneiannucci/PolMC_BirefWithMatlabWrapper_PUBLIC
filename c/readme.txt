 /***********************************************************
 *  Copyright Jessica C. Ramella-Roman 2005 *
 *  README FILE *
 *	Contains simple explaination on how to run Monte Carlo code * and 8 test cases.
 *
 *
 *
 * J. Ramella-Roman, S. A. Prahl, S. L. Jacques Three Monte Carlo programs of polarized light transport into scattering media: part I, 2005 Optics Express, submitted 2005.
 *
 ****/Programs compiles and links with -> make
 Programs runs with 				 -> ./iquv

 Results of total reflectance an total transmittance are printed on screen for every status of
 polarization launched.Programs generates 100x100 pixel images to contruct Mueller Matrix:
 Generated matrices as : HH HV HP HR ; VH VV VP VR ; PH PV PP PR ; RH RV RP RR
 H = HORIZONTAL POLARIZED PARALLEL TO REFERENCE FRAME;
 V = VERTICAL POLARIZED PERPENDICULAR TO REFERENCE FRAME;
 P = 45 POLARIZED;
  R = RIGHT CIRCULAR POLARIZED;
  /*************/
/* Examples
  /*************/

  sphere diameter = 2.00000;
  [micro m]mus = 827.81840; [cm^-1]
g   = 0.76861;
rho = 0.01000; [particle /(micro m)^3]
  Slab size=0.00483 [cm] => [4/mus]
Photons = 1e5;
n_media = 1;
  index of refraction median_sphere = 1.59;
  index of refraction sphere
  /* NOMALIZED BY PHOTON LAUNCHED;
  R= TOTAL REFLECTANCE [I Q U V];
  T= TOTAL TRANSMITTANCE [I Q U V];
  launch H [1 1 0 0]
R = 0.29299       0.08992        -0.00054        -0.00014
  T = 0.70701      0.51252         -0.00094        0.00133
  launch V [1 -1 0 0]
  R = 0.29306       -0.09181       -0.00049        -0.00004
T = 0.70694      -0.51268        -0.00114        0.00011
  launch P [ 1 0 1 0]
  R = 0.29254       0.00313       -0.08724        -0.00070
  T = 0.70746      -0.00033        0.51334         0.00084
  launch R [1 0 0 1]
  R = 0.29285     -0.00081        -0.00037        -0.00875
  T = 0.70715      0.00039         0.00078         0.51589

  sphere diameter = 0.01000; [micro m]
mus		= 0.00000;[cm^-1]
  g		= 0.00051;
  rho		= 0.01000;[particle /(micro m)^3]
  Slab size = 275959772.13944 [cm] =>[4/mus]
  n_media  = 1;
  index of refraction median_sphere = 1.59;
  index of refraction sphere
  launch H [1 1 0 0]
R= 0.68934       0.28741         -0.00059        -0.00000
T= 0.31066      0.07206         0.00035         -0.00000
  launch V [1 0 1 0]
R= 0.68858       -0.28715        0.00055         -0.00000
  T= 0.31142      -0.07305        -0.00013        -0.00000
  launch P [1 0 1 0]
R= 0.68850       -0.00040        -0.28743        0.00000
  T= 0.31150      0.00017         0.07283         0.00000
  launch R [1 0 0 1]
R= 0.68870       -0.00065        0.00032         -0.20367
  T= 0.31130      -0.00029        -0.00061        0.04982
