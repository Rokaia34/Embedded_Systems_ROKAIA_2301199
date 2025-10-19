*** Settings ***
Documentation     UART interface tests for embedded button inputs and LED control
Resource          ../resources/keywords.resource
Default Tags      embedded

*** Test Cases ***

# ===============================
# Use Case 1: Button Input UART
# ===============================

Button Press Message
    Connect to Device
    ${msg}=    Send Button Press
    Verify UART Message    button_pressed    ${msg}
    [Teardown]    Close Device Connection

Button Release Message
    Connect to Device
    ${msg}=    Send Button Release
    Verify UART Message    button_released    ${msg}
    [Teardown]    Close Device Connection

Button Press and Release Sequence
    Connect to Device
    ${press}=    Send Button Press
    Verify UART Message    button_pressed    ${press}
    ${release}=    Send Button Release
    Verify UART Message    button_released    ${release}
    [Teardown]    Close Device Connection

# ===============================
# Use Case 2: LED Control UART
# ===============================

Turn LED On
    Connect to Device
    ${cmd}=    Send UART Command    led_on
    Verify LED State    ON
    [Teardown]    Close Device Connection

Turn LED Off
    Connect to Device
    ${cmd}=    Send UART Command    led_off
    Verify LED State    OFF
    [Teardown]    Close Device Connection

Invalid LED Command
    Connect to Device
    ${cmd}=    Send UART Command    led_blink
    Verify UART Message    Unknown command    ${cmd}
    [Teardown]    Close Device Connection

LED On/Off Sequence
    Connect to Device
    ${cmd1}=    Send UART Command    led_on
    Verify LED State    ON
    ${cmd2}=    Send UART Command    led_off
    Verify LED State    OFF
    [Teardown]    Close Device Connection
