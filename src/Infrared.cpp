//
// Created by Zhang ZhuHan on 2024/7/3.
//
#include "Infrared.h"
#include <Arduino.h>

IRrecv irrecv(RECV_PIN);
decode_results results;

void infInit() {
    irrecv.enableIRIn();         // 启动红外接收
}

int infLoop() {
    int x = -1;
    if(irrecv.decode(&results)) {
        // 解码红外遥控信号
        switch(results.value) {
            case 0x488F3CBB:
                x = 0;
                break;
            case 0xE318261B:
                x = 1;
                break;
            case 0x511DBB:
                x = 2;
                break;
            case 0xEE886D7F:
                x = 3;
                break;
            case 0x52A3D41F:
                x = 4;
                break;
            case 0xD7E84B1B:
                x = 5;
                break;
            case 0x20FE4DBB:
                x = 6;
                break;
        }
        irrecv.resume();   // 开始读取下一条信息
    }
    return x;
}