function out = importBulk(filename,  xlen, ylen, zlen, dataLines)
%IMPORTFILE Import data from a text file
%  OUTBULKP = IMPORTFILE(FILENAME) reads data from text file FILENAME
%  for the default selection.  Returns the numeric data.
%
%  OUTBULKP = IMPORTFILE(FILE, DATALINES) reads data for the specified
%  row interval(s) of text file FILENAME. Specify DATALINES as a
%  positive scalar integer or a N-by-2 array of positive scalar integers
%  for dis-contiguous row intervals.
%
%  Example:
%  outBulkP = importfile("/Users/leanneiannucci/Desktop/iquv-0.8.3/outBulk_P.dat", [1, Inf]);
%
%  See also READTABLE.
%
% Auto-generated by MATLAB on 08-Sep-2022 14:19:25

%% Input handling

% If dataLines is not specified, define defaults
if nargin < 5
    dataLines = [1, Inf];
end

%% Set up the Import Options and import the data
opts = delimitedTextImportOptions("NumVariables", 1);

% Specify range and delimiter
opts.DataLines = dataLines;
opts.Delimiter = ",";

% Specify column names and types
opts.VariableNames = "VarName1";
opts.VariableTypes = "double";

% Specify file level properties
opts.ExtraColumnsRule = "ignore";
opts.EmptyLineRule = "read";

% Import the data
outBulkP = readtable(filename, opts);

%% Convert to output type
outBulkP = table2array(outBulkP);

%% convert to 3d array

%out=permute(reshape(outBulkP,xlen,ylen,zlen),[2,3,1]);
out = reshape(outBulkP,[xlen,ylen,zlen]);
end