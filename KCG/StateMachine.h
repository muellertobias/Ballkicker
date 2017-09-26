/* $********** SCADE Suite KCG 32-bit 6.6 (build i15) ***********
** Command: kcg66.exe -config D:/Development/Scadet/RobotTar/KCG/config.txt
** Generation date: 2017-09-26T16:09:39
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
  kcg_bool /* Stop/, StopSignal/, _L35/ */ Stop;
} inC_StateMachine;

/* =====================  no output structure  ====================== */

/* ========================  context type  ========================= */
typedef struct {
  /* ---------------------------  outputs  --------------------------- */
  kcg_uint32 /* CountValue/, _L27/ */ CountValue;
  kcg_int16 /* Speed/, SpeedValue/, _L26/ */ SpeedValue;
  /* -----------------------  no local probes  ----------------------- */
  /* ----------------------- local memories  ------------------------- */
  kcg_bool init;
  SSM_ST_CountSM_Count_RobotTar /* RobotTar:Count:CountSM: */ CountSM_state_nxt_Count_RobotTar;
  SSM_ST_RobotTar /* RobotTar: */ RobotTar_state_nxt;
  kcg_uint32 /* Counting/ */ Counting;
  kcg_int16 /* Speed/ */ Speed;
  kcg_int16 /* _kicks/ */ _kicks;
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
** Generation date: 2017-09-26T16:09:39
*************************************************************$ */

