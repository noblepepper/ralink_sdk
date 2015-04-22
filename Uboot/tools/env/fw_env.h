/*
 * (C) Copyright 2002
 * Wolfgang Denk, DENX Software Engineering, wd@denx.de.
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	 See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

/*
 * To build the utility with the run-time configuration
 * uncomment the next line.
 * See included "fw_env.config" sample file (TRAB board)
 * for notes on configuration.
 */
#define CONFIG_FILE     "/etc/fw_env.config"

#undef HAVE_REDUND /* For systems with 2 env sectors */
#define DEVICE1_NAME      "/dev/mtd1"
#define DEVICE2_NAME      "/dev/mtd2"
#define DEVICE1_OFFSET    0x0000
#define ENV1_SIZE         0x10000
#define DEVICE1_ESIZE     0x10000
#define DEVICE2_OFFSET    0x0000
#define ENV2_SIZE         0x4000
#define DEVICE2_ESIZE     0x4000

#define CONFIG_BOOTDELAY	1	/* autoboot after 1 second	*/
#define CONFIG_BOOTCOMMAND	"tftp"							
#define CONFIG_BAUDRATE		57600
#define	CONFIG_ETHADDR		"00:AA:BB:CC:DD:10"
#define	CONFIG_IPADDR		"10.10.10.123"
#define	CONFIG_SERVERIP		"10.10.10.3"
#define CONFIG_RAMARGS		"setenv bootargs root=/dev/ram rw"
#define CONFIG_ADDIP		"setenv bootargs $(bootargs) ip=$(ipaddr):$(serverip):$(gatewayip):$(netmask):$(hostname):$(netdev):off"
#define CONFIG_ADDMISC		"setenv bootargs $(bootargs) console=ttyS0,$(baudrate) ethaddr=$(ethaddr) panic=1"
#define CONFIG_FLASH_SELF	"run ramargs addip addmisc;bootm $(kernel_addr) $(ramdisk_addr)"
#define CONFIG_KERNEL_ADDR	"BFC40000"
#define CONFIG_U_BOOT		"u-boot.bin"
#define	CONFIG_LOAD		"tftp 8A100000 $(u-boot)"
#define	CONFIG_U_B		"protect off 1:0-1;era 1:0-1;cp.b 8A100000 BC400000 $(filesize)"
#define	CONFIG_LOADFS		"tftp 8A100000 root.cramfs"
#define	CONFIG_U_FS		"era bc540000 bc83ffff;cp.b 8A100000 BC540000 $(filesize)"
#define	CONFIG_TEST_TFTP	"tftp 8A100000 root.cramfs;run test_tftp"
#define	CONFIG_STDIN		"serial"
#define	CONFIG_STDOUT		"serial"
#define	CONFIG_STDERR		"serial"
#define	CONFIG_ETHACT		"Eth0 (10/100-M)"

extern		void  fw_printenv(int argc, char *argv[]);
extern unsigned char *fw_getenv  (unsigned char *name);
extern		int   fw_setenv  (int argc, char *argv[]);

extern unsigned	long  crc32	 (unsigned long, const unsigned char *, unsigned);
