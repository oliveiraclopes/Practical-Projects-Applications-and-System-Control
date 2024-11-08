#include "16f874.h"
#device adc=8
#use delay(clock=1000000)
#fuses XT, NOWDT, NOPUT

// Function to calculate the median of three values
long int median(long int *vec) {
   long int temp;
   long int sorted[3];   // Array to hold sorted values
   
   sorted[0] = vec[0];
   sorted[1] = vec[1];
   sorted[2] = vec[2];
   
   // Sort the three values to find the median
   if (sorted[0] > sorted[1]) {
      temp = sorted[0];
      sorted[0] = sorted[1];
      sorted[1] = temp;
   }
   if (sorted[0] > sorted[2]) {
      temp = sorted[0];
      sorted[0] = sorted[2];
      sorted[2] = temp;
   }
   if (sorted[1] > sorted[2]) {
      temp = sorted[1];
      sorted[1] = sorted[2];
      sorted[2] = temp;
   }
   
   return sorted[1]; // Return the median value
}

void main() {
   int i = 0;
   long int voltage[12];           // Array to store ADC readings
   long int sum_voltage = 0;
   long int avg_voltage;
   char avg;
   
   setup_adc_ports(ALL_ANALOG);    // Set all ports as analog
   setup_adc(ADC_CLOCK_INTERNAL);  // Set ADC clock source
   set_adc_channel(0);             // Set ADC to read from channel 0
   delay_us(100);                  // Small delay for ADC stabilization
   output_high(PIN_C0);            // Set PIN_C0 high

   while(1) {
      // Fill voltage array with ADC readings
      for (i = 1; i < 11; i++) {
         delay_ms(1);
         voltage[i] = read_adc();
      }
      voltage[0] = voltage[1];      // Repeat the first sample
      voltage[11] = voltage[10];    // Repeat the last sample

      // Apply median filtering and output results
      for (i = 0; i < 10; i++) {
         output_d(median(&voltage[i])); // Output the median of three samples
         output_low(PIN_C0);           // Set PIN_C0 low
         delay_ms(10);
         output_high(PIN_C0);          // Set PIN_C0 high
      }
   }
}