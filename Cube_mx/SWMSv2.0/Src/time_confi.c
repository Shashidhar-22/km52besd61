//#include "main.h"
//#include<stdio.h>
//#include "device_h.h"

//extern I2C_HandleTypeDef hi2c1;
//int count1;
//char buffer[10];
//void config_date(){

//while(1){
//	
//HAL_Delay(250);	

//unsigned char str[10];

//if(!(HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_10)))
//{
//count1++;
//HAL_Delay(250);

//while(1)
//{


//if(!(HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_8))){

//++str[count1];

//HAL_Delay(300);

//if(count1==1&&str[count1]>=60 || str[count1]<0){
//str[count1]=0;
//}
//if(count1==2&&str[count1]>24 || str[count1]<0){
//str[count1]=0;
//}
//if(count1==4&&str[count1]>31 || str[count1]<0){
//str[count1]=0;
//}
//if(count1==5&&str[count1]>12 || str[count1]<0){
//str[count1]=0;
//}

////KM_LCD_Write_CMD(0x01);
//sprintf(buffer,"%02x %02d %02x ",str[2],str[1],str[0]);
//KM_LCD_Write_CMD(0x80);
//KM_LCD_string(buffer);
//HAL_Delay(30);
////KM_LCD_Write_CMD(0x01);
//sprintf(buffer,"%02x %02d %02x ",str[3],str[4],str[5]);
//KM_LCD_Write_CMD(0xC0);
//KM_LCD_string(buffer);
////HAL_Delay(30);
////print(str);


//// HAL_I2C_Mem_Write(&hi2c1,0x68<<1,0x01,0x01,str,0x01,100);


//}

//if(!(HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_9))){

//--str[count1];
//HAL_Delay(2500);

//// print(str);

//if(str[count1]<0){
//str[count1]=0;
//}




//sprintf(buffer,"%02x %02d %02x ",str[2],str[1],str[0]);
//KM_LCD_Write_CMD(0x80);
//KM_LCD_string(buffer);
//sprintf(buffer,"%02x %02d %02x ",str[4],str[5],str[6]);
//KM_LCD_Write_CMD(0xC0);
//KM_LCD_string(buffer);


//// HAL_I2C_Mem_Write(&hi2c1,0x68<<1,0x01,0x01,str,0x01,100);


//}


//HAL_I2C_Mem_Write(&hi2c1,0x68<<1,0x00,0x01,str,0x08,100);

//if(!(HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_10))){
//break;

//}


//}




//}


//if(count1==7){
//break;
//}

//}


//}