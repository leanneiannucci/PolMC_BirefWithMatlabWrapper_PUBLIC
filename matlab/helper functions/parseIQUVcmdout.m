function [in,out] = parseIQUVcmdout(cmdout)
%% pick up anything that is a number, . or - as a string until you hit a different char

outVars = "";
last = false;
count = 1;
for i = 1:numel(cmdout)
    if ismember(cmdout(i),['0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '-', '.', '+'])
        outVars(count) = outVars(count) + cmdout(i);
        last = true;
    elseif ismember(cmdout(i), 'e') && ismember(cmdout(i+1), ['-', '+']) 
        outVars(count) = outVars(count) + cmdout(i);
        last = true;
    elseif last 
        count = count+1;
        outVars(count) = "";
        last = false;
    end
end

%% parse outVars and convert to variables
% outVars = string of 38 output doubles from IQUV

in.dia = str2double(outVars(1,1));
in.mus = str2double(outVars(1,2));
in.g = str2double(outVars(1,3));
in.rho = str2double(outVars(1,4));
in.nphot = str2double(outVars(1,6));
in.duration = str2double(outVars(1,16));
in.biref = str2double(outVars(1,7));
in.mua = str2double(outVars(1,5));

out.R.I = str2double(outVars(1,8));
out.R.Q = str2double(outVars(1,9));
out.R.U = str2double(outVars(1,10));
out.R.V = str2double(outVars(1,11));

out.T.I = str2double(outVars(1,12));
out.T.Q = str2double(outVars(1,13));
out.T.U = str2double(outVars(1,14));
out.T.V = str2double(outVars(1,15));
end