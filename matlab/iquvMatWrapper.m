%% IQUV MATLAB WRAPPER
% Created by Leanne Iannucci
% Last Edited November 1, 2022
%
% This matlab code was generated to act as a user-friendly wrapper around
% the IQUV program writted by Jessica Ramella-Roman at FIU. 
%
% The user is prompted to first select a save location for their data. This
% folder will be the save location for the .txt file that is generated
% detailing their run parameters as well as all of the output parameters.
%
% The user then enters a loop where the program promps the user to input
% run parameters in a user interface. The corresponding text file is
% generated and saved in the c folder and the save location indicated by
% the user. This process repeats until the user says they are satisfied.
%
% Then, matlab calls the command line from within itself, making a fresh
% copy of IQUV Birefringence via the Makefile and then calling the 
% program's executable post-compilation. It includes the corresponding .txt
% input file as a command argument. 
% 
% The simulation runs, and the code saves a png of both the reflected and
% transmitted surfaces' I Q U V DoLP and AoP, as well as summaries of the 
% average I Q U and V in a csv. It saves the input arguments in a fresh csv
% as well (as output from the executable). All of these variables are also
% saved in a mat file for future analysis.
%
% This loop then repeats for how ever many .txt files were generated.
%

%% clear out
clc;clearvars;
cd(erase(mfilename('fullpath'), mfilename));
addpath(genpath(cd));

%% cd to folder where this is
p = erase(mfilename('fullpath'), mfilename);
cd(p);
addpath(genpath(cd))

%% ask user where they want the data saved

disp("Where do you want the data saved?")
[savePath] = uigetdir;

%% start while loop for input txt file generation
satisfied = false;
count = 1;
while ~(satisfied)
    %% prompt user to input information
    
    inputParams(count) = MCINPUTAPP_helper;
    
    %% create input .txt file
    
    [saveMeIn(count), ~] = createInputTXT(inputParams(count), savePath, p);
    tmpInputParams = inputParams(count);
    cd(savePath)
    save(strcat(erase(saveMeIn(count), ".txt"), "-inputParams.mat"), "tmpInputParams");
    
    %% ask user if they have any more files they want to generate

    answer = questdlg("Do you have more simulations you want to run?");
    switch answer
        case "Yes"
            satisfied = false;
            count = count + 1;
        case "No"
            satisfied = true;
    end
end
%% cd to c path

pathC = strcat(erase(p, strcat(filesep, "matlab")), "c");
cd(pathC);

%% run iquv
q = waitbar(0, strcat("Simulation Progress: 0/", num2str(count), " Runs Completed"));
for i = 1:count
    [~,~] = system("make clean");
    [~,~] = system("make clean_dat");
    [~,~] = system("make");
    [~,cmdout] = system(strcat("./iquv ", saveMeIn(i)), '-echo');
    
    %% parse cmdout
    
    [in,out] = parseIQUVcmdout(cmdout);
    
    
    %% read in all out dat files
    
    out = parseOutDatFiles(out);
    
    %% Calculate DoLP and AoP
    
    out = calcDoLP_AoP(out);
    
    
    %% plot bulk ref and trans images
    
    d = plotOutputStokes(out, inputParams(i).jjj, inputParams(i).length/2, inputParams(i).width/2);
    
    %% put data into a table
    b = in;
    a.R_I = out.R.I;
    a.R_Q = out.R.Q;
    a.R_U = out.R.U;
    a.R_V = out.R.V;
    a.R_AVGDoLP = mean(out.R.bulk.DoLP, 'all');
    tmpR = circ_stats(out.R.bulk.AoP(~isnan(out.R.bulk.AoP)));
    a.R_STDAoP = rad2deg(tmpR.std);
    a.T_I = out.T.I;
    a.T_Q = out.T.Q;
    a.T_U = out.T.U;
    a.T_V = out.T.V;
    a.T_AVGDoLP = mean(out.T.bulk.DoLP, 'all');
    tmpT = circ_stats(out.T.bulk.AoP(~isnan(out.T.bulk.AoP)));
    a.T_STDAoP = rad2deg(tmpT.std);
    c = struct2table(a);
    clear tmpT tmpR
    
    %% save output graphs
    
    saveMe = strcat(inputParams(i).filename, '-output');
    cd(savePath)
    saveas(d, strcat(saveMe, "-Stokes-images.png"))
    savefig(d,strcat(saveMe,"-Stokes-images-editable.fig"))
    writetable(struct2table(b), strcat(saveMe, "-printed-parameters.csv"))
    writetable(c, strcat(saveMe, "-Stokes-summary.csv"))
    save(strcat(string(saveMe), ".mat"), 'in', 'out', '-v7.3')
    
    close(d)
    clear c a b in out cmdout
    
    %% clean up folder with code
    
    % cd to code folder
    cd(pathC);
    [~,~] = system("make clean");
    [~,~] = system("make clean_dat");
    [~,~] = system(strcat("rm ", saveMeIn(i)));

    waitbar(i/count, q, strcat("Simulation Progress: ", num2str(i), "/", num2str(count), " Runs Completed"));
end

