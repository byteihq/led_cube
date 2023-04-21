#include "main.h"
#include "LED_cube.h"

void cube_set_zero(Cube *cube) {
  unsigned short int i = 0;
  unsigned short int j = 0;
    for (j = 0; j < CUBE_SIZE * CUBE_SIZE * CUBE_SIZE * 3; ++j) {
        cube->leds[i] = 0;
    }
}
void stdin_set_params() {
  //настройка stdin в режим блокирующего (ожидающего) чтения
  //настройка времени ожидания через tcgetattr
}
void get_cube(Cube *cube) {
	unsigned short int j = 0;
	for (j = 0; j < CUBE_SIZE * CUBE_SIZE * CUBE_SIZE * 3; ++j) {
	        cube->leds[j] = 34;
	}
  //считать от питонистов данные в режиме ожидания
  //считываем данные для кубика, вбиваем их в структуру
}
//void send_cube(const uint8_t[]) {  //функция должна иметь большую скорость для
//                                    //точности передачи бит -> нельзя разбивать
//                                    //на подфункции, максимально оптимизировать
//
//  uint16_t i = 0;
//  uint16_t j = 0;
//  uint8_t k = 0;
//  uint8_t m = 0;
//    for (j = 0; j < CUBE_SIZE * CUBE_SIZE * CUBE_SIZE * 3; ++j) {
//    	  for (m = 0; m < 8; ++m) {
//			 if ((cube->leds[j]) & (1 << m)) {
//					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_SET);
//					//GPIOx->BSRR = (GPIO_PIN_1+i);
//					TIM1->CNT= 0;
//					while(TIM1->CNT < 50){};
//					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_RESET);
//					//GPIOx->BSRR = (uint32_t)(GPIO_PIN_1+i) << 16U;
//				} else {
//					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_SET);
//					TIM1->CNT= 0;
//					while(TIM1->CNT < 2) {};
//					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_RESET);
//					TIM1->CNT= 0;
//					while(TIM1->CNT < 28) {};
//				}
//      }
//    }
//    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_RESET);
//    TIM1->CNT= 0;
//    while(TIM1->CNT < 0xff00) {};
//}
