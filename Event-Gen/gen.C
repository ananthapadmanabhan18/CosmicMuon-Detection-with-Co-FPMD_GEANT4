#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "EcoMug.h"

int main(){
    
    std::array<double, 3> pos = {0,0,0};

    EcoMug mug;
    mug.SetUseSky();
    mug.SetSkyCenterPosition(pos);

    return 0;

}