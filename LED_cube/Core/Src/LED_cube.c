#include "main.h"
#include "LED_cube.h"

void cube_set_zero(Cube *cube) {
  unsigned short int i = 0;
  unsigned short int j = 0;
  unsigned short int k = 0;
  for (i = 0; i < CUBE_SIZE; ++i) {
    for (j = 0; j < CUBE_SIZE * CUBE_SIZE; ++j) {
      for (j = 0; j < 8 * 3; ++j) {
        cube->flats[i].leds[j].RGB[k] = 0;
      }
    }
  }
}
void stdin_set_params() {
  //настройка stdin в режим блокирующего (ожидающего) чтения
  //настройка времени ожидания через tcgetattr
}
void get_cube(Cube *cube) {
  //считать от питонистов данные в режиме ожидания
  //считываем данные для кубика, вбиваем их в структуру
}
void send_cube(const Cube *cube) {  //функция должна иметь большую скорость для
                                    //точности передачи бит -> нельзя разбивать
                                    //на подфункции, максимально оптимизировать
  uint16_t i = 0;
  uint8_t j = 0;
  uint8_t k = 0;
  for (i = GPIO_PIN_0; i < GPIO_PIN_7; i *= 2) {
    for (j = 0; j < CUBE_SIZE * CUBE_SIZE; ++j) {
      for (k = 0; k < CUBE_SIZE * CUBE_SIZE; ++k) {
        if ((cube->flats[i].leds[j]) & (1 << j)) {
        	HAL_GPIO_WritePin(GPIOA, i, GPIO_PIN_SET);
        	//GPIOx->BSRR = (GPIO_PIN_1+i);
        	TIM1->CNT= 0;
        	while(TIM1->CNT < 50){};
        	HAL_GPIO_WritePin(GPIOA, i, GPIO_PIN_RESET);
        	//GPIOx->BSRR = (uint32_t)(GPIO_PIN_1+i) << 16U;
        	TIM1->CNT= 0;
        } else {
        	HAL_GPIO_WritePin(GPIOA, i, GPIO_PIN_SET);
        	TIM1->CNT= 0;
        	while(TIM1->CNT < 2) {};
        	HAL_GPIO_WritePin(GPIOA, i, GPIO_PIN_RESET);
        	TIM1->CNT= 0;
        	while(TIM1->CNT < 49) {};
        }
      }
    }
    HAL_GPIO_WritePin(GPIOA, i, GPIO_PIN_RESET);
  }
}
