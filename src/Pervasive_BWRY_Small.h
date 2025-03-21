///
/// @file Pervasive_BWRY_Small.h
/// @brief Driver for BWRY small screens
///
/// @details Project Pervasive Displays Library Suite
/// @n Based on highView technology
///
/// @author Rei Vilo
/// @date 21 Jan 2025
/// @version 902
///
/// @copyright (c) Pervasive Displays, 2010-2025
/// @copyright All rights reserved
/// @copyright For exclusive use with Pervasive Displays screens
///
/// * Basic edition: for hobbyists and for basic usage
/// @n Creative Commons Attribution-ShareAlike 4.0 International (CC BY-SA 4.0)
/// @see https://creativecommons.org/licenses/by-sa/4.0/
///
/// @n Consider the Evaluation or Commercial editions for professionals or organisations and for commercial usage
///
/// * Evaluation edition: for professionals or organisations, evaluation only, no commercial usage
/// @n All rights reserved
///
/// * Commercial edition: for professionals or organisations, commercial usage
/// @n All rights reserved
///
/// * Viewer edition: for professionals or organisations
/// @n All rights reserved
///
/// * Documentation
/// @n All rights reserved
///
/// @see Application notes
/// * [Application Note Small Size for Spectra 4](https://www.pervasivedisplays.com/wp-content/uploads/2023/02/ApplicationNote_Spectra_4_smallSize_EPD_v01_20230522.pdf)
///

// SDK and configuration
#include "PDLS_Common.h"

#if (PDLS_COMMON_RELEASE < 902)
#error Required PDLS_COMMON_RELEASE 902
#endif // PDLS_COMMON_RELEASE

// Driver
#include "Driver_EPD_Virtual.h"

#ifndef DRIVER_BWRY_SMALL_RELEASE
///
/// @brief Library release number
///
#define DRIVER_BWRY_SMALL_RELEASE 902

///
/// @name List of supported screens
/// @details Colour black-white-red-yellow "Spectra 4" screens
///
/// @note Normal update
/// @see https://www.pervasivedisplays.com/products/?_sft_etc_itc=itc&_sft_product_colour=black-white-red-yellow
/// @{
///
#define eScreen_EPD_154_QS_0F SCREEN(SIZE_154, FILM_Q, DRIVER_F) ///< reference 154-QS-0F
#define eScreen_EPD_213_QS_0F SCREEN(SIZE_213, FILM_Q, DRIVER_F) ///< reference 213-QS-0F
#define eScreen_EPD_266_QS_0F SCREEN(SIZE_266, FILM_Q, DRIVER_F) ///< reference 266-QS-0F
#define eScreen_EPD_417_QS_0A SCREEN(SIZE_417, FILM_Q, DRIVER_A) ///< reference 417-QS-0A
/// @}

///
/// @name List of features
/// @{
///
#define WITH_COLOURS ///< With colours
#define WITH_COLOURS_BWRY ///< Black-White-Red-Yellow colours
/// @}

///
/// @brief Driver variant
///
#define DRIVER_EPD_RELEASE DRIVER_BWRY_SMALL_RELEASE
#define DRIVER_EPD_VARIANT "BWRY small"

///
/// @brief BWRY small screens class
///
class Pervasive_BWRY_Small : public Driver_EPD_Virtual
{
  public:

    ///
    /// @brief Constructor
    /// @param eScreen_EPD
    /// @param board
    ///
    Pervasive_BWRY_Small(eScreen_EPD_t eScreen_EPD, pins_t board);

    /// @name General
    /// @{

    ///
    /// @brief Initialisation
    /// @details Initialise the board and read OTP
    ///
    void begin();

    ///
    /// @brief Driver reference
    ///
    /// @return STRING_CONST_TYPE scope and release number
    /// @note Example `BWRY small v9.0.0`
    ///
    STRING_CONST_TYPE reference();

    ///
    /// @brief Normal update
    ///
    /// @param frame next image
    /// @param sizeFrame size of the frame
    ///
    void updateNormal(FRAMEBUFFER_CONST_TYPE frame, uint32_t sizeFrame);

    /// @}

  protected:

  private:

    // Variables and functions specific to the screen
    uint8_t COG_data[112]; // OTP

    void COG_reset();
    void COG_getDataOTP();
    void COG_initial();
    void COG_sendImageDataNormal(FRAMEBUFFER_CONST_TYPE frame, uint32_t sizeFrame);
    void COG_update();
    void COG_stopDCDC();
};

#endif // DRIVER_BWRY_SMALL_RELEASE
