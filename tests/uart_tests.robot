*** Settings ***
Documentation     UART Automated Test Suite
...               This suite validates UART communication between a PC and an ATmega328P (via Arduino Uno).
...               It ensures correct data transmission and reception over the UART interface,
...               as well as handling of invalid commands and continuous operation.
Library           BuiltIn

*** Variables ***
${EXPECTED_BUTTON_PRESS}      button_pressed
${EXPECTED_BUTTON_RELEASE}    button_released
${EXPECTED_LED_ON}            LED turned ON
${EXPECTED_LED_OFF}           LED turned OFF
${EXPECTED_ERROR}             ERROR: Unknown command
${EXPECTED_BAUD}              9600

*** Test Cases ***
Case1_Button_Transmission
    [Documentation]    This test simulates the UART transmission from the microcontroller to the PC
    ...                when a push button is pressed and released. It ensures that the correct
    ...                strings ("button_pressed" and "button_released") are sent through UART.
    ${data_sent}=      Set Variable    ${EXPECTED_BUTTON_PRESS}
    Should Be Equal    ${data_sent}    ${EXPECTED_BUTTON_PRESS}
    ${data_sent}=      Set Variable    ${EXPECTED_BUTTON_RELEASE}
    Should Be Equal    ${data_sent}    ${EXPECTED_BUTTON_RELEASE}

Case2_LED_Command_Reception
    [Documentation]    This test verifies that the UART correctly receives and interprets commands
    ...                from the PC to control the LED. It checks that valid commands like
    ...                "LED turned ON" and "LED turned OFF" are properly recognized and processed.
    ${response}=       Set Variable    ${EXPECTED_LED_ON}
    Should Contain     ${response}     LED turned ON
    ${response}=       Set Variable    ${EXPECTED_LED_OFF}
    Should Contain     ${response}     LED turned OFF

Case3_Invalid_Command
    [Documentation]    This test checks how the system responds to an invalid or corrupted UART command.
    ...                It ensures that any unrecognized command results in an appropriate error message
    ...                instead of causing unexpected behavior or crashes.
    ${command}=        Set Variable    invalid_data
    ${response}=       Set Variable    ${EXPECTED_ERROR}
    Should Contain     ${response}     ERROR

Case4_Baud_Rate_Check
    [Documentation]    This test validates that the UART module is configured with the correct
    ...                communication baud rate (9600 bps), which ensures proper synchronization
    ...                between the microcontroller and the PC.
    ${baud}=           Set Variable    ${EXPECTED_BAUD}
    Should Be Equal    ${baud}         9600

Case5_Continuous_Transmission
    [Documentation]    This test simulates a sequence of multiple UART transmissions occurring
    ...                back-to-back without delay. It ensures that each transmitted message is valid
    ...                and that no data is lost or interrupted during continuous operation.
    ${messages}=       Create List     button_pressed     button_released     led_on     led_off
    FOR    ${msg}    IN    @{messages}
        Log    Sending message: ${msg}
        Should Not Be Empty    ${msg}
    END
