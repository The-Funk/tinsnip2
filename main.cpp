#include <iostream>
#include "zdb/zdb.h"
#include <string>
#include <vector>
#include <tclap/CmdLine.h>

using namespace std;
using namespace TCLAP;

int main(int argc, char* argv[]) {
    try {
        //Create argument parser
        CmdLine argp("For more help, you can find examples on the web at www.foo.bar", ' ', "0.1");

        //Add Value storing Arguments....

        //Source IP Arg
        ValueArg<string> srcArg("s","src-ip","IP Address where traffic originates",true,"192.168.x.x","");
        //Source IP Range Arg
        ValueArg<string> rngArg("r","src-range","IP Range where traffic originates",true,"192.168.x.x","");
        //Host IP Arg
        ValueArg<std::string> hostArg("h","host-ip","Address of host machine",true,"192.168.x.x","");

        //Add Switch Arguments....

        //Set sniffer on/off, default value runs program with sniffer off
        SwitchArg sniffArg("s","sniff-traffic","Print name backwards", argp, false);
        //Set ARP poisoning on/off, default value runs program with Poisoning off
        SwitchArg arpsnArg("p","poison-arp","Poison target machine's ARP cache", argp, false);
        
        argp.parse(argc,argv);

        if (sniffArg.getValue()){
            cout << "Yep! It's parsin!" << endl;
        }
    }
    catch (TCLAP::ArgException &e) {
        cerr << "Error: " << e.error() << " in Arg: " << e.argId() << endl;
    }
    return 0;
}
