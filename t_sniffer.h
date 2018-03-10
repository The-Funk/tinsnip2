//
// Created by cole on 3/4/18.
//

#ifndef TINSNIP_TSNIFFER_H
#define TINSNIP_TSNIFFER_H

#include <string>
#include <tins/tins.h>

class t_sniffer {

//Data members unique to/only accessible to the sniffer object
private:

    Tins::SnifferConfiguration config;    //Universal configuration object
    std::string target;                   //Target IP or Range for sniffer
    std::string intf;                     //Interface to listen on
    bool promisc;                         //Specify whether interface should listen in promisc mode
    bool OnOffSwitch;                     //Create an on/off condition for handlePacket to check

//Public data members
public:
    t_sniffer(std::string intf);                                    //Overloaded constructor w/ intf
    t_sniffer(std::string intf, std::string target);                //Overloaded constructor w/ intf & target
    t_sniffer(std::string intf, std::string target, bool promisc);  //Overloaded constructor w/ intf, target, & promisc
    void startSniff();                                              //Start the sniffing session
    void stopSniff();                                               //Stop the sniffing session
    bool handlePacket(Tins::PDU& packet);                           //Determines what to do during session

};


#endif //TINSNIP_TSNIFFER_H
