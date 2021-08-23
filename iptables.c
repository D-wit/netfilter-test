#include<stdio.h>
#include<stdlib.h>

void iptables()
{
    system("iptables -F");
    system("iptables -A OUTPUT -j NFQUEUE --queue-num 0");
    system("iptables -A INPUT -j NFQUEUE --queue-num 0");
    system("iptables -A OUTPUT -p udp -j DROP");
    system("iptables -A INPUT -p udp -j DROP");
}
