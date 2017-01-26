//
// Created by cole on 1/26/17.
//

#include "sniffer.h"
#include "tins/tins.h"

using namespace Tins;
using namespace std;

EthernetII eth = EthernetII() / IP() / TCP();
TCP *tcp = eth.find_pdu<TCP>();
IP *ip = eth.find_pdu<IP>();