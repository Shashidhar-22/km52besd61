void LCD_Clock_Init(void);
void KM_LCD_Init(void);

void KM_LCD_Write_Str(char *str);
void KM_LCD_Write_Upper_Str(char *str);
void KM_LCD_Write_Lower_Str(char *str);

void KM_LCD_Write_Data( unsigned char c);
void KM_LCD_Write_Cmd(unsigned char c);
void write_high_nibble( unsigned char data );
void write_low_nibble( unsigned char data );
