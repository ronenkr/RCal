################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -f

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include libraries/libzmanim/src/subdir.mk
-include libraries/WiFiManager/subdir.mk
-include libraries/WiFi/src/subdir.mk
-include libraries/WebServer/src/detail/subdir.mk
-include libraries/WebServer/src/subdir.mk
-include libraries/Update/src/subdir.mk
-include libraries/SPI/src/subdir.mk
-include libraries/SD/src/subdir.mk
-include libraries/GxEPD/src/GxQYEG0290RWS800/subdir.mk
-include libraries/GxEPD/src/GxQYEG0290BN/subdir.mk
-include libraries/GxEPD/src/GxIO/GxIO_SPI/subdir.mk
-include libraries/GxEPD/src/GxIO/subdir.mk
-include libraries/GxEPD/src/GxGDGDEW0102T4/subdir.mk
-include libraries/GxEPD/src/GxGDEW075Z09/subdir.mk
-include libraries/GxEPD/src/GxGDEW075Z08/subdir.mk
-include libraries/GxEPD/src/GxGDEW075T8/subdir.mk
-include libraries/GxEPD/src/GxGDEW075T7/subdir.mk
-include libraries/GxEPD/src/GxGDEW0583T7/subdir.mk
-include libraries/GxEPD/src/GxGDEW042Z15/subdir.mk
-include libraries/GxEPD/src/GxGDEW042T2/subdir.mk
-include libraries/GxEPD/src/GxGDEW0371W7/subdir.mk
-include libraries/GxEPD/src/GxGDEW029Z10/subdir.mk
-include libraries/GxEPD/src/GxGDEW029T5/subdir.mk
-include libraries/GxEPD/src/GxGDEW027W3/subdir.mk
-include libraries/GxEPD/src/GxGDEW027C44/subdir.mk
-include libraries/GxEPD/src/GxGDEW026T0/subdir.mk
-include libraries/GxEPD/src/GxGDEW0213Z16/subdir.mk
-include libraries/GxEPD/src/GxGDEW0213M21/subdir.mk
-include libraries/GxEPD/src/GxGDEW0213I5F/subdir.mk
-include libraries/GxEPD/src/GxGDEW0154Z17/subdir.mk
-include libraries/GxEPD/src/GxGDEW0154Z04/subdir.mk
-include libraries/GxEPD/src/GxGDEW0102I4F/subdir.mk
-include libraries/GxEPD/src/GxGDEP015OC1/subdir.mk
-include libraries/GxEPD/src/GxGDEM0213B74/subdir.mk
-include libraries/GxEPD/src/GxGDEH029A1/subdir.mk
-include libraries/GxEPD/src/GxGDEH0213B73/subdir.mk
-include libraries/GxEPD/src/GxGDEH0213B72/subdir.mk
-include libraries/GxEPD/src/GxGDEH0154D67/subdir.mk
-include libraries/GxEPD/src/GxGDE0213B72B/subdir.mk
-include libraries/GxEPD/src/GxGDE0213B72/subdir.mk
-include libraries/GxEPD/src/GxGDE0213B1/subdir.mk
-include libraries/GxEPD/src/GxDEPG0750BN/subdir.mk
-include libraries/GxEPD/src/GxDEPG0290R/subdir.mk
-include libraries/GxEPD/src/GxDEPG0290B/subdir.mk
-include libraries/GxEPD/src/GxDEPG0266BN/subdir.mk
-include libraries/GxEPD/src/GxDEPG0213BN/subdir.mk
-include libraries/GxEPD/src/GxDEPG0150BN/subdir.mk
-include libraries/GxEPD/src/GxDEPG0097BW/subdir.mk
-include libraries/GxEPD/src/subdir.mk
-include libraries/FS/src/subdir.mk
-include libraries/DNSServer/src/subdir.mk
-include libraries/Adafruit-GFX-Library/subdir.mk
-include libraries/AceButton/src/ace_button/subdir.mk
-include core/core/libb64/subdir.mk
-include core/core/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CCM_DEPS)),)
-include $(CCM_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(CXXM_DEPS)),)
-include $(CXXM_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C++M_DEPS)),)
-include $(C++M_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
AR += \
/home/user/Documents/sloeber-workspace/RCa/Release/arduino.ar \

ELF += \
RCa.elf \

HEX += \
RCa.hex \



#bootloaderTest
BurnBootLoader: 
	@echo trying to burn bootloader ${bootloader.tool}
	${tools.${bootloader.tool}.erase.pattern}
	${tools.${bootloader.tool}.bootloader.pattern}

uploadWithBuild: all
	@echo trying to build and upload with upload tool ${upload.tool}
	${tools.${upload.tool}.upload.pattern}

uploadWithoutBuild: 
	@echo trying to upload without build with upload tool ${upload.tool}
	${tools.${upload.tool}.upload.pattern}
    
uploadWithProgrammerWithBuild: all
	@echo trying to build and upload with programmer ${program.tool}
	${tools.${program.tool}.program.pattern}

uploadWithProgrammerWithoutBuild: 
	@echo trying to upload with programmer ${program.tool} without build
	${tools.${program.tool}.program.pattern}

# All Target
all:
	-${recipe.hooks.prebuild.1.pattern}
	${recipe.hooks.prebuild.2.pattern} ||:
	$(MAKE) --no-print-directory main-build

# Main-build Target
main-build: RCa

# Tool invocations
RCa: $(HEX)
	@echo 'Building target: $@'
	@echo 'Printing size:'
	"/home/user/Documents/Sloeber/arduinoPlugin/packages/esp32/tools/xtensa-esp32-elf-gcc/1.22.0-97-gc752ad5-5.2.0/bin/xtensa-esp32-elf-size" -A "/home/user/Documents/sloeber-workspace/RCa/Release/RCa.elf"
	@echo 'Finished building target: $@'
	@echo ' '

/home/user/Documents/sloeber-workspace/RCa/Release/arduino.ar: $(AR_OBJ)
	@echo 'Starting archiver'
	"/home/user/Documents/Sloeber/arduinoPlugin/packages/esp32/tools/xtensa-esp32-elf-gcc/1.22.0-97-gc752ad5-5.2.0/bin/xtensa-esp32-elf-ar" cru  "/home/user/Documents/sloeber-workspace/RCa/Release/arduino.ar" $(AR_OBJ)
	@echo 'Finished building: $@'
	@echo ' '

RCa.elf: $(LINK_OBJ) $(AR)
	@echo 'Starting combiner'
	"/home/user/Documents/Sloeber/arduinoPlugin/packages/esp32/tools/xtensa-esp32-elf-gcc/1.22.0-97-gc752ad5-5.2.0/bin/xtensa-esp32-elf-gcc" -nostdlib "-L/home/user/Documents/Sloeber/arduinoPlugin/packages/esp32/hardware/esp32/1.0.6/tools/sdk/lib" "-L/home/user/Documents/Sloeber/arduinoPlugin/packages/esp32/hardware/esp32/1.0.6/tools/sdk/ld" -T esp32_out.ld -T esp32.project.ld -T esp32.rom.ld -T esp32.peripherals.ld -T esp32.rom.libgcc.ld -T esp32.rom.spiram_incompatible_fns.ld -u esp_app_desc -u ld_include_panic_highint_hdl -u call_user_start_cpu0 -Wl,--gc-sections -Wl,-static -Wl,--undefined=uxTopUsedPriority  -u __cxa_guard_dummy -u __cxx_fatal_exception   -Wl,--start-group  $(LINK_OBJ) $(AR) -lgcc -lesp_websocket_client -lwpa2 -ldetection -lesp_https_server -lwps -lhal -lconsole -lpe -lsoc -lsdmmc -lpthread -llog -lesp_http_client -ljson -lmesh -lesp32-camera -lnet80211 -lwpa_supplicant -lc -lmqtt -lcxx -lesp_https_ota -lulp -lefuse -lpp -lmdns -lbt -lwpa -lspiffs -lheap -limage_util -lunity -lrtc -lmbedtls -lface_recognition -lnghttp -ljsmn -lopenssl -lcore -lfatfs -lm -lprotocomm -lsmartconfig -lxtensa-debug-module -ldl -lesp_event -lesp-tls -lfd -lespcoredump -lesp_http_server -lfr -lsmartconfig_ack -lwear_levelling -ltcp_transport -llwip -lphy -lvfs -lcoap -lesp32 -llibsodium -lbootloader_support -ldriver -lcoexist -lasio -lod -lmicro-ecc -lesp_ringbuf -ldetection_cat_face -lapp_update -lespnow -lface_detection -lapp_trace -lnewlib -lbtdm_app -lwifi_provisioning -lfreertos -lfreemodbus -lethernet -lnvs_flash -lspi_flash -lc_nano -lexpat -lfb_gfx -lprotobuf-c -lesp_adc_cal -ltcpip_adapter  -lstdc++ -lc-psram-workaround -lm-psram-workaround -Wl,--end-group -Wl,-EL -o "/home/user/Documents/sloeber-workspace/RCa/Release/RCa.elf"
	@echo 'Finished building: $@'
	@echo ' '

RCa.hex: $(ELF)
	@echo 'Do all objcopy commands'
	${recipe.objcopy.bin.pattern}
	${recipe.objcopy.hex.pattern}
	${recipe.objcopy.partitions.bin.pattern}
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(CCM_DEPS)$(C_UPPER_DEPS)$(PDE_DEPS)$(CXXM_DEPS)$(C_DEPS)$(AR)$(CC_DEPS)$(AR_OBJ)$(C++_DEPS)$(LINK_OBJ)$(CXX_DEPS)$(ASM_DEPS)$(HEX)$(INO_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(C++M_DEPS)$(ELF)$(CPP_DEPS)
	-@echo ' '

.PHONY: all clean dependents main-build pre-build

-include ../makefile.targets
