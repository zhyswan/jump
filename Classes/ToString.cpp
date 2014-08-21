//
//  ToString.cpp
//  jump
//
//  Created by nova on 14-8-20.
//
//

#include "ToString.h"
#include <sstream>

using namespace std;

const char * ToString::fromBool(bool b){
    return b?"true":"false";
}

const char * ToString::from(double i){
    ostringstream ss;
    ss << i;
    return ss.str().data();
    
    //char cs[256];
    //sprintf(cs, "%.0f",i);
    //return cs;
}

