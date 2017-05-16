#include <iostream>
#include "zdb/zdb.h"
#include <string>
#include <vector>
#include "optionparser.h"

using namespace std;

struct Arg: public option::Arg
{
    static void printError(const char* msg1, const option::Option& opt, const char* msg2)
    {
        fprintf(stderr, "%s", msg1);
        fwrite(opt.name, opt.namelen, 1, stderr);
        fprintf(stderr, "%s", msg2);
    }

    static option::ArgStatus Unknown(const option::Option& option, bool msg)
    {
        if (msg) printError("Unknown option '", option, "'\n");
        return option::ARG_ILLEGAL;
    }

    static option::ArgStatus Required(const option::Option& option, bool msg)
    {
        if (option.arg != 0)
            return option::ARG_OK;

        if (msg) printError("Option '", option, "' requires an argument\n");
        return option::ARG_ILLEGAL;
    }

    static option::ArgStatus NonEmpty(const option::Option& option, bool msg)
    {
        if (option.arg != 0 && option.arg[0] != 0)
            return option::ARG_OK;

        if (msg) printError("Option '", option, "' requires a non-empty argument\n");
        return option::ARG_ILLEGAL;
    }

    static option::ArgStatus Numeric(const option::Option& option, bool msg)
    {
        char* endptr = 0;
        if (option.arg != 0 && strtol(option.arg, &endptr, 10)){};
        if (endptr != option.arg && *endptr == 0)
            return option::ARG_OK;

        if (msg) printError("Option '", option, "' requires a numeric argument\n");
        return option::ARG_ILLEGAL;
    }
};

enum  optionIndex { UNKNOWN, HELP, GWAY, TRGT, SNF, PSN };
const option::Descriptor usage[] =
        {
                {UNKNOWN, 0, "", "",Arg::None, "USAGE: example [options]\n\n"
                                                               "Options:" },
                {HELP, 0, "h", "help",Arg::None, "  --help  \tPrint usage and exit." },
                {GWAY, 1, "g", "gateway",Arg::Required, "  --gateway, -g  \tSet the gateway address." },
                {TRGT, 2, "t", "target",Arg::Optional, "  --target, -t  \tSet the target machine address." },
                {SNF, 3, "s", "sniff",Arg::None, "  --sniff, -s  \tSet program to sniff traffic only." },
                {PSN, 3, "p", "poison",Arg::None, "  --poison, -p  \tSet program to perform ARP poisoning." },
                {0,0,0,0,0,0}
        };

int main(int argc, char* argv[])
{
    argc-=(argc>0); argv+=(argc>0); // skip program name argv[0] if present
    option::Stats  stats(usage, argc, argv);
    vector<option::Option> options(stats.options_max);
    vector<option::Option> buffer(stats.buffer_max);
    option::Parser parse(usage, argc, argv, &options[0], &buffer[0]);

    for (int i = 0; i < parse.optionsCount(); ++i)
    {
        option::Option& opt = buffer[i];
        switch (opt.index())
        {
            case HELP:
                option::printUsage(cout, usage);
                break;
            case GWAY:
                if (opt.arg)
                    cout << "Found arg" << opt.arg << endl;
                else
                    cout << "Argument not found." << endl;
                break;
            case UNKNOWN:
                // not possible because Arg::Unknown returns ARG_ILLEGAL
                // which aborts the parse with an error
                break;
        }
    }
    if (parse.error())
        return 1;

    for (option::Option* opt = options[UNKNOWN]; opt; opt = opt->next())
        std::cout << "Unknown option: " << std::string(opt->name,opt->namelen) << "\n";

    return 0;
}
