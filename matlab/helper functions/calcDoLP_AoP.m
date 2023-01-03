function [out] = calcDoLP_AoP(out)

out.R.bulk.DoLP = sqrt((out.R.bulk.Q).^2 + (out.R.bulk.U).^2)./(out.R.bulk.I);
out.R.bulk.AoP = ((1/2)*atan(out.R.bulk.U./out.R.bulk.Q));

out.T.bulk.DoLP = sqrt((out.T.bulk.Q).^2 + (out.T.bulk.U).^2)./(out.T.bulk.I);
out.T.bulk.AoP = ((1/2)*atan(out.T.bulk.U./out.T.bulk.Q));


end