#include <iostream>
#include <stdint.h>
#include <cctype>
#include <string.h>
#include "../Driver/Driver.hpp"
#include "../ServoMgr/ServoMgr.hpp"
#include "../Common/Common.hpp"
using namespace std;

/************************************************
 ******************* MACROS *******************
 ***********************************************/
#define ENABLE_DEBUG 0
#define ENABLE_STD_IN 0
#define ENABLE_WHILE_1 0

#define MAX_USERS 1
#define FIV_PERCENT_ABOVE(x) (x + ((x) / 2))
#define FIV_PERCENT_BELOW(x) (x - ((x) / 2))

#define MAX_ARGC_ARGS 4
#define IN_EDIT_MODE_IDX 1
#define IN_DRIVER_ID_IDX 2
#define IN_WEIGHT_IDX 3
#define IN_HEIGHT_IDX 4
/********************************************************
 ******************* Global Variables *******************
 ********************************************************/
driver Global_drivers[MAX_USERS];

/************************************************
 ******************* STATIC FUNC ****************
 ***********************************************/
uint16_t map(uint16_t x, uint16_t in_min, uint16_t in_max, uint16_t out_min, uint16_t out_max)
{
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

/************************************************
 ******************* APIs    *******************
 ***********************************************/

/**
 * Adjusts the seat position based on the driver's weight and height.
 *
 * @param driver pointer to the driver object
 *
 * @return structure containing the servo signals for height and slide adjustments
 *
 * @throws None
 */
S_DEG adjustSeat(driver *driver)
{
    uint16_t Local_u8Weight = driver->getWeight();
    uint16_t Local_u8Height = driver->getHeight();
    S_DEG Local_ServoSignals = {0, 0}; // Initialize to 0 when creating instance
    // Height adjustment
    if (Local_u8Height <= MIN_HEIGHT)
    {
#if ENABLE_DEBUG == 1
        cout << "seat higher and further front." << endl;
#endif
        Local_ServoSignals.ST_HGT_S1 = map(Local_u8Height, MIN_HEIGHT, FIV_PERCENT_BELOW(MIN_HEIGHT), 90, 0);
    }
    else if (Local_u8Height >= MAX_HEIGHT)
    {
#if ENABLE_DEBUG == 1
        cout << "seat lower and further back." << endl;
#endif
        Local_ServoSignals.ST_HGT_S1 = map(Local_u8Height, MAX_HEIGHT, FIV_PERCENT_ABOVE(MAX_HEIGHT), 90, 180);
    }
    else
    {
// No adjustment
#if ENABLE_DEBUG == 1
        cout << "standard seat position." << endl;
#endif
        Local_ServoSignals.ST_HGT_S1 = 90;
    }
    // Weight adjustment
    if (Local_u8Weight <= MIN_WEIGHT)
    {
#if ENABLE_DEBUG == 1
        cout << "decreased lumbar support and a slightly raised backrest." << endl;
#endif
        Local_ServoSignals.ST_SLD_S2 = map(Local_u8Weight, MIN_WEIGHT, FIV_PERCENT_BELOW(MIN_WEIGHT), 90, 0);
    }
    else if (Local_u8Weight >= MAX_WEIGHT)
    {
#if ENABLE_DEBUG == 1
        cout << "increased lumbar support and a slightly reclined backrest." << endl;
#endif
        Local_ServoSignals.ST_SLD_S2 = map(Local_u8Weight, MAX_WEIGHT, FIV_PERCENT_ABOVE(MAX_WEIGHT), 90, 180);
    }
    else
    {
// No adjustment
#if ENABLE_DEBUG == 1
        cout << "standard seat position." << endl;
#endif
        Local_ServoSignals.ST_SLD_S2 = 90;
    }
    /*  Save Driver Data */
    driver->setSeatHeight((uint8_t)Local_ServoSignals.ST_HGT_S1);
    driver->setSeatSlide((uint8_t)Local_ServoSignals.ST_SLD_S2);

    /*  Return Data */
    return Local_ServoSignals;
}


void mainLogic(uint8_t Loc_u8UserId, uint8_t Loc_editMode, uint16_t In_Weight, uint16_t In_Height)
{
    S_DEG Local_ServoSignals = {0, 0}; // Initialize to 0 when creating instance
#if ENABLE_WHILE_1 == 1
    while (1)
    {
#endif
#if ENABLE_DEBUG == 1 && ENABLE_STD_IN == 1
        cout << endl
             << "Loc_u8UserId = ";
        cin >> Loc_u8UserId;
        cin.ignore();
        cout << endl
             << "Loc_editMode = ";
        cin >> Loc_editMode;
        cin.ignore();
        Loc_u8UserId = Loc_u8UserId - '0';
#endif
        if (Loc_u8UserId < MAX_USERS)
        {
            /* Play or Edit*/
            if (Loc_editMode == 1 || Global_drivers[Loc_u8UserId].getSeatSlide() == 0 || Global_drivers[Loc_u8UserId].getSeatHeight() == 0)
            {

#if ENABLE_DEBUG == 1 && ENABLE_STD_IN == 1
                cout << endl
                     << "Enter Weight = ";
                cin >> In_Weight;
                cin.ignore();
                cout << endl
                     << "Enter Height = ";
                cin >> In_Height;
                cin.ignore();
                cout << "\n **************************** START CALC ************************\n";
#endif
                /* Set Coming Data to Driver ID*/
                Global_drivers[Loc_u8UserId].setDriverData(In_Weight, In_Height);
                /* Adjust Seat */
                Local_ServoSignals = adjustSeat(&Global_drivers[Loc_u8UserId]);
                /*  Perform Servo Action */
            }
#if ENABLE_DEBUG == 1
            else
            {
                cout << "seat already adjusted." << endl;
            }
#endif
            /*  Perform Servo Action */
#if ENABLE_DEBUG == 1
            cout << "\n **************************** PERFORM SERVO ACTION ************************\n";
#endif
            ServoMgr_voidControl(&Local_ServoSignals);
        }
        else
        {
// MAX Users Reached
#if ENABLE_DEBUG == 1
            cout << "ERROR MAX USERS REACHED." << endl;
#endif
        }
#if ENABLE_WHILE_1 == 1
    }
#endif
}

/**
 * Checks if the given string represents a valid integer.
 *
 * @param str the input string to be checked
 *
 * @return true if the input string represents a valid integer, false otherwise
 *
 * @throws None
 */
bool is_valid_int(const string &str)
{
    for (char c : str)
    {
        if (!isdigit(c))
        {
            return false;
        }
    }
    return true;
}

#ifndef UNIT_TEST
int main(int argc, char *argv[])
{
    /*  Get User Number */
    uint8_t Loc_u8UserId = 0;
    uint8_t Loc_editMode = 0;
    uint16_t In_Weight = 0;
    uint16_t In_Height = 0;
    string LOC_argv = "";
#if ENABLE_DEBUG == 0
    if (argc >= (int)(MAX_ARGC_ARGS+1))
    {
        LOC_argv = argv[IN_DRIVER_ID_IDX];
        if (!is_valid_int(LOC_argv))
        {
            cerr << "Invalid input" << endl;
            return 0;
        }
        Loc_u8UserId = stoi(argv[IN_DRIVER_ID_IDX]);

        LOC_argv = argv[IN_EDIT_MODE_IDX];
        if (!is_valid_int(LOC_argv))
        {
            cerr << "Invalid input" << endl;
            return 0;
        }
        Loc_editMode = stoi(argv[IN_EDIT_MODE_IDX]);

        LOC_argv = argv[IN_WEIGHT_IDX];
        if (!is_valid_int(LOC_argv))
        {
            cerr << "Invalid input" << endl;
            return 0;
        }
        In_Weight = stoi(argv[IN_WEIGHT_IDX]);

        LOC_argv = argv[IN_HEIGHT_IDX];
        if (!is_valid_int(LOC_argv))
        {
            cerr << "Invalid input" << endl;
            return 0;
        }
        In_Height = stoi(argv[IN_HEIGHT_IDX]);
    }
    else
    {
        cerr << "Unexpected number of args" << endl;
        return 0;
    }
#endif
    ServoMgr_voidInit();
    mainLogic(Loc_u8UserId, Loc_editMode, In_Weight, In_Height);
    return 1;
}
#endif