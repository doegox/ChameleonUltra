#ifndef NRF_LOG_BACKEND_USBCDC_H
#define NRF_LOG_BACKEND_USBCDC_H

#include "nrf_log_backend_interface.h"

#ifdef __cplusplus
extern "C" {
#endif

//==========================================================
// <e> NRF_LOG_BACKEND_USBCDC_ENABLED - nrf_log_backend_usbcdc - Log USBCDC backend
//==========================================================
#ifndef NRF_LOG_BACKEND_USBCDC_ENABLED
#define NRF_LOG_BACKEND_USBCDC_ENABLED 1
#endif

// <o> NRF_LOG_BACKEND_USBCDC_TEMP_BUFFER_SIZE - Size of buffer for partially processed strings. 
// <i> Size of the buffer is a trade-off between RAM usage and processing.
// <i> if buffer is smaller then strings will often be fragmented.
// <i> It is recommended to use size which will fit typical log and only the
// <i> longer one will be fragmented.

#ifndef NRF_LOG_BACKEND_USBCDC_TEMP_BUFFER_SIZE
#define NRF_LOG_BACKEND_USBCDC_TEMP_BUFFER_SIZE 64
#endif


extern const nrf_log_backend_api_t nrf_log_backend_usbcdc_api;

typedef struct {
    nrf_log_backend_t               backend;
} nrf_log_backend_usbcdc_t;

#define NRF_LOG_BACKEND_USBCDC_DEF(_name)                         \
    NRF_LOG_BACKEND_DEF(_name, nrf_log_backend_usbcdc_api, NULL)

#if NRF_LOG_ENABLED
#define NRF_LOG_BACKEND_USBCDC_INIT() nrf_log_backend_usbcdc_init()
#else
#define NRF_LOG_BACKEND_USBCDC_INIT()
#endif

void nrf_log_backend_usbcdc_init(void);

#ifdef __cplusplus
}
#endif

#endif //NRF_LOG_BACKEND_USBCDC_H

/** @} */
