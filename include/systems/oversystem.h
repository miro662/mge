#ifndef __SYSTEMS_OVERSYSTEM_H
#define __SYSTEMS_OVERSYSTEM_H

// systems/oversystem.h - defines function related to oversystem
//                        (system which manages other systems)

// ===== FUNCTIONS =====

// Loads system
void MGE_loadSystem(void (*systemConstructor)());
// Checks if system is loaded, returns 1 if it is, returns 0 if not
bool MGE_isSystemLoaded(void (*systemConstructor)());
// Loads system if it is not loaded
void MGE_requireSystem(void (*systemConstructor)());
// Frees system list
void MGE_freeSystemList();

// ===== SYSTEMS =====

// Oversystem - system which manages other systems
void MGE_S_Oversystem();


#endif
