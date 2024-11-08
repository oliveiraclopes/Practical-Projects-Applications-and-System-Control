#include "16f874.h"
#device adc=8
#use delay(clock=1000000)
#fuses XT, NOWDT, NOPUT

void main() {
   int i = 0;
   long int voltage[5];            // Array to store 5 ADC readings
   long int sum_voltage = 0;
   long int avg_voltage;           // Variable for average voltage calculation
   char avg;                       // Variable to store the final average value as char

   setup_adc_ports(ALL_ANALOG);    // Set all ports as analog
   setup_adc(ADC_CLOCK_INTERNAL);  // Set ADC clock source
   set_adc_channel(0);             // Set ADC to read from channel 0
   delay_us(100);                  // Small delay for ADC stabilization
   output_high(PIN_C0);            // Set PIN_C0 high

   while(1) {
      // Loop to read ADC values and store them in the array
      for(i = 0; i <= 4; i++) {
         delay_ms(1);
         voltage[i] = read_adc();
      }
      
      // Calculate the average of the 5 ADC values
      avg_voltage = (long int)((voltage[0] + voltage[1] + voltage[2] + voltage[3] + voltage[4]) / 5);
      i = 0;
      avg = (char) avg_voltage;   // Convert the average voltage to char
      output_d(avg);              // Output the average to PORTD
      output_low(PIN_C0);         // Set PIN_C0 low
      delay_ms(10);               // Delay for output stabilization
      output_high(PIN_C0);        // Set PIN_C0 high
   }   
}
