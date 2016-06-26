// systems/events/eventmgmt.c - implementation of event management functions

#include <mge.h>

void MGE_addCallback(MGE_Event* event, void (*callback)(void*)) {
  MGEI_EventCallback* newCallback = malloc(sizeof(MGEI_EventCallback));
  newCallback->callback = callback;
  newCallback->nextCallback = (struct MGEI_EventCallback*) *event;

  *event = newCallback;
}

void MGE_call(MGE_Event event, void* data) {
  MGEI_EventCallback* next = event;
  while (next != NULL) {
    MGEI_EventCallback* current = next;
    next = (MGEI_EventCallback*) next->nextCallback;
    (current->callback)(data);
  }
}

void MGE_freeEvent(MGE_Event event) {
  MGEI_EventCallback* next = event;
  while (next != NULL) {
    MGEI_EventCallback* current = next;
    next = (MGEI_EventCallback*) next->nextCallback;
    free(current);
  }
}
