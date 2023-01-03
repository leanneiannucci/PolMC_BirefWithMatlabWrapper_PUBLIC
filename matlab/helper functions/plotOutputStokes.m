function [a] = plotOutputStokes(out, jjj, length, width)
cmap = inferno;
a = figure("Position", [272,60,764,806]);hold on;

switch jjj
    case 1
        titleString = "Input H (S = [1 1 0 0)";
    case 2
        titleString = "Input V (S = [1 -1 0 0)";
    case 3
        titleString = "Input P (S = [1 0 1 0)";
    case 4
        titleString = "Input R (S = [1 0 0 1)";
end

x = linspace(-length, length, 98);
y = linspace(-width, width, 98);

subplot(6,2,1); imagesc(x,y, out.R.bulk.I(2:99, 2:99)); hold on; colormap(cmap);  hold on; colorbar; hold on; subtitle("Reflected"); hold on; ylabel("S_0"); hold on;
subplot(6,2,2); imagesc(x,y, out.T.bulk.I(2:99, 2:99)); hold on; colormap(cmap); hold on;  hold on; colorbar; hold on; subtitle("Transmitted"); hold on;
subplot(6,2,3); imagesc(x,y, out.R.bulk.Q(2:99, 2:99)); hold on; colormap(cmap); hold on;  hold on; colorbar; hold on; ylabel("S_1"); hold on;
subplot(6,2,4); imagesc(x,y, out.T.bulk.Q(2:99, 2:99)); hold on; colormap(cmap); hold on;  hold on; colorbar; hold on;
subplot(6,2,5); imagesc(x,y, out.R.bulk.U(2:99, 2:99)); hold on; colormap(cmap); hold on;  hold on; colorbar; hold on; ylabel("S_2"); hold on;
subplot(6,2,6); imagesc(x,y, out.T.bulk.U(2:99, 2:99)); hold on; colormap(cmap); hold on;  hold on; colorbar; hold on;
subplot(6,2,7); imagesc(x,y, out.R.bulk.V(2:99, 2:99)); hold on; colormap(cmap); hold on;  hold on; colorbar; hold on; ylabel("S_3"); hold on;
subplot(6,2,8); imagesc(x,y, out.T.bulk.V(2:99, 2:99)); hold on; colormap(cmap); hold on;  hold on; colorbar; hold on;
b = subplot(6,2,9); imagesc(x,y, out.R.bulk.DoLP(2:99, 2:99)); hold on; colormap(b,"jet"); hold on;  hold on; colorbar; hold on; ylabel("DoLP"); hold on;
c = subplot(6,2,10); imagesc(x,y, out.T.bulk.DoLP(2:99, 2:99)); hold on; clim(b.CLim); colormap(c,"jet"); hold on; hold on; colorbar; hold on; 
d = subplot(6,2,11); imagesc(x,y,rad2deg(out.R.bulk.AoP(2:99, 2:99))); hold on; clim(d, [-180, 180]); colormap(d,"hsv"); hold on;  hold on; colorbar; hold on; ylabel("AoP"); hold on;
e = subplot(6,2,12); imagesc(x,y,rad2deg(out.T.bulk.AoP(2:99, 2:99))); hold off; clim(e, [-180, 180]); colormap(e,"hsv"); hold on;  hold on; colorbar; hold on;

sgtitle(titleString); hold on;

end