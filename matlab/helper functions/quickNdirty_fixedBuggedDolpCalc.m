%% load in files 
[file, path] = uigetfile("*.mat", "MultiSelect", "on");
addpath(path);
if isa(file, "char")
    file = {file};
end

%% 

for i = 1:numel(file) 
    load(file{i});

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

    
    writetable(c, strcat(erase(file{i}, '-output.mat'), "-output-Stokes-summary.csv"));
end