

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from pr1.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#ifndef pr1Plugin_368352690_h
#define pr1Plugin_368352690_h

#include "pr1.h"

struct RTICdrStream;

#ifndef pres_typePlugin_h
#include "pres/pres_typePlugin.h"
#endif

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

extern "C" {

    #define MsgPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 

    #define MsgPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define MsgPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

    #define MsgPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define MsgPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern Msg*
    MsgPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern Msg*
    MsgPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern Msg*
    MsgPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    MsgPluginSupport_copy_data(
        Msg *out,
        const Msg *in);

    NDDSUSERDllExport extern void 
    MsgPluginSupport_destroy_data_w_params(
        Msg *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    MsgPluginSupport_destroy_data_ex(
        Msg *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    MsgPluginSupport_destroy_data(
        Msg *sample);

    NDDSUSERDllExport extern void 
    MsgPluginSupport_print_data(
        const Msg *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    MsgPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    MsgPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    MsgPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    MsgPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    MsgPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        Msg *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    MsgPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        Msg *out,
        const Msg *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool
    MsgPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const Msg *sample); 

    NDDSUSERDllExport extern RTIBool
    MsgPlugin_serialize_to_cdr_buffer_ex(
        char *buffer,
        unsigned int *length,
        const Msg *sample,
        DDS_DataRepresentationId_t representation);

    NDDSUSERDllExport extern RTIBool 
    MsgPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        Msg **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    MsgPlugin_deserialize_from_cdr_buffer(
        Msg *sample,
        const char * buffer,
        unsigned int length);    
    #ifndef NDDS_STANDALONE_TYPE
    NDDSUSERDllExport extern DDS_ReturnCode_t
    MsgPlugin_data_to_string(
        const Msg *sample,
        char *str,
        DDS_UnsignedLong *str_size, 
        const struct DDS_PrintFormatProperty *property);    
    #endif

    NDDSUSERDllExport extern unsigned int 
    MsgPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    MsgPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    MsgPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    MsgPlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    MsgPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        Msg ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern
    struct RTIXCdrInterpreterPrograms *MsgPlugin_get_programs();

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    MsgPlugin_new(void);

    NDDSUSERDllExport extern void
    MsgPlugin_delete(struct PRESTypePlugin *);

}

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

#endif /* pr1Plugin_368352690_h */

