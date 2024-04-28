[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/WyWUi_sY)
[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-718a45dd9cf7e7f842a935f5ebbe5719a5e09af4491e668f4dbf3b35d5cca122.svg)](https://classroom.github.com/online_ide?assignment_repo_id=13234862&assignment_repo_type=AssignmentRepo)

# *Overview*
+ This C program is designed for implementing a SMART SECURITY SYSTEM, specifically targeting the MKL25Z4 microcontroller. It demonstrates the usage of various peripherals including I2C communication, PWM for LED control, and GPIO for sensor and buzzer interfacing. The primary functionality revolves around detecting obstacles using an IR sensor, controlling RGB LED brightness, and playing tones with a buzzer to generate an alarm.

# *Key Features*
+ **I2C Communication**: Implements I2C protocol for communicating with devices like the ZX Sensor.
+ **RGB LED Control**: Utilizes PWM (Pulse Width Modulation) to adjust the brightness of RGB LEDs.
+ **IR Sensor Interfacing**: Detects obstacles using an IR sensor connected to a GPIO pin.
+ **Buzzer Control**: Generates sound by PWM connected to a buzzer.

# *Code Structure*
+ **Preprocessor Directives**: Includes necessary headers and defines macros for pin assignments and configurations.
    - **Initialization Functions**:
        + **init_Buzzer()**: Configures GPIO for buzzer control.
        + **init_RGB_LED()**: Sets up PWM for RGB LED control.
        + **init_IR_Sensor()**: Initializes GPIO for IR sensor input.
        + **i2c_init()**: Initializes I2C0 peripheral for communication.

    - **Utility Functions**:
        + **delayMicroseconds()**: Provides a delay mechanism.
        + **playTone()**: Plays a tone using the buzzer.
        + **set_Red_LED_Brightness()**: Adjusts the brightness of the red LED.
        + **i2c_start(), i2c_stop(), i2c_send_byte(), i2c_read_byte()**: Manage I2C data transmission and reception.
        + **zx_read_register(), zx_write_register()**: Read from and write to ZX sensor registers via I2C.
    - **Main Function**: The main() function initializes peripherals and runs a loop that:
        + Reads the IR sensor and detects obstacles.
        + Controls the red LED brightness and buzzer based on the sensor input.
        + Reads data from the ZX sensor using I2C.

# *Hardware Requirements*
+ **MCU**: MKL25Z4 Microcontroller.
+ **Peripherals**:
    - RGB LED connected to TPM channels.
    - Buzzer connected to a GPIO pin.
    - IR sensor connected to a GPIO pin.
    - ZX sensor (or any I2C compatible device).

# *Software Requirements*
+ **Development Environment**: Any IDE or toolchain that supports MKL25Z4 (e.g., MCUXpresso, Keil).
+ **Libraries**: Standard C library, board-specific headers (board.h, peripherals.h, etc.).

# *Usage*
+ **Setup**: Connect the hardware components as defined in the macro definitions.
+ **Compilation**: Compile the program using a suitable compiler for MKL25Z4.
+ **Deployment**: Flash the compiled program to the MKL25Z4 microcontroller.
+ **Operation**: On powering up, the MCU will start monitoring the IR sensor and react accordingly by adjusting LED brightness and playing tones.

# *Notes*
+ The code is structured for readability and modular design.
+ It is recommended to understand the MKL25Z4 MCU features and consult its datasheet for detailed information on the peripherals used.
+ The I2C address and register values should match those of the connected I2C device (ZX Sensor in this case).

# *Screenshots*

+ *Logic Analyzer 1*

![Logic_1](https://github.com/unph4914/Final_project_esd/assets/143901715/b9e6b44d-72d4-4026-b0a5-61a433d25c8a)

+ *Logic Analyzer 2*

![Logic_2](https://github.com/unph4914/Final_project_esd/assets/143901715/447c2ff3-e4fa-40d9-bb3a-135624f70a0b)

+ *Output 1*

![Output_1](https://github.com/unph4914/Final_project_esd/assets/143901715/dfc88fb6-feb3-4d97-afdb-1d104779f879)

+ *Output 2*

![Output_2](https://github.com/unph4914/Final_project_esd/assets/143901715/3c4d423f-5a9c-4f12-9e93-2a58f9d7ee8a)

+ *State Diagram*

![State_diagram](https://github.com/unph4914/Final_project_esd/assets/143901715/ff81fc5c-eab5-4f9a-ae6c-f2ec92e16b2e)
