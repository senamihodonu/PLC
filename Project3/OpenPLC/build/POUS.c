void LOGGER_init__(LOGGER *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MSG,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->LEVEL,LOGLEVEL__INFO,retain)
  __INIT_VAR(data__->TRIG0,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void LOGGER_body__(LOGGER *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if ((__GET_VAR(data__->TRIG,) && !(__GET_VAR(data__->TRIG0,)))) {
    #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
    #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)

   LogMessage(GetFbVar(LEVEL),(char*)GetFbVar(MSG, .body),GetFbVar(MSG, .len));
  
    #undef GetFbVar
    #undef SetFbVar
;
  };
  __SET_VAR(data__->,TRIG0,,__GET_VAR(data__->TRIG,));

  goto __end;

__end:
  return;
} // LOGGER_body__() 





void PYTHON_EVAL_init__(PYTHON_EVAL *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CODE,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->ACK,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RESULT,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->STATE,0,retain)
  __INIT_VAR(data__->BUFFER,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->PREBUFFER,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->TRIGM1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TRIGGED,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void PYTHON_EVAL_body__(PYTHON_EVAL *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __IL_DEFVAR_T __IL_DEFVAR;
  __IL_DEFVAR_T __IL_DEFVAR_BACK;
  #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
  #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)
extern void __PythonEvalFB(int, PYTHON_EVAL*);__PythonEvalFB(0, data__);
  #undef GetFbVar
  #undef SetFbVar
;

  goto __end;

__end:
  return;
} // PYTHON_EVAL_body__() 





void PYTHON_POLL_init__(PYTHON_POLL *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CODE,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->ACK,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RESULT,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->STATE,0,retain)
  __INIT_VAR(data__->BUFFER,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->PREBUFFER,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->TRIGM1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TRIGGED,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void PYTHON_POLL_body__(PYTHON_POLL *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __IL_DEFVAR_T __IL_DEFVAR;
  __IL_DEFVAR_T __IL_DEFVAR_BACK;
  #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
  #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)
extern void __PythonEvalFB(int, PYTHON_EVAL*);__PythonEvalFB(1,(PYTHON_EVAL*)(void*)data__);
  #undef GetFbVar
  #undef SetFbVar
;

  goto __end;

__end:
  return;
} // PYTHON_POLL_body__() 





void PYTHON_GEAR_init__(PYTHON_GEAR *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->N,0,retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CODE,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->ACK,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RESULT,__STRING_LITERAL(0,""),retain)
  PYTHON_EVAL_init__(&data__->PY_EVAL,retain);
  __INIT_VAR(data__->COUNTER,0,retain)
  __INIT_VAR(data__->_TMP_ADD10_OUT,0,retain)
  __INIT_VAR(data__->_TMP_EQ13_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_SEL15_OUT,0,retain)
  __INIT_VAR(data__->_TMP_AND7_OUT,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void PYTHON_GEAR_body__(PYTHON_GEAR *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,_TMP_ADD10_OUT,,ADD__UINT__UINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (UINT)__GET_VAR(data__->COUNTER,),
    (UINT)1));
  __SET_VAR(data__->,_TMP_EQ13_OUT,,EQ__BOOL__UINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (UINT)__GET_VAR(data__->N,),
    (UINT)__GET_VAR(data__->_TMP_ADD10_OUT,)));
  __SET_VAR(data__->,_TMP_SEL15_OUT,,SEL__UINT__BOOL__UINT__UINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BOOL)__GET_VAR(data__->_TMP_EQ13_OUT,),
    (UINT)__GET_VAR(data__->_TMP_ADD10_OUT,),
    (UINT)0));
  __SET_VAR(data__->,COUNTER,,__GET_VAR(data__->_TMP_SEL15_OUT,));
  __SET_VAR(data__->,_TMP_AND7_OUT,,AND__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->_TMP_EQ13_OUT,),
    (BOOL)__GET_VAR(data__->TRIG,)));
  __SET_VAR(data__->PY_EVAL.,TRIG,,__GET_VAR(data__->_TMP_AND7_OUT,));
  __SET_VAR(data__->PY_EVAL.,CODE,,__GET_VAR(data__->CODE,));
  PYTHON_EVAL_body__(&data__->PY_EVAL);
  __SET_VAR(data__->,ACK,,__GET_VAR(data__->PY_EVAL.ACK,));
  __SET_VAR(data__->,RESULT,,__GET_VAR(data__->PY_EVAL.RESULT,));

  goto __end;

__end:
  return;
} // PYTHON_GEAR_body__() 





void PROGRAM3_init__(PROGRAM3 *data__, BOOL retain) {
  __INIT_VAR(data__->FACTORYIORESET0,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->STARTBUTTON0,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->ESTOP0,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RETRO0,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RETRO1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->VS00,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->VS01,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->VS02,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->VS03,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TAPP0_DETECTED,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TAPP0_MOVINGX,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TAPP0_MOVINGZ,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TAPP0_ROTATING,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RETRO2,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RETROREFLECTIVESENSOR3,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RETRO4,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->VS10,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->VS11,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->VS12,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->VISIONSENSOR13,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TAPP1_DETECTED,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TWOAXISPICKPLACE1_MOVINGX,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TWOAXISPICKPLACE1_MOVINGZ,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TWOAXISPICKPLACE1_ROTATING,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RETROREFLECTIVESENSOR5,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RETROREFLECTIVESENSOR6,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RETRO7,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->VS20,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->VS21,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->VS22,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->VISIONSENSOR23,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TAPP2_DETECTED,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TWOAXISPICKPLACE2_MOVINGX,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TWOAXISPICKPLACE2_MOVINGZ,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TWOAXISPICKPLACE2_ROTATING,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RETROREFLECTIVESENSOR8,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RETROREFLECTIVESENSOR9,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RETROREFLECTIVESENSOR10,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->VISIONSENSOR30,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->VISIONSENSOR31,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->VISIONSENSOR32,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->VISIONSENSOR33,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RETRO11,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RETRO12,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RETRO13,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RETRO14,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RETRO15,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RETRO16,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TAPP0X,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TAPP0Z,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TAPP0_GRAB,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TAPP0_ROTATECW,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TAPP0_ROTATECCW,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->BC_6M_0,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->BC_6M_1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->BC_6M_2,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->BC_6M_3,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->BC_6M_4,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TAPP1X,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TAPP1Z,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TAPP1_GRAB,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TAPP1_ROTATECCW,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TAPP1_ROTATECW,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->GREENBOXDETECTED,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TAPP2X,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TAPP2Z,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TAPP2_GRAB,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TAPP2_ROTATECW,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TAPP2_ROTATECCW,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->BC_2M_0,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->BLUEBOXDETECTED,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->GREYBOXDETECTED0,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->STACKLIGHT0_GREEN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->STACKLIGHT0_YELLOW,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->STACKLIGHT0_RED,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->STACKLIGHT1_GREEN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->STACKLIGHT1_YELLOW,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->STACKLIGHT1_RED,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->STACKLIGHT2_GREEN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->STACKLIGHT2_YELLOW,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->STACKLIGHT2_RED,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->LIGHTINDICATOR_RED_2,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->BLUEGRABBED,0,retain)
  __INIT_VAR(data__->GREENGRABBED,0,retain)
  __INIT_VAR(data__->GREYGRABBED,0,retain)
  __INIT_VAR(data__->BLUEMISSED,0,retain)
  __INIT_VAR(data__->GREENMISSED,0,retain)
  __INIT_VAR(data__->GREYMISSED,0,retain)
  __INIT_VAR(data__->FACTORYRESET,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->STARTCONDITION,__BOOL_LITERAL(FALSE),retain)
  RS_init__(&data__->RS1,retain);
  __INIT_VAR(data__->TAPP0ZPT,__time_to_timespec(1, 0, 2, 0, 0, 0),retain)
  __INIT_VAR(data__->RCW0PT,__time_to_timespec(1, 0, 2, 0, 0, 0),retain)
  __INIT_VAR(data__->RCW1PT,__time_to_timespec(1, 0, 2, 0, 0, 0),retain)
  __INIT_VAR(data__->RCW2PT,__time_to_timespec(1, 0, 2, 0, 0, 0),retain)
  __INIT_VAR(data__->TAPP1ZPT,__time_to_timespec(1, 0, 2, 0, 0, 0),retain)
  __INIT_VAR(data__->TAPP2ZPT,__time_to_timespec(1, 0, 2, 0, 0, 0),retain)
  __INIT_VAR(data__->TAPP0ZET,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->TAPP1ZET,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->TAPP2ZET,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->GRAB0PT,__time_to_timespec(1, 0, 0.5, 0, 0, 0),retain)
  __INIT_VAR(data__->GRAB2PT,__time_to_timespec(1, 0, 0.5, 0, 0, 0),retain)
  __INIT_VAR(data__->GRAB1PT,__time_to_timespec(1, 0, 0.5, 0, 0, 0),retain)
  __INIT_VAR(data__->GRAB0ET,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->RCW0ET,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->RCW1ET,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->RCW2ET,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->GRAB1ET,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->GRAB2ET,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->GRAB0TPPT,__time_to_timespec(1, 0, 3, 0, 0, 0),retain)
  __INIT_VAR(data__->GRAB1TPPT,__time_to_timespec(1, 0, 3, 0, 0, 0),retain)
  __INIT_VAR(data__->GRAB2TPPT,__time_to_timespec(1, 0, 3, 0, 0, 0),retain)
  __INIT_VAR(data__->GRAB0TPET,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->GRAB1TPET,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->GRAB2TPET,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->GREYBOX,__BOOL_LITERAL(FALSE),retain)
  RS_init__(&data__->RS5,retain);
  __INIT_VAR(data__->GRABBEDMAX,50,retain)
  RS_init__(&data__->RS11,retain);
  RS_init__(&data__->RS9,retain);
  RS_init__(&data__->RS10,retain);
  RS_init__(&data__->RS12,retain);
  TON_init__(&data__->TON0,retain);
  RS_init__(&data__->RS14,retain);
  TON_init__(&data__->TON1,retain);
  RS_init__(&data__->RS15,retain);
  RS_init__(&data__->RS16,retain);
  TON_init__(&data__->TON2,retain);
  TP_init__(&data__->TP0,retain);
  RS_init__(&data__->RS13,retain);
  RS_init__(&data__->RS17,retain);
  RS_init__(&data__->RS18,retain);
  RS_init__(&data__->RS2,retain);
  CTU_init__(&data__->CTU0,retain);
  RS_init__(&data__->RS20,retain);
  CTU_init__(&data__->CTU1,retain);
  RS_init__(&data__->RS21,retain);
  CTU_init__(&data__->CTU2,retain);
  RS_init__(&data__->RS30,retain);
  CTU_init__(&data__->CTU3,retain);
  RS_init__(&data__->RS31,retain);
  RS_init__(&data__->RS32,retain);
  RS_init__(&data__->RS7,retain);
  RS_init__(&data__->RS37,retain);
  RS_init__(&data__->RS38,retain);
  TON_init__(&data__->TON8,retain);
  CTU_init__(&data__->CTU4,retain);
  RS_init__(&data__->RS41,retain);
  CTU_init__(&data__->CTU5,retain);
  RS_init__(&data__->RS42,retain);
  RS_init__(&data__->RS19,retain);
  RS_init__(&data__->RS22,retain);
  RS_init__(&data__->RS23,retain);
  RS_init__(&data__->RS24,retain);
  RS_init__(&data__->RS25,retain);
  TON_init__(&data__->TON3,retain);
  RS_init__(&data__->RS6,retain);
  RS_init__(&data__->RS26,retain);
  RS_init__(&data__->RS27,retain);
  TON_init__(&data__->TON4,retain);
  TP_init__(&data__->TP1,retain);
  TON_init__(&data__->TON5,retain);
  RS_init__(&data__->RS28,retain);
  RS_init__(&data__->RS29,retain);
  RS_init__(&data__->RS33,retain);
  RS_init__(&data__->RS34,retain);
  RS_init__(&data__->RS35,retain);
  RS_init__(&data__->RS36,retain);
  TON_init__(&data__->TON6,retain);
  TP_init__(&data__->TP2,retain);
  TON_init__(&data__->TON7,retain);
  RS_init__(&data__->RS43,retain);
  RS_init__(&data__->RS44,retain);
  R_TRIG_init__(&data__->R_TRIG1,retain);
  F_TRIG_init__(&data__->F_TRIG1,retain);
  F_TRIG_init__(&data__->F_TRIG2,retain);
  R_TRIG_init__(&data__->R_TRIG2,retain);
  R_TRIG_init__(&data__->R_TRIG3,retain);
  __INIT_VAR(data__->_TMP_EQ104_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_LT118_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_GT105_OUT,__BOOL_LITERAL(FALSE),retain)
  F_TRIG_init__(&data__->F_TRIG3,retain);
  R_TRIG_init__(&data__->R_TRIG4,retain);
  R_TRIG_init__(&data__->R_TRIG5,retain);
  __INIT_VAR(data__->_TMP_LT211_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_EQ195_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_GT196_OUT,__BOOL_LITERAL(FALSE),retain)
  F_TRIG_init__(&data__->F_TRIG4,retain);
  R_TRIG_init__(&data__->R_TRIG6,retain);
  R_TRIG_init__(&data__->R_TRIG7,retain);
  __INIT_VAR(data__->_TMP_EQ300_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_GT301_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_LT316_OUT,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void PROGRAM3_body__(PROGRAM3 *data__) {
  // Initialise TEMP variables

  __SET_VAR(data__->R_TRIG1.,CLK,,__GET_VAR(data__->FACTORYIORESET0,));
  R_TRIG_body__(&data__->R_TRIG1);
  __SET_VAR(data__->,FACTORYRESET,,(!(__GET_VAR(data__->ESTOP0,)) || __GET_VAR(data__->R_TRIG1.Q,)));
  __SET_VAR(data__->RS1.,S,,__GET_VAR(data__->STARTCONDITION,));
  __SET_VAR(data__->RS1.,R1,,__GET_VAR(data__->FACTORYRESET,));
  RS_body__(&data__->RS1);
  __SET_VAR(data__->RS11.,S,,__GET_VAR(data__->RS1.Q1,));
  __SET_VAR(data__->RS11.,R1,,(((((((!(__GET_VAR(data__->TAPP1_ROTATECW,)) && __GET_VAR(data__->VS12,)) && !(__GET_VAR(data__->VS11,))) && !(__GET_VAR(data__->VS10,))) && !(__GET_VAR(data__->RETRO4,))) || ((((!(__GET_VAR(data__->TAPP2_ROTATECW,)) && __GET_VAR(data__->VS22,)) && __GET_VAR(data__->VS21,)) && __GET_VAR(data__->VS20,)) && !(__GET_VAR(data__->RETRO7,)))) || ((((!(__GET_VAR(data__->TAPP0_ROTATECW,)) && !(__GET_VAR(data__->VS02,))) && !(__GET_VAR(data__->VS01,))) && __GET_VAR(data__->VS00,)) && !(__GET_VAR(data__->RETRO1,)))) || __GET_VAR(data__->FACTORYRESET,)));
  RS_body__(&data__->RS11);
  __SET_VAR(data__->,BC_6M_0,,__GET_VAR(data__->RS11.Q1,));
  __SET_VAR(data__->,BC_6M_3,,__GET_VAR(data__->RS11.Q1,));
  __SET_VAR(data__->F_TRIG1.,CLK,,__GET_VAR(data__->STARTBUTTON0,));
  F_TRIG_body__(&data__->F_TRIG1);
  __SET_VAR(data__->,STARTCONDITION,,(__GET_VAR(data__->F_TRIG1.Q,) || __GET_VAR(data__->FACTORYRESET,)));
  __SET_VAR(data__->RS2.,S,,__GET_VAR(data__->STARTCONDITION,));
  __SET_VAR(data__->RS2.,R1,,__GET_VAR(data__->FACTORYRESET,));
  RS_body__(&data__->RS2);
  __SET_VAR(data__->,BC_2M_0,,__GET_VAR(data__->RS2.Q1,));
  __SET_VAR(data__->,BC_6M_1,,__GET_VAR(data__->RS2.Q1,));
  __SET_VAR(data__->,BC_6M_2,,__GET_VAR(data__->RS2.Q1,));
  __SET_VAR(data__->,BC_6M_4,,__GET_VAR(data__->RS2.Q1,));
  __SET_VAR(data__->RS5.,S,,__GET_VAR(data__->STARTCONDITION,));
  __SET_VAR(data__->RS5.,R1,,__GET_VAR(data__->FACTORYRESET,));
  RS_body__(&data__->RS5);
  __SET_VAR(data__->RS9.,S,,((((!(__GET_VAR(data__->VS02,)) && !(__GET_VAR(data__->VS01,))) && __GET_VAR(data__->VS00,)) && !(__GET_VAR(data__->RETRO1,))) && __GET_VAR(data__->RS5.Q1,)));
  __SET_VAR(data__->RS9.,R1,,(((((__GET_VAR(data__->TAPP0Z,) && __GET_VAR(data__->TAPP0_ROTATECW,)) && __GET_VAR(data__->TAPP0_ROTATECCW,)) && !(__GET_VAR(data__->TAPP0_DETECTED,))) || __GET_VAR(data__->FACTORYRESET,)) || !(__GET_VAR(data__->RETRO11,))));
  RS_body__(&data__->RS9);
  __SET_VAR(data__->,TAPP0X,,__GET_VAR(data__->RS9.Q1,));
  __SET_VAR(data__->RS12.,S,,__GET_VAR(data__->STARTCONDITION,));
  __SET_VAR(data__->RS12.,R1,,__GET_VAR(data__->FACTORYRESET,));
  RS_body__(&data__->RS12);
  __SET_VAR(data__->TON0.,IN,,(__GET_VAR(data__->TAPP0X,) && __GET_VAR(data__->RS12.Q1,)));
  __SET_VAR(data__->TON0.,PT,,__GET_VAR(data__->TAPP0ZPT,));
  TON_body__(&data__->TON0);
  __SET_VAR(data__->RS10.,S,,__GET_VAR(data__->TON0.Q,));
  __SET_VAR(data__->RS10.,R1,,((((__GET_VAR(data__->TAPP0_GRAB,) && __GET_VAR(data__->TAPP0_DETECTED,)) || ((__GET_VAR(data__->TAPP0_ROTATECW,) && __GET_VAR(data__->TAPP0_ROTATECCW,)) && !(__GET_VAR(data__->TAPP0_DETECTED,)))) || __GET_VAR(data__->FACTORYRESET,)) || !(__GET_VAR(data__->RETRO11,))));
  RS_body__(&data__->RS10);
  __SET_VAR(data__->,TAPP0Z,,__GET_VAR(data__->RS10.Q1,));
  __SET_VAR(data__->,TAPP0ZET,,__GET_VAR(data__->TON0.ET,));
  __SET_VAR(data__->RS14.,S,,__GET_VAR(data__->STARTCONDITION,));
  __SET_VAR(data__->RS14.,R1,,__GET_VAR(data__->FACTORYRESET,));
  RS_body__(&data__->RS14);
  __SET_VAR(data__->TON1.,IN,,(__GET_VAR(data__->TAPP0Z,) && __GET_VAR(data__->RS14.Q1,)));
  __SET_VAR(data__->TON1.,PT,,__GET_VAR(data__->GRAB0PT,));
  TON_body__(&data__->TON1);
  __SET_VAR(data__->RS13.,S,,__GET_VAR(data__->TON1.Q,));
  __SET_VAR(data__->RS13.,R1,,((((__GET_VAR(data__->TAPP0_ROTATECW,) && __GET_VAR(data__->TAPP0_ROTATECCW,)) && !(__GET_VAR(data__->TAPP0_DETECTED,))) || __GET_VAR(data__->FACTORYRESET,)) || !(__GET_VAR(data__->RETRO11,))));
  RS_body__(&data__->RS13);
  __SET_VAR(data__->TP0.,IN,,__GET_VAR(data__->RS13.Q1,));
  __SET_VAR(data__->TP0.,PT,,__GET_VAR(data__->GRAB0TPPT,));
  TP_body__(&data__->TP0);
  __SET_VAR(data__->,TAPP0_GRAB,,__GET_VAR(data__->TP0.Q,));
  __SET_VAR(data__->,GRAB0TPET,,__GET_VAR(data__->TP0.ET,));
  __SET_VAR(data__->,GRAB0ET,,__GET_VAR(data__->TON1.ET,));
  __SET_VAR(data__->RS16.,S,,__GET_VAR(data__->STARTCONDITION,));
  __SET_VAR(data__->RS16.,R1,,__GET_VAR(data__->FACTORYRESET,));
  RS_body__(&data__->RS16);
  __SET_VAR(data__->TON2.,IN,,(__GET_VAR(data__->TAPP0_GRAB,) && __GET_VAR(data__->RS16.Q1,)));
  __SET_VAR(data__->TON2.,PT,,__GET_VAR(data__->RCW0PT,));
  TON_body__(&data__->TON2);
  __SET_VAR(data__->,RCW0ET,,__GET_VAR(data__->TON2.ET,));
  __SET_VAR(data__->RS15.,S,,__GET_VAR(data__->TON2.Q,));
  __SET_VAR(data__->RS15.,R1,,(((__GET_VAR(data__->TAPP0_ROTATECCW,) && !(__GET_VAR(data__->RETRO0,))) || __GET_VAR(data__->FACTORYRESET,)) || !(__GET_VAR(data__->RETRO11,))));
  RS_body__(&data__->RS15);
  __SET_VAR(data__->,TAPP0_ROTATECW,,__GET_VAR(data__->RS15.Q1,));
  __SET_VAR(data__->F_TRIG2.,CLK,,__GET_VAR(data__->RETRO2,));
  F_TRIG_body__(&data__->F_TRIG2);
  __SET_VAR(data__->RS20.,S,,__GET_VAR(data__->STARTCONDITION,));
  __SET_VAR(data__->RS20.,R1,,__GET_VAR(data__->FACTORYRESET,));
  RS_body__(&data__->RS20);
  __SET_VAR(data__->R_TRIG2.,CLK,,(__GET_VAR(data__->F_TRIG2.Q,) && __GET_VAR(data__->RS20.Q1,)));
  R_TRIG_body__(&data__->R_TRIG2);
  __SET_VAR(data__->CTU0.,CU,,__GET_VAR(data__->R_TRIG2.Q,));
  __SET_VAR(data__->CTU0.,R,,__GET_VAR(data__->FACTORYRESET,));
  __SET_VAR(data__->CTU0.,PV,,__GET_VAR(data__->GRABBEDMAX,));
  CTU_body__(&data__->CTU0);
  __SET_VAR(data__->,BLUEGRABBED,,__GET_VAR(data__->CTU0.CV,));
  __SET_VAR(data__->RS21.,S,,__GET_VAR(data__->STARTCONDITION,));
  __SET_VAR(data__->RS21.,R1,,__GET_VAR(data__->FACTORYRESET,));
  RS_body__(&data__->RS21);
  __SET_VAR(data__->R_TRIG3.,CLK,,(((!(__GET_VAR(data__->VISIONSENSOR32,)) && !(__GET_VAR(data__->VISIONSENSOR31,))) && __GET_VAR(data__->VISIONSENSOR30,)) && __GET_VAR(data__->RS21.Q1,)));
  R_TRIG_body__(&data__->R_TRIG3);
  __SET_VAR(data__->CTU1.,CU,,__GET_VAR(data__->R_TRIG3.Q,));
  __SET_VAR(data__->CTU1.,R,,__GET_VAR(data__->FACTORYRESET,));
  __SET_VAR(data__->CTU1.,PV,,__GET_VAR(data__->GRABBEDMAX,));
  CTU_body__(&data__->CTU1);
  __SET_VAR(data__->,BLUEMISSED,,__GET_VAR(data__->CTU1.CV,));
  __SET_VAR(data__->RS18.,S,,__GET_VAR(data__->STARTCONDITION,));
  __SET_VAR(data__->RS18.,R1,,__GET_VAR(data__->FACTORYRESET,));
  RS_body__(&data__->RS18);
  __SET_VAR(data__->RS17.,S,,(((((!(__GET_VAR(data__->VS01,)) && __GET_VAR(data__->VS00,)) && !(__GET_VAR(data__->TAPP0_DETECTED,))) && __GET_VAR(data__->TAPP0_ROTATECW,)) || !(__GET_VAR(data__->RETRO11,))) && __GET_VAR(data__->RS18.Q1,)));
  __SET_VAR(data__->RS17.,R1,,(((((((!(__GET_VAR(data__->TAPP0_ROTATECW,)) && !(__GET_VAR(data__->VS02,))) && !(__GET_VAR(data__->VS01,))) && __GET_VAR(data__->VS00,)) && !(__GET_VAR(data__->RETRO1,))) || (__GET_VAR(data__->TAPP0_ROTATECW,) && !(__GET_VAR(data__->RETRO0,)))) || __GET_VAR(data__->FACTORYRESET,)) || !(__GET_VAR(data__->RETRO12,))));
  RS_body__(&data__->RS17);
  __SET_VAR(data__->,TAPP0_ROTATECCW,,__GET_VAR(data__->RS17.Q1,));
  __SET_VAR(data__->,_TMP_EQ104_OUT,,EQ__BOOL__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (INT)__GET_VAR(data__->BLUEGRABBED,),
    (INT)__GET_VAR(data__->BLUEMISSED,)));
  __SET_VAR(data__->,STACKLIGHT0_YELLOW,,__GET_VAR(data__->_TMP_EQ104_OUT,));
  __SET_VAR(data__->,_TMP_LT118_OUT,,LT__BOOL__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (INT)__GET_VAR(data__->BLUEGRABBED,),
    (INT)__GET_VAR(data__->BLUEMISSED,)));
  __SET_VAR(data__->,STACKLIGHT0_RED,,__GET_VAR(data__->_TMP_LT118_OUT,));
  __SET_VAR(data__->,_TMP_GT105_OUT,,GT__BOOL__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (INT)__GET_VAR(data__->BLUEGRABBED,),
    (INT)__GET_VAR(data__->BLUEMISSED,)));
  __SET_VAR(data__->,STACKLIGHT0_GREEN,,__GET_VAR(data__->_TMP_GT105_OUT,));
  __SET_VAR(data__->RS6.,S,,__GET_VAR(data__->STARTCONDITION,));
  __SET_VAR(data__->RS6.,R1,,__GET_VAR(data__->FACTORYRESET,));
  RS_body__(&data__->RS6);
  __SET_VAR(data__->RS23.,S,,((((__GET_VAR(data__->VS12,) && !(__GET_VAR(data__->VS11,))) && !(__GET_VAR(data__->VS10,))) && !(__GET_VAR(data__->RETRO4,))) && __GET_VAR(data__->RS6.Q1,)));
  __SET_VAR(data__->RS23.,R1,,(((((__GET_VAR(data__->TAPP1Z,) && __GET_VAR(data__->TAPP1_ROTATECW,)) && __GET_VAR(data__->TAPP1_ROTATECCW,)) && !(__GET_VAR(data__->TAPP1_DETECTED,))) || __GET_VAR(data__->FACTORYRESET,)) || !(__GET_VAR(data__->RETRO14,))));
  RS_body__(&data__->RS23);
  __SET_VAR(data__->,TAPP1X,,__GET_VAR(data__->RS23.Q1,));
  __SET_VAR(data__->RS24.,S,,__GET_VAR(data__->STARTCONDITION,));
  __SET_VAR(data__->RS24.,R1,,__GET_VAR(data__->FACTORYRESET,));
  RS_body__(&data__->RS24);
  __SET_VAR(data__->TON5.,IN,,(__GET_VAR(data__->TAPP1X,) && __GET_VAR(data__->RS24.Q1,)));
  __SET_VAR(data__->TON5.,PT,,__GET_VAR(data__->TAPP1ZPT,));
  TON_body__(&data__->TON5);
  __SET_VAR(data__->RS22.,S,,__GET_VAR(data__->TON5.Q,));
  __SET_VAR(data__->RS22.,R1,,((((__GET_VAR(data__->TAPP1_GRAB,) && __GET_VAR(data__->TAPP1_DETECTED,)) || ((__GET_VAR(data__->TAPP1_ROTATECW,) && __GET_VAR(data__->TAPP1_ROTATECCW,)) && !(__GET_VAR(data__->TAPP1_DETECTED,)))) || __GET_VAR(data__->FACTORYRESET,)) || !(__GET_VAR(data__->RETRO14,))));
  RS_body__(&data__->RS22);
  __SET_VAR(data__->,TAPP1Z,,__GET_VAR(data__->RS22.Q1,));
  __SET_VAR(data__->,TAPP1ZET,,__GET_VAR(data__->TON5.ET,));
  __SET_VAR(data__->RS25.,S,,__GET_VAR(data__->STARTCONDITION,));
  __SET_VAR(data__->RS25.,R1,,__GET_VAR(data__->FACTORYRESET,));
  RS_body__(&data__->RS25);
  __SET_VAR(data__->TON3.,IN,,(__GET_VAR(data__->TAPP1Z,) && __GET_VAR(data__->RS25.Q1,)));
  __SET_VAR(data__->TON3.,PT,,__GET_VAR(data__->GRAB1PT,));
  TON_body__(&data__->TON3);
  __SET_VAR(data__->RS19.,S,,__GET_VAR(data__->TON3.Q,));
  __SET_VAR(data__->RS19.,R1,,((((__GET_VAR(data__->TAPP1_ROTATECW,) && __GET_VAR(data__->TAPP1_ROTATECCW,)) && !(__GET_VAR(data__->TAPP1_DETECTED,))) || __GET_VAR(data__->FACTORYRESET,)) || !(__GET_VAR(data__->RETRO14,))));
  RS_body__(&data__->RS19);
  __SET_VAR(data__->TP1.,IN,,__GET_VAR(data__->RS19.Q1,));
  __SET_VAR(data__->TP1.,PT,,__GET_VAR(data__->GRAB1TPPT,));
  TP_body__(&data__->TP1);
  __SET_VAR(data__->,TAPP1_GRAB,,__GET_VAR(data__->TP1.Q,));
  __SET_VAR(data__->,GRAB1TPET,,__GET_VAR(data__->TP1.ET,));
  __SET_VAR(data__->,GRAB1ET,,__GET_VAR(data__->TON3.ET,));
  __SET_VAR(data__->F_TRIG3.,CLK,,__GET_VAR(data__->RETROREFLECTIVESENSOR5,));
  F_TRIG_body__(&data__->F_TRIG3);
  __SET_VAR(data__->RS31.,S,,__GET_VAR(data__->STARTCONDITION,));
  __SET_VAR(data__->RS31.,R1,,__GET_VAR(data__->FACTORYRESET,));
  RS_body__(&data__->RS31);
  __SET_VAR(data__->R_TRIG4.,CLK,,(__GET_VAR(data__->F_TRIG3.Q,) && __GET_VAR(data__->RS31.Q1,)));
  R_TRIG_body__(&data__->R_TRIG4);
  __SET_VAR(data__->CTU3.,CU,,__GET_VAR(data__->R_TRIG4.Q,));
  __SET_VAR(data__->CTU3.,R,,__GET_VAR(data__->FACTORYRESET,));
  __SET_VAR(data__->CTU3.,PV,,__GET_VAR(data__->GRABBEDMAX,));
  CTU_body__(&data__->CTU3);
  __SET_VAR(data__->,GREENGRABBED,,__GET_VAR(data__->CTU3.CV,));
  __SET_VAR(data__->RS27.,S,,__GET_VAR(data__->STARTCONDITION,));
  __SET_VAR(data__->RS27.,R1,,__GET_VAR(data__->FACTORYRESET,));
  RS_body__(&data__->RS27);
  __SET_VAR(data__->TON4.,IN,,(__GET_VAR(data__->TAPP1_GRAB,) && __GET_VAR(data__->RS27.Q1,)));
  __SET_VAR(data__->TON4.,PT,,__GET_VAR(data__->RCW1PT,));
  TON_body__(&data__->TON4);
  __SET_VAR(data__->,RCW1ET,,__GET_VAR(data__->TON4.ET,));
  __SET_VAR(data__->RS26.,S,,__GET_VAR(data__->TON4.Q,));
  __SET_VAR(data__->RS26.,R1,,(((__GET_VAR(data__->TAPP1_ROTATECCW,) && !(__GET_VAR(data__->RETROREFLECTIVESENSOR3,))) || __GET_VAR(data__->FACTORYRESET,)) || !(__GET_VAR(data__->RETRO14,))));
  RS_body__(&data__->RS26);
  __SET_VAR(data__->,TAPP1_ROTATECW,,__GET_VAR(data__->RS26.Q1,));
  __SET_VAR(data__->RS30.,S,,__GET_VAR(data__->STARTCONDITION,));
  __SET_VAR(data__->RS30.,R1,,__GET_VAR(data__->FACTORYRESET,));
  RS_body__(&data__->RS30);
  __SET_VAR(data__->R_TRIG5.,CLK,,(((__GET_VAR(data__->VISIONSENSOR32,) && !(__GET_VAR(data__->VISIONSENSOR31,))) && !(__GET_VAR(data__->VISIONSENSOR30,))) && __GET_VAR(data__->RS30.Q1,)));
  R_TRIG_body__(&data__->R_TRIG5);
  __SET_VAR(data__->CTU2.,CU,,__GET_VAR(data__->R_TRIG5.Q,));
  __SET_VAR(data__->CTU2.,R,,__GET_VAR(data__->FACTORYRESET,));
  __SET_VAR(data__->CTU2.,PV,,__GET_VAR(data__->GRABBEDMAX,));
  CTU_body__(&data__->CTU2);
  __SET_VAR(data__->,GREENMISSED,,__GET_VAR(data__->CTU2.CV,));
  __SET_VAR(data__->,_TMP_LT211_OUT,,LT__BOOL__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (INT)__GET_VAR(data__->GREENGRABBED,),
    (INT)__GET_VAR(data__->GREENMISSED,)));
  __SET_VAR(data__->,STACKLIGHT1_RED,,__GET_VAR(data__->_TMP_LT211_OUT,));
  __SET_VAR(data__->,_TMP_EQ195_OUT,,EQ__BOOL__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (INT)__GET_VAR(data__->GREENGRABBED,),
    (INT)__GET_VAR(data__->GREENMISSED,)));
  __SET_VAR(data__->,STACKLIGHT1_YELLOW,,__GET_VAR(data__->_TMP_EQ195_OUT,));
  __SET_VAR(data__->,_TMP_GT196_OUT,,GT__BOOL__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (INT)__GET_VAR(data__->GREENGRABBED,),
    (INT)__GET_VAR(data__->GREENMISSED,)));
  __SET_VAR(data__->,STACKLIGHT1_GREEN,,__GET_VAR(data__->_TMP_GT196_OUT,));
  __SET_VAR(data__->RS29.,S,,__GET_VAR(data__->STARTCONDITION,));
  __SET_VAR(data__->RS29.,R1,,__GET_VAR(data__->FACTORYRESET,));
  RS_body__(&data__->RS29);
  __SET_VAR(data__->RS28.,S,,(((((!(__GET_VAR(data__->VS10,)) && __GET_VAR(data__->VS12,)) && !(__GET_VAR(data__->TAPP1_DETECTED,))) && __GET_VAR(data__->TAPP1_ROTATECW,)) || !(__GET_VAR(data__->RETRO14,))) && __GET_VAR(data__->RS29.Q1,)));
  __SET_VAR(data__->RS28.,R1,,(((((((!(__GET_VAR(data__->TAPP1_ROTATECW,)) && __GET_VAR(data__->VS12,)) && !(__GET_VAR(data__->VS11,))) && !(__GET_VAR(data__->VS10,))) && !(__GET_VAR(data__->RETRO4,))) || (__GET_VAR(data__->TAPP1_ROTATECW,) && !(__GET_VAR(data__->RETROREFLECTIVESENSOR3,)))) || __GET_VAR(data__->FACTORYRESET,)) || !(__GET_VAR(data__->RETRO13,))));
  RS_body__(&data__->RS28);
  __SET_VAR(data__->,TAPP1_ROTATECCW,,__GET_VAR(data__->RS28.Q1,));
  __SET_VAR(data__->RS7.,S,,__GET_VAR(data__->STARTCONDITION,));
  __SET_VAR(data__->RS7.,R1,,__GET_VAR(data__->FACTORYRESET,));
  RS_body__(&data__->RS7);
  __SET_VAR(data__->RS32.,S,,((((__GET_VAR(data__->VS22,) && __GET_VAR(data__->VS21,)) && __GET_VAR(data__->VS20,)) && !(__GET_VAR(data__->RETRO7,))) && __GET_VAR(data__->RS7.Q1,)));
  __SET_VAR(data__->RS32.,R1,,(((((__GET_VAR(data__->TAPP2Z,) && __GET_VAR(data__->TAPP2_ROTATECW,)) && __GET_VAR(data__->TAPP2_ROTATECCW,)) && !(__GET_VAR(data__->TAPP2_DETECTED,))) || __GET_VAR(data__->FACTORYRESET,)) || !(__GET_VAR(data__->RETRO15,))));
  RS_body__(&data__->RS32);
  __SET_VAR(data__->,TAPP2X,,__GET_VAR(data__->RS32.Q1,));
  __SET_VAR(data__->RS35.,S,,__GET_VAR(data__->STARTCONDITION,));
  __SET_VAR(data__->RS35.,R1,,__GET_VAR(data__->FACTORYRESET,));
  RS_body__(&data__->RS35);
  __SET_VAR(data__->TON7.,IN,,(__GET_VAR(data__->TAPP2X,) && __GET_VAR(data__->RS35.Q1,)));
  __SET_VAR(data__->TON7.,PT,,__GET_VAR(data__->TAPP2ZPT,));
  TON_body__(&data__->TON7);
  __SET_VAR(data__->RS34.,S,,__GET_VAR(data__->TON7.Q,));
  __SET_VAR(data__->RS34.,R1,,((((__GET_VAR(data__->TAPP2_GRAB,) && __GET_VAR(data__->TAPP2_DETECTED,)) || ((__GET_VAR(data__->TAPP2_ROTATECW,) && __GET_VAR(data__->TAPP2_ROTATECCW,)) && !(__GET_VAR(data__->TAPP2_DETECTED,)))) || __GET_VAR(data__->FACTORYRESET,)) || !(__GET_VAR(data__->RETRO15,))));
  RS_body__(&data__->RS34);
  __SET_VAR(data__->,TAPP2Z,,__GET_VAR(data__->RS34.Q1,));
  __SET_VAR(data__->,TAPP2ZET,,__GET_VAR(data__->TON7.ET,));
  __SET_VAR(data__->RS36.,S,,__GET_VAR(data__->STARTCONDITION,));
  __SET_VAR(data__->RS36.,R1,,__GET_VAR(data__->FACTORYRESET,));
  RS_body__(&data__->RS36);
  __SET_VAR(data__->TON6.,IN,,(__GET_VAR(data__->TAPP2Z,) && __GET_VAR(data__->RS36.Q1,)));
  __SET_VAR(data__->TON6.,PT,,__GET_VAR(data__->GRAB2PT,));
  TON_body__(&data__->TON6);
  __SET_VAR(data__->RS33.,S,,__GET_VAR(data__->TON6.Q,));
  __SET_VAR(data__->RS33.,R1,,((((__GET_VAR(data__->TAPP2_ROTATECW,) && __GET_VAR(data__->TAPP2_ROTATECCW,)) && !(__GET_VAR(data__->TAPP2_DETECTED,))) || __GET_VAR(data__->FACTORYRESET,)) || !(__GET_VAR(data__->RETRO15,))));
  RS_body__(&data__->RS33);
  __SET_VAR(data__->TP2.,IN,,__GET_VAR(data__->RS33.Q1,));
  __SET_VAR(data__->TP2.,PT,,__GET_VAR(data__->GRAB2TPPT,));
  TP_body__(&data__->TP2);
  __SET_VAR(data__->,TAPP2_GRAB,,__GET_VAR(data__->TP2.Q,));
  __SET_VAR(data__->,GRAB2TPET,,__GET_VAR(data__->TP2.ET,));
  __SET_VAR(data__->,GRAB2ET,,__GET_VAR(data__->TON6.ET,));
  __SET_VAR(data__->RS38.,S,,__GET_VAR(data__->STARTCONDITION,));
  __SET_VAR(data__->RS38.,R1,,__GET_VAR(data__->FACTORYRESET,));
  RS_body__(&data__->RS38);
  __SET_VAR(data__->TON8.,IN,,(__GET_VAR(data__->TAPP2_GRAB,) && __GET_VAR(data__->RS38.Q1,)));
  __SET_VAR(data__->TON8.,PT,,__GET_VAR(data__->RCW2PT,));
  TON_body__(&data__->TON8);
  __SET_VAR(data__->RS37.,S,,__GET_VAR(data__->TON8.Q,));
  __SET_VAR(data__->RS37.,R1,,(((__GET_VAR(data__->TAPP2_ROTATECCW,) && !(__GET_VAR(data__->RETROREFLECTIVESENSOR6,))) || __GET_VAR(data__->FACTORYRESET,)) || !(__GET_VAR(data__->RETRO15,))));
  RS_body__(&data__->RS37);
  __SET_VAR(data__->,TAPP2_ROTATECW,,__GET_VAR(data__->RS37.Q1,));
  __SET_VAR(data__->,RCW2ET,,__GET_VAR(data__->TON8.ET,));
  __SET_VAR(data__->F_TRIG4.,CLK,,__GET_VAR(data__->RETROREFLECTIVESENSOR8,));
  F_TRIG_body__(&data__->F_TRIG4);
  __SET_VAR(data__->RS42.,S,,__GET_VAR(data__->STARTCONDITION,));
  __SET_VAR(data__->RS42.,R1,,__GET_VAR(data__->FACTORYRESET,));
  RS_body__(&data__->RS42);
  __SET_VAR(data__->R_TRIG6.,CLK,,(__GET_VAR(data__->F_TRIG4.Q,) && __GET_VAR(data__->RS42.Q1,)));
  R_TRIG_body__(&data__->R_TRIG6);
  __SET_VAR(data__->CTU5.,CU,,__GET_VAR(data__->R_TRIG6.Q,));
  __SET_VAR(data__->CTU5.,R,,__GET_VAR(data__->FACTORYRESET,));
  __SET_VAR(data__->CTU5.,PV,,__GET_VAR(data__->GRABBEDMAX,));
  CTU_body__(&data__->CTU5);
  __SET_VAR(data__->,GREYGRABBED,,__GET_VAR(data__->CTU5.CV,));
  __SET_VAR(data__->RS41.,S,,__GET_VAR(data__->STARTCONDITION,));
  __SET_VAR(data__->RS41.,R1,,__GET_VAR(data__->FACTORYRESET,));
  RS_body__(&data__->RS41);
  __SET_VAR(data__->R_TRIG7.,CLK,,(((__GET_VAR(data__->VISIONSENSOR32,) && __GET_VAR(data__->VISIONSENSOR31,)) && __GET_VAR(data__->VISIONSENSOR30,)) && __GET_VAR(data__->RS41.Q1,)));
  R_TRIG_body__(&data__->R_TRIG7);
  __SET_VAR(data__->CTU4.,CU,,__GET_VAR(data__->R_TRIG7.Q,));
  __SET_VAR(data__->CTU4.,R,,__GET_VAR(data__->FACTORYRESET,));
  __SET_VAR(data__->CTU4.,PV,,__GET_VAR(data__->GRABBEDMAX,));
  CTU_body__(&data__->CTU4);
  __SET_VAR(data__->,GREYMISSED,,__GET_VAR(data__->CTU4.CV,));
  __SET_VAR(data__->,_TMP_EQ300_OUT,,EQ__BOOL__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (INT)__GET_VAR(data__->GREYGRABBED,),
    (INT)__GET_VAR(data__->GREYMISSED,)));
  __SET_VAR(data__->,STACKLIGHT2_YELLOW,,__GET_VAR(data__->_TMP_EQ300_OUT,));
  __SET_VAR(data__->,_TMP_GT301_OUT,,GT__BOOL__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (INT)__GET_VAR(data__->GREYGRABBED,),
    (INT)__GET_VAR(data__->GREYMISSED,)));
  __SET_VAR(data__->,STACKLIGHT2_GREEN,,__GET_VAR(data__->_TMP_GT301_OUT,));
  __SET_VAR(data__->,_TMP_LT316_OUT,,LT__BOOL__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (INT)__GET_VAR(data__->GREYGRABBED,),
    (INT)__GET_VAR(data__->GREYMISSED,)));
  __SET_VAR(data__->,STACKLIGHT2_RED,,__GET_VAR(data__->_TMP_LT316_OUT,));
  __SET_VAR(data__->RS44.,S,,__GET_VAR(data__->STARTCONDITION,));
  __SET_VAR(data__->RS44.,R1,,__GET_VAR(data__->FACTORYRESET,));
  RS_body__(&data__->RS44);
  __SET_VAR(data__->RS43.,S,,((!(__GET_VAR(data__->RETRO15,)) || (((__GET_VAR(data__->VS21,) && __GET_VAR(data__->VS22,)) && !(__GET_VAR(data__->TAPP2_DETECTED,))) && __GET_VAR(data__->TAPP2_ROTATECW,))) && __GET_VAR(data__->RS44.Q1,)));
  __SET_VAR(data__->RS43.,R1,,(((((((!(__GET_VAR(data__->TAPP2_ROTATECW,)) && __GET_VAR(data__->VS22,)) && __GET_VAR(data__->VS21,)) && __GET_VAR(data__->VS20,)) && !(__GET_VAR(data__->RETRO4,))) || (__GET_VAR(data__->TAPP2_ROTATECW,) && !(__GET_VAR(data__->RETROREFLECTIVESENSOR6,)))) || __GET_VAR(data__->FACTORYRESET,)) || !(__GET_VAR(data__->RETRO16,))));
  RS_body__(&data__->RS43);
  __SET_VAR(data__->,TAPP2_ROTATECCW,,__GET_VAR(data__->RS43.Q1,));

  goto __end;

__end:
  return;
} // PROGRAM3_body__() 





