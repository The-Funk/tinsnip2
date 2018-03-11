//
// Created by The-Funk on 3/4/18.
//

#include "t_sniffer.h"
#include <iostream>

using namespace std;
using namespace Tins;


t_sniffer::t_sniffer() {

    //Set immediate mode to keep things fast
    this->config.set_immediate_mode(true);

}

//Set interface, if none set use default
void t_sniffer::setIntf(string intf) {
    if(intf != "default") {
        this->intf = intf;
        cout << "Interface name manually set to: " << intf;
    }
    else {
        NetworkInterface iface = NetworkInterface::default_interface();
        this->intf = iface.name();
        cout << "Interface name set to default: " << iface.name();
    }
}

void t_sniffer::setTarget(string target) {
    //Set ip src filter
    this->config.set_filter("ip src" + target);
}

void t_sniffer::setPromisc(bool promisc) {
    //Set promiscuity on interface
    this->config.set_promisc_mode(promisc);
}


//Capture packets and run handlePacket template functor on each, sequentially, until functor returns false
void t_sniffer::startSniff() {
    this->OnOffSwitch = true;
    Sniffer sniffer(this->intf, this->config);
    sniffer.sniff_loop([&](Packet& packet) {
        if(this->OnOffSwitch){

            return true;
        }
        return false;
    });
}

void t_sniffer::stopSniff() {
    this->OnOffSwitch = false;
}
