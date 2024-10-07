
/*lcd*/
void LCD_init(void);
void write_higher_nibble(unsigned char c);
void write_lower_nibble(unsigned char c);
void KM_LCD_Write_CMD(unsigned char c);
void KM_LCD_Write_Data(unsigned char c);
void KM_LCD_up_string(char *str);
void KM_LCD_down_string(char *str);
void KM_LCD_string(char *str);

/*adc*/
void ADC_DATA(void);

/*rtc*/
void RTC_DATA(void);

/*wifi*/
void command_send(char *cmd);
int wifi_responce_ok();
int chip_responce();
int wifi_responce_done();

void wifiinit(void);
void wifioperation();

/*time configuration*/
void config_date();