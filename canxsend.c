#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/* Network specific header files */
#include <net/if.h>
#include <sys/ioctl.h>
#include <sys/socket.h>

#include "x/can/lib/can.h"
#include "x/can/raw.h"
#include "x/can/lib.h"

int main(int argc, char **argv)
{
    int s; /* raw socket for CAN */
    int required_mtu;
    int mtu;
    int enable_canfd = 1;
    
    /* CAN induces vars */
    struct sockaddr_can addr;
    struct canfd_frame frame;
    struct ifreq ifr;

    /* empty args */
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <device> <can_frame>.\n", argv[0]);
        return 1;
    }

    /* parse CAN frame */
    required_mtu = parse_canframe(argv[2], &frame);
    if (!required_mtu) {
        fprintf(stderr, "\nWrong CAN-frame format! You ain't a hacker.\n\n");
    }

}
