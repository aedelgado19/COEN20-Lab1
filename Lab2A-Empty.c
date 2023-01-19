#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


//convert array of binary bits to signed int
// Input:   bits[0] = Least significant bit
//          bits[7] = Most significant bit
// Output:  0 <= return value < 255
uint32_t Bits2Unsigned(int8_t bits[8]){
  uint32_t value = 0;
  for (int i = 0; i < 8; i++){
    value += (bits[i] * pow(2,i));
    printf("%u\n", value);
  }

  
  return value ;
}

// Input:   bits[0] = Least significant bit
//          bits[7] = Most significant bit
// Output: -128 <= return value <= +127
int32_t Bits2Signed(int8_t bits[8]){
  int32_t value = 0;

  //just calculate as regular and subtract the overflow
  for (int i = 0; i < 7; i++){
    value += (bits[i] * pow(2,i));
    printf("%i\n", value);
  }
  if(bits[7] == 1){
    value -= 128;
    printf("was negative: %i\n", value);
  }
  return value ;
}

//add 1 to binary 
void Increment(int8_t bits[8]){
  int32_t bit = 0;
  int32_t sum = 0;
  if(bits[0] == 0){
    bits[0] = 1;
    return;
  } 
  bits[0] = 0;
  int carry = 0; // fake boolean: 0 = false, 1 = true
  for(int i = 1; (carry == 0) && (i < 8); i++){
    if(bits[i] == 0){
      bits[i] = 1;
      carry = 1;
    } else {
      bits[i] = 0;
    }
  }
  //  printf("end result: %i", Bits2Signed(bits));
}


// Input:   0 <= n <= 255
// Output:  Converts n to an array of bits
// Where:   bits[0] = Least significant bit
//          bits[7] = Most significant bit
void Unsigned2Bits(uint32_t n, int8_t bits[8]){
  //  int32_t bit;
  int storage[8];
  for (int i = 7; i >= 0; i--){
    storage[i] = n % 2;
    n /= 2;
  }
  //storage array holds the binary, will be in reverse order
  for (int j = 0; j < 8; j++){
    printf("%d", storage[j]);
  }

}

int main(){
  /*  char input[8];
  uint32_t n;
  printf("Enter your 8 bit array: ");
  scanf("%s", input);
  */
  int8_t test[8] = {1,1,1,1,1,1,1,1};

  //enter in backwards!!!
  
  Bits2Unsigned(test);
  printf("bits 2 unsigned done, now bits 2 signed\n");
  Bits2Signed(test);
  Increment(test);
  Unsigned2Bits(65, test);
  return 0;
}
