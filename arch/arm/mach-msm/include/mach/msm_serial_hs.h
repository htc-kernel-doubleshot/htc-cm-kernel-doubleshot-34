/*
 * Copyright (C) 2008 Google, Inc.
 * Author: Nick Pelly <npelly@google.com>
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#ifndef __ASM_ARCH_MSM_SERIAL_HS_H
#define __ASM_ARCH_MSM_SERIAL_HS_H

#include<linux/serial_core.h>

struct msm_serial_hs_platform_data {
	int wakeup_irq;  
	
	unsigned char inject_rx_on_wakeup;
	char rx_to_inject;
	int (*gpio_config)(int);

	
		
	#ifdef CONFIG_SERIAL_BCM_BT_LPM
	void (*exit_lpm_cb)(struct uart_port *);
#endif
};

unsigned int msm_hs_tx_empty(struct uart_port *uport);
void msm_hs_request_clock_off(struct uart_port *uport);
void msm_hs_request_clock_on(struct uart_port *uport);
void msm_hs_set_mctrl(struct uart_port *uport,
				    unsigned int mctrl);

#ifdef CONFIG_SERIAL_BCM_BT_LPM
/* uport->lock must be held when calling _locked() */
extern void msm_hs_request_clock_off_locked(struct uart_port *uport);
extern void msm_hs_request_clock_on_locked(struct uart_port *uport);
#endif

#endif
