################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
/home/user/Arduino/libraries/GxEPD/src/GxGDEH0213B73/GxGDEH0213B73.cpp 

LINK_OBJ += \
./libraries/GxEPD/src/GxGDEH0213B73/GxGDEH0213B73.cpp.o 

CPP_DEPS += \
./libraries/GxEPD/src/GxGDEH0213B73/GxGDEH0213B73.cpp.d 


# Each subdirectory must supply rules for building sources it contributes
libraries/GxEPD/src/GxGDEH0213B73/GxGDEH0213B73.cpp.o: /home/user/Arduino/libraries/GxEPD/src/GxGDEH0213B73/GxGDEH0213B73.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/home/user/Documents/Sloeber/arduinoPlugin/packages/esp32/tools/xtensa-esp32-elf-gcc/1.22.0-97-gc752ad5-5.2.0/bin/xtensa-esp32-elf-g++" -DESP_PLATFORM "-DMBEDTLS_CONFIG_FILE=\"mbedtls/esp_config.h\"" -DHAVE_CONFIG_H -DGCC_NOT_5_2_0=0 -DWITH_POSIX "-I/home/user/Documents/Sloeber/arduinoPlugin/packages/esp32/hardware/esp32/1.0.6/tools/sdk/include/config" "-I/home/user/Documents/Sloeber/arduinoPlugin/packages/esp32/hardware/esp32/1.0.6/tools/sdk/include/app_trace" "-I/home/user/Documents/Sloeber/arduinoPlugin/packages/esp32/hardware/esp32/1.0.6/tools/sdk/include/app_update" "-I/home/user/Documents/Sloeber/arduinoPlugin/packages/esp32/hardware/esp32/1.0.6/tools/sdk/include/asio" "-I/home/user/Documents/Sloeber/arduinoPlugin/packages/esp32/hardware/esp32/1.0.6/tools/sdk/include/bootloader_support" "-I/home/user/Documents/Sloeber/arduinoPlugin/packages/esp32/hardware/esp32/1.0.6/tools/sdk/include/bt" "-I/home/user/Documents/Sloeber/arduinoPlugin/packages/esp32/hardware/esp32/1.0.6/tools/sdk/include/coap" "-I/home/user/Documents/Sloeber/arduinoPlugin/packages/esp32/hardware/esp32/1.0.6/tools/sdk/include/console" "-I/home/user/Documents/Sloeber/arduinoPlugin/packages/esp32/hardware/esp32/1.0.6/tools/sdk/include/driver" "-I/home/user/Documents/Sloeber/arduinoPlugin/packages/esp32/hardware/esp32/1.0.6/tools/sdk/include/efuse" "-I/home/user/Documents/Sloeber/arduinoPlugin/packages/esp32/hardware/esp32/1.0.6/tools/sdk/include/esp-tls" "-I/home/user/Documents/Sloeber/arduinoPlugin/packages/esp32/hardware/esp32/1.0.6/tools/sdk/include/esp32" "-I/home/user/Documents/Sloeber/arduinoPlugin/packages/esp32/hardware/esp32/1.0.6/tools/sdk/include/esp_adc_cal" "-I/home/user/Documents/Sloeber/arduinoPlugin/packages/esp32/hardware/esp32/1.0.6/tools/sdk/include/esp_event" "-I/home/user/Documents/Sloeber/arduinoPlugin/packages/esp32/hardware/esp32/1.0.6/tools/sdk/include/esp_http_client" "-I/home/user/Documents/Sloeber/arduinoPlugin/packages/esp32/hardware/esp32/1.0.6/tools/sdk/include/esp_http_server" "-I/home/user/Documents/Sloeber/arduinoPlugin/packages/esp32/hardware/esp32/1.0.6/tools/sdk/include/esp_https_ota" "-I/home/user/Documents/Sloeber/arduinoPlugin/packages/esp32/hardware/esp32/1.0.6/tools/sdk/include/esp_https_server" "-I/home/user/Documents/Sloeber/arduinoPlugin/packages/esp32/hardware/esp32/1.0.6/tools/sdk/include/esp_ringbuf" "-I/home/user/Documents/Sloeber/arduinoPlugin/packages/esp32/hardware/esp32/1.0.6/tools/sdk/include/esp_websocket_client" "-I/home/user/Documents/Sloeber/arduinoPlugin/packages/esp32/hardware/esp32/1.0.6/tools/sdk/include/espcoredump" "-I/home/user/Documents/Sloeber/arduinoPlugin/packages/esp32/hardware/esp32/1.0.6/tools/sdk/include/ethernet" "-I/home/user/Documents/Sloeber/arduinoPlugin/packages/esp32/hardware/esp32/1.0.6/tools/sdk/include/expat" "-I/home/user/Documents/Sloeber/arduinoPlugin/packages/esp32/hardware/esp32/1.0.6/tools/sdk/include/fatfs" "-I/home/user/Documents/Sloeber/arduinoPlugin/packages/esp32/hardware/esp32/1.0.6/tools/sdk/include/freemodbus" "-I/home/user/Documents/Sloeber/arduinoPlugin/packages/esp32/hardware/esp32/1.0.6/tools/sdk/include/freertos" "-I/home/user/Documents/Sloeber/arduinoPlugin/packages/esp32/hardware/esp32/1.0.6/tools/sdk/include/heap" "-I/home/user/Documents/Sloeber/arduinoPlugin/packages/esp32/hardware/esp32/1.0.6/tools/sdk/include/idf_test" "-I/home/user/Documents/Sloeber/arduinoPlugin/packages/esp32/hardware/esp32/1.0.6/tools/sdk/include/jsmn" "-I/home/user/Documents/Sloeber/arduinoPlugin/packages/esp32/hardware/esp32/1.0.6/tools/sdk/include/json" "-I/home/user/Documents/Sloeber/arduinoPlugin/packages/esp32/hardware/esp32/1.0.6/tools/sdk/include/libsodium" "-I/home/user/Documents/Sloeber/arduinoPlugin/packages/esp32/hardware/esp32/1.0.6/tools/sdk/include/log" "-I/home/user/Documents/Sloeber/arduinoPlugin/packages/esp32/hardware/esp32/1.0.6/tools/sdk/include/lwip" "-I/home/user/Documents/Sloeber/arduinoPlugin/packages/esp32/hardware/esp32/1.0.6/tools/sdk/include/mbedtls" "-I/home/user/Documents/Sloeber/arduinoPlugin/packages/esp32/hardware/esp32/1.0.6/tools/sdk/include/mdns" "-I/home/user/Documents/Sloeber/arduinoPlugin/packages/esp32/hardware/esp32/1.0.6/tools/sdk/include/micro-ecc" "-I/home/user/Documents/Sloeber/arduinoPlugin/packages/esp32/hardware/esp32/1.0.6/tools/sdk/include/mqtt" "-I/home/user/Documents/Sloeber/arduinoPlugin/packages/esp32/hardware/esp32/1.0.6/tools/sdk/include/newlib" "-I/home/user/Documents/Sloeber/arduinoPlugin/packages/esp32/hardware/esp32/1.0.6/tools/sdk/include/nghttp" "-I/home/user/Documents/Sloeber/arduinoPlugin/packages/esp32/hardware/esp32/1.0.6/tools/sdk/include/nvs_flash" "-I/home/user/Documents/Sloeber/arduinoPlugin/packages/esp32/hardware/esp32/1.0.6/tools/sdk/include/openssl" "-I/home/user/Documents/Sloeber/arduinoPlugin/packages/esp32/hardware/esp32/1.0.6/tools/sdk/include/protobuf-c" "-I/home/user/Documents/Sloeber/arduinoPlugin/packages/esp32/hardware/esp32/1.0.6/tools/sdk/include/protocomm" "-I/home/user/Documents/Sloeber/arduinoPlugin/packages/esp32/hardware/esp32/1.0.6/tools/sdk/include/pthread" "-I/home/user/Documents/Sloeber/arduinoPlugin/packages/esp32/hardware/esp32/1.0.6/tools/sdk/include/sdmmc" "-I/home/user/Documents/Sloeber/arduinoPlugin/packages/esp32/hardware/esp32/1.0.6/tools/sdk/include/smartconfig_ack" "-I/home/user/Documents/Sloeber/arduinoPlugin/packages/esp32/hardware/esp32/1.0.6/tools/sdk/include/soc" "-I/home/user/Documents/Sloeber/arduinoPlugin/packages/esp32/hardware/esp32/1.0.6/tools/sdk/include/spi_flash" "-I/home/user/Documents/Sloeber/arduinoPlugin/packages/esp32/hardware/esp32/1.0.6/tools/sdk/include/spiffs" "-I/home/user/Documents/Sloeber/arduinoPlugin/packages/esp32/hardware/esp32/1.0.6/tools/sdk/include/tcp_transport" "-I/home/user/Documents/Sloeber/arduinoPlugin/packages/esp32/hardware/esp32/1.0.6/tools/sdk/include/tcpip_adapter" "-I/home/user/Documents/Sloeber/arduinoPlugin/packages/esp32/hardware/esp32/1.0.6/tools/sdk/include/ulp" "-I/home/user/Documents/Sloeber/arduinoPlugin/packages/esp32/hardware/esp32/1.0.6/tools/sdk/include/unity" "-I/home/user/Documents/Sloeber/arduinoPlugin/packages/esp32/hardware/esp32/1.0.6/tools/sdk/include/vfs" "-I/home/user/Documents/Sloeber/arduinoPlugin/packages/esp32/hardware/esp32/1.0.6/tools/sdk/include/wear_levelling" "-I/home/user/Documents/Sloeber/arduinoPlugin/packages/esp32/hardware/esp32/1.0.6/tools/sdk/include/wifi_provisioning" "-I/home/user/Documents/Sloeber/arduinoPlugin/packages/esp32/hardware/esp32/1.0.6/tools/sdk/include/wpa_supplicant" "-I/home/user/Documents/Sloeber/arduinoPlugin/packages/esp32/hardware/esp32/1.0.6/tools/sdk/include/xtensa-debug-module" "-I/home/user/Documents/Sloeber/arduinoPlugin/packages/esp32/hardware/esp32/1.0.6/tools/sdk/include/esp-face" "-I/home/user/Documents/Sloeber/arduinoPlugin/packages/esp32/hardware/esp32/1.0.6/tools/sdk/include/esp32-camera" "-I/home/user/Documents/Sloeber/arduinoPlugin/packages/esp32/hardware/esp32/1.0.6/tools/sdk/include/esp-face" "-I/home/user/Documents/Sloeber/arduinoPlugin/packages/esp32/hardware/esp32/1.0.6/tools/sdk/include/fb_gfx" -std=gnu++11 -Os -g3 -Wpointer-arith -fexceptions -fstack-protector -ffunction-sections -fdata-sections -fstrict-volatile-bitfields -mlongcalls -nostdlib -w -Wno-error=maybe-uninitialized -Wno-error=unused-function -Wno-error=unused-but-set-variable -Wno-error=unused-variable -Wno-error=deprecated-declarations -Wno-unused-parameter -Wno-unused-but-set-parameter -Wno-missing-field-initializers -Wno-sign-compare -fno-rtti -MMD -c -DF_CPU=240000000L -DARDUINO=10812 -DARDUINO_ESP32_DEV -DARDUINO_ARCH_ESP32 "-DARDUINO_BOARD=\"ESP32_DEV\"" -DARDUINO_VARIANT="esp32"  -DESP32 -DCORE_DEBUG_LEVEL=0 -DBOARD_HAS_PSRAM -mfix-esp32-psram-cache-issue -I"/home/user/Documents/Sloeber/arduinoPlugin/packages/esp32/hardware/esp32/1.0.6/cores/esp32" -I"/home/user/Documents/Sloeber/arduinoPlugin/packages/esp32/hardware/esp32/1.0.6/variants/esp32" -I"/home/user/Documents/Sloeber/arduinoPlugin/packages/esp32/hardware/esp32/1.0.6/libraries/FS/src" -I"/home/user/Documents/Sloeber/arduinoPlugin/packages/esp32/hardware/esp32/1.0.6/libraries/SD/src" -I"/home/user/Arduino/libraries/AceButton/src" -I"/home/user/Arduino/libraries/GxEPD/src" -I"/home/user/Documents/Sloeber/arduinoPlugin/packages/esp32/hardware/esp32/1.0.6/libraries/WiFi/src" -I"/home/user/Documents/Sloeber/arduinoPlugin/packages/esp32/hardware/esp32/1.0.6/libraries/SPI/src" -I"/home/user/Arduino/libraries/Adafruit-GFX-Library" -I"/home/user/Documents/Sloeber/arduinoPlugin/libraries/WiFiManager/2.0.17" -I"/home/user/Documents/Sloeber/arduinoPlugin/packages/esp32/hardware/esp32/1.0.6/libraries/WebServer/src" -I"/home/user/Documents/Sloeber/arduinoPlugin/packages/esp32/hardware/esp32/1.0.6/libraries/DNSServer/src" -I"/home/user/Documents/Sloeber/arduinoPlugin/packages/esp32/hardware/esp32/1.0.6/libraries/Update/src" -I"/home/user/Arduino/libraries/libzmanim/src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 "$<" -o "$@"
	@echo 'Finished building: $<'
	@echo ' '


