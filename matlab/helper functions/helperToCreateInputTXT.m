function [saveMeIn, saveMeOut] = helperToCreateInputTXT(inputParams)

saveMeIn = strcat(inputParams.filename, "-input.txt");
saveMeOut = strcat(inputParams.filename, '-output.txt');
fileID = fopen(saveMeIn,'w');
fprintf(fileID, "# OUTPUT FILENAME\n");
fprintf(fileID, "%s \n", saveMeOut);
fprintf(fileID, "\n");
fprintf(fileID, "# LIGHT INFO\n");
fprintf(fileID, "%d \t\t # light type (1 = H, 2 = V, 3 = P, 4 = R, 5 = U) \n", inputParams.jjj);
fprintf(fileID, "%.3E \t\t # No. of photons \n", inputParams.nphot);
fprintf(fileID, "%.3f \t\t # wavelength of light (um)\n", inputParams.lambda/1000);
fprintf(fileID, "%.3f \t\t # radius of beam (cm)\n", inputParams.beamRad);
fprintf(fileID, "%.5f \t\t # Polar incidence angle (rad)\n", deg2rad(inputParams.pol));
fprintf(fileID, "%.5f \t\t # Azimuthal incidence angle (rad)\n", deg2rad(inputParams.azi));

fprintf(fileID, "\n");
fprintf(fileID, "# TISSUE GEOM\n");
fprintf(fileID, "%.3f \t\t # Thickness (cm) \n", inputParams.thick);
fprintf(fileID, "%.3f \t\t # Width (cm) \n", inputParams.width);
fprintf(fileID, "%.3f \t\t # Length (cm) \n", inputParams.length);
fprintf(fileID, "\n");
fprintf(fileID, "# MIE SCATTERING\n");
fprintf(fileID, "%.E \t\t# number of angles for mie scattering\n", inputParams.nangles);
fprintf(fileID, "%.3f \t\t# radius (um)\n", inputParams.rad);
fprintf(fileID, "%.3f \t\t# sphere refractive index (real)\n", inputParams.np_r);
fprintf(fileID, "%.3f \t\t# sphere refractive index (imaginary)\n", inputParams.np_im);
fprintf(fileID, "%.3f \t\t# medium refractive index (real)\n", inputParams.nm_r);
fprintf(fileID, "%.3f \t\t# medium refractive index (imaginary)\n", inputParams.nm_im);
fprintf(fileID, "%.3f \t\t# mu_s (1/cm)\n", inputParams.mus);
fprintf(fileID, "%.3f \t\t# mu_a (1/cm)\n", inputParams.mua);
fprintf(fileID, "\n");
fprintf(fileID, "# BIREFRINGENCE\n");
fprintf(fileID, "%.3f \t\t# ordinary refractive index\n", inputParams.nm_r);
fprintf(fileID, "%.3E \t\t# birefringence (change in n between ordinary and extraordinary)\n", inputParams.dn);

end
