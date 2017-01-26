#include <iostream>
#include "tins/tins.h"
//#include "zdb/zdb.h"
#include <string>
#include <vector>
#include "optionparser.h"

using namespace Tins;
using namespace std;

enum  optionIndex { UNKNOWN, HELP, GWAY, TRGT, TGTRNG };
const option::Descriptor usage[] =
        {
                {UNKNOWN, 0, "", "",option::Arg::None, "USAGE: example [options]\n\n"
                                                               "Options:" },
                {HELP, 0, "h", "help",option::Arg::None, "  --help  \tPrint usage and exit." },
                {GWAY, 1, "g", "gateway",option::Arg::Optional, "  --gateway, -g  \tSet the gateway address." },
                {TRGT, 2, "t", "target",option::Arg::Optional, "  --target, -t  \tSet the target machine address." },
                {TGTRNG, 2, "r", "range",option::Arg::Optional, "  --range, -r  \tSet a range of targets." },
                {0,0,0,0,0,0}
        };

int main(int argc, char* argv[])
{
    argc-=(argc>0); argv+=(argc>0); // skip program name argv[0] if present
    option::Stats  stats(usage, argc, argv);
    std::vector<option::Option> options(stats.options_max);
    std::vector<option::Option> buffer(stats.buffer_max);
    option::Parser parse(usage, argc, argv, &options[0], &buffer[0]);

    if (parse.error())
        return 1;

    if (options[HELP] || argc == 0) {
        option::printUsage(std::cout, usage);
        return 0;
    }

    if (options[GWAY]){
        cout << "Hello" << endl;
    }

    if (options[TRGT]){
        cout << "Hey" << endl;
    }

    cout << parse.optionsCount() << endl;

    for (option::Option* opt = options[UNKNOWN]; opt; opt = opt->next())
        std::cout << "Unknown option: " << std::string(opt->name,opt->namelen) << "\n";

    for (int i = 0; i < parse.nonOptionsCount(); ++i)
        std::cout << "Non-option #" << i << ": " << parse.nonOption(i) << "\n";

    return 0;
}

    //EthernetII eth;
    //IP *ip = new IP();
    //TCP *tcp = new TCP();
    // tcp is ip's inner pdu
    //ip->inner_pdu(tcp);
    // ip is eth's inner pdu
    //eth.inner_pdu(ip);
