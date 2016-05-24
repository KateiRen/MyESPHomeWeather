/*
 * user_main.c
 *
 *  Created on: 24.05.2016
 *      Author: Karsten
 */

#include <ets_sys.h>
#include <osapi.h>
#include <gpio.h>
#include <user_interface.h>
#include <os_type.h>
//#include <c_types.h>
#include "driver/uart.h"

LOCAL os_timer_t blink_timer;
LOCAL uint8_t led_state=0;


LOCAL void ICACHE_FLASH_ATTR blink_cb(void *arg)	{
	led_state = !led_state;
	GPIO_OUTPUT_SET(5, led_state);
}

//system_init_done_cb
//void user_rf_pre_init(void)

/*
void initDone() {
	wifi_set_opmode_current(STATION_MODE);
	struct station_config stationConfig;
	strncpy(stationConfig.ssid, "KateiRen", 32);
	strncpy(stationConfig.password, "Dana.Karsten.", 64);
	wifi_station_set_config(&stationConfig);
}
*/

//wifi_station_set_auto_connect() // automatisches WiFi (Re)Connect deaktivieren
//wifi_set_opmode()
/*
void eventHandler(System_Event_t *event) {
	switch(event->event) {
		case EVENT_STAMODE_CONNECTED:
			os_printf("Event: EVENT_STAMODE_CONNECTED\n");
			break;
		case EVENT_STAMODE_DISCONNECTED:
			os_printf("Event: EVENT_STAMODE_DISCONNECTED\n");
			break;
		case EVENT_STAMODE_AUTHMODE_CHANGE:
			os_printf("Event: EVENT_STAMODE_AUTHMODE_CHANGE\n");
			break;
		case EVENT_STAMODE_GOT_IP:
			os_printf("Event: EVENT_STAMODE_GOT_IP\n");
			break;
		case EVENT_SOFTAPMODE_STACONNECTED:
			os_printf("Event: EVENT_SOFTAPMODE_STACONNECTED\n");
			break;
		case EVENT_SOFTAPMODE_STADISCONNECTED:
			os_printf("Event: EVENT_SOFTAPMODE_STADISCONNECTED\n");
			break;
		default:
			os_printf("Unexpected event: %d\n", event->event);
			break;
	}
}

*/

void user_init(void)
{
	// Configure the UART
	uart_init(BIT_RATE_115200, BIT_RATE_115200);
	// Enable system messages (sind aber per default an)
	system_set_os_print(1);
	gpio_init();

	PIN_FUNC_SELECT(PERIPHS_IO_MUX_GPIO5_U, FUNC_GPIO5);
	os_timer_disarm(&blink_timer);
	os_timer_setfn(&blink_timer, (os_timer_func_t *)blink_cb, (void *)0);
	os_timer_arm(&blink_timer, 1000, 1);


	//wifi_set_event_handler_cb(eventHandler);

	os_printf("Los gehts!");
	//Serial1.printf("");


}
