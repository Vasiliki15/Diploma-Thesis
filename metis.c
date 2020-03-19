#include <cstddef> /* NULL */
#include <metis.h>
#include <iostream> 
#include <stdio.h>

// Install metis from:
// http://glaros.dtc.umn.edu/gkhome/fetch/sw/metis/metis-5.1.0.tar.gz

// Build with
// g++ metis.cc -lmetis

int main(){

    idx_t nVertices = 288;
    idx_t nEdges    = 617;
    idx_t nWeights  = 1;
    idx_t nParts    = 24;
    //idx_t options[17]={1};
  
    idx_t objval;
    idx_t part[nVertices];


    // Indexes of starting points in adjacent array
    idx_t xadj[nVertices+1] = {0,2,6,11,15,20,24,29,33,38,42,47,51,56,60,65,67,69,74,79,84,89,94,99,104,106,108,113,118,123,128,
133,138,143,145,147,152,157,162,167,172,177,182,184,186,191,196,201,206,211,216,221,223,225,230,
235,240,245,250,255,260,262,264,269,274,279,284,289,294,299,301,303,308,313,318,323,328,333,338,
340,342,347,352,357,362,367,372,377,379,381,386,391,396,401,406,411,416,418,420,425,430,435,440,
445,450,455,457,459,464,469,474,479,484,489,494,496,498,503,508,513,518,523,528,533,535,537,542,
547,552,557,562,567,572,574,576,581,586,591,596,601,606,611,613,615,620,625,630,635,640,645,650,
652,654,659,664,669,674,679,684,689,691,693,698,703,708,713,718,723,728,730,732,737,742,747,752,
757,762,767,769,771,776,781,786,791,796,801,806,808,810,815,820,825,830,835,840,845,847,849,854,
859,864,869,874,879,884,886,888,893,898,903,908,913,918,923,925,927,932,937,942,947,952,957,962,
964,966,971,976,981,986,991,996,1001,1003,1005,1010,1015,1020,1025,1030,1035,1040,1042,1044,1049,
1054,1059,1064,1069,1074,1079,1081,1083,1088,1093,1098,1103,1108,1113,1118,1120,1122,1127,1132,
1137,1142,1147,1152,1157,1159,1161,1166,1171,1176,1181,1186,1191,1196,1198,1200,1204,1208,1212,
1216,1220,1224,1228,1230,1232,1234};



    // Adjacent vertices in consecutive index order
    idx_t adjncy[2 * nEdges] = {0,1,0,1,2,3,1,2,4,16,17,1,3,4,5,2,3,4,6,18,3,5,6,7,4,5,6,8,19,5,7,8,9,6,7,8,10,20,7,9,10,11,8,9,
10,12,21,9,11,12,13,10,11,12,14,22,11,13,14,15,12,13,14,23,24,13,15,2,16,2,17,18,25,26,4,17,18,19,
27,6,18,19,20,28,8,19,20,21,29,10,20,21,22,30,12,21,22,23,31,14,22,23,32,33,14,24,17,25,17,26,27,
34,35,18,26,27,28,36,19,27,28,29,37,20,28,29,30,38,21,29,30,31,39,22,30,31,32,40,23,31,32,41,42,
23,33,26,34,26,35,36,43,44,27,35,36,37,45,28,36,37,38,46,29,37,38,39,47,30,38,39,40,48,31,39,40,
41,49,32,40,41,50,51,32,42,35,43,35,44,45,52,53,36,44,45,46,54,37,45,46,47,55,38,46,47,48,56,39,
47,48,49,57,40,48,49,50,58,41,49,50,59,60,41,51,44,52,44,53,54,61,62,45,53,54,55,63,46,54,55,56,
64,47,55,56,57,65,48,56,57,58,66,49,57,58,59,67,50,58,59,68,69,50,60,53,61,53,62,63,70,71,54,62,
63,64,72,55,63,64,65,73,56,64,65,66,74,57,65,66,67,75,58,66,67,68,76,59,67,68,77,78,59,69,62,70,
62,71,72,79,80,63,71,72,73,81,64,72,73,74,82,65,73,74,75,83,66,74,75,76,84,67,75,76,77,85,68,76,
77,86,87,68,78,71,79,71,80,81,88,89,72,80,81,82,90,73,81,82,83,91,74,82,83,84,92,75,83,84,85,93,
76,84,85,86,94,77,85,86,95,96,77,87,80,88,80,89,90,97,98,81,89,90,91,99,82,90,91,92,100,83,91,92,
93,101,84,92,93,94,102,85,93,94,95,103,86,94,95,104,105,86,96,89,97,89,98,99,106,107,90,98,99,100,
108,91,99,100,101,109,92,100,101,102,110,93,101,102,103,111,94,102,103,104,112,95,103,104,113,114,
95,105,98,106,98,107,108,115,116,99,107,108,109,117,100,108,109,110,118,101,109,110,111,119,102,
110,111,112,120,103,111,112,113,121,104,112,113,122,123,104,114,107,115,107,116,117,124,125,108,
116,117,118,126,109,117,118,119,127,110,118,119,120,128,111,119,120,121,129,112,120,121,122,130,113,
121,122,131,132,113,123,116,124,116,125,126,133,134,117,125,126,127,135,118,126,127,128,136,119,127,128,
129,137,120,128,129,130,138,121,129,130,131,139,122,130,131,140,141,122,132,125,133,125,134,135,142,143,126,
134,135,136,144,127,135,136,137,145,128,136,137,138,146,129,137,138,139,147,130,138,139,140,148,131,139,140,
149,150,131,141,134,142,134,143,144,151,152,135,143,144,145,153,136,144,145,146,154,137,145,146,147,155,138,146,
147,148,156,139,147,148,149,157,140,148,149,158,159,140,150,143,151,143,152,153,160,161,144,152,153,154,162,145,153,
154,155,163,146,154,155,156,164,147,155,156,157,165,148,156,157,158,166,149,157,158,167,168,149,159,152,160,152,161,162,169,170,153,161,162,163,171,154,162,163,164,172,155,163,164,165,173,156,164,
165,166,174,157,165,166,167,175,158,166,167,176,177,158,168,161,169,161,170,171,178,179,162,170,171,172,180,163,171,172,173,181,164,172,173,174,182,165,173,174,175,183,166,174,175,176,184,167,175,176,
185,186,167,177,170,178,170,179,180,187,188,171,179,180,181,189,172,180,181,182,190,173,181,182,183,191,174,182,183,184,192,175,183,184,185,193,176,184,185,194,195,176,186,179,187,179,188,189,196,197,
180,188,189,190,198,181,189,190,191,199,182,190,191,192,200,183,191,192,193,201,184,192,193,194,202,185,193,194,203,204,185,195,188,196,188,197,198,205,206,189,197,198,199,207,190,198,199,200,208,191,
199,200,201,209,192,200,201,202,210,193,201,202,203,211,194,202,203,212,213,194,204,197,205,197,206,207,214,215,198,206,207,208,216,199,207,208,209,217,200,208,209,210,218,201,209,210,211,219,202,210,
211,212,220,203,211,212,221,222,203,213,206,214,206,215,216,223,224,207,215,216,217,225,208,216,217,218,226,209,217,218,219,227,210,218,219,220,228,211,219,220,221,229,212,220,221,230,231,212,222,215,
223,215,224,225,232,233,216,224,225,226,234,217,225,226,227,235,218,226,227,228,236,219,227,228,229,237,220,228,229,230,238,221,229,230,239,240,221,231,224,232,224,233,234,241,242,225,233,234,235,243,
226,234,235,236,244,227,235,236,237,245,228,236,237,238,246,229,237,238,239,247,230,238,239,248,249,230,240,233,241,233,242,243,250,251,234,242,243,244,252,235,243,244,245,253,236,244,245,246,254,237,
245,246,247,255,238,246,247,248,256,239,247,248,257,258,239,249,242,250,242,251,252,259,260,243,251,252,253,261,244,252,253,254,262,245,253,254,255,263,246,254,255,256,264,247,255,256,257,265,248,256,
257,266,267,248,258,251,259,251,260,261,268,269,252,260,261,262,270,253,261,262,263,271,254,262,263,264,272,255,263,264,265,273,256,264,265,266,274,257,265,266,275,276,257,267,260,268,260,269,270,277,
278,261,269,270,271,279,262,270,271,272,280,263,271,272,273,281,264,272,273,274,282,265,273,274,275,283,266,274,275,284,285,266,276,269,277,269,278,279,286,270,278,279,280,271,279,280,281,272,280,281,
282,273,281,282,283,274,282,283,284,275,283,284,287,275,285,278,286,284,287};

    // Weights of vertices
    // if all weights are equal then can be set to NULL
    idx_t vwgt[nVertices * nWeights];
    
    
    //int ret = METIS_PartGraphRecursive(&nVertices,& nWeights, xadj, adjncy,
    				       //NULL, NULL, NULL, &nParts, NULL,
    				       //NULL, NULL, &objval, part);

    int ret = METIS_PartGraphKway(&nVertices,& nWeights, xadj, adjncy,
				       NULL, NULL, NULL, &nParts, NULL,
				       NULL, NULL, &objval, part);

    std::cout << ret << std::endl;
    
    for(unsigned part_i = 0; part_i < nVertices; part_i++){
	std::cout << part[part_i] << std::endl;
    }

    //part_i << " " << 
    std::cout << objval << std::endl;
    return 0;
}
