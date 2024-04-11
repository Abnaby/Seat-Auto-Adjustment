#include <iostream>
#include "Driver.hpp"

using namespace std;

/*************************************************
******************* MACROS ***********************
*************************************************/

#define AVG_WEIGHT 80
#define AVG_HEIGHT 172

/****************************************************************************
*******************      FUNCTION DECLARATIONS       ***********************
****************************************************************************/

/**
 * @brief Construct a new driver::driver object
 *
 * Constructor for the driver class, which is the base class for
 * all other classes of drivers in this project.
 */
driver::driver(/* args */)
{
    this->weight = AVG_WEIGHT;
    this->height = AVG_HEIGHT;
    this->seatSlide = 0;
    this->seatHeight = 0;
}

/**
 * Set the weight for the driver.
 *
 * @param weight the new weight to set
 */
void driver::setWeight(uint16_t weight)
{
    if (weight > MAX_WEIGHT)
    {
        this->weight = MAX_WEIGHT;
    }
    else if (weight < MIN_WEIGHT)
    {
        this->weight = MIN_WEIGHT;
    }
    else
    {
        this->weight = weight;
    }
}

/**
 * Sets the height of the driver.
 *
 * @param height the height to set for the driver
 */
void driver::setHeight(uint16_t height)
{
    if (height > MAX_HEIGHT)
    {
        this->height = MAX_HEIGHT;
    }
    else if (height < MIN_HEIGHT)
    {
        this->height = MIN_HEIGHT;
    }
    else
    {
        this->height = height;
    }
}

/**
 * Set the seat slide position.
 *
 * @param seatSlide the value to set the seat slide to
 */
void driver::setSeatSlide(uint16_t seatSlide)
{
    this->seatSlide = seatSlide;
}

/**
 * Set the seat height of the driver.
 *
 * @param seatHeight the new seat height to set
 */
void driver::setSeatHeight(uint16_t seatHeight)
{
    this->seatHeight = seatHeight;
}

/**
 * Sets the driver's weight and height.
 *
 * @param weight the weight of the driver
 * @param height the height of the driver
 *
 */
void driver::setDriverData(uint16_t weight, uint16_t height)
{
    this->weight = weight;
    this->height = height;
}

/**
 * Get the weight of the driver.
 *
 * @return the weight of the driver
 */
uint16_t driver::getWeight()
{
    return this->weight;
}

/**
 * Get the height of the driver.
 *
 * @return the height of the driver
 */
uint16_t driver::getHeight()
{
    return this->height;
}

/**
 * Get the value of the seat slide for the driver.
 *
 * @return the seat slide value
 */
uint16_t driver::getSeatSlide()
{
    return this->seatSlide;
}

/**
 * Get the seat height from the driver object.
 *
 * @return the seat height
 */
uint16_t driver::getSeatHeight()
{
    return this->seatHeight;
}

/**
 * Copies the driver's weight and height data into the provided pointers.
 *
 * @param weight pointer to store the driver's weight
 * @param height pointer to store the driver's height
 *
 * @return void
 */
void driver::getDriverData(uint16_t *weight, uint16_t *height)
{
    *weight = this->weight;
    *height = this->height;
}
