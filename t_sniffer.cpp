//
// Created by The-Funk on 3/4/18.
//

#include "t_sniffer.h"

using namespace std;
using namespace Tins;

t_sniffer::t_sniffer() {
    //Set immediate mode whenever creating a new sniffer object to keep things fast
    this->config().set_immediate_mode(true);
}


t_sniffer::t_sniffer(string target, string intf) {
    //Set immediate mode whenever creating a new sniffer object to keep things fast
    this->config().set_immediate_mode(true);
    this->config().set_promisc_mode(true);
    this->config().set_filter("ip src" + target);
}

//Capture packets and run handlePacket template functor on each, sequentially, until functor returns false
void t_sniffer::startSniff() {
    this->OnOffSwitch = true;
    this->sniffer().sniff_loop(handlePacket);
}

void t_sniffer::stopSniff() {
    this->OnOffSwitch = false;
}

bool t_sniffer::handlePacket(Packet& packet){
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