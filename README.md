## Tutorial 1 : LED Blink
Here we will be using the General purpose I/O pins and configuring them to be an output and writing data to it. We setup an external LED which will be driven by the GPIO pin.

## Tutorial 2 : LED Switch
Here we will use digital inputs as well as outputs. We setup an external switch and LED. When the switch is pressed the LED turns off and vice versa.

## Tutorial 3 : External Interrupts
Here we use INT0 which is an external interrupt to trigger RED led blink. Otherwise the program keeps blinking the GREEN led. If the switch is polled, we have to wait for the delay of the GREEN led blink before we can start blinking the RED one, while on the other hand using it as an interrupt takes care of this issue.