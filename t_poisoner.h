//
// Created by root on 3/4/18.
//

#ifndef TINSNIP_TPOISONER_H
#define TINSNIP_TPOISONER_H

#include <tins/tins.h>

class t_poisoner {

private:
    Tins::NetworkInterface hostAdapter;
    Tins::PacketSender sender;

public:
    t_poisoner(std::string hostAdapter);
    std::string getGatewayAddr();
    std::string getVictimAddrs();
    void poisonARP(std::string gw);
};


#endif //TINSNIP_TPOISONER_H
