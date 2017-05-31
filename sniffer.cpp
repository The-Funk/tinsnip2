//
// Created by cole on 1/26/17.
//

#include "sniffer.h"
#include "tins/tins.h"

using namespace Tins;
using namespace std;

EthernetII eth = EthernetII() / IP() / TCP();

//Create pointer for TCP frame PDU inside IP frame PDU inside Ethernet frame PDU
TCP *tcp = eth.find_pdu<TCP>();

//Create pointer for IP packet PDU inside Ethernet frame PDU
IP *ip = eth.find_pdu<IP>();

//Creates an IPV4 address
IPv4Address lo("127.0.0.1");

