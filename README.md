# ralink_sdk
RT5350 linux SDK from Ralink modified to open webpage on ethernet port
Webpage can be triggered by gpio 0 (default) or gpio 27 (use setenv webgpio 27 in console)

DO NOT BUILD WITH GCC > 3.5.2 !!!

Suitable tool chain is available in Uboot/toolchain

For VoCore run make menuconfig in Uboot directory, set path to toolchain, chip type to ASIC,
chip ID to rt5350 and DRAM Component to 256 Mb
