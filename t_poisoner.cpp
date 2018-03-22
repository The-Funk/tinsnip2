//
// Created by root on 3/4/18.
//

#include "t_poisoner.h"

using namespace std;
using namespace Tins;

t_poisoner::t_poisoner(string hostAdapter){
    this->hostAdapter = NetworkInterface(hostAdapter);                  //Create a network adapter
}
