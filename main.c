// main.c - contains MGE entry point

#include <mge.h>

// MGE entry point
int main(int argc, char* argv[]) {
  // Load systems
  MGE_requireSystem(MGE_S_Oversystem);
  MGE_requireSystem(MGE_S_Events);

  // Call start event
  //MGE_call(MGE_E_InitEngine, null);
  return 0;
}
