function [saveMeIn, saveMeOut] = createInputTXT(inputParams, savePath, p)

cd(savePath)
helperToCreateInputTXT(inputParams);
pathC = strcat(erase(p, strcat(filesep, "matlab")), "c");
cd(pathC)
[saveMeIn, saveMeOut] = helperToCreateInputTXT(inputParams);


end