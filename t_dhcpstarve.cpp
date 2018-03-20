//
// Created by The-Funk on 3/13/18.
//

#include "t_dhcpstarve.h"
#include "viface/viface.hpp"

//#include "sdbusplus"
#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <time.h>
#include <array>
#include <cmath>
#include <chrono>
#include <thread>

using namespace std;
using namespace Tins;

t_dhcpstarve::t_dhcpstarve(string hostAdapter) {
    this->hostAdapter = NetworkInterface(hostAdapter);                  //Create a network adapter
}

void t_dhcpstarve::autogenVirtIfaces() {
    srand(time(0));                                                     //Seed random number generator
    string mask = this->hostAdapter.ipv4_mask().to_string();            //Get netmask
    istringstream ss(mask);                                             //Load netmask into istringstream
    string token;                                                       //Create token for octects
    int bin = 0, hostbits = 0, numIfaces = 0;                           //Utility ints!
    char hex[16] = {'1','2','3','4','5','6','7','8',
                    '9','0','A','B','C','D','E','F'};                   //Create array for storing hex values

    while(getline(ss, token, '.')) {                                    //Iterate through mask using the iss, split by .
        int octet = stoi(token);                                        //Use stoi to convert octet string tokens into integers
        if (octet == 0) {                                               //If the octet is all host bits
            hostbits += 8;                                              //Add 8
        }
        else {                                                          //Else do math
            while (octet > 0) {                                         //Use nested while to add to host bit count
                bin = octet % 2;                                        //Is there a remainder when dividing ints?
                if (bin == 0) {                                         //If no, that's a zero!
                    hostbits++;                                         //And thus a host bit :)
                }
                octet /= 2;                                             //Divide by 2 for real, remember, ints will round!
            }
        }
    }

    numIfaces = (pow(2, hostbits) - 2);                                 //We should now have the number of host bits, let's do the math!

    array<string, numIfaces> macs;

    for (int i=1; i <= numIfaces; i++) {                                //
        viface::VIface iface("viface%d");                               //
        iface.setMAC("66:23:2d:28:c6:84");                              //
    }
}

string * t_dhcpstarve::autogenMACs(int numIfaces){
    ifstream f;
    streampos end;
    f.open("macvendors", ifstream::in|ifstream::binary);
    f.seekg (0, ios::end);
    end = f.tellg();



}

    // Create interface
    //
    // Configure interface
    //


    // Bring-up interface
    //iface.up();

    //HERE'S THE DEAL
    //You need to get a picture of the network, figure out the netmask/bcast/etc from the interface selected
    //Learn more about DHCP, figure out what message a completely starved DHCP server would send
    //Create tap interfaces using libviface based on an assumed number of available addresses (determined by netmask)
    //Assign each tap interface a legit looking fake MAC address
    //Use sdbusplus to interact with systemd-networkd or network-manager or whatever and add a new bridge interface
    //Ideally temporarily disable overly complex network managers and just use systemd-networkd
    //THEN restart networking with your tap interfaces connected to the bridge interface
    //Allow tap interfaces to request addresses, or run dhcpdiscover process manually for each interface on timed delay

    //THIS WORKS ON ETHERNET INTERFACES

    //NOW THE PROBLEM
    //Wifi interfaces don't like to be bridged
    //Ideally each of our fake interfaces should have its own MAC address
    //WiFi AP's don't like multiple MACs on the same interface because only one can associate with the station at a time
    //There are ways around this, however none of them play nicely with DHCP
    //So for now we have to make a sacrifice and not use tap interfaces when trying to starve a wifi network

    //string cmdstring = "dhcpcd " + iface.getName();
    //system(cmdstring.c_str());

