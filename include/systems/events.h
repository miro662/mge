#ifndef __SYSTEMS_EVENTS_H
#define __SYSTEMS_EVENTS_H

// systems/events.h - defines system which handles event managemet

// ===== TYPES =====

// Describes event
typedef struct {
  void (*callback)(void*);
  struct MGEI_EventCallback* nextCallback;
} MGEI_EventCallback;

typedef MGEI_EventCallback* MGE_Event;

// ===== FUNCTIONS =====

// Adds callback to event
void MGE_addCallback(MGE_Event* event, void (*callback)(void*));
// Removes calllback from event
// void MGE_RemoveCallback(MGE_Event* event, void (*callback)(void*));
// Calls event with given data
void MGE_call(MGE_Event event, void* data);
// Frees event
void MGE_freeEvent(MGE_Event event);

// ===== SYSTEMS =====

// Events - system which handles event management
void MGE_S_Events();

// ===== EVENTS =====

// Event called after everything is loaded by main function
extern MGE_Event MGE_E_Start;
// Event called after calling systems' constructors, but before starting
extern MGE_Event MGE_E_AtStart;
// Event called in order to exit from the game
extern MGE_Event MGE_E_Exit;
// Event called on exiting program (by function attached to atexit)
extern MGE_Event MGE_E_AtExit;



#endif
