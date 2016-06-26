// systems/events/system.c - defines system which handles event managemet

#include <mge.h>

MGE_Event MGE_E_Start = NULL;
MGE_Event MGE_E_AtStart = NULL;
MGE_Event MGE_E_Exit = NULL;
MGE_Event MGE_E_AtExit = NULL;

void startEventsSystem(void* data);
void eventsExit(void* data);
void eventsAtExit();

void MGE_S_Events() {
  MGE_requireSystem(MGE_S_Oversystem);

  MGE_addCallback(&MGE_E_Start, startEventsSystem);
  MGE_addCallback(&MGE_E_Exit, eventsExit);
  atexit(eventsAtExit);
}

void startEventsSystem(void* data) {
  MGE_call(MGE_E_AtStart, NULL);
}

void eventsExit(void* data) {
  exit(0);
}

void eventsAtExit() {
  MGE_call(MGE_E_AtExit, NULL);

  MGE_freeEvent(MGE_E_Start);
  MGE_freeEvent(MGE_E_AtStart);
  MGE_freeEvent(MGE_E_AtExit);
  MGE_freeEvent(MGE_E_Exit);
}
