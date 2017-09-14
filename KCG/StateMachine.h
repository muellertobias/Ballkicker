/* $********** SCADE Suite KCG 32-bit 6.6 (build i15) ***********
** Command: kcg66.exe -config D:/Development/Scadet/RobotTar/KCG/config.txt
** Generation date: 2017-09-11T14:21:06
*************************************************************$ */
#ifndef _StateMachine_H_
#define _StateMachine_H_

#include "kcg_types.h"

/* ========================  input structure  ====================== */
typedef struct {
  kcg_int16 /* @1/IROI_Input/,
     @1/_L3/,
     @2/IRIO_Input/,
     @2/_L3/,
     AverageSonar/,
     _L1/ */ AverageSonar;
  kcg_bool /* Start/, StartSignal/, _L15/ */ Start;
} inC_StateMachine;

/* =====================  no output structure  ====================== */

/* ========================  context type  ========================= */
typedef struct {
  /* ---------------------------  outputs  --------------------------- */
  kcg_uint32 /* CountValue/ */ CountValue;
  kcg_int16 /* SpeedValue/ */ SpeedValue;
  /* -----------------------  no local probes  ----------------------- */
  /* ----------------------- local memories  ------------------------- */
  kcg_int16 /* Speed/ */ Speed;
  kcg_uint32 /* Counting/ */ Counting;
  SSM_ST_SM2 /* SM2: */ SM2_state_nxt;
  SSM_ST_CountSM /* CountSM: */ CountSM_state_nxt;
  /* -------------------- no sub nodes' contexts  -------------------- */
  /* ----------------- no clocks of observable data ------------------ */
} outC_StateMachine;

/* ===========  node initialization and cycle functions  =========== */
/* StateMachine/ */
extern void StateMachine(inC_StateMachine *inC, outC_StateMachine *outC);

#ifndef KCG_NO_EXTERN_CALL_TO_RESET
extern void StateMachine_reset(outC_StateMachine *outC);
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */

#ifndef KCG_USER_DEFINED_INIT
extern void StateMachine_init(outC_StateMachine *outC);
#endif /* KCG_USER_DEFINED_INIT */

/*
  Expanded instances for: StateMachine/
  @1: (math::InRangeOutIn#1)
  @2: (math::InRangeInOut#1)
*/

#endif /* _StateMachine_H_ */
/* $********** SCADE Suite KCG 32-bit 6.6 (build i15) ***********
** StateMachine.h
** Generation date: 2017-09-11T14:21:06
*************************************************************$ */

