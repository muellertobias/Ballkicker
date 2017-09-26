/* $********** SCADE Suite KCG 32-bit 6.6 (build i15) ***********
** Command: kcg66.exe -config D:/Development/Scadet/RobotTar/KCG/config.txt
** Generation date: 2017-09-26T15:13:06
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
  kcg_bool /* KickMoveBackward/,
     KickMoveBackwardSignal/,
     _L22/ */ KickMoveBackward;
  kcg_bool /* KickMoveFinished/,
     KickMoveFinishedSignal/,
     _L25/ */ KickMoveFinished;
  kcg_int16 /* KickCountValue/, _L32/ */ KickCountValue;
  kcg_bool /* Stop/, StopSignal/, _L35/ */ Stop;
} inC_StateMachine;

/* =====================  no output structure  ====================== */

/* ========================  context type  ========================= */
typedef struct {
  /* ---------------------------  outputs  --------------------------- */
  kcg_uint32 /* CountValue/, _L27/ */ CountValue;
  kcg_int16 /* Speed/, SpeedValue/, _L26/ */ SpeedValue;
  kcg_int16 /* ArmSpeedValue/, _L23/ */ ArmSpeedValue;
  /* -----------------------  no local probes  ----------------------- */
  /* ----------------------- local memories  ------------------------- */
  kcg_int16 /* _kicks/ */ _kicks;
  kcg_int16 /* ArmSpeed/ */ ArmSpeed;
  kcg_int16 /* Speed/ */ Speed;
  kcg_uint32 /* Counting/ */ Counting;
  SSM_ST_SM3 /* SM3: */ SM3_state_nxt;
  SSM_ST_Kicking_Kick_SM3 /* SM3:Kick:Kicking: */ Kicking_state_nxt_Kick_SM3;
  SSM_ST_CountSM_DriveAndCount_SM3 /* SM3:DriveAndCount:CountSM: */ CountSM_state_nxt_DriveAndCount_SM3;
  kcg_bool init;
  kcg_bool init1;
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
** Generation date: 2017-09-26T15:13:06
*************************************************************$ */

