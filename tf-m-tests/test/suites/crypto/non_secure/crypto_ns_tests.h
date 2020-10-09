/*
 * Copyright (c) 2018-2020, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __CRYPTO_NS_TESTS_H__
#define __CRYPTO_NS_TESTS_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "test_framework.h"

/**
 * \brief Register testsuite for Crypto non-secure interface.
 *
 * \param[in] p_test_suite The test suite to be executed.
 */
void register_testsuite_ns_crypto_interface(struct test_suite_t *p_test_suite);

#ifdef __cplusplus
}
#endif

#endif /* __CRYPTO_NS_TESTS_H__ */
