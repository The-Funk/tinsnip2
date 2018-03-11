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

    Tins::SnifferConfiguration config;                //Universal configuration object
    std::string intf;                                 //Interface to listen on
    bool OnOffSwitch;                                 //Create an on/off condition for handlePacket to check

//Public data members
public:
    t_sniffer();                                      //Default constructor, use default intf
    void setIntf(std::string intf);                   //
    void setTarget(std::string target);               //
    void setPromisc(bool promisc);                    //
    void startSniff();                                //Start the sniffing session
    void stopSniff();                                 //Stop the sniffing session

};


#endif //TINSNIP_TSNIFFER_H
