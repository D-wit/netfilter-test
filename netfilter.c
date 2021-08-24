#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <libnet.h>

int netfilter(unsigned char* buffer, char* host_name, int host_len)
{
    struct libnet_ipv4_hdr* ip;
    struct libnet_tcp_hdr* tcp;
    
    ip = (struct libnet_ipv4_hdr*)buffer;    
    buffer += (ip->ip_hl) * 4;

    tcp = (struct libnet_tcp_hdr*)buffer;
    buffer += (tcp->th_off) * 4;
    
    char* text;
    text = malloc(sizeof(char)*(host_len+1));
    int j = 0, count = 0;
    
    if(ntohs(tcp->th_dport) == 80){
        for(int i = 0; i < ntohs(ip->ip_len) - ((ip->ip_hl + tcp->th_off)*4); i++){
            if(buffer[i]=='H' && buffer[i+1]=='o' && buffer[i+2]=='s' && buffer[i+3]=='t'){
                printf("Host!!!!!!!!!!!!\n");
                
                while(1){
                	if(buffer[i+6] == 0x0d || buffer[i+6] == 0x0d){
                		break;
			}
			if(j > host_len + 100) break;
              	
                	*(text+j) = buffer[i+6];

                	
                	++count;
                	i++;
                	j++;
                }
            }
        }
    }
    if(count == host_len && strcmp(text,host_name)==0){
    	printf("너 차단\n");
    	free(text);
    	return 0;
    }
    else{
    	free(text);
    	return 1;
    }
}
