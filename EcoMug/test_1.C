#include <stdio.h>
#include "EcoMug.h"
#include <math.h>
#include <fstream>



int main(){
    EcoMug gen;
    gen.SetUseSky();
    gen.SetSkySize({{10.,10.}});
    gen.SetSkyCenterPosition({{0.,0.,10.}});
    std::array<double,3> muon_pos;

    std::ofstream myFile("muon_data.txt");


    for(auto event =0;event<100; ++event){
        gen.Generate();
        muon_pos = gen.GetGenerationPosition();
        double muon_x = muon_pos[0];
        double muon_y = muon_pos[1];
        double muon_z = muon_pos[2];
        double muon_mom = gen.GetGenerationMomentum();
        double muon_theta = gen.GetGenerationTheta();
        double muon_phi = gen.GetGenerationPhi();
        double muon_charge = gen.GetCharge();
        myFile << muon_x << "\t" << muon_y << "\t" << muon_z << "\t" << muon_mom << "\t" << muon_theta << "\t" << muon_phi << "\t" << muon_charge << "\t" <<std::endl;
    }
    myFile.close();

    return 0;
}