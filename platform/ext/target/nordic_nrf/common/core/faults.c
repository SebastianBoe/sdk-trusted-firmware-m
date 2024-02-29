/*
 * Copyright (c) 2018-2022, Arm Limited. All rights reserved.
 * Copyright (c) 2020, Nordic Semiconductor ASA. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <stdio.h>
#include "cmsis.h"
#include "spu.h"
#include "utilities.h"
#include "nrf_exception_info.h"
/* "exception_info.h" must be the last include because of the IAR pragma */
#include "exception_info.h"

void SPU_Handler(void)
{
#ifdef TFM_EXCEPTION_INFO_DUMP
    nrf_exception_info_store_context();
#endif
    /* Clear SPU interrupt flag and pending SPU IRQ */
    spu_clear_events();

#ifdef SPU_IRQn
    NVIC_ClearPendingIRQ(SPU_IRQn);
#else
    // TODO: NCSDK-25011: Support nrf54l
#endif

    tfm_core_panic();
}

__attribute__((naked)) void SPU_IRQHandler(void)
{
    EXCEPTION_INFO();

    __ASM volatile(
        "BL        SPU_Handler             \n"
        "B         .                       \n"
    );
}
