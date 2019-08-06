#include "config.h"

void main(void){
    
    SystemInit();
    
    while (1) {
        // Read remote control datas (8 bytes)
        for(uint8_t i = 1; i < 9; i++) {
            CBUSM2_Read(i);
        }
        if(Special(SPECIAL_FORWARD)) {
            Motor_Stop();
            Motor(FRONT_RIGHT, MAX_SPEED);
            Motor(FRONT_LEFT, MAX_SPEED);
            Motor(BACK_RIGHT, MAX_SPEED);
            Motor(BACK_LEFT, MAX_SPEED);
            __delay_ms(1000);
            Motor_Stop();
            SpecialClear(SPECIAL_FORWARD);
        } else if(Special(SPECIAL_LEFT)) {
            Motor_Stop();
            Motor(FRONT_RIGHT, MAX_SPEED);
            Motor(BACK_RIGHT, MAX_SPEED);
            __delay_ms(1000);
            Motor_Stop();
            SpecialClear(SPECIAL_LEFT);
        } else if(Special(SPECIAL_RIGHT)) {
            Motor_Stop();
            Motor(FRONT_LEFT, MAX_SPEED);
            Motor(BACK_LEFT, MAX_SPEED);
            __delay_ms(1000);
            Motor_Stop();
            SpecialClear(SPECIAL_RIGHT);
        } else if(Special(SPECIAL_BACKWARD)) {
            /* Not featured */
            SpecialClear(SPECIAL_BACKWARD);
        } else if(Special(SPECIAL_UP)) {
            /* Not featured */
            SpecialClear(SPECIAL_UP);
        } else if(Special(SPECIAL_DOWN)) {
            Motor_Stop();
            Motor(UP_RIGHT, MAX_SPEED);
            Motor(UP_LEFT, MAX_SPEED);
            __delay_ms(1000);
            Motor_Stop();
            SpecialClear(SPECIAL_DOWN);
        } else if(Special(SPECIAL_TURN_BACK)) {
            Motor_Stop();
            Motor(FRONT_RIGHT, MAX_SPEED);
            Motor(BACK_RIGHT, MAX_SPEED);
            __delay_ms(2000);
            Motor_Stop();
            SpecialClear(SPECIAL_LEFT);
        } else {
            // If special mode not occured
            Motor_SimpleMode();
        }
        // For gripper and camera servo control
        Motor_Servo();
    }
}



