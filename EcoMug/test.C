#include <stdio.h>
#include "EcoMug.h"



int main() {

    EcoMug gen;
    gen.SetUseSky();
    gen.SetSkySize({{10.,10.}});
    gen.SetSkyCenterPosition({{0.,0.,0.}});
    std::array<double,3> muon_pos;

    // FILE *file = fopen("/home/apmnair18/Documents/GitHub/Geant4_ROOT/Geant4/Working Folder/gun_data.txt", "w");
    FILE *file = fopen("p_data.txt", "w");
    if (file == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }


    for(auto event =0;event<100000; ++event){
        gen.Generate();
        muon_pos = gen.GetGenerationPosition();
        double muon_x = muon_pos[0];
        double muon_y = muon_pos[1];
        double muon_z = muon_pos[2];
        double muon_mom = gen.GetGenerationMomentum();
        double muon_theta = gen.GetGenerationTheta();
        double muon_phi = gen.GetGenerationPhi();
        double muon_charge = gen.GetCharge();
        //fprintf(file, "%lf\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf\n", muon_x, muon_y, muon_z, muon_mom, muon_theta, muon_phi, muon_charge);
        fprintf(file, "%lf\n",muon_mom);
    }
    fclose(file);
    return 0;
}


