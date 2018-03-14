//
// Created by The-Funk on 3/13/18.
//

#ifndef TINSNIP_T_DHCPSTARVE_H
#define TINSNIP_T_DHCPSTARVE_H

#include "viface/viface.hpp"

class t_dhcpstarve {
private:
    int numHosts;
    int delay;

public:
    t_dhcpstarve();
    void setSubnetSize();
    void setDelay();
    void starveNetwork();

};


#endif //TINSNIP_T_DHCPSTARVE_H
