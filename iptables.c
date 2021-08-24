#include<stdio.h>
#include<stdlib.h>

void iptables()
{
    system("iptables -F");
    system("iptables -A OUTPUT -j NFQUEUE --queue-num 0");
    system("iptables -A INPUT -j NFQUEUE --queue-num 0");
}
