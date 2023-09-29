/*
 * DEBUGGER code
 * 
 * On "publish", when buffer is free, debugger stores arbitrary variables 
 * content into, and mark this buffer as filled
 * 
 * 
 * Buffer content is read asynchronously, (from non real time part), 
 * and then buffer marked free again.
 *  
 * 
 * */
#ifdef TARGET_DEBUG_AND_RETAIN_DISABLE

void __init_debug    (void){}
void __cleanup_debug (void){}
void __retrieve_debug(void){}
void __publish_debug (void){}

#else

#include "iec_types_all.h"
#include "POUS.h"
/*for memcpy*/
#include <string.h>
#include <stdio.h>

typedef unsigned int dbgvardsc_index_t;
typedef unsigned short trace_buf_offset_t;

#define BUFFER_EMPTY 0
#define BUFFER_FULL 1

#ifndef TARGET_ONLINE_DEBUG_DISABLE

#define TRACE_BUFFER_SIZE 4096
#define TRACE_LIST_SIZE 1024

/* Atomically accessed variable for buffer state */
static long trace_buffer_state = BUFFER_EMPTY;

typedef struct trace_item_s {
    dbgvardsc_index_t dbgvardsc_index;
} trace_item_t;

trace_item_t trace_list[TRACE_LIST_SIZE];
char trace_buffer[TRACE_BUFFER_SIZE];

/* Trace's cursor*/
static trace_item_t *trace_list_collect_cursor = trace_list;
static trace_item_t *trace_list_addvar_cursor = trace_list;
static const trace_item_t *trace_list_end = 
    &trace_list[TRACE_LIST_SIZE-1];
static char *trace_buffer_cursor = trace_buffer;
static const char *trace_buffer_end = trace_buffer + TRACE_BUFFER_SIZE;



#define FORCE_BUFFER_SIZE 1024
#define FORCE_LIST_SIZE 256

typedef struct force_item_s {
    dbgvardsc_index_t dbgvardsc_index;
    void *value_pointer_backup;
} force_item_t;

force_item_t force_list[FORCE_LIST_SIZE];
char force_buffer[FORCE_BUFFER_SIZE];

/* Force's cursor*/
static force_item_t *force_list_apply_cursor = force_list;
static force_item_t *force_list_addvar_cursor = force_list;
static const force_item_t *force_list_end = 
    &force_list[FORCE_LIST_SIZE-1];
static char *force_buffer_cursor = force_buffer;
static const char *force_buffer_end = force_buffer + FORCE_BUFFER_SIZE;


#endif

/***
 * Declare programs 
 **/
extern PROGRAM3 RES0__INSTANCE0;

/***
 * Declare global variables from resources and conf 
 **/
extern       PROGRAM3   RES0__INSTANCE0;

typedef const struct {
    void *ptr;
    __IEC_types_enum type;
} dbgvardsc_t;

static const dbgvardsc_t dbgvardsc[] = {
{&(RES0__INSTANCE0.FACTORYIORESET0), BOOL_ENUM},
{&(RES0__INSTANCE0.STARTBUTTON0), BOOL_ENUM},
{&(RES0__INSTANCE0.ESTOP0), BOOL_ENUM},
{&(RES0__INSTANCE0.RETRO0), BOOL_ENUM},
{&(RES0__INSTANCE0.RETRO1), BOOL_ENUM},
{&(RES0__INSTANCE0.VS00), BOOL_ENUM},
{&(RES0__INSTANCE0.VS01), BOOL_ENUM},
{&(RES0__INSTANCE0.VS02), BOOL_ENUM},
{&(RES0__INSTANCE0.VS03), BOOL_ENUM},
{&(RES0__INSTANCE0.TAPP0_DETECTED), BOOL_ENUM},
{&(RES0__INSTANCE0.TAPP0_MOVINGX), BOOL_ENUM},
{&(RES0__INSTANCE0.TAPP0_MOVINGZ), BOOL_ENUM},
{&(RES0__INSTANCE0.TAPP0_ROTATING), BOOL_ENUM},
{&(RES0__INSTANCE0.RETRO2), BOOL_ENUM},
{&(RES0__INSTANCE0.RETROREFLECTIVESENSOR3), BOOL_ENUM},
{&(RES0__INSTANCE0.RETRO4), BOOL_ENUM},
{&(RES0__INSTANCE0.VS10), BOOL_ENUM},
{&(RES0__INSTANCE0.VS11), BOOL_ENUM},
{&(RES0__INSTANCE0.VS12), BOOL_ENUM},
{&(RES0__INSTANCE0.VISIONSENSOR13), BOOL_ENUM},
{&(RES0__INSTANCE0.TAPP1_DETECTED), BOOL_ENUM},
{&(RES0__INSTANCE0.TWOAXISPICKPLACE1_MOVINGX), BOOL_ENUM},
{&(RES0__INSTANCE0.TWOAXISPICKPLACE1_MOVINGZ), BOOL_ENUM},
{&(RES0__INSTANCE0.TWOAXISPICKPLACE1_ROTATING), BOOL_ENUM},
{&(RES0__INSTANCE0.RETROREFLECTIVESENSOR5), BOOL_ENUM},
{&(RES0__INSTANCE0.RETROREFLECTIVESENSOR6), BOOL_ENUM},
{&(RES0__INSTANCE0.RETRO7), BOOL_ENUM},
{&(RES0__INSTANCE0.VS20), BOOL_ENUM},
{&(RES0__INSTANCE0.VS21), BOOL_ENUM},
{&(RES0__INSTANCE0.VS22), BOOL_ENUM},
{&(RES0__INSTANCE0.VISIONSENSOR23), BOOL_ENUM},
{&(RES0__INSTANCE0.TAPP2_DETECTED), BOOL_ENUM},
{&(RES0__INSTANCE0.TWOAXISPICKPLACE2_MOVINGX), BOOL_ENUM},
{&(RES0__INSTANCE0.TWOAXISPICKPLACE2_MOVINGZ), BOOL_ENUM},
{&(RES0__INSTANCE0.TWOAXISPICKPLACE2_ROTATING), BOOL_ENUM},
{&(RES0__INSTANCE0.RETROREFLECTIVESENSOR8), BOOL_ENUM},
{&(RES0__INSTANCE0.RETROREFLECTIVESENSOR9), BOOL_ENUM},
{&(RES0__INSTANCE0.RETROREFLECTIVESENSOR10), BOOL_ENUM},
{&(RES0__INSTANCE0.VISIONSENSOR30), BOOL_ENUM},
{&(RES0__INSTANCE0.VISIONSENSOR31), BOOL_ENUM},
{&(RES0__INSTANCE0.VISIONSENSOR32), BOOL_ENUM},
{&(RES0__INSTANCE0.VISIONSENSOR33), BOOL_ENUM},
{&(RES0__INSTANCE0.RETRO11), BOOL_ENUM},
{&(RES0__INSTANCE0.RETRO12), BOOL_ENUM},
{&(RES0__INSTANCE0.RETRO13), BOOL_ENUM},
{&(RES0__INSTANCE0.RETRO14), BOOL_ENUM},
{&(RES0__INSTANCE0.RETRO15), BOOL_ENUM},
{&(RES0__INSTANCE0.RETRO16), BOOL_ENUM},
{&(RES0__INSTANCE0.TAPP0X), BOOL_ENUM},
{&(RES0__INSTANCE0.TAPP0Z), BOOL_ENUM},
{&(RES0__INSTANCE0.TAPP0_GRAB), BOOL_ENUM},
{&(RES0__INSTANCE0.TAPP0_ROTATECW), BOOL_ENUM},
{&(RES0__INSTANCE0.TAPP0_ROTATECCW), BOOL_ENUM},
{&(RES0__INSTANCE0.BC_6M_0), BOOL_ENUM},
{&(RES0__INSTANCE0.BC_6M_1), BOOL_ENUM},
{&(RES0__INSTANCE0.BC_6M_2), BOOL_ENUM},
{&(RES0__INSTANCE0.BC_6M_3), BOOL_ENUM},
{&(RES0__INSTANCE0.BC_6M_4), BOOL_ENUM},
{&(RES0__INSTANCE0.TAPP1X), BOOL_ENUM},
{&(RES0__INSTANCE0.TAPP1Z), BOOL_ENUM},
{&(RES0__INSTANCE0.TAPP1_GRAB), BOOL_ENUM},
{&(RES0__INSTANCE0.TAPP1_ROTATECCW), BOOL_ENUM},
{&(RES0__INSTANCE0.TAPP1_ROTATECW), BOOL_ENUM},
{&(RES0__INSTANCE0.GREENBOXDETECTED), BOOL_ENUM},
{&(RES0__INSTANCE0.TAPP2X), BOOL_ENUM},
{&(RES0__INSTANCE0.TAPP2Z), BOOL_ENUM},
{&(RES0__INSTANCE0.TAPP2_GRAB), BOOL_ENUM},
{&(RES0__INSTANCE0.TAPP2_ROTATECW), BOOL_ENUM},
{&(RES0__INSTANCE0.TAPP2_ROTATECCW), BOOL_ENUM},
{&(RES0__INSTANCE0.BC_2M_0), BOOL_ENUM},
{&(RES0__INSTANCE0.BLUEBOXDETECTED), BOOL_ENUM},
{&(RES0__INSTANCE0.GREYBOXDETECTED0), BOOL_ENUM},
{&(RES0__INSTANCE0.STACKLIGHT0_GREEN), BOOL_ENUM},
{&(RES0__INSTANCE0.STACKLIGHT0_YELLOW), BOOL_ENUM},
{&(RES0__INSTANCE0.STACKLIGHT0_RED), BOOL_ENUM},
{&(RES0__INSTANCE0.STACKLIGHT1_GREEN), BOOL_ENUM},
{&(RES0__INSTANCE0.STACKLIGHT1_YELLOW), BOOL_ENUM},
{&(RES0__INSTANCE0.STACKLIGHT1_RED), BOOL_ENUM},
{&(RES0__INSTANCE0.STACKLIGHT2_GREEN), BOOL_ENUM},
{&(RES0__INSTANCE0.STACKLIGHT2_YELLOW), BOOL_ENUM},
{&(RES0__INSTANCE0.STACKLIGHT2_RED), BOOL_ENUM},
{&(RES0__INSTANCE0.LIGHTINDICATOR_RED_2), BOOL_ENUM},
{&(RES0__INSTANCE0.BLUEGRABBED), INT_ENUM},
{&(RES0__INSTANCE0.GREENGRABBED), INT_ENUM},
{&(RES0__INSTANCE0.GREYGRABBED), INT_ENUM},
{&(RES0__INSTANCE0.BLUEMISSED), INT_ENUM},
{&(RES0__INSTANCE0.GREENMISSED), INT_ENUM},
{&(RES0__INSTANCE0.GREYMISSED), INT_ENUM},
{&(RES0__INSTANCE0.FACTORYRESET), BOOL_ENUM},
{&(RES0__INSTANCE0.STARTCONDITION), BOOL_ENUM},
{&(RES0__INSTANCE0.RS1.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.RS1.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.RS1.S), BOOL_ENUM},
{&(RES0__INSTANCE0.RS1.R1), BOOL_ENUM},
{&(RES0__INSTANCE0.RS1.Q1), BOOL_ENUM},
{&(RES0__INSTANCE0.TAPP0ZPT), TIME_ENUM},
{&(RES0__INSTANCE0.RCW0PT), TIME_ENUM},
{&(RES0__INSTANCE0.RCW1PT), TIME_ENUM},
{&(RES0__INSTANCE0.RCW2PT), TIME_ENUM},
{&(RES0__INSTANCE0.TAPP1ZPT), TIME_ENUM},
{&(RES0__INSTANCE0.TAPP2ZPT), TIME_ENUM},
{&(RES0__INSTANCE0.TAPP0ZET), TIME_ENUM},
{&(RES0__INSTANCE0.TAPP1ZET), TIME_ENUM},
{&(RES0__INSTANCE0.TAPP2ZET), TIME_ENUM},
{&(RES0__INSTANCE0.GRAB0PT), TIME_ENUM},
{&(RES0__INSTANCE0.GRAB2PT), TIME_ENUM},
{&(RES0__INSTANCE0.GRAB1PT), TIME_ENUM},
{&(RES0__INSTANCE0.GRAB0ET), TIME_ENUM},
{&(RES0__INSTANCE0.RCW0ET), TIME_ENUM},
{&(RES0__INSTANCE0.RCW1ET), TIME_ENUM},
{&(RES0__INSTANCE0.RCW2ET), TIME_ENUM},
{&(RES0__INSTANCE0.GRAB1ET), TIME_ENUM},
{&(RES0__INSTANCE0.GRAB2ET), TIME_ENUM},
{&(RES0__INSTANCE0.GRAB0TPPT), TIME_ENUM},
{&(RES0__INSTANCE0.GRAB1TPPT), TIME_ENUM},
{&(RES0__INSTANCE0.GRAB2TPPT), TIME_ENUM},
{&(RES0__INSTANCE0.GRAB0TPET), TIME_ENUM},
{&(RES0__INSTANCE0.GRAB1TPET), TIME_ENUM},
{&(RES0__INSTANCE0.GRAB2TPET), TIME_ENUM},
{&(RES0__INSTANCE0.GREYBOX), BOOL_ENUM},
{&(RES0__INSTANCE0.RS5.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.RS5.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.RS5.S), BOOL_ENUM},
{&(RES0__INSTANCE0.RS5.R1), BOOL_ENUM},
{&(RES0__INSTANCE0.RS5.Q1), BOOL_ENUM},
{&(RES0__INSTANCE0.GRABBEDMAX), INT_ENUM},
{&(RES0__INSTANCE0.RS11.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.RS11.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.RS11.S), BOOL_ENUM},
{&(RES0__INSTANCE0.RS11.R1), BOOL_ENUM},
{&(RES0__INSTANCE0.RS11.Q1), BOOL_ENUM},
{&(RES0__INSTANCE0.RS9.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.RS9.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.RS9.S), BOOL_ENUM},
{&(RES0__INSTANCE0.RS9.R1), BOOL_ENUM},
{&(RES0__INSTANCE0.RS9.Q1), BOOL_ENUM},
{&(RES0__INSTANCE0.RS10.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.RS10.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.RS10.S), BOOL_ENUM},
{&(RES0__INSTANCE0.RS10.R1), BOOL_ENUM},
{&(RES0__INSTANCE0.RS10.Q1), BOOL_ENUM},
{&(RES0__INSTANCE0.RS12.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.RS12.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.RS12.S), BOOL_ENUM},
{&(RES0__INSTANCE0.RS12.R1), BOOL_ENUM},
{&(RES0__INSTANCE0.RS12.Q1), BOOL_ENUM},
{&(RES0__INSTANCE0.TON0.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.TON0.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.TON0.IN), BOOL_ENUM},
{&(RES0__INSTANCE0.TON0.PT), TIME_ENUM},
{&(RES0__INSTANCE0.TON0.Q), BOOL_ENUM},
{&(RES0__INSTANCE0.TON0.ET), TIME_ENUM},
{&(RES0__INSTANCE0.TON0.STATE), SINT_ENUM},
{&(RES0__INSTANCE0.TON0.PREV_IN), BOOL_ENUM},
{&(RES0__INSTANCE0.TON0.CURRENT_TIME), TIME_ENUM},
{&(RES0__INSTANCE0.TON0.START_TIME), TIME_ENUM},
{&(RES0__INSTANCE0.RS14.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.RS14.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.RS14.S), BOOL_ENUM},
{&(RES0__INSTANCE0.RS14.R1), BOOL_ENUM},
{&(RES0__INSTANCE0.RS14.Q1), BOOL_ENUM},
{&(RES0__INSTANCE0.TON1.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.TON1.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.TON1.IN), BOOL_ENUM},
{&(RES0__INSTANCE0.TON1.PT), TIME_ENUM},
{&(RES0__INSTANCE0.TON1.Q), BOOL_ENUM},
{&(RES0__INSTANCE0.TON1.ET), TIME_ENUM},
{&(RES0__INSTANCE0.TON1.STATE), SINT_ENUM},
{&(RES0__INSTANCE0.TON1.PREV_IN), BOOL_ENUM},
{&(RES0__INSTANCE0.TON1.CURRENT_TIME), TIME_ENUM},
{&(RES0__INSTANCE0.TON1.START_TIME), TIME_ENUM},
{&(RES0__INSTANCE0.RS15.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.RS15.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.RS15.S), BOOL_ENUM},
{&(RES0__INSTANCE0.RS15.R1), BOOL_ENUM},
{&(RES0__INSTANCE0.RS15.Q1), BOOL_ENUM},
{&(RES0__INSTANCE0.RS16.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.RS16.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.RS16.S), BOOL_ENUM},
{&(RES0__INSTANCE0.RS16.R1), BOOL_ENUM},
{&(RES0__INSTANCE0.RS16.Q1), BOOL_ENUM},
{&(RES0__INSTANCE0.TON2.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.TON2.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.TON2.IN), BOOL_ENUM},
{&(RES0__INSTANCE0.TON2.PT), TIME_ENUM},
{&(RES0__INSTANCE0.TON2.Q), BOOL_ENUM},
{&(RES0__INSTANCE0.TON2.ET), TIME_ENUM},
{&(RES0__INSTANCE0.TON2.STATE), SINT_ENUM},
{&(RES0__INSTANCE0.TON2.PREV_IN), BOOL_ENUM},
{&(RES0__INSTANCE0.TON2.CURRENT_TIME), TIME_ENUM},
{&(RES0__INSTANCE0.TON2.START_TIME), TIME_ENUM},
{&(RES0__INSTANCE0.TP0.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.TP0.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.TP0.IN), BOOL_ENUM},
{&(RES0__INSTANCE0.TP0.PT), TIME_ENUM},
{&(RES0__INSTANCE0.TP0.Q), BOOL_ENUM},
{&(RES0__INSTANCE0.TP0.ET), TIME_ENUM},
{&(RES0__INSTANCE0.TP0.STATE), SINT_ENUM},
{&(RES0__INSTANCE0.TP0.PREV_IN), BOOL_ENUM},
{&(RES0__INSTANCE0.TP0.CURRENT_TIME), TIME_ENUM},
{&(RES0__INSTANCE0.TP0.START_TIME), TIME_ENUM},
{&(RES0__INSTANCE0.RS13.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.RS13.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.RS13.S), BOOL_ENUM},
{&(RES0__INSTANCE0.RS13.R1), BOOL_ENUM},
{&(RES0__INSTANCE0.RS13.Q1), BOOL_ENUM},
{&(RES0__INSTANCE0.RS17.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.RS17.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.RS17.S), BOOL_ENUM},
{&(RES0__INSTANCE0.RS17.R1), BOOL_ENUM},
{&(RES0__INSTANCE0.RS17.Q1), BOOL_ENUM},
{&(RES0__INSTANCE0.RS18.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.RS18.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.RS18.S), BOOL_ENUM},
{&(RES0__INSTANCE0.RS18.R1), BOOL_ENUM},
{&(RES0__INSTANCE0.RS18.Q1), BOOL_ENUM},
{&(RES0__INSTANCE0.RS2.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.RS2.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.RS2.S), BOOL_ENUM},
{&(RES0__INSTANCE0.RS2.R1), BOOL_ENUM},
{&(RES0__INSTANCE0.RS2.Q1), BOOL_ENUM},
{&(RES0__INSTANCE0.CTU0.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.CTU0.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.CTU0.CU), BOOL_ENUM},
{&(RES0__INSTANCE0.CTU0.R), BOOL_ENUM},
{&(RES0__INSTANCE0.CTU0.PV), INT_ENUM},
{&(RES0__INSTANCE0.CTU0.Q), BOOL_ENUM},
{&(RES0__INSTANCE0.CTU0.CV), INT_ENUM},
{&(RES0__INSTANCE0.CTU0.CU_T.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.CTU0.CU_T.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.CTU0.CU_T.CLK), BOOL_ENUM},
{&(RES0__INSTANCE0.CTU0.CU_T.Q), BOOL_ENUM},
{&(RES0__INSTANCE0.CTU0.CU_T.M), BOOL_ENUM},
{&(RES0__INSTANCE0.RS20.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.RS20.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.RS20.S), BOOL_ENUM},
{&(RES0__INSTANCE0.RS20.R1), BOOL_ENUM},
{&(RES0__INSTANCE0.RS20.Q1), BOOL_ENUM},
{&(RES0__INSTANCE0.CTU1.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.CTU1.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.CTU1.CU), BOOL_ENUM},
{&(RES0__INSTANCE0.CTU1.R), BOOL_ENUM},
{&(RES0__INSTANCE0.CTU1.PV), INT_ENUM},
{&(RES0__INSTANCE0.CTU1.Q), BOOL_ENUM},
{&(RES0__INSTANCE0.CTU1.CV), INT_ENUM},
{&(RES0__INSTANCE0.CTU1.CU_T.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.CTU1.CU_T.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.CTU1.CU_T.CLK), BOOL_ENUM},
{&(RES0__INSTANCE0.CTU1.CU_T.Q), BOOL_ENUM},
{&(RES0__INSTANCE0.CTU1.CU_T.M), BOOL_ENUM},
{&(RES0__INSTANCE0.RS21.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.RS21.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.RS21.S), BOOL_ENUM},
{&(RES0__INSTANCE0.RS21.R1), BOOL_ENUM},
{&(RES0__INSTANCE0.RS21.Q1), BOOL_ENUM},
{&(RES0__INSTANCE0.CTU2.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.CTU2.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.CTU2.CU), BOOL_ENUM},
{&(RES0__INSTANCE0.CTU2.R), BOOL_ENUM},
{&(RES0__INSTANCE0.CTU2.PV), INT_ENUM},
{&(RES0__INSTANCE0.CTU2.Q), BOOL_ENUM},
{&(RES0__INSTANCE0.CTU2.CV), INT_ENUM},
{&(RES0__INSTANCE0.CTU2.CU_T.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.CTU2.CU_T.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.CTU2.CU_T.CLK), BOOL_ENUM},
{&(RES0__INSTANCE0.CTU2.CU_T.Q), BOOL_ENUM},
{&(RES0__INSTANCE0.CTU2.CU_T.M), BOOL_ENUM},
{&(RES0__INSTANCE0.RS30.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.RS30.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.RS30.S), BOOL_ENUM},
{&(RES0__INSTANCE0.RS30.R1), BOOL_ENUM},
{&(RES0__INSTANCE0.RS30.Q1), BOOL_ENUM},
{&(RES0__INSTANCE0.CTU3.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.CTU3.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.CTU3.CU), BOOL_ENUM},
{&(RES0__INSTANCE0.CTU3.R), BOOL_ENUM},
{&(RES0__INSTANCE0.CTU3.PV), INT_ENUM},
{&(RES0__INSTANCE0.CTU3.Q), BOOL_ENUM},
{&(RES0__INSTANCE0.CTU3.CV), INT_ENUM},
{&(RES0__INSTANCE0.CTU3.CU_T.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.CTU3.CU_T.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.CTU3.CU_T.CLK), BOOL_ENUM},
{&(RES0__INSTANCE0.CTU3.CU_T.Q), BOOL_ENUM},
{&(RES0__INSTANCE0.CTU3.CU_T.M), BOOL_ENUM},
{&(RES0__INSTANCE0.RS31.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.RS31.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.RS31.S), BOOL_ENUM},
{&(RES0__INSTANCE0.RS31.R1), BOOL_ENUM},
{&(RES0__INSTANCE0.RS31.Q1), BOOL_ENUM},
{&(RES0__INSTANCE0.RS32.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.RS32.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.RS32.S), BOOL_ENUM},
{&(RES0__INSTANCE0.RS32.R1), BOOL_ENUM},
{&(RES0__INSTANCE0.RS32.Q1), BOOL_ENUM},
{&(RES0__INSTANCE0.RS7.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.RS7.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.RS7.S), BOOL_ENUM},
{&(RES0__INSTANCE0.RS7.R1), BOOL_ENUM},
{&(RES0__INSTANCE0.RS7.Q1), BOOL_ENUM},
{&(RES0__INSTANCE0.RS37.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.RS37.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.RS37.S), BOOL_ENUM},
{&(RES0__INSTANCE0.RS37.R1), BOOL_ENUM},
{&(RES0__INSTANCE0.RS37.Q1), BOOL_ENUM},
{&(RES0__INSTANCE0.RS38.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.RS38.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.RS38.S), BOOL_ENUM},
{&(RES0__INSTANCE0.RS38.R1), BOOL_ENUM},
{&(RES0__INSTANCE0.RS38.Q1), BOOL_ENUM},
{&(RES0__INSTANCE0.TON8.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.TON8.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.TON8.IN), BOOL_ENUM},
{&(RES0__INSTANCE0.TON8.PT), TIME_ENUM},
{&(RES0__INSTANCE0.TON8.Q), BOOL_ENUM},
{&(RES0__INSTANCE0.TON8.ET), TIME_ENUM},
{&(RES0__INSTANCE0.TON8.STATE), SINT_ENUM},
{&(RES0__INSTANCE0.TON8.PREV_IN), BOOL_ENUM},
{&(RES0__INSTANCE0.TON8.CURRENT_TIME), TIME_ENUM},
{&(RES0__INSTANCE0.TON8.START_TIME), TIME_ENUM},
{&(RES0__INSTANCE0.CTU4.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.CTU4.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.CTU4.CU), BOOL_ENUM},
{&(RES0__INSTANCE0.CTU4.R), BOOL_ENUM},
{&(RES0__INSTANCE0.CTU4.PV), INT_ENUM},
{&(RES0__INSTANCE0.CTU4.Q), BOOL_ENUM},
{&(RES0__INSTANCE0.CTU4.CV), INT_ENUM},
{&(RES0__INSTANCE0.CTU4.CU_T.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.CTU4.CU_T.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.CTU4.CU_T.CLK), BOOL_ENUM},
{&(RES0__INSTANCE0.CTU4.CU_T.Q), BOOL_ENUM},
{&(RES0__INSTANCE0.CTU4.CU_T.M), BOOL_ENUM},
{&(RES0__INSTANCE0.RS41.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.RS41.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.RS41.S), BOOL_ENUM},
{&(RES0__INSTANCE0.RS41.R1), BOOL_ENUM},
{&(RES0__INSTANCE0.RS41.Q1), BOOL_ENUM},
{&(RES0__INSTANCE0.CTU5.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.CTU5.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.CTU5.CU), BOOL_ENUM},
{&(RES0__INSTANCE0.CTU5.R), BOOL_ENUM},
{&(RES0__INSTANCE0.CTU5.PV), INT_ENUM},
{&(RES0__INSTANCE0.CTU5.Q), BOOL_ENUM},
{&(RES0__INSTANCE0.CTU5.CV), INT_ENUM},
{&(RES0__INSTANCE0.CTU5.CU_T.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.CTU5.CU_T.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.CTU5.CU_T.CLK), BOOL_ENUM},
{&(RES0__INSTANCE0.CTU5.CU_T.Q), BOOL_ENUM},
{&(RES0__INSTANCE0.CTU5.CU_T.M), BOOL_ENUM},
{&(RES0__INSTANCE0.RS42.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.RS42.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.RS42.S), BOOL_ENUM},
{&(RES0__INSTANCE0.RS42.R1), BOOL_ENUM},
{&(RES0__INSTANCE0.RS42.Q1), BOOL_ENUM},
{&(RES0__INSTANCE0.RS19.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.RS19.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.RS19.S), BOOL_ENUM},
{&(RES0__INSTANCE0.RS19.R1), BOOL_ENUM},
{&(RES0__INSTANCE0.RS19.Q1), BOOL_ENUM},
{&(RES0__INSTANCE0.RS22.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.RS22.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.RS22.S), BOOL_ENUM},
{&(RES0__INSTANCE0.RS22.R1), BOOL_ENUM},
{&(RES0__INSTANCE0.RS22.Q1), BOOL_ENUM},
{&(RES0__INSTANCE0.RS23.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.RS23.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.RS23.S), BOOL_ENUM},
{&(RES0__INSTANCE0.RS23.R1), BOOL_ENUM},
{&(RES0__INSTANCE0.RS23.Q1), BOOL_ENUM},
{&(RES0__INSTANCE0.RS24.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.RS24.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.RS24.S), BOOL_ENUM},
{&(RES0__INSTANCE0.RS24.R1), BOOL_ENUM},
{&(RES0__INSTANCE0.RS24.Q1), BOOL_ENUM},
{&(RES0__INSTANCE0.RS25.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.RS25.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.RS25.S), BOOL_ENUM},
{&(RES0__INSTANCE0.RS25.R1), BOOL_ENUM},
{&(RES0__INSTANCE0.RS25.Q1), BOOL_ENUM},
{&(RES0__INSTANCE0.TON3.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.TON3.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.TON3.IN), BOOL_ENUM},
{&(RES0__INSTANCE0.TON3.PT), TIME_ENUM},
{&(RES0__INSTANCE0.TON3.Q), BOOL_ENUM},
{&(RES0__INSTANCE0.TON3.ET), TIME_ENUM},
{&(RES0__INSTANCE0.TON3.STATE), SINT_ENUM},
{&(RES0__INSTANCE0.TON3.PREV_IN), BOOL_ENUM},
{&(RES0__INSTANCE0.TON3.CURRENT_TIME), TIME_ENUM},
{&(RES0__INSTANCE0.TON3.START_TIME), TIME_ENUM},
{&(RES0__INSTANCE0.RS6.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.RS6.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.RS6.S), BOOL_ENUM},
{&(RES0__INSTANCE0.RS6.R1), BOOL_ENUM},
{&(RES0__INSTANCE0.RS6.Q1), BOOL_ENUM},
{&(RES0__INSTANCE0.RS26.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.RS26.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.RS26.S), BOOL_ENUM},
{&(RES0__INSTANCE0.RS26.R1), BOOL_ENUM},
{&(RES0__INSTANCE0.RS26.Q1), BOOL_ENUM},
{&(RES0__INSTANCE0.RS27.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.RS27.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.RS27.S), BOOL_ENUM},
{&(RES0__INSTANCE0.RS27.R1), BOOL_ENUM},
{&(RES0__INSTANCE0.RS27.Q1), BOOL_ENUM},
{&(RES0__INSTANCE0.TON4.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.TON4.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.TON4.IN), BOOL_ENUM},
{&(RES0__INSTANCE0.TON4.PT), TIME_ENUM},
{&(RES0__INSTANCE0.TON4.Q), BOOL_ENUM},
{&(RES0__INSTANCE0.TON4.ET), TIME_ENUM},
{&(RES0__INSTANCE0.TON4.STATE), SINT_ENUM},
{&(RES0__INSTANCE0.TON4.PREV_IN), BOOL_ENUM},
{&(RES0__INSTANCE0.TON4.CURRENT_TIME), TIME_ENUM},
{&(RES0__INSTANCE0.TON4.START_TIME), TIME_ENUM},
{&(RES0__INSTANCE0.TP1.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.TP1.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.TP1.IN), BOOL_ENUM},
{&(RES0__INSTANCE0.TP1.PT), TIME_ENUM},
{&(RES0__INSTANCE0.TP1.Q), BOOL_ENUM},
{&(RES0__INSTANCE0.TP1.ET), TIME_ENUM},
{&(RES0__INSTANCE0.TP1.STATE), SINT_ENUM},
{&(RES0__INSTANCE0.TP1.PREV_IN), BOOL_ENUM},
{&(RES0__INSTANCE0.TP1.CURRENT_TIME), TIME_ENUM},
{&(RES0__INSTANCE0.TP1.START_TIME), TIME_ENUM},
{&(RES0__INSTANCE0.TON5.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.TON5.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.TON5.IN), BOOL_ENUM},
{&(RES0__INSTANCE0.TON5.PT), TIME_ENUM},
{&(RES0__INSTANCE0.TON5.Q), BOOL_ENUM},
{&(RES0__INSTANCE0.TON5.ET), TIME_ENUM},
{&(RES0__INSTANCE0.TON5.STATE), SINT_ENUM},
{&(RES0__INSTANCE0.TON5.PREV_IN), BOOL_ENUM},
{&(RES0__INSTANCE0.TON5.CURRENT_TIME), TIME_ENUM},
{&(RES0__INSTANCE0.TON5.START_TIME), TIME_ENUM},
{&(RES0__INSTANCE0.RS28.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.RS28.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.RS28.S), BOOL_ENUM},
{&(RES0__INSTANCE0.RS28.R1), BOOL_ENUM},
{&(RES0__INSTANCE0.RS28.Q1), BOOL_ENUM},
{&(RES0__INSTANCE0.RS29.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.RS29.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.RS29.S), BOOL_ENUM},
{&(RES0__INSTANCE0.RS29.R1), BOOL_ENUM},
{&(RES0__INSTANCE0.RS29.Q1), BOOL_ENUM},
{&(RES0__INSTANCE0.RS33.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.RS33.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.RS33.S), BOOL_ENUM},
{&(RES0__INSTANCE0.RS33.R1), BOOL_ENUM},
{&(RES0__INSTANCE0.RS33.Q1), BOOL_ENUM},
{&(RES0__INSTANCE0.RS34.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.RS34.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.RS34.S), BOOL_ENUM},
{&(RES0__INSTANCE0.RS34.R1), BOOL_ENUM},
{&(RES0__INSTANCE0.RS34.Q1), BOOL_ENUM},
{&(RES0__INSTANCE0.RS35.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.RS35.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.RS35.S), BOOL_ENUM},
{&(RES0__INSTANCE0.RS35.R1), BOOL_ENUM},
{&(RES0__INSTANCE0.RS35.Q1), BOOL_ENUM},
{&(RES0__INSTANCE0.RS36.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.RS36.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.RS36.S), BOOL_ENUM},
{&(RES0__INSTANCE0.RS36.R1), BOOL_ENUM},
{&(RES0__INSTANCE0.RS36.Q1), BOOL_ENUM},
{&(RES0__INSTANCE0.TON6.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.TON6.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.TON6.IN), BOOL_ENUM},
{&(RES0__INSTANCE0.TON6.PT), TIME_ENUM},
{&(RES0__INSTANCE0.TON6.Q), BOOL_ENUM},
{&(RES0__INSTANCE0.TON6.ET), TIME_ENUM},
{&(RES0__INSTANCE0.TON6.STATE), SINT_ENUM},
{&(RES0__INSTANCE0.TON6.PREV_IN), BOOL_ENUM},
{&(RES0__INSTANCE0.TON6.CURRENT_TIME), TIME_ENUM},
{&(RES0__INSTANCE0.TON6.START_TIME), TIME_ENUM},
{&(RES0__INSTANCE0.TP2.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.TP2.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.TP2.IN), BOOL_ENUM},
{&(RES0__INSTANCE0.TP2.PT), TIME_ENUM},
{&(RES0__INSTANCE0.TP2.Q), BOOL_ENUM},
{&(RES0__INSTANCE0.TP2.ET), TIME_ENUM},
{&(RES0__INSTANCE0.TP2.STATE), SINT_ENUM},
{&(RES0__INSTANCE0.TP2.PREV_IN), BOOL_ENUM},
{&(RES0__INSTANCE0.TP2.CURRENT_TIME), TIME_ENUM},
{&(RES0__INSTANCE0.TP2.START_TIME), TIME_ENUM},
{&(RES0__INSTANCE0.TON7.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.TON7.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.TON7.IN), BOOL_ENUM},
{&(RES0__INSTANCE0.TON7.PT), TIME_ENUM},
{&(RES0__INSTANCE0.TON7.Q), BOOL_ENUM},
{&(RES0__INSTANCE0.TON7.ET), TIME_ENUM},
{&(RES0__INSTANCE0.TON7.STATE), SINT_ENUM},
{&(RES0__INSTANCE0.TON7.PREV_IN), BOOL_ENUM},
{&(RES0__INSTANCE0.TON7.CURRENT_TIME), TIME_ENUM},
{&(RES0__INSTANCE0.TON7.START_TIME), TIME_ENUM},
{&(RES0__INSTANCE0.RS43.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.RS43.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.RS43.S), BOOL_ENUM},
{&(RES0__INSTANCE0.RS43.R1), BOOL_ENUM},
{&(RES0__INSTANCE0.RS43.Q1), BOOL_ENUM},
{&(RES0__INSTANCE0.RS44.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.RS44.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.RS44.S), BOOL_ENUM},
{&(RES0__INSTANCE0.RS44.R1), BOOL_ENUM},
{&(RES0__INSTANCE0.RS44.Q1), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG1.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG1.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG1.CLK), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG1.Q), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG1.M), BOOL_ENUM},
{&(RES0__INSTANCE0.F_TRIG1.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.F_TRIG1.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.F_TRIG1.CLK), BOOL_ENUM},
{&(RES0__INSTANCE0.F_TRIG1.Q), BOOL_ENUM},
{&(RES0__INSTANCE0.F_TRIG1.M), BOOL_ENUM},
{&(RES0__INSTANCE0.F_TRIG2.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.F_TRIG2.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.F_TRIG2.CLK), BOOL_ENUM},
{&(RES0__INSTANCE0.F_TRIG2.Q), BOOL_ENUM},
{&(RES0__INSTANCE0.F_TRIG2.M), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG2.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG2.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG2.CLK), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG2.Q), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG2.M), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG3.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG3.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG3.CLK), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG3.Q), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG3.M), BOOL_ENUM},
{&(RES0__INSTANCE0._TMP_EQ104_OUT), BOOL_ENUM},
{&(RES0__INSTANCE0._TMP_LT118_OUT), BOOL_ENUM},
{&(RES0__INSTANCE0._TMP_GT105_OUT), BOOL_ENUM},
{&(RES0__INSTANCE0.F_TRIG3.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.F_TRIG3.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.F_TRIG3.CLK), BOOL_ENUM},
{&(RES0__INSTANCE0.F_TRIG3.Q), BOOL_ENUM},
{&(RES0__INSTANCE0.F_TRIG3.M), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG4.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG4.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG4.CLK), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG4.Q), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG4.M), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG5.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG5.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG5.CLK), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG5.Q), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG5.M), BOOL_ENUM},
{&(RES0__INSTANCE0._TMP_LT211_OUT), BOOL_ENUM},
{&(RES0__INSTANCE0._TMP_EQ195_OUT), BOOL_ENUM},
{&(RES0__INSTANCE0._TMP_GT196_OUT), BOOL_ENUM},
{&(RES0__INSTANCE0.F_TRIG4.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.F_TRIG4.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.F_TRIG4.CLK), BOOL_ENUM},
{&(RES0__INSTANCE0.F_TRIG4.Q), BOOL_ENUM},
{&(RES0__INSTANCE0.F_TRIG4.M), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG6.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG6.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG6.CLK), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG6.Q), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG6.M), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG7.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG7.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG7.CLK), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG7.Q), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG7.M), BOOL_ENUM},
{&(RES0__INSTANCE0._TMP_EQ300_OUT), BOOL_ENUM},
{&(RES0__INSTANCE0._TMP_GT301_OUT), BOOL_ENUM},
{&(RES0__INSTANCE0._TMP_LT316_OUT), BOOL_ENUM}
};

static const dbgvardsc_index_t retain_list[] = {

};
static unsigned int retain_list_collect_cursor = 0;
static const unsigned int retain_list_size = sizeof(retain_list)/sizeof(dbgvardsc_index_t);

typedef void(*__for_each_variable_do_fp)(dbgvardsc_t*);
void __for_each_variable_do(__for_each_variable_do_fp fp)
{
    unsigned int i;
    for(i = 0; i < sizeof(dbgvardsc)/sizeof(dbgvardsc_t); i++){
        dbgvardsc_t *dsc = &dbgvardsc[i];
        if(dsc->type != UNKNOWN_ENUM) 
            (*fp)(dsc);
    }
}

#define __Unpack_desc_type dbgvardsc_t


#define __Unpack_case_t(TYPENAME)                                           \
        case TYPENAME##_ENUM :                                              \
            if(flags) *flags = ((__IEC_##TYPENAME##_t *)varp)->flags;       \
            if(value_p) *value_p = &((__IEC_##TYPENAME##_t *)varp)->value;  \
		    if(size) *size = sizeof(TYPENAME);                              \
            break;

#define __Unpack_case_p(TYPENAME)                                           \
        case TYPENAME##_O_ENUM :                                            \
        case TYPENAME##_P_ENUM :                                            \
            if(flags) *flags = ((__IEC_##TYPENAME##_p *)varp)->flags;       \
            if(value_p) *value_p = ((__IEC_##TYPENAME##_p *)varp)->value;   \
		    if(size) *size = sizeof(TYPENAME);                              \
            break;

#define __Is_a_string(dsc) (dsc->type == STRING_ENUM)   ||\
                           (dsc->type == STRING_P_ENUM) ||\
                           (dsc->type == STRING_O_ENUM)

static int UnpackVar(__Unpack_desc_type *dsc, void **value_p, char *flags, size_t *size)
{
    void *varp = dsc->ptr;
    /* find data to copy*/
    switch(dsc->type){
        __ANY(__Unpack_case_t)
        __ANY(__Unpack_case_p)
    default:
        return 0; /* should never happen */
    }
    return 1;
}



void Remind(unsigned int offset, unsigned int count, void * p);

extern int CheckRetainBuffer(void);
extern void InitRetain(void);

void __init_debug(void)
{
    /* init local static vars */
#ifndef TARGET_ONLINE_DEBUG_DISABLE
    trace_buffer_cursor = trace_buffer;
    trace_list_addvar_cursor = trace_list;
    trace_list_collect_cursor = trace_list;
    trace_buffer_state = BUFFER_EMPTY;

    force_buffer_cursor = force_buffer;
    force_list_addvar_cursor = force_list;
    force_list_apply_cursor = force_list;
#endif

    InitRetain();
    /* Iterate over all variables to fill debug buffer */
    if(CheckRetainBuffer()){
        static unsigned int retain_offset = 0;
        retain_list_collect_cursor = 0;

        /* iterate over retain list */
        while(retain_list_collect_cursor < retain_list_size){
            void *value_p = NULL;
            size_t size;
            char* next_cursor;

            dbgvardsc_t *dsc = &dbgvardsc[
                retain_list[retain_list_collect_cursor]];

            UnpackVar(dsc, &value_p, NULL, &size);

            printf("Reminding %d %ld \n", retain_list_collect_cursor, size);

            /* if buffer not full */
            Remind(retain_offset, size, value_p);
            /* increment cursor according size*/
            retain_offset += size;

            retain_list_collect_cursor++;
        }
    }else{
        char mstr[] = "RETAIN memory invalid - defaults used";
        LogMessage(LOG_WARNING, mstr, sizeof(mstr));
    }
}

extern void InitiateDebugTransfer(void);
extern void CleanupRetain(void);

extern unsigned long __tick;

void __cleanup_debug(void)
{
#ifndef TARGET_ONLINE_DEBUG_DISABLE
    trace_buffer_cursor = trace_buffer;
    InitiateDebugTransfer();
#endif    

    CleanupRetain();
}

void __retrieve_debug(void)
{
}

void Retain(unsigned int offset, unsigned int count, void * p);

/* Return size of all retain variables */
unsigned int GetRetainSize(void)
{
    unsigned int retain_size = 0;
    retain_list_collect_cursor = 0;

    /* iterate over retain list */
    while(retain_list_collect_cursor < retain_list_size){
        void *value_p = NULL;
        size_t size;
        char* next_cursor;

        dbgvardsc_t *dsc = &dbgvardsc[
            retain_list[retain_list_collect_cursor]];

        UnpackVar(dsc, &value_p, NULL, &size);

        retain_size += size;
        retain_list_collect_cursor++;
    }

    printf("Retain size %d \n", retain_size);
            
    return retain_size;
}


extern void PLC_GetTime(IEC_TIME*);
extern int TryEnterDebugSection(void);
extern long AtomicCompareExchange(long*, long, long);
extern long long AtomicCompareExchange64(long long* , long long , long long);
extern void LeaveDebugSection(void);
extern void ValidateRetainBuffer(void);
extern void InValidateRetainBuffer(void);

#define __ReForceOutput_case_p(TYPENAME)                                                            \
        case TYPENAME##_P_ENUM :                                                                    \
        case TYPENAME##_O_ENUM :                                                                    \
            {                                                                                       \
                char *next_cursor = force_buffer_cursor + sizeof(TYPENAME);                         \
                if(next_cursor <= force_buffer_end ){                                               \
                    /* outputs real value must be systematically forced */                          \
                    if(vartype == TYPENAME##_O_ENUM)                                                \
                        /* overwrite value pointed by backup */                                     \
                        *((TYPENAME *)force_list_apply_cursor->value_pointer_backup) =  \
                            *((TYPENAME *)force_buffer_cursor);                                     \
                    /* inc force_buffer cursor */                                                   \
                    force_buffer_cursor = next_cursor;                                              \
                }else{                                                                              \
                    stop = 1;                                                                       \
                }                                                                                   \
            }                                                                                       \
            break;
void __publish_debug(void)
{
    InValidateRetainBuffer();
    
#ifndef TARGET_ONLINE_DEBUG_DISABLE 
    /* Check there is no running debugger re-configuration */
    if(TryEnterDebugSection()){
        /* Lock buffer */
        long latest_state = AtomicCompareExchange(
            &trace_buffer_state,
            BUFFER_EMPTY,
            BUFFER_FULL);
            
        /* If buffer was free */
        if(latest_state == BUFFER_EMPTY)
        {
            int stop = 0;
            /* Reset force list cursor */
            force_list_apply_cursor = force_list;

            /* iterate over force list */
            while(!stop && force_list_apply_cursor < force_list_addvar_cursor){
                dbgvardsc_t *dsc = &dbgvardsc[
                    force_list_apply_cursor->dbgvardsc_index];
                void *varp = dsc->ptr;
                __IEC_types_enum vartype = dsc->type;
                switch(vartype){
                    __ANY(__ReForceOutput_case_p)
                default:
                    break;
                }
                force_list_apply_cursor++;                                                      \
            }

            /* Reset buffer cursor */
            trace_buffer_cursor = trace_buffer;
            /* Reset trace list cursor */
            trace_list_collect_cursor = trace_list;

            /* iterate over trace list */
            while(trace_list_collect_cursor < trace_list_addvar_cursor){
                void *value_p = NULL;
                size_t size;
                char* next_cursor;

                dbgvardsc_t *dsc = &dbgvardsc[
                    trace_list_collect_cursor->dbgvardsc_index];

                UnpackVar(dsc, &value_p, NULL, &size);

                /* copy visible variable to buffer */;
                if(__Is_a_string(dsc)){
                    /* optimization for strings */
                    /* assume NULL terminated strings */
                    size = ((STRING*)value_p)->len + 1;
                }

                /* compute next cursor positon.*/
                next_cursor = trace_buffer_cursor + size;
                /* check for buffer overflow */
                if(next_cursor < trace_buffer_end)
                    /* copy data to the buffer */
                    memcpy(trace_buffer_cursor, value_p, size);
                else
                    /* stop looping in case of overflow */
                    break;
                /* increment cursor according size*/
                trace_buffer_cursor = next_cursor;
                trace_list_collect_cursor++;
            }
            
            /* Leave debug section,
             * Trigger asynchronous transmission 
             * (returns immediately) */
            InitiateDebugTransfer(); /* size */
        }
        LeaveDebugSection();
    }
#endif
    static unsigned int retain_offset = 0;
    /* when not debugging, do only retain */
    retain_list_collect_cursor = 0;

    /* iterate over retain list */
    while(retain_list_collect_cursor < retain_list_size){
        void *value_p = NULL;
        size_t size;
        char* next_cursor;

        dbgvardsc_t *dsc = &dbgvardsc[
            retain_list[retain_list_collect_cursor]];

        UnpackVar(dsc, &value_p, NULL, &size);

        /* if buffer not full */
        Retain(retain_offset, size, value_p);
        /* increment cursor according size*/
        retain_offset += size;

        retain_list_collect_cursor++;
    }
    ValidateRetainBuffer();
}

#ifndef TARGET_ONLINE_DEBUG_DISABLE

#define TRACE_LIST_OVERFLOW    1
#define FORCE_LIST_OVERFLOW    2
#define FORCE_BUFFER_OVERFLOW  3

#define __ForceVariable_case_t(TYPENAME)                                                \
        case TYPENAME##_ENUM :                                                          \
            /* add to force_list*/                                                      \
            force_list_addvar_cursor->dbgvardsc_index = idx;                            \
            ((__IEC_##TYPENAME##_t *)varp)->flags |= __IEC_FORCE_FLAG;                  \
            ((__IEC_##TYPENAME##_t *)varp)->value = *((TYPENAME *)force);               \
            break;
#define __ForceVariable_case_p(TYPENAME)                                                \
        case TYPENAME##_P_ENUM :                                                        \
        case TYPENAME##_O_ENUM :                                                        \
            {                                                                           \
                char *next_cursor = force_buffer_cursor + sizeof(TYPENAME);             \
                if(next_cursor <= force_buffer_end ){                                   \
                    /* add to force_list*/                                              \
                    force_list_addvar_cursor->dbgvardsc_index = idx;                    \
                    /* save pointer to backup */                                        \
                    force_list_addvar_cursor->value_pointer_backup =                    \
                        ((__IEC_##TYPENAME##_p *)varp)->value;                          \
                    /* store forced value in force_buffer */                            \
                    *((TYPENAME *)force_buffer_cursor) = *((TYPENAME *)force);          \
                    /* replace pointer with pointer to force_buffer */                  \
                    ((__IEC_##TYPENAME##_p *)varp)->value =                             \
                        (TYPENAME *)force_buffer_cursor;                                \
                    /* mark variable as forced */                                       \
                    ((__IEC_##TYPENAME##_p *)varp)->flags |= __IEC_FORCE_FLAG;          \
                    /* inc force_buffer cursor */                                       \
                    force_buffer_cursor = next_cursor;                                  \
                    /* outputs real value must be systematically forced */              \
                    if(vartype == TYPENAME##_O_ENUM)                                    \
                        *(((__IEC_##TYPENAME##_p *)varp)->value) = *((TYPENAME *)force);\
                } else {                                                                \
                    error_code = FORCE_BUFFER_OVERFLOW;                                 \
                    goto error_cleanup;                                                 \
                }                                                                       \
            }                                                                           \
            break;


void ResetDebugVariables(void);

int RegisterDebugVariable(dbgvardsc_index_t idx, void* force)
{
    int error_code = 0;
    if(idx < sizeof(dbgvardsc)/sizeof(dbgvardsc_t)){
        /* add to trace_list, inc trace_list_addvar_cursor*/
        if(trace_list_addvar_cursor <= trace_list_end){
            trace_list_addvar_cursor->dbgvardsc_index = idx;
            trace_list_addvar_cursor++;
        } else {
            error_code = TRACE_LIST_OVERFLOW;
            goto error_cleanup;
        }
        if(force){
            if(force_list_addvar_cursor <= force_list_end){
                dbgvardsc_t *dsc = &dbgvardsc[idx];
                void *varp = dsc->ptr;
                __IEC_types_enum vartype = dsc->type;

                switch(vartype){
                    __ANY(__ForceVariable_case_t)
                    __ANY(__ForceVariable_case_p)
                default:
                    break;
                }
                /* inc force_list cursor */
                force_list_addvar_cursor++;
            } else {
                error_code = FORCE_LIST_OVERFLOW;
                goto error_cleanup;
            }
        }
    }
    return 0;

error_cleanup:
    ResetDebugVariables();
    trace_buffer_state = BUFFER_EMPTY;
    return error_code;
    
}

#define ResetForcedVariable_case_t(TYPENAME)                                            \
        case TYPENAME##_ENUM :                                                          \
            ((__IEC_##TYPENAME##_t *)varp)->flags &= ~__IEC_FORCE_FLAG;                 \
            /* for local variable we don't restore original value */                    \
            /* that can be added if needed, but it was like that since ever */          \
            break;

#define ResetForcedVariable_case_p(TYPENAME)                                            \
        case TYPENAME##_P_ENUM :                                                        \
        case TYPENAME##_O_ENUM :                                                        \
            ((__IEC_##TYPENAME##_p *)varp)->flags &= ~__IEC_FORCE_FLAG;                 \
            /* restore backup to pointer */                                             \
            ((__IEC_##TYPENAME##_p *)varp)->value =                                     \
                force_list_apply_cursor->value_pointer_backup;                          \
            break;

void ResetDebugVariables(void)
{
    /* Reset trace list */
    trace_list_addvar_cursor = trace_list;

    force_list_apply_cursor = force_list;
    /* Restore forced variables */
    while(force_list_apply_cursor < force_list_addvar_cursor){
        dbgvardsc_t *dsc = &dbgvardsc[
            force_list_apply_cursor->dbgvardsc_index];
        void *varp = dsc->ptr;
        switch(dsc->type){
            __ANY(ResetForcedVariable_case_t)
            __ANY(ResetForcedVariable_case_p)
        default:
            break;
        }
        /* inc force_list cursor */
        force_list_apply_cursor++;
    } /* else TODO: warn user about failure to force */ 

    /* Reset force list */
    force_list_addvar_cursor = force_list;
    /* Reset force buffer */
    force_buffer_cursor = force_buffer;
}

void FreeDebugData(void)
{
    /* atomically mark buffer as free */
    AtomicCompareExchange(
        &trace_buffer_state,
        BUFFER_FULL,
        BUFFER_EMPTY);
}
int WaitDebugData(unsigned long *tick);
/* Wait until debug data ready and return pointer to it */
int GetDebugData(unsigned long *tick, unsigned long *size, void **buffer){
    int wait_error = WaitDebugData(tick);
    if(!wait_error){
        *size = trace_buffer_cursor - trace_buffer;
        *buffer = trace_buffer;
    }
    return wait_error;
}
#endif
#endif

