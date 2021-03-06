/**
 * @file transport.c
 * @brief TODO.
 *
 */


#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <avr/io.h>

#include "board.h"
#include "usb_rawhid.h"
#include "protocol.h"
#include "transport.h"


void transport_init(void)
{
    usb_init();
}


uint8_t transport_ready(void)
{
    return ((usb_configured() == 0) ? 0 : 1);
}


uint8_t transport_send(
        const proto_msg_s * const msg)
{
    const int8_t status = usb_rawhid_send(
            (const uint8_t*) msg,
            TRANSPORT_TX_TIMEOUT);
    
    return ((status == 0) ? 0 : 1);
}
