# ruuvi.nrf_sdk15_3_overrides.c
Override specific files in nRF5 SDK15.3

# License
MIT, check LICENSE

# Changes
## FDS
 - Expose boundary setting to application.

## nrf_bootloader_wdt.c
 - Cap WDT feed timer into 2^20 timer ticks. 
 - Feed WDT after timer has been started.

## nrfx_wdt.c
 - Fix watchdog overflow on multiply by 2^15 / 1000 conversion
 
## ble_dfu*
  - Conditionally compile modules
  - ble_dfu_unbonded.c: Add critical section to bootloader initialization to avoid interrupts being misdirected.
  
## nrf_ble_scan.c
  - Pass scan data with event_id NRF_BLE_SCAN_EVT_NOT_FOUND to application if no filters are enabled

## t2t_lib, t4t_lib
  - Use NFC binaries from nRF5 SDK 17.2
