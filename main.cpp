#include <iostream>
#include <vector>
#include <tclap/CmdLine.h>
#include "t_sniffer.h"

using namespace std;
using namespace TCLAP;

//Added const here and that got rid of a red mark later on when calling parse against the program
//argument list... not sure why or what effect this will have yet.
int main(int argc, const char* argv[]) {
    try {
        //Create argument parser
        CmdLine argp("For more help, you can find examples on the web at www.foo.bar", ' ', "0.1");

        //Add Value storing Arguments....

        //Sniffer interface. If not set, defaults to first interface with default gateway
        ValueArg<string> intArg("i", "intf", "Interface to use for sniffing", false, "default", "");
        //Target IP Range Arg
        ValueArg<string> rngArg("t", "target-range", "IP Range where traffic originates", true, "192.168.x.x", "");

        //Add Switch Arguments....

        //Set sniffer on/off, default value runs program with sniffer off
        SwitchArg sniffArg("s", "sniff-traffic", "Sniff target traffic", argp, false);
        //Set ARP poisoning on/off, default value runs program with Poisoning off
        SwitchArg arpsnArg("p", "poison-arp", "Poison target machine's ARP cache", argp, false);

        //Add ValueArgs to command line
        argp.add(intArg);

        //Parse remaining SwitchArgs
        argp.parse(argc, argv);

        if (sniffArg.getValue()) {
            t_sniffer sniffer;
            //Set sniffer interface
            sniffer.setIntf(intArg.getValue());
            sniffer.startSniff();
        }
    }
    catch (TCLAP::ArgException &e) {
        cerr << "Error: " << e.error() << " in Arg: " << e.argId() << endl;
    }
    return 0;
}
