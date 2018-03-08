# tinsnip2

This tool is intended to be used as an all purpose network monitor and basic MitM tool similar to Ettercap.

Ultimately the tool will implement connection pooling via libzdb in order to interface with a database.

It is the intention of the developer to start with SQLite and then evolve from there.

The following features have been decided upon and need implemented:

- Basic Network Sniffing with simple filters
- Packet logging via SQLite
- Report writing via reportpp
- ARP Spoofing/Poisoning
- DNS Spoofing/Poisoning
- DHCP Starvation