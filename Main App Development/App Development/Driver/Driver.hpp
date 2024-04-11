#ifndef DRIVER_DATA_H
#define DRIVER_DATA_H
#include <stdint.h>

/****************************************************************************
****************************** MACROS ***************************************
****************************************************************************/
#define MAX_WEIGHT 120
#define MIN_WEIGHT 60

#define MAX_HEIGHT 200
#define MIN_HEIGHT 60

/****************************************************************************
******************* CLASSES AND FUNCTION DECLARATIONS ***********************
****************************************************************************/
class driver
{
private:
    /* data */
    uint16_t weight;
    uint16_t height;
    uint16_t seatSlide;
    uint16_t seatHeight;

public:
    driver(/* args */);
    
    /* Setters */
    void setWeight(uint16_t weight);
    void setHeight(uint16_t height);
    void setSeatSlide(uint16_t seatSlide);
    void setSeatHeight(uint16_t seatHeight);
    void setDriverData(uint16_t weight, uint16_t height);

    /* Getters */
    uint16_t getWeight();
    uint16_t getHeight();
    uint16_t getSeatSlide();
    uint16_t getSeatHeight();
    void getDriverData(uint16_t *weight, uint16_t *height);
};

#endif