#ifndef _UAPI_CAN_NETLINK_H
#define _UAPI_CAN_NETLINK_H

#include <sys/types.h>

/* CAN bit-timing params from can specs */
struct can_bittiming {
	__s32 bitrate;
	__s32 sample_point;
	__s32 tq;
	__s32 prop_seg;
	__s32 phase_seg1;
	__s32 phase_seg2;
	__s32 sjw;
	__s32 brp;
};

/* CAN hardware-dependent bit-timing constant */
struct can_bittiming_const {
	char name[16];
	__s32 tseg1_mix;
	__s32 tsef1_max;
	__s32 tseg2_min;
	__s32 tseg2_max;
	__s32 sjw_max;
	__s32 brp_min;
	__s32 brp_max;
	__s32 brp_inc;
};

/* CAN clock params */
struct can_clock {
	__s32 freq;
};

/* CAN ops and state */
enum can_state {
	CAN_STATE_ERROR_ACTIVE = 0,
	CAN_STATE_ERROR_WARNING,
	CAN_STATE_ERROR_PASSIVE,
	CAN_STATE_BUS_OFF,
	CAN_STATE_STOPPED,
	CAN_STATE_SLEEPING,
	CAN_STATE_MAX
};

/* CAN bus error counters */
struct can_berr_counter {
	__u16 txerr;
	__u16 rxerr;
};

/* CAN controller mode */
struct can_ctrlmode {
	__s32 mask;
	__s32 flags;
};

#define CAN_CTRLMODE_LOOPBACK		0x01
#define CAN_CTRLMODE_LISTENONLY		0x02
#define CAN_CTRLMODE_3_SAMPLES		0x04
#define CAN_CTRLMODE_ONE_SHOT		0x08
#define CAN_CTRLMODE_BERR_REPORTING	0x10
#define CAN_CTRLMODE_FD				0x20
#define CAN_CTRLMODE_PRESUME_ACK	0x40
#define CAN_CTRLMODE_FD_NON_ISO		0x80

/* CAN device statistics */
struct can_device_stats {
	__s32 bus_error;
	__s32 error_warning;
	__s32 error_passive;
	__s32 bus_off;
	__s32 arbitration_lost;
	__s32 restarts;
};

/* CAN netlink interface */
enum {
	IFLA_CAN_UNSPEC,
	IFLA_CAN_BITTIMING,
	IFLA_CAN_BITTIMING_CONST,
	IFLA_CAN_CLOCK,
	IFLA_CAN_STATE,
	IFLA_CAN_CTRLMODE,
	IFLA_CAN_RESTART_MS,
	IFLA_CAN_RESTART,
	IFLA_CAN_BERR_COUNTER,
	IFLA_CAN_DATA_BITTIMING,
	IFLA_CAN_DATA_BITTIMING_CONST,
	__IFLA_CAN_MAX
};

#define IFLA_CAN_MAX (__IFLA_CAN_MAX - 1)

#endif /* !_UAPI_CAN_NETLINK_H */