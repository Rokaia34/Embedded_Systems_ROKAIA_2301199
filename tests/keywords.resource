*** Keywords ***
# Device Connection
Connect to Device
    Log    Connecting to embedded UART device...

Close Device Connection
    Log    Closing connection to device...

# Use Case 1: Button Input
Send Button Press
    Log    Simulating button press
    [Return]    button_pressed

Send Button Release
    Log    Simulating button release
    [Return]    button_released

Verify UART Message
    [Arguments]    ${expected}    ${actual}
    Should Be Equal    ${actual}    ${expected}

# Use Case 2: LED Control
Send UART Command
    [Arguments]    ${command}
    Log    Sending UART command: ${command}
    # Simulate response from device
    Run Keyword If    '${command}'=='led_on'    Set Variable    LED turned ON
    ...    ELSE IF    '${command}'=='led_off'    Set Variable    LED turned OFF
    ...    ELSE    Set Variable    Unknown command
    [Return]    ${command}

Verify LED State
    [Arguments]    ${expected_state}
    Log    Checking LED state is: ${expected_state}
