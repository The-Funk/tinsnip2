//
// Created by The-Funk on 3/4/18.
//

#include "t_sniffer.h"

using namespace std;
using namespace Tins;


t_sniffer::t_sniffer(string intf) {
    //Set interface
    this->intf = intf;
    //Set immediate mode to keep things fast
    this->config.set_immediate_mode(true);
}

t_sniffer::t_sniffer(string intf, string target) {
    //Set interface
    this->intf = intf;
    //Set immediate mode to keep things fast
    this->config.set_immediate_mode(true);
    //Set ip src filter
    this->config.set_filter("ip src" + target);
}

t_sniffer::t_sniffer(string intf, string target, bool promisc) {
    //Set interface
    this->intf = intf;
    //Set immediate mode to keep things fast
    this->config.set_immediate_mode(true);
    //Set ip src filter
    this->config.set_filter("ip src" + target);
    //Set promiscuity on interface
    this->config.set_promisc_mode(promisc);
}

//Capture packets and run handlePacket template functor on each, sequentially, until functor returns false
void t_sniffer::startSniff() {
    this->OnOffSwitch = true;
    Sniffer sniffer(this->intf, this->config);
    sniffer.sniff_loop(make_sniffer_handler(this, &t_sniffer::handlePacket));
}

void t_sniffer::stopSniff() {
    this->OnOffSwitch = false;
}

bool t_sniffer::handlePacket(PDU& packet){
    if(this->OnOffSwitch){
        //What to do if we're supposed to be sniffing
        //Open database connection
    }
    else{
        return false;
    }
    //Default condition is to continue sniffing
    return true;
}