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
void MGE_AddCallback(MGE_Event* event, void (*callback)(void*));
// Removes calllback from event
// void MGE_RemoveCallback(MGE_Event* event, void (*callback)(void*));
// Calls event with given data
void MGE_Call(MGE_Event event, void* data);
// Frees event
void MGE_FreeEvent(MGE_Event event);

// ===== SYSTEMS =====

// Events - system which handles event management
void MGE_S_Events();


#endif
