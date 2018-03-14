//
// Created by The-Funk on 3/13/18.
//

#include "t_dhcpstarve.h"
#include "viface/viface.hpp"

using namespace std;

t_dhcpstarve::t_dhcpstarve() {
    // Create interface
    viface::VIface iface("viface%d");

// Configure interface
    iface.setMAC("66:23:2d:28:c6:84");
    // Bring-up interface
    iface.up();
    string cmdstring = "dhcpcd " + iface.getName();
    system(cmdstring.c_str());



}