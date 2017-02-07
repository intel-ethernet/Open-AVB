/*
 ******************************************************************
 * COPYRIGHT � Symphony Teleca
 *----------------------------------------------------------------*
 * MODULE : AEM - AVDECC Entity Model Public Interface
 *
 * PROGRAMMER : Ken Carlino (Triple Play Integration)
 * DATE :       21-Nov-2013
 * VERSION :    1.0
 *
 *----------------------------------------------------------------*
 *
 * MODULE SUMMARY : Public Interface for the AVDECC Entity Model Functionality
 *
 *----------------------------------------------------------------*
 *
 * MODIFICATION RECORDS
 *
 ******************************************************************
 */

#ifndef OPENAVB_AEM_PUB_H
#define OPENAVB_AEM_PUB_H 1

#include "openavb_types_pub.h"
#include "openavb_aem_types_pub.h"

typedef struct openavb_descriptor_pvt *openavb_descriptor_pvt_ptr_t;

typedef struct openavb_avdecc_configuration_cfg openavb_avdecc_configuration_cfg_t;

// Before calling any Entity Model functions the AVDECC function openavbAvdeccInitialize() must be called with the Entity Descriptor.
// The Entity Descriptor is the root of all descriptors and must exist to do most things in AVDECC.

// Gets the current configuration descriptor index for the Entity Model. Error checking is not performed on this function.
U16 openavbAemGetConfigIdx(void);

// Adds descriptors to the Entity Model. The Configuration Descriptor must be added first.
bool openavbAemAddDescriptor(void *pDescriptor, U16 configIdx, U16 *pResultIdx);

// Get a pointer to a descriptor in the Entity Model.
void *openavbAemGetDescriptor(U16 configIdx, U16 descriptorType, U16 descriptorIdx);

// Get the index of the descriptor in the Entity Model, or OPENAVB_AEM_DESCRIPTOR_INVALID if not found.
U16 openavbAemGetDescriptorIndex(U16 configIdx, const void *pDescriptor);

// Add a string to a standard descriptor U8 [64] string field.
bool openavbAemSetString(U8 *pMem, const char *pString);

// Checks if the Entity Model is acquired.
bool openavbAemIsAcquired(void);

// Checks if the Entity Model is locked.
bool openavbAemIsLocked(void);

// Sets the internal Entity Model acquired flag. Care should be used with this function it can impact controller access.
bool openavbAemAcquire(bool flag);

// Sets the internal Entity Model acquired flag. Care should be used with this function it can impact controller access.
bool openavbAemLock(bool flag);


#endif // OPENAVB_AEM_PUB_H