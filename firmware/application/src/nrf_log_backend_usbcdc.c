#include "sdk_common.h"
#include "nrf_log_backend_usbcdc.h"
#if NRF_MODULE_ENABLED(NRF_LOG) && NRF_MODULE_ENABLED(NRF_LOG_BACKEND_USBCDC)
#include "nrf_log_backend_serial.h"
#include "nrf_log_internal.h"
#include "nrf_log_ctrl.h"
#include "app_error.h"
#include "usb_main.h"
#include "settings.h"

static uint8_t m_string_buff[NRF_LOG_BACKEND_USBCDC_TEMP_BUFFER_SIZE];

NRF_LOG_BACKEND_USBCDC_DEF(usbcdc_log_backend);

void nrf_log_backend_usbcdc_init(void)
{
    int32_t backend_id = -1;
    (void)backend_id;
//#if defined(NRF_LOG_BACKEND_USBCDC_ENABLED) && NRF_LOG_BACKEND_USBCDC_ENABLED
    backend_id = nrf_log_backend_add(&usbcdc_log_backend, NRF_LOG_SEVERITY_DEBUG);
    ASSERT(backend_id >= 0);
    nrf_log_backend_enable(&usbcdc_log_backend);
//#endif
}

static void serial_tx(void const * p_context, char const * p_buffer, size_t len)
{
    if (is_usb_log_working() && (get_usb_log_mode() == SettingsUsbCdcLogModeNrfLog)) {
        usb_cdc_log_write(p_buffer, len);
    }
}

static void nrf_log_backend_usbcdc_put(nrf_log_backend_t const * p_backend,
                                     nrf_log_entry_t * p_msg)
{
    nrf_log_backend_serial_put(p_backend, p_msg, m_string_buff,
                               NRF_LOG_BACKEND_USBCDC_TEMP_BUFFER_SIZE, serial_tx);
}

static void nrf_log_backend_usbcdc_flush(nrf_log_backend_t const * p_backend)
{

}

static void nrf_log_backend_usbcdc_panic_set(nrf_log_backend_t const * p_backend)
{
//    nrf_drv_usbcdc_uninit(&m_usbcdc);
}

const nrf_log_backend_api_t nrf_log_backend_usbcdc_api = {
        .put       = nrf_log_backend_usbcdc_put,
        .flush     = nrf_log_backend_usbcdc_flush,
        .panic_set = nrf_log_backend_usbcdc_panic_set,
};

#endif //NRF_MODULE_ENABLED(NRF_LOG) && NRF_MODULE_ENABLED(NRF_LOG_BACKEND_USBCDC)
