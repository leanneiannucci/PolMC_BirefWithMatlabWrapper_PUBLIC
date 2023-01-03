disp("pick params file");
[file, path] = uigetfile("*.csv");

out = importparamsweep(strcat(path,file));
out_struct = table2struct(out);
clearvars out;
cd(path)

disp("pick parent folder");
p = uigetdir;

for i =1:size(out_struct,1)
    stokesFile = strcat(num2str(i), "-output-Stokes-summary.csv");
    [out_struct(i).R_I, out_struct(i).R_Q, out_struct(i).R_U, out_struct(i).R_V, ...
        out_struct(i).R_AVGDoLP, out_struct(i).R_STDAoP, out_struct(i).T_I, ...
        out_struct(i).T_Q, out_struct(i).T_U, out_struct(i).T_V, ...
        out_struct(i).T_AVGDoLP, out_struct(i).T_STDAoP] = importStokesOut(stokesFile);
    clearvars stokesFile;
end

writetable(struct2table(out_struct), "parameterSweep-outputSummary.csv");