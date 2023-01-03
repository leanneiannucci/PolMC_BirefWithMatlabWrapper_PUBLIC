function inputStruct = MCINPUTAPP_helper

        inputStruct = struct;
        app = polMC_inputparams;

        waitfor(app.UIFigure, 'Visible');


        inputStruct.filename = app.FilenameEditField.Value;
        inputStruct.thick = app.ThicknesscmEditField.Value;
        inputStruct.width = app.WidthcmEditField.Value;
        inputStruct.length = app.LengthcmEditField.Value;


        inputStruct.dn = app.nEditField.Value;
        tmp = app.LightTypeDropDown.Value;
            if strcmp(tmp, 'H (1 1 0 0)')
                inputStruct.jjj = 1;
            elseif strcmp(tmp, 'V (1 -1 0 0)')
                inputStruct.jjj = 2;
            elseif strcmp(tmp, 'P (1 0 1 0)')
                inputStruct.jjj = 3;
            elseif strcmp(tmp, 'R (1 0 0 1)')
                inputStruct.jjj = 4;
            elseif strcmp(tmp, 'U (1 0 0 0)')
                inputStruct.jjj = 5;
            end
        inputStruct.nphot = app.NumberofPhotonsEditField.Value;
        inputStruct.lambda = app.WavelengthofLightnmEditField.Value;
        inputStruct.nangles = 1000;
        inputStruct.rad = app.RadiusmEditField.Value;
        inputStruct.beamRad = app.LightBeamRadiuscmEditField.Value;
        inputStruct.np_r = app.SphereRIRealEditField.Value;
        %inputStruct.np_im = app.SphereRIImaginaryEditField.Value;
        inputStruct.np_im = 0;
        inputStruct.nm_r = app.MediumRIRealEditField.Value;
        %inputStruct.nm_im = app.MediumRIImaginaryEditField.Value;
        inputStruct.nm_im = 0;
        inputStruct.mus = app.s1cmEditField.Value;
        inputStruct.mua = app.a1cmEditField.Value;
        inputStruct.pol = (app.polEditField.Value);
        inputStruct.azi = (app.aziEditField.Value);

       
        
end