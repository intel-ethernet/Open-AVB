/*
 ******************************************************************
 * COPYRIGHT � Symphony Teleca
 *----------------------------------------------------------------*
 * MODULE : AEM - AVDECC Stream IO Descriptor Public Interface
 *
 * PROGRAMMER : Ken Carlino (Triple Play Integration)
 * DATE :       3-Dec-2013
 * VERSION :    1.0
 *
 *----------------------------------------------------------------*
 *
 * MODULE SUMMARY : Pulbic Interface for the Stream IO Desciptor
 *
 *----------------------------------------------------------------*
 *
 * MODIFICATION RECORDS
 *
 ******************************************************************
 */

#ifndef OPENAVB_DESCRIPTOR_STREAM_IO_PUB_H
#define OPENAVB_DESCRIPTOR_STREAM_IO_PUB_H 1

#include "openavb_types_pub.h"
#include "openavb_aem_types_pub.h"
#include "openavb_aem_pub.h"
#include "openavb_tl_pub.h"
#include "openavb_avdecc_read_ini_pub.h"

#define OPENAVB_DESCRIPTOR_STREAM_IO_MAX_FORMATS (47)

// STREAM IO Descriptor IEEE Std 1722.1-2013 clause 7.2.6
typedef struct {
	openavb_descriptor_pvt_ptr_t descriptorPvtPtr;

	U16 descriptor_type;
	U16 descriptor_index;
	U8 object_name[OPENAVB_AEM_STRLEN_MAX];
	openavb_aem_string_ref_t localized_description;
	U16 clock_domain_index;
	U16 stream_flags;
	openavb_aem_stream_format_t current_format;
	U16 formats_offset;
	U16 number_of_formats;
	U8 backup_talker_entity_id_0[8];
	U16 backup_talker_unique_id_0;
	U8 backup_talker_entity_id_1[8];
	U16 backup_talker_unique_id_1;
	U8 backup_talker_entity_id_2[8];
	U16 backup_talker_unique_id_2;
	U8 backedup_talker_entity_id[8];
	U16 backedup_talker_unique_id;
	U16 avb_interface_index;
	U32 buffer_length;
	openavb_aem_stream_format_t stream_formats[OPENAVB_DESCRIPTOR_STREAM_IO_MAX_FORMATS];

	// Also save a pointer to the supplied stream information.
	const openavb_tl_data_cfg_t *stream;

} openavb_aem_descriptor_stream_io_t;

openavb_aem_descriptor_stream_io_t *openavbAemDescriptorStreamInputNew(void);
openavb_aem_descriptor_stream_io_t *openavbAemDescriptorStreamOutputNew(void);

bool openavbAemDescriptorStreamInputInitialize(openavb_aem_descriptor_stream_io_t *pDescriptor, U16 nConfigIdx, const openavb_avdecc_configuration_cfg_t *pConfig);
bool openavbAemDescriptorStreamOutputInitialize(openavb_aem_descriptor_stream_io_t *pDescriptor, U16 nConfigIdx, const openavb_avdecc_configuration_cfg_t *pConfig);

#endif // OPENAVB_DESCRIPTOR_STREAM_IO_PUB_H