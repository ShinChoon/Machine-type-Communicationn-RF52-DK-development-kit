/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"

static EventQueue event_queue(4* EVENTS_EVENT_SIZE);

void schedule_ble_application(BLE::OnEventsToProcessCallbackContext* context){
    event_queue.call(callback(&(context->ble), &BLE::processEvents));
}

// Blinking rate in milliseconds
#define BLINKING_RATE     500ms


int main()
{
    // Initialise the digital pin LED1 as an output
    DigitalOut led(LED1);

    while (true) {
        led = !led;
        ThisThread::sleep_for(BLINKING_RATE);
    }
}
