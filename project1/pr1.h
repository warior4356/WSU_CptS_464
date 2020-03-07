

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from pr1.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#ifndef pr1_368352690_h
#define pr1_368352690_h

#ifndef NDDS_STANDALONE_TYPE
#ifndef ndds_cpp_h
#include "ndds/ndds_cpp.h"
#endif
#include "rti/xcdr/Interpreter.hpp"
#else
#include "ndds_standalone_type.h"
#endif

static const DDS_Long MSG_LEN= 256;

extern "C" {

    extern const char *MsgTYPENAME;

}

struct MsgSeq;
#ifndef NDDS_STANDALONE_TYPE
class MsgTypeSupport;
class MsgDataWriter;
class MsgDataReader;
#endif
class Msg 
{
  public:
    typedef struct MsgSeq Seq;
    #ifndef NDDS_STANDALONE_TYPE
    typedef MsgTypeSupport TypeSupport;
    typedef MsgDataWriter DataWriter;
    typedef MsgDataReader DataReader;
    #endif

    DDS_Char *   sender ;
    DDS_Char *   message ;

};
#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

#ifndef NDDS_STANDALONE_TYPE
NDDSUSERDllExport DDS_TypeCode* Msg_get_typecode(void); /* Type code */
NDDSUSERDllExport RTIXCdrTypePlugin *Msg_get_type_plugin_info(void);
NDDSUSERDllExport RTIXCdrSampleAccessInfo *Msg_get_sample_access_info(void);
NDDSUSERDllExport RTIXCdrSampleAccessInfo *Msg_get_sample_seq_access_info(void);
#endif

DDS_SEQUENCE(MsgSeq, Msg);

NDDSUSERDllExport
RTIBool Msg_initialize(
    Msg* self);

NDDSUSERDllExport
RTIBool Msg_initialize_ex(
    Msg* self,RTIBool allocatePointers,RTIBool allocateMemory);

NDDSUSERDllExport
RTIBool Msg_initialize_w_params(
    Msg* self,
    const struct DDS_TypeAllocationParams_t * allocParams);  

NDDSUSERDllExport
RTIBool Msg_finalize_w_return(
    Msg* self);

NDDSUSERDllExport
void Msg_finalize(
    Msg* self);

NDDSUSERDllExport
void Msg_finalize_ex(
    Msg* self,RTIBool deletePointers);

NDDSUSERDllExport
void Msg_finalize_w_params(
    Msg* self,
    const struct DDS_TypeDeallocationParams_t * deallocParams);

NDDSUSERDllExport
void Msg_finalize_optional_members(
    Msg* self, RTIBool deletePointers);  

NDDSUSERDllExport
RTIBool Msg_copy(
    Msg* dst,
    const Msg* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

#ifndef NDDS_STANDALONE_TYPE
namespace rti { 
    namespace xcdr {
        template <>
        struct type_code<Msg> {
            static const RTIXCdrTypeCode * get();
        };

    } 
}

#endif

#endif /* pr1 */

