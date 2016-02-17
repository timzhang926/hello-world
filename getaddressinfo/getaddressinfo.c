#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>

#ifndef   NI_MAXHOST
#define   NI_MAXHOST 1025
#endif

int main(void)
{
    struct addrinfo* result;
    struct addrinfo* res;
    int error;

    /* resolve the domain name into a list of addresses */
    error = getaddrinfo("www.google.com", NULL, NULL, &result);
    if (error != 0) {   
        if (error == EAI_SYSTEM) {
            perror("getaddrinfo");
        } else {
            fprintf(stderr, "error in getaddrinfo: %s\n", gai_strerror(error));
        }   
        exit(EXIT_FAILURE);
    }   

    /* loop over all returned results and do inverse lookup */
    for (res = result; res != NULL; res = res->ai_next) {   
        char hostname[NI_MAXHOST];
        error = getnameinfo(res->ai_addr, res->ai_addrlen, hostname, NI_MAXHOST, NULL, 0, 0); 
        if (error != 0) {
            fprintf(stderr, "error in getnameinfo: %s\n", gai_strerror(error));
            continue;
        }
        if (*hostname != '\0')
            printf("hostname: %s, ai_flags: %d, ai_family: %d, ai_socktype: %d, ai_protocol: %d, ai_canonname: %s, sa_data: %s\n", hostname, res->ai_flags, res->ai_family, res->ai_socktype, res->ai_protocol, res->ai_canonname, res->ai_addr->sa_data);
    }   

    freeaddrinfo(result);
    return 0;
}
