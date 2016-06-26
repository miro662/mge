// main.c - contains MGE entry point

#include <mge.h>

void start(void* data)
{
  printf("starting\n");
}

void aexit(void* data)
{
  printf("exiting\n");
}

// MGE entry point
int main(int argc, char* argv[]) {
  // Load systems
  MGE_requireSystem(MGE_S_Oversystem);
  MGE_requireSystem(MGE_S_Events);

  //b
  MGE_addCallback(&MGE_E_AtStart, start);
  MGE_addCallback(&MGE_E_AtExit, aexit);
  //b

  // Call start event
  MGE_call(MGE_E_Start, NULL);
  return 0;
}
