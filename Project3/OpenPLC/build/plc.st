TYPE
  LOGLEVEL : (CRITICAL, WARNING, INFO, DEBUG) := INFO;
END_TYPE

FUNCTION_BLOCK LOGGER
  VAR_INPUT
    TRIG : BOOL;
    MSG : STRING;
    LEVEL : LOGLEVEL := INFO;
  END_VAR
  VAR
    TRIG0 : BOOL;
  END_VAR

  IF TRIG AND NOT TRIG0 THEN
  {{
   LogMessage(GetFbVar(LEVEL),(char*)GetFbVar(MSG, .body),GetFbVar(MSG, .len));
  }}
  END_IF;
  TRIG0:=TRIG;
END_FUNCTION_BLOCK



FUNCTION_BLOCK python_eval
  VAR_INPUT
    TRIG : BOOL;
    CODE : STRING;
  END_VAR
  VAR_OUTPUT
    ACK : BOOL;
    RESULT : STRING;
  END_VAR
  VAR
    STATE : DWORD;
    BUFFER : STRING;
    PREBUFFER : STRING;
    TRIGM1 : BOOL;
    TRIGGED : BOOL;
  END_VAR

  {extern void __PythonEvalFB(int, PYTHON_EVAL*);__PythonEvalFB(0, data__);}
END_FUNCTION_BLOCK

FUNCTION_BLOCK python_poll
  VAR_INPUT
    TRIG : BOOL;
    CODE : STRING;
  END_VAR
  VAR_OUTPUT
    ACK : BOOL;
    RESULT : STRING;
  END_VAR
  VAR
    STATE : DWORD;
    BUFFER : STRING;
    PREBUFFER : STRING;
    TRIGM1 : BOOL;
    TRIGGED : BOOL;
  END_VAR

  {extern void __PythonEvalFB(int, PYTHON_EVAL*);__PythonEvalFB(1,(PYTHON_EVAL*)(void*)data__);}
END_FUNCTION_BLOCK

FUNCTION_BLOCK python_gear
  VAR_INPUT
    N : UINT;
    TRIG : BOOL;
    CODE : STRING;
  END_VAR
  VAR_OUTPUT
    ACK : BOOL;
    RESULT : STRING;
  END_VAR
  VAR
    py_eval : python_eval;
    COUNTER : UINT;
    _TMP_ADD10_OUT : UINT;
    _TMP_EQ13_OUT : BOOL;
    _TMP_SEL15_OUT : UINT;
    _TMP_AND7_OUT : BOOL;
  END_VAR

  _TMP_ADD10_OUT := ADD(COUNTER, 1);
  _TMP_EQ13_OUT := EQ(N, _TMP_ADD10_OUT);
  _TMP_SEL15_OUT := SEL(_TMP_EQ13_OUT, _TMP_ADD10_OUT, 0);
  COUNTER := _TMP_SEL15_OUT;
  _TMP_AND7_OUT := AND(_TMP_EQ13_OUT, TRIG);
  py_eval(TRIG := _TMP_AND7_OUT, CODE := CODE);
  ACK := py_eval.ACK;
  RESULT := py_eval.RESULT;
END_FUNCTION_BLOCK


PROGRAM program3
  VAR
    FactoryIOReset0 : BOOL;
    StartButton0 : BOOL;
    EStop0 : BOOL;
    Retro0 : BOOL;
    Retro1 : BOOL;
    VS00 : BOOL;
    VS01 : BOOL;
    VS02 : BOOL;
    VS03 : BOOL;
    TAPP0_Detected : BOOL;
    TAPP0_MovingX : BOOL;
    TAPP0_MovingZ : BOOL;
    TAPP0_Rotating : BOOL;
    Retro2 : BOOL;
    RetroreflectiveSensor3 : BOOL;
    Retro4 : BOOL;
    VS10 : BOOL;
    VS11 : BOOL;
    VS12 : BOOL;
    VisionSensor13 : BOOL;
    TAPP1_Detected : BOOL;
    TwoAxisPickPlace1_MovingX : BOOL;
    TwoAxisPickPlace1_MovingZ : BOOL;
    TwoAxisPickPlace1_Rotating : BOOL;
    RetroreflectiveSensor5 : BOOL;
    RetroreflectiveSensor6 : BOOL;
    Retro7 : BOOL;
    VS20 : BOOL;
    VS21 : BOOL;
    VS22 : BOOL;
    VisionSensor23 : BOOL;
    TAPP2_Detected : BOOL;
    TwoAxisPickPlace2_MovingX : BOOL;
    TwoAxisPickPlace2_MovingZ : BOOL;
    TwoAxisPickPlace2_Rotating : BOOL;
    RetroreflectiveSensor8 : BOOL;
    RetroreflectiveSensor9 : BOOL;
    RetroreflectiveSensor10 : BOOL;
    VisionSensor30 : BOOL;
    VisionSensor31 : BOOL;
    VisionSensor32 : BOOL;
    VisionSensor33 : BOOL;
    Retro11 : BOOL;
    Retro12 : BOOL;
    Retro13 : BOOL;
    Retro14 : BOOL;
    Retro15 : BOOL;
    Retro16 : BOOL;
    TAPP0X : BOOL;
    TAPP0Z : BOOL;
    TAPP0_Grab : BOOL;
    TAPP0_RotateCW : BOOL;
    TAPP0_RotateCCW : BOOL;
    BC_6m_0 : BOOL;
    BC_6m_1 : BOOL;
    BC_6m_2 : BOOL;
    BC_6m_3 : BOOL;
    BC_6m_4 : BOOL;
    TAPP1X : BOOL;
    TAPP1Z : BOOL;
    TAPP1_Grab : BOOL;
    TAPP1_RotateCCW : BOOL;
    TAPP1_RotateCW : BOOL;
    GreenBoxDetected : BOOL;
    TAPP2X : BOOL;
    TAPP2Z : BOOL;
    TAPP2_Grab : BOOL;
    TAPP2_RotateCW : BOOL;
    TAPP2_RotateCCW : BOOL;
    BC_2m_0 : BOOL;
    BlueBoxDetected : BOOL;
    GreyBoxDetected0 : BOOL;
    StackLight0_Green : BOOL;
    StackLight0_Yellow : BOOL;
    StackLight0_Red : BOOL;
    StackLight1_Green : BOOL;
    StackLight1_Yellow : BOOL;
    StackLight1_Red : BOOL;
    StackLight2_Green : BOOL;
    StackLight2_Yellow : BOOL;
    StackLight2_Red : BOOL;
    LightIndicator_Red_2 : BOOL;
    BlueGrabbed : INT;
    GreenGrabbed : INT;
    GreyGrabbed : INT;
    BlueMissed : INT;
    GreenMissed : INT;
    GreyMissed : INT;
  END_VAR
  VAR
    FactoryReset : BOOL;
    StartCondition : BOOL;
    RS1 : RS;
    TAPP0ZPT : TIME := T#2s;
    RCW0PT : TIME := T#2s;
    RCW1PT : TIME := T#2s;
    RCW2PT : TIME := T#2s;
    TAPP1ZPT : TIME := T#2s;
    TAPP2ZPT : TIME := T#2s;
    TAPP0ZET : TIME;
    TAPP1ZET : TIME;
    TAPP2ZET : TIME;
    Grab0PT : TIME := T#0.5s;
    Grab2PT : TIME := T#0.5s;
    Grab1PT : TIME := T#0.5s;
    Grab0ET : TIME;
    RCW0ET : TIME;
    RCW1ET : TIME;
    RCW2ET : TIME;
    Grab1ET : TIME;
    Grab2ET : TIME;
    Grab0TPPT : TIME := T#3s;
    Grab1TPPT : TIME := T#3s;
    Grab2TPPT : TIME := T#3s;
    Grab0TPET : TIME;
    Grab1TPET : TIME;
    Grab2TPET : TIME;
    GreyBox : BOOL;
    RS5 : RS;
    GrabbedMax : INT := 50;
    RS11 : RS;
    RS9 : RS;
    RS10 : RS;
    RS12 : RS;
    TON0 : TON;
    RS14 : RS;
    TON1 : TON;
    RS15 : RS;
    RS16 : RS;
    TON2 : TON;
    TP0 : TP;
    RS13 : RS;
    RS17 : RS;
    RS18 : RS;
    RS2 : RS;
    CTU0 : CTU;
    RS20 : RS;
    CTU1 : CTU;
    RS21 : RS;
    CTU2 : CTU;
    RS30 : RS;
    CTU3 : CTU;
    RS31 : RS;
    RS32 : RS;
    RS7 : RS;
    RS37 : RS;
    RS38 : RS;
    TON8 : TON;
    CTU4 : CTU;
    RS41 : RS;
    CTU5 : CTU;
    RS42 : RS;
    RS19 : RS;
    RS22 : RS;
    RS23 : RS;
    RS24 : RS;
    RS25 : RS;
    TON3 : TON;
    RS6 : RS;
    RS26 : RS;
    RS27 : RS;
    TON4 : TON;
    TP1 : TP;
    TON5 : TON;
    RS28 : RS;
    RS29 : RS;
    RS33 : RS;
    RS34 : RS;
    RS35 : RS;
    RS36 : RS;
    TON6 : TON;
    TP2 : TP;
    TON7 : TON;
    RS43 : RS;
    RS44 : RS;
    R_TRIG1 : R_TRIG;
    F_TRIG1 : F_TRIG;
    F_TRIG2 : F_TRIG;
    R_TRIG2 : R_TRIG;
    R_TRIG3 : R_TRIG;
    _TMP_EQ104_OUT : BOOL;
    _TMP_LT118_OUT : BOOL;
    _TMP_GT105_OUT : BOOL;
    F_TRIG3 : F_TRIG;
    R_TRIG4 : R_TRIG;
    R_TRIG5 : R_TRIG;
    _TMP_LT211_OUT : BOOL;
    _TMP_EQ195_OUT : BOOL;
    _TMP_GT196_OUT : BOOL;
    F_TRIG4 : F_TRIG;
    R_TRIG6 : R_TRIG;
    R_TRIG7 : R_TRIG;
    _TMP_EQ300_OUT : BOOL;
    _TMP_GT301_OUT : BOOL;
    _TMP_LT316_OUT : BOOL;
  END_VAR

  R_TRIG1(CLK := FactoryIOReset0);
  FactoryReset := NOT(EStop0) OR R_TRIG1.Q;
  RS1(S := StartCondition, R1 := FactoryReset);
  RS11(S := RS1.Q1, R1 := NOT(TAPP1_RotateCW) AND VS12 AND NOT(VS11) AND NOT(VS10) AND NOT(Retro4) OR NOT(TAPP2_RotateCW) AND VS22 AND VS21 AND VS20 AND NOT(Retro7) OR NOT(TAPP0_RotateCW) AND NOT(VS02) AND NOT(VS01) AND VS00 AND NOT(Retro1) OR FactoryReset);
  BC_6m_0 := RS11.Q1;
  BC_6m_3 := RS11.Q1;
  F_TRIG1(CLK := StartButton0);
  StartCondition := F_TRIG1.Q OR FactoryReset;
  RS2(S := StartCondition, R1 := FactoryReset);
  BC_2m_0 := RS2.Q1;
  BC_6m_1 := RS2.Q1;
  BC_6m_2 := RS2.Q1;
  BC_6m_4 := RS2.Q1;
  RS5(S := StartCondition, R1 := FactoryReset);
  RS9(S := NOT(VS02) AND NOT(VS01) AND VS00 AND NOT(Retro1) AND RS5.Q1, R1 := TAPP0Z AND TAPP0_RotateCW AND TAPP0_RotateCCW AND NOT(TAPP0_Detected) OR FactoryReset OR NOT(Retro11));
  TAPP0X := RS9.Q1;
  RS12(S := StartCondition, R1 := FactoryReset);
  TON0(IN := TAPP0X AND RS12.Q1, PT := TAPP0ZPT);
  RS10(S := TON0.Q, R1 := TAPP0_Grab AND TAPP0_Detected OR TAPP0_RotateCW AND TAPP0_RotateCCW AND NOT(TAPP0_Detected) OR FactoryReset OR NOT(Retro11));
  TAPP0Z := RS10.Q1;
  TAPP0ZET := TON0.ET;
  RS14(S := StartCondition, R1 := FactoryReset);
  TON1(IN := TAPP0Z AND RS14.Q1, PT := Grab0PT);
  RS13(S := TON1.Q, R1 := TAPP0_RotateCW AND TAPP0_RotateCCW AND NOT(TAPP0_Detected) OR FactoryReset OR NOT(Retro11));
  TP0(IN := RS13.Q1, PT := Grab0TPPT);
  TAPP0_Grab := TP0.Q;
  Grab0TPET := TP0.ET;
  Grab0ET := TON1.ET;
  RS16(S := StartCondition, R1 := FactoryReset);
  TON2(IN := TAPP0_Grab AND RS16.Q1, PT := RCW0PT);
  RCW0ET := TON2.ET;
  RS15(S := TON2.Q, R1 := TAPP0_RotateCCW AND NOT(Retro0) OR FactoryReset OR NOT(Retro11));
  TAPP0_RotateCW := RS15.Q1;
  F_TRIG2(CLK := Retro2);
  RS20(S := StartCondition, R1 := FactoryReset);
  R_TRIG2(CLK := F_TRIG2.Q AND RS20.Q1);
  CTU0(CU := R_TRIG2.Q, R := FactoryReset, PV := GrabbedMax);
  BlueGrabbed := CTU0.CV;
  RS21(S := StartCondition, R1 := FactoryReset);
  R_TRIG3(CLK := NOT(VisionSensor32) AND NOT(VisionSensor31) AND VisionSensor30 AND RS21.Q1);
  CTU1(CU := R_TRIG3.Q, R := FactoryReset, PV := GrabbedMax);
  BlueMissed := CTU1.CV;
  RS18(S := StartCondition, R1 := FactoryReset);
  RS17(S := (NOT(VS01) AND VS00 AND NOT(TAPP0_Detected) AND TAPP0_RotateCW OR NOT(Retro11)) AND RS18.Q1, R1 := NOT(TAPP0_RotateCW) AND NOT(VS02) AND NOT(VS01) AND VS00 AND NOT(Retro1) OR TAPP0_RotateCW AND NOT(Retro0) OR FactoryReset OR NOT(Retro12));
  TAPP0_RotateCCW := RS17.Q1;
  _TMP_EQ104_OUT := EQ(BlueGrabbed, BlueMissed);
  StackLight0_Yellow := _TMP_EQ104_OUT;
  _TMP_LT118_OUT := LT(BlueGrabbed, BlueMissed);
  StackLight0_Red := _TMP_LT118_OUT;
  _TMP_GT105_OUT := GT(BlueGrabbed, BlueMissed);
  StackLight0_Green := _TMP_GT105_OUT;
  RS6(S := StartCondition, R1 := FactoryReset);
  RS23(S := VS12 AND NOT(VS11) AND NOT(VS10) AND NOT(Retro4) AND RS6.Q1, R1 := TAPP1Z AND TAPP1_RotateCW AND TAPP1_RotateCCW AND NOT(TAPP1_Detected) OR FactoryReset OR NOT(Retro14));
  TAPP1X := RS23.Q1;
  RS24(S := StartCondition, R1 := FactoryReset);
  TON5(IN := TAPP1X AND RS24.Q1, PT := TAPP1ZPT);
  RS22(S := TON5.Q, R1 := TAPP1_Grab AND TAPP1_Detected OR TAPP1_RotateCW AND TAPP1_RotateCCW AND NOT(TAPP1_Detected) OR FactoryReset OR NOT(Retro14));
  TAPP1Z := RS22.Q1;
  TAPP1ZET := TON5.ET;
  RS25(S := StartCondition, R1 := FactoryReset);
  TON3(IN := TAPP1Z AND RS25.Q1, PT := Grab1PT);
  RS19(S := TON3.Q, R1 := TAPP1_RotateCW AND TAPP1_RotateCCW AND NOT(TAPP1_Detected) OR FactoryReset OR NOT(Retro14));
  TP1(IN := RS19.Q1, PT := Grab1TPPT);
  TAPP1_Grab := TP1.Q;
  Grab1TPET := TP1.ET;
  Grab1ET := TON3.ET;
  F_TRIG3(CLK := RetroreflectiveSensor5);
  RS31(S := StartCondition, R1 := FactoryReset);
  R_TRIG4(CLK := F_TRIG3.Q AND RS31.Q1);
  CTU3(CU := R_TRIG4.Q, R := FactoryReset, PV := GrabbedMax);
  GreenGrabbed := CTU3.CV;
  RS27(S := StartCondition, R1 := FactoryReset);
  TON4(IN := TAPP1_Grab AND RS27.Q1, PT := RCW1PT);
  RCW1ET := TON4.ET;
  RS26(S := TON4.Q, R1 := TAPP1_RotateCCW AND NOT(RetroreflectiveSensor3) OR FactoryReset OR NOT(Retro14));
  TAPP1_RotateCW := RS26.Q1;
  RS30(S := StartCondition, R1 := FactoryReset);
  R_TRIG5(CLK := VisionSensor32 AND NOT(VisionSensor31) AND NOT(VisionSensor30) AND RS30.Q1);
  CTU2(CU := R_TRIG5.Q, R := FactoryReset, PV := GrabbedMax);
  GreenMissed := CTU2.CV;
  _TMP_LT211_OUT := LT(GreenGrabbed, GreenMissed);
  StackLight1_Red := _TMP_LT211_OUT;
  _TMP_EQ195_OUT := EQ(GreenGrabbed, GreenMissed);
  StackLight1_Yellow := _TMP_EQ195_OUT;
  _TMP_GT196_OUT := GT(GreenGrabbed, GreenMissed);
  StackLight1_Green := _TMP_GT196_OUT;
  RS29(S := StartCondition, R1 := FactoryReset);
  RS28(S := (NOT(VS10) AND VS12 AND NOT(TAPP1_Detected) AND TAPP1_RotateCW OR NOT(Retro14)) AND RS29.Q1, R1 := NOT(TAPP1_RotateCW) AND VS12 AND NOT(VS11) AND NOT(VS10) AND NOT(Retro4) OR TAPP1_RotateCW AND NOT(RetroreflectiveSensor3) OR FactoryReset OR NOT(Retro13));
  TAPP1_RotateCCW := RS28.Q1;
  RS7(S := StartCondition, R1 := FactoryReset);
  RS32(S := VS22 AND VS21 AND VS20 AND NOT(Retro7) AND RS7.Q1, R1 := TAPP2Z AND TAPP2_RotateCW AND TAPP2_RotateCCW AND NOT(TAPP2_Detected) OR FactoryReset OR NOT(Retro15));
  TAPP2X := RS32.Q1;
  RS35(S := StartCondition, R1 := FactoryReset);
  TON7(IN := TAPP2X AND RS35.Q1, PT := TAPP2ZPT);
  RS34(S := TON7.Q, R1 := TAPP2_Grab AND TAPP2_Detected OR TAPP2_RotateCW AND TAPP2_RotateCCW AND NOT(TAPP2_Detected) OR FactoryReset OR NOT(Retro15));
  TAPP2Z := RS34.Q1;
  TAPP2ZET := TON7.ET;
  RS36(S := StartCondition, R1 := FactoryReset);
  TON6(IN := TAPP2Z AND RS36.Q1, PT := Grab2PT);
  RS33(S := TON6.Q, R1 := TAPP2_RotateCW AND TAPP2_RotateCCW AND NOT(TAPP2_Detected) OR FactoryReset OR NOT(Retro15));
  TP2(IN := RS33.Q1, PT := Grab2TPPT);
  TAPP2_Grab := TP2.Q;
  Grab2TPET := TP2.ET;
  Grab2ET := TON6.ET;
  RS38(S := StartCondition, R1 := FactoryReset);
  TON8(IN := TAPP2_Grab AND RS38.Q1, PT := RCW2PT);
  RS37(S := TON8.Q, R1 := TAPP2_RotateCCW AND NOT(RetroreflectiveSensor6) OR FactoryReset OR NOT(Retro15));
  TAPP2_RotateCW := RS37.Q1;
  RCW2ET := TON8.ET;
  F_TRIG4(CLK := RetroreflectiveSensor8);
  RS42(S := StartCondition, R1 := FactoryReset);
  R_TRIG6(CLK := F_TRIG4.Q AND RS42.Q1);
  CTU5(CU := R_TRIG6.Q, R := FactoryReset, PV := GrabbedMax);
  GreyGrabbed := CTU5.CV;
  RS41(S := StartCondition, R1 := FactoryReset);
  R_TRIG7(CLK := VisionSensor32 AND VisionSensor31 AND VisionSensor30 AND RS41.Q1);
  CTU4(CU := R_TRIG7.Q, R := FactoryReset, PV := GrabbedMax);
  GreyMissed := CTU4.CV;
  _TMP_EQ300_OUT := EQ(GreyGrabbed, GreyMissed);
  StackLight2_Yellow := _TMP_EQ300_OUT;
  _TMP_GT301_OUT := GT(GreyGrabbed, GreyMissed);
  StackLight2_Green := _TMP_GT301_OUT;
  _TMP_LT316_OUT := LT(GreyGrabbed, GreyMissed);
  StackLight2_Red := _TMP_LT316_OUT;
  RS44(S := StartCondition, R1 := FactoryReset);
  RS43(S := (NOT(Retro15) OR VS21 AND VS22 AND NOT(TAPP2_Detected) AND TAPP2_RotateCW) AND RS44.Q1, R1 := NOT(TAPP2_RotateCW) AND VS22 AND VS21 AND VS20 AND NOT(Retro4) OR TAPP2_RotateCW AND NOT(RetroreflectiveSensor6) OR FactoryReset OR NOT(Retro16));
  TAPP2_RotateCCW := RS43.Q1;
END_PROGRAM


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : program3;
  END_RESOURCE
END_CONFIGURATION
