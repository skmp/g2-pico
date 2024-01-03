/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "pico/stdlib.h"
#include "hardware/pio.h"
// Our assembled program:
#include "g2_modem.pio.h"

////// G2 //////

// PIO block
// GP0 ~ GP7: data bus
// GP8 ~ GP15: addr bus
// GP16: nWR
// GP17: nRD
// GP18: nCS

// gpio
// GP19: nIRQ


#define G2_PIN_BASE 0

#define G2_DATA_SHIFT 0
#define G2_DATA_MASK 255
#define G2_ADDR_SHIFT 8
#define G2_ADDR_MASK 255
#define G2_IS_READ_MASK 65536

uint8_t g2_ram[G2_ADDR_MASK + 1];

int main() {
    // Choose which PIO instance to use (there are two instances)
    PIO pio = pio0;

    // Our assembled program needs to be loaded into this PIO's instruction
    // memory. This SDK function will find a location (offset) in the
    // instruction memory where there is enough space for our program. We need
    // to remember this location!
    uint offset = pio_add_program(pio, &g2_modem_program);

    // Find a free state machine on our chosen PIO (erroring if there are
    // none). Configure it to run our program, and start it, using the
    // helper function we included in our .pio file.
    uint sm = pio_claim_unused_sm(pio, true);
    g2_modem_program_init(pio, sm, offset, G2_PIN_BASE);

    // The state machine is now running. Any value we push to its TX FIFO will
    // appear on the LED pin.
    while (true) {
        uint32_t action = pio_sm_get_blocking(pio, sm);
        uint32_t addr = (action >> G2_ADDR_SHIFT) & G2_ADDR_MASK;
        uint32_t is_read = action & G2_IS_READ_MASK;
        
        if (is_read) {
            // this is a read, we need to reply ASAP
            pio_sm_put_blocking(pio, sm, g2_ram[addr]);
        } else {
            uint32_t data = (action >> G2_DATA_SHIFT) & G2_DATA_MASK;
            g2_ram[addr] = data;
        }
    }
}
