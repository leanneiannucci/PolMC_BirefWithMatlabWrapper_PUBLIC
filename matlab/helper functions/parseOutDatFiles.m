function out = parseOutDatFiles(out)


    out.R.bulk.I = importIQUVdat("outI_R");
    out.R.bulk.Q = importIQUVdat("outQ_R");
    out.R.bulk.U = importIQUVdat("outU_R");
    out.R.bulk.V = importIQUVdat("outV_R");


    out.T.bulk.I = importIQUVdat("outI_T");
    out.T.bulk.Q = importIQUVdat("outQ_T");
    out.T.bulk.U = importIQUVdat("outU_T");
    out.T.bulk.V = importIQUVdat("outV_T");

end