//
// Created by The-Funk on 3/13/18.
//

#ifndef TINSNIP_T_DHCPSTARVE_H
#define TINSNIP_T_DHCPSTARVE_H

#include "viface/viface.hpp"
#include <tins/tins.h>

class t_dhcpstarve {
private:
    Tins::NetworkInterface hostAdapter;
    int numHosts;
    int delay;

public:
    t_dhcpstarve(std::string hostAdapter);
    void autogenVirtIfaces();
    std::string * autogenMACs(int numIfaces);
    void setDelay();
    void starveNetwork();

};


#endif //TINSNIP_T_DHCPSTARVE_H
