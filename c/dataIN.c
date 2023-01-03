//
// Created by Leanne Iannucci on 10/20/22.
//

# include "dataIN.h"
# include <string.h>
# include <stdio.h>
# include "inputStruct.h"
# include <stdlib.h>
# include <stddef.h>
# include <time.h>
# include <ctype.h>


# define Boolean char
# define STRLEN      256                 // pulled from MCML to handle input data from txt files



//
//GetFnameFromArgv(argc, argv, input_filename);
//input_file_ptr = GetFile(input_filename);
//CheckParm(input_file_ptr, &in_parm);


/***********************************************************
 *	Get the file name of the input data file from the
 *	argument to the command line.
 ****/
void GetFnameFromArgv(int argc, char * argv[], char * input_filename) {
    if(argc>=2) {			/* filename in command line */
        strcpy(input_filename, argv[1]);
    }
    else
        input_filename[0] = '\0';
}






/***********************************************************
 *	Check the input parameters for each run.
 ****/
void getInputParams(FILE* File_Ptr, char* fileOut, int* jjj, double* thick, double* width, double* length, long* Nphotons, double* lambda, long* nangles, double* radius,
                    double* nre_p, double* nim_p, double* nre_med, double* nim_med,
                    double* mus, double* mua, double* no, double* dn, double* beamRad, double* pol, double* azi){


    char buff[STRLEN];
    char str2[STRLEN]; // create buffer stream


    if(File_Ptr == NULL) {
        printf("Error opening file");
       // return(-1);
    }
//   while ( fgets (buff, STRLEN, File_Ptr)!=NULL ) {
//        sscanf(buff, "%s", str2);
//        puts(str2);
//        printf("\n");
//        str2[0] = NULL;
//    }

    if(fgets(buff, STRLEN, File_Ptr)!= NULL ) {buff[0] = NULL; str2[0] = NULL; }; // get label
    if(fgets(buff, STRLEN, File_Ptr)!= NULL ) { sscanf(buff, "%s", fileOut); buff[0] = NULL; str2[0] = NULL; } // get output filename
    if(fgets(buff, STRLEN, File_Ptr)!= NULL ) {buff[0] = NULL; str2[0] = NULL; }; //get space

    if(fgets(buff, STRLEN, File_Ptr)!= NULL ) {buff[0] = NULL; str2[0] = NULL; }; //get label
    if(fgets(buff, STRLEN, File_Ptr)!= NULL ) {sscanf(buff, "%s", str2); *jjj = atoi(str2);  buff[0] = NULL; str2[0] = NULL;}; //get jjj
    if(fgets(buff, STRLEN, File_Ptr)!= NULL ) {sscanf(buff, "%s", str2); *Nphotons = (long)(atof(str2));  buff[0] = NULL; str2[0] = NULL;}; //get Nphot
    if(fgets(buff, STRLEN, File_Ptr)!= NULL ) {sscanf(buff, "%s", str2); *lambda = atof(str2);  buff[0] = NULL; str2[0] = NULL;}; //get lambda
    if(fgets(buff, STRLEN, File_Ptr)!= NULL ) {sscanf(buff, "%s", str2); *beamRad = atof(str2);  buff[0] = NULL; str2[0] = NULL;}; //get beamRad
    if(fgets(buff, STRLEN, File_Ptr)!= NULL ) {sscanf(buff, "%s", str2); *pol = (atof(str2));  buff[0] = NULL; str2[0] = NULL;}; //get pol
    if(fgets(buff, STRLEN, File_Ptr)!= NULL ) {sscanf(buff, "%s", str2); *azi = (atof(str2));  buff[0] = NULL; str2[0] = NULL;}; //get azi
    if(fgets(buff, STRLEN, File_Ptr)!= NULL ) {buff[0] = NULL; str2[0] = NULL;}; //get space

    if(fgets(buff, STRLEN, File_Ptr)!= NULL ) {buff[0] = NULL; str2[0] = NULL;}; // get label
    if(fgets(buff, STRLEN, File_Ptr)!= NULL ) {sscanf(buff, "%s", str2); *thick = atof(str2);  buff[0] = NULL; str2[0] = NULL;}; //get hw
    if(fgets(buff, STRLEN, File_Ptr)!= NULL ) {sscanf(buff, "%s", str2); *width = (atof(str2))/2;  buff[0] = NULL; str2[0] = NULL;}; //get hw
    if(fgets(buff, STRLEN, File_Ptr)!= NULL ) {sscanf(buff, "%s", str2); *length = (atof(str2))/2;  buff[0] = NULL; str2[0] = NULL;}; //get hw
    if(fgets(buff, STRLEN, File_Ptr)!= NULL ) {buff[0] = NULL; str2[0] = NULL;}; //get space

    if(fgets(buff, STRLEN, File_Ptr)!= NULL ) {buff[0] = NULL; str2[0] = NULL;}; // get label
    if(fgets(buff, STRLEN, File_Ptr)!= NULL ) {sscanf(buff, "%s", str2); *nangles = (long)(atof(str2));  buff[0] = NULL; str2[0] = NULL;}; //get nagles
    if(fgets(buff, STRLEN, File_Ptr)!= NULL ) {sscanf(buff, "%s", str2); *radius = atof(str2);  buff[0] = NULL; str2[0] = NULL;}; //get radius
    if(fgets(buff, STRLEN, File_Ptr)!= NULL ) {sscanf(buff, "%s", str2); *nre_p = atof(str2);  buff[0] = NULL; str2[0] = NULL;}; //get nre_p
    if(fgets(buff, STRLEN, File_Ptr)!= NULL ) {sscanf(buff, "%s", str2); *nim_p = atof(str2);  buff[0] = NULL; str2[0] = NULL;}; //get nim_p
    if(fgets(buff, STRLEN, File_Ptr)!= NULL ) {sscanf(buff, "%s", str2); *nre_med = atof(str2);  buff[0] = NULL; str2[0] = NULL;}; //get nre_med
    if(fgets(buff, STRLEN, File_Ptr)!= NULL ) {sscanf(buff, "%s", str2); *nim_med = atof(str2);  buff[0] = NULL; str2[0] = NULL;}; //get nim_med
    if(fgets(buff, STRLEN, File_Ptr)!= NULL ) {sscanf(buff, "%s", str2); *mus = atof(str2);  buff[0] = NULL; str2[0] = NULL;}; //get mus
    if(fgets(buff, STRLEN, File_Ptr)!= NULL ) {sscanf(buff, "%s", str2); *mua = atof(str2);  buff[0] = NULL; str2[0] = NULL;}; //get mua
    if(fgets(buff, STRLEN, File_Ptr)!= NULL ) {buff[0] = NULL; str2[0] = NULL;}; //get space

    if(fgets(buff, STRLEN, File_Ptr)!= NULL ) {buff[0] = NULL; str2[0] = NULL;}; // get label
    if(fgets(buff, STRLEN, File_Ptr)!= NULL ) {sscanf(buff, "%s", str2); *no = atof(str2);  buff[0] = NULL; str2[0] = NULL;}; //get no
    if(fgets(buff, STRLEN, File_Ptr)!= NULL ) {sscanf(buff, "%s", str2); *dn = atof(str2);  buff[0] = NULL; str2[0] = NULL;}; //get dn

}