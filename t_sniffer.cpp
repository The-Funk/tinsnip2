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
        cout << "Interface name manually set to: " << intf << endl;
    }
    else {
        NetworkInterface iface = NetworkInterface::default_interface();
        this->intf = iface.name();
        cout << "Interface name set to default: " << iface.name() << endl;
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
    int count = 0;
    bool linkTypeKnown = false;
    sniffer.sniff_loop([&](Packet& packet) {
        if(this->OnOffSwitch && count < 10) {
            if (!linkTypeKnown && packet.pdu()->find_pdu<EthernetII>()) {
                cout << "This is an Ethernet interface." << endl;
                linkTypeKnown = true;
            }
            else if (!linkTypeKnown && packet.pdu()->find_pdu<Dot11>()) {
                cout << "This is an 802.11 wifi interface." << endl;
                linkTypeKnown = true;
            }

            if (packet.pdu()->find_pdu<IP>()) {
                // Just print timestamp's seconds and IP source address
                cout << "At: " << packet.timestamp().seconds() << " - " << packet.pdu()->rfind_pdu<IP>().src_addr()
                     << endl;
            }
            count++;
            return true;
        }
        return false;
    });
}

void t_sniffer::stopSniff() {
    this->OnOffSwitch = false;
}
