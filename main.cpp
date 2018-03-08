#include <iostream>
#include <string>
#include <vector>
#include <tclap/CmdLine.h>

using namespace std;
using namespace TCLAP;

//Added const here and that got rid of a red mark later on when calling parse against the program
//argument list... not sure why or what effect this will have yet.
int main(int argc, const char* argv[]) {
    try {
        //Create argument parser
        CmdLine argp("For more help, you can find examples on the web at www.foo.bar", ' ', "0.1");

        //Add Value storing Arguments....

        //Source IP Arg
        ValueArg<string> srcArg("s","src-ip","IP Address where traffic originates",true,"192.168.x.x","");
        //Source IP Range Arg
        ValueArg<string> rngArg("r","src-range","IP Range where traffic originates",true,"192.168.x.x","");
        //Host IP Arg
        ValueArg<string> hostArg("h","host-ip","Address of host machine",true,"192.168.x.x","");

        //Add Switch Arguments....

        //Set sniffer on/off, default value runs program with sniffer off
        SwitchArg sniffArg("s","sniff-traffic","Sniff target traffic", argp, false);
        //Set ARP poisoning on/off, default value runs program with Poisoning off
        SwitchArg arpsnArg("p","poison-arp","Poison target machine's ARP cache", argp, false);

        argp.parse(argc,argv);

        if (sniffArg.getValue()){
            cout << "Yep! It's sniffin!" << endl;
        }
    }
    catch (TCLAP::ArgException &e) {
        cerr << "Error: " << e.error() << " in Arg: " << e.argId() << endl;
    }
    return 0;
}
