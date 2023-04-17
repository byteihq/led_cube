#ifndef INCLUDE_LED_CUBE_H
#define INCLUDE_LED_CUBE_H
#define CUBE_SIZE 8

typedef struct LED_struct {
  uint8_t RGB[3];
} LED;
typedef struct Flat_struct {
  LED leds[CUBE_SIZE * CUBE_SIZE];
} Flat;
typedef struct Cube_struct {
  Flat flats[CUBE_SIZE];
} Cube;
void cube_set_zero(Cube *);
void stdin_set_params();
void get_cube(Cube *);
void send_cube(const Cube *);
inline void HAL_Delay_Bit(uint8_t);

#endif //INCLUDE_LED_CUBE_H
