#include <iostream>
#include "tins/tins.h"
//#include "zdb/zdb.h"

using namespace Tins;
using namespace std;

int main ( int argc, char *argv[] ) {

    if (argc < 2) {
        cout << "No args" << endl;
    }
    else {
        cout << "You right" << endl;
    }

    //EthernetII eth;
    //IP *ip = new IP();
    //TCP *tcp = new TCP();
    // tcp is ip's inner pdu
    //ip->inner_pdu(tcp);
    // ip is eth's inner pdu
    //eth.inner_pdu(ip);

    return 0;
}