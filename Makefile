netfilter-test: main.o netfilter.o iptables.o
	gcc -o netfilter-test main.o netfilter.o iptables.o -lnetfilter_queue

main.o: iptables_.h main.c
	gcc -c -o main.o main.c
	
netfilter.o: iptables_.h netfilter.c
	gcc -c -o netfilter.o netfilter.c

iptables.o: iptables_.h iptables.c
	gcc -c -o iptables.o iptables.c


