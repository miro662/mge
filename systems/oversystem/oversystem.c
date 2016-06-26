// systems/oversystem/oversystem.c - defines function related to oversystem
//                                   (system which manages other systems)

#include <mge.h>

typedef struct {
  void (*systemConstructor)();
  struct MGE_SystemsListItem *next;
} MGE_SystemsListItem;

MGE_SystemsListItem *systems = NULL;

void MGE_S_Oversystem() {
  atexit(MGE_freeSystemList);
}

void MGE_freeSystemList() {
  MGE_SystemsListItem* nextSystem = systems;
  while (nextSystem != NULL) {
    MGE_SystemsListItem* currentSystem = nextSystem;
    nextSystem = (MGE_SystemsListItem*) currentSystem->next;

    free(currentSystem);
  }
}

void MGE_loadSystem(void (*systemConstructor)()) {
  // create new system
  MGE_SystemsListItem* newSystem = malloc(sizeof(MGE_SystemsListItem));
  newSystem->systemConstructor = systemConstructor;
  newSystem->next = (struct MGE_SystemsListItem*) systems;

  // add new system to list
  systems = newSystem;

  // call new system's constructor
  (systems->systemConstructor)();
}

bool MGE_isSystemLoaded(void (*systemConstructor)()) {
  MGE_SystemsListItem* nextSystem = systems;
  while (nextSystem != NULL) {
    MGE_SystemsListItem* currentSystem = nextSystem;
    nextSystem = (MGE_SystemsListItem*) currentSystem->next;

    if (currentSystem->systemConstructor == systemConstructor) {
      return true;
    }
  }
  return false;
}

void MGE_requireSystem(void (*systemConstructor)()) {
  if (!MGE_isSystemLoaded(systemConstructor)) {
    MGE_loadSystem(systemConstructor);
  }
}
