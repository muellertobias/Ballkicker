/* $********** SCADE Suite KCG 32-bit 6.6 (build i15) ***********
** Command: kcg66.exe -config D:/Development/Scadet/RobotTar/KCG/config.txt
** Generation date: 2017-09-28T15:51:45
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "StateMachine.h"

/* StateMachine/ */
void StateMachine(inC_StateMachine *inC, outC_StateMachine *outC)
{
  /* RobotTar:Count:CountSM: */
  SSM_ST_CountSM_Count_RobotTar CountSM_state_act_Count_RobotTar;
  /* RobotTar:Count:CountSM: */
  SSM_ST_CountSM_Count_RobotTar CountSM_state_sel_Count_RobotTar;
  /* RobotTar:Count: */
  kcg_bool Count_weakb_clock_RobotTar;
  /* RobotTar:, RobotTar:Count:<1> */
  kcg_bool RobotTar_reset_nxt_partial;
  /* RobotTar:Search: */
  kcg_bool Search_weakb_clock_RobotTar;
  /* RobotTar:Search:<2> */
  kcg_bool tr_2_clock_Search_RobotTar;
  /* RobotTar:, RobotTar:Free:<1> */
  kcg_bool tr_1_clock_Free_RobotTar;
  /* RobotTar:, RobotTar:Release:<1> */
  kcg_bool tr_1_clock_Release_RobotTar;
  /* RobotTar: */
  SSM_ST_RobotTar RobotTar_state_act;
  /* RobotTar: */
  kcg_bool RobotTar_reset_act;
  /* RobotTar: */
  SSM_TR_RobotTar RobotTar_fired_strong;
  /* Speed/ */
  kcg_int16 Speed;
  /* @1/IROI_Output/, @1/_L29/, OffBallSignal/, _L9/ */
  kcg_bool _L9;
  /* @2/IRIO_Output/, @2/_L10/, OnBallSignal/, _L14/ */
  kcg_bool _L14;

  _L9 = (kcg_lit_int16(15) >= inC->AverageSonar) & (inC->AverageSonar >
      kcg_lit_int16(0));
  /* RobotTar: */
  switch (outC->RobotTar_state_nxt) {
    case SSM_st_Finish_RobotTar :
      RobotTar_reset_act = inC->Stop;
      if (inC->Stop) {
        RobotTar_state_act = SSM_st_Release_RobotTar;
        RobotTar_fired_strong = SSM_TR_Finish_Release_1_Finish_RobotTar;
      }
      else {
        RobotTar_state_act = SSM_st_Finish_RobotTar;
        RobotTar_fired_strong = SSM_TR_no_trans_RobotTar;
      }
      break;
    case SSM_st_Release_RobotTar :
      tr_1_clock_Release_RobotTar = !inC->Stop;
      RobotTar_reset_act = tr_1_clock_Release_RobotTar;
      if (tr_1_clock_Release_RobotTar) {
        RobotTar_state_act = SSM_st_Init_RobotTar;
        RobotTar_fired_strong = SSM_TR_Release_Init_1_Release_RobotTar;
      }
      else {
        RobotTar_state_act = SSM_st_Release_RobotTar;
        RobotTar_fired_strong = SSM_TR_no_trans_RobotTar;
      }
      break;
    case SSM_st_Free_RobotTar :
      tr_1_clock_Free_RobotTar = !inC->Stop;
      RobotTar_reset_act = tr_1_clock_Free_RobotTar;
      if (tr_1_clock_Free_RobotTar) {
        RobotTar_state_act = SSM_st_Search_RobotTar;
        RobotTar_fired_strong = SSM_TR_Free_Search_1_Free_RobotTar;
      }
      else {
        RobotTar_state_act = SSM_st_Free_RobotTar;
        RobotTar_fired_strong = SSM_TR_no_trans_RobotTar;
      }
      break;
    case SSM_st_Search_RobotTar :
      RobotTar_reset_act = inC->Stop;
      if (inC->Stop) {
        RobotTar_state_act = SSM_st_Release_RobotTar;
        RobotTar_fired_strong = SSM_TR_Search_Release_1_Search_RobotTar;
      }
      else {
        RobotTar_state_act = SSM_st_Search_RobotTar;
        RobotTar_fired_strong = SSM_TR_no_trans_RobotTar;
      }
      break;
    case SSM_st_Kick_RobotTar :
      RobotTar_reset_act = _L9;
      if (_L9) {
        RobotTar_state_act = SSM_st_Search_RobotTar;
        RobotTar_fired_strong = SSM_TR_Kick_Search_1_Kick_RobotTar;
      }
      else {
        RobotTar_state_act = SSM_st_Kick_RobotTar;
        RobotTar_fired_strong = SSM_TR_no_trans_RobotTar;
      }
      break;
    case SSM_st_Init_RobotTar :
      RobotTar_reset_act = inC->Start;
      if (inC->Start) {
        RobotTar_state_act = SSM_st_Count_RobotTar;
        RobotTar_fired_strong = SSM_TR_Init_Count_1_Init_RobotTar;
      }
      else {
        RobotTar_state_act = SSM_st_Init_RobotTar;
        RobotTar_fired_strong = SSM_TR_no_trans_RobotTar;
      }
      break;
    case SSM_st_Count_RobotTar :
      RobotTar_reset_act = kcg_false;
      RobotTar_state_act = SSM_st_Count_RobotTar;
      RobotTar_fired_strong = SSM_TR_no_trans_RobotTar;
      break;
    default :
      /* this default branch is unreachable */
      break;
  }
  _L14 = (kcg_lit_int16(256) > inC->AverageSonar) & (inC->AverageSonar >=
      kcg_lit_int16(16));
  /* RobotTar: */
  switch (RobotTar_state_act) {
    case SSM_st_Finish_RobotTar :
      outC->CountValue = outC->Counting;
      break;
    case SSM_st_Release_RobotTar :
      outC->CountValue = outC->Counting;
      break;
    case SSM_st_Free_RobotTar :
      outC->CountValue = outC->Counting;
      break;
    case SSM_st_Search_RobotTar :
      Search_weakb_clock_RobotTar = RobotTar_fired_strong != SSM_TR_no_trans_RobotTar;
      if (Search_weakb_clock_RobotTar) {
      }
      else {
        tr_2_clock_Search_RobotTar = _L14;
      }
      outC->CountValue = outC->Counting;
      break;
    case SSM_st_Kick_RobotTar :
      outC->CountValue = outC->Counting;
      break;
    case SSM_st_Init_RobotTar :
      outC->CountValue = outC->Counting;
      break;
    case SSM_st_Count_RobotTar :
      if (RobotTar_reset_act) {
        outC->init = kcg_true;
      }
      Count_weakb_clock_RobotTar = RobotTar_fired_strong != SSM_TR_no_trans_RobotTar;
      if (Count_weakb_clock_RobotTar) {
      }
      else {
        RobotTar_reset_nxt_partial = inC->Stop;
      }
      /* RobotTar:Count:CountSM: */
      if (outC->init) {
        CountSM_state_sel_Count_RobotTar = SSM_st_Init_CountSM_Count_RobotTar;
      }
      else {
        CountSM_state_sel_Count_RobotTar = outC->CountSM_state_nxt_Count_RobotTar;
      }
      /* RobotTar:Count:CountSM: */
      switch (CountSM_state_sel_Count_RobotTar) {
        case SSM_st_Init_CountSM_Count_RobotTar :
          /* RobotTar:Count:CountSM:Init:<1> */
          if (inC->Start) {
            CountSM_state_act_Count_RobotTar = SSM_st_Wait_CountSM_Count_RobotTar;
            outC->CountValue = kcg_lit_uint32(0);
          }
          else {
            CountSM_state_act_Count_RobotTar = SSM_st_Init_CountSM_Count_RobotTar;
            outC->CountValue = outC->Counting;
          }
          break;
        case SSM_st_Count_CountSM_Count_RobotTar :
          /* RobotTar:Count:CountSM:Count:<1> */
          if (_L9) {
            CountSM_state_act_Count_RobotTar = SSM_st_Wait_CountSM_Count_RobotTar;
            outC->CountValue = outC->Counting + kcg_lit_uint32(1);
          }
          else {
            CountSM_state_act_Count_RobotTar = SSM_st_Count_CountSM_Count_RobotTar;
            outC->CountValue = outC->Counting;
          }
          break;
        case SSM_st_Wait_CountSM_Count_RobotTar :
          if (_L14) {
            CountSM_state_act_Count_RobotTar = SSM_st_Count_CountSM_Count_RobotTar;
          }
          else {
            CountSM_state_act_Count_RobotTar = SSM_st_Wait_CountSM_Count_RobotTar;
          }
          outC->CountValue = outC->Counting;
          break;
        default :
          /* this default branch is unreachable */
          break;
      }
      /* RobotTar:Count:CountSM: */
      switch (CountSM_state_act_Count_RobotTar) {
        case SSM_st_Init_CountSM_Count_RobotTar :
          outC->CountSM_state_nxt_Count_RobotTar = SSM_st_Init_CountSM_Count_RobotTar;
          break;
        case SSM_st_Count_CountSM_Count_RobotTar :
          outC->CountSM_state_nxt_Count_RobotTar = SSM_st_Count_CountSM_Count_RobotTar;
          break;
        case SSM_st_Wait_CountSM_Count_RobotTar :
          outC->CountSM_state_nxt_Count_RobotTar = SSM_st_Wait_CountSM_Count_RobotTar;
          break;
        default :
          /* this default branch is unreachable */
          break;
      }
      break;
    default :
      /* this default branch is unreachable */
      break;
  }
  /* RobotTar: */
  switch (outC->RobotTar_state_nxt) {
    case SSM_st_Finish_RobotTar :
      /* RobotTar:Finish:<1> */
      if (inC->Stop) {
        Speed = kcg_lit_int16(20);
      }
      else {
        Speed = outC->Speed;
      }
      break;
    case SSM_st_Release_RobotTar :
      /* RobotTar:Release:<1> */
      if (tr_1_clock_Release_RobotTar) {
        Speed = kcg_lit_int16(0);
      }
      else {
        Speed = outC->Speed;
      }
      break;
    case SSM_st_Free_RobotTar :
      /* RobotTar:Free:<1> */
      if (tr_1_clock_Free_RobotTar) {
        /* RobotTar:Free:<1>_kicks= */
        if ((outC->CountValue == kcg_lit_uint32(5)) | (outC->CountValue ==
            kcg_lit_uint32(2))) {
          outC->_kicks = kcg_lit_int16(2);
        }
        else {
          outC->_kicks = kcg_lit_int16(1);
        }
        Speed = kcg_lit_int16(-25);
      }
      else {
        Speed = outC->Speed;
      }
      break;
    case SSM_st_Search_RobotTar :
      /* RobotTar:Search:<1> */
      if (inC->Stop) {
        Speed = kcg_lit_int16(20);
      }
      else {
        Speed = outC->Speed;
      }
      break;
    case SSM_st_Kick_RobotTar :
      /* RobotTar:Kick:<1> */
      if (_L9) {
        outC->_kicks = outC->_kicks - kcg_lit_int16(1);
        Speed = kcg_lit_int16(-25);
      }
      else {
        Speed = outC->Speed;
      }
      break;
    case SSM_st_Init_RobotTar :
      /* RobotTar:Init:<1> */
      if (inC->Start) {
        Speed = kcg_lit_int16(25);
      }
      else {
        Speed = outC->Speed;
      }
      break;
    case SSM_st_Count_RobotTar :
      Speed = outC->Speed;
      break;
    default :
      /* this default branch is unreachable */
      break;
  }
  /* RobotTar: */
  switch (RobotTar_state_act) {
    case SSM_st_Finish_RobotTar :
      outC->RobotTar_state_nxt = SSM_st_Finish_RobotTar;
      outC->SpeedValue = Speed;
      break;
    case SSM_st_Release_RobotTar :
      outC->RobotTar_state_nxt = SSM_st_Release_RobotTar;
      outC->SpeedValue = Speed;
      break;
    case SSM_st_Free_RobotTar :
      outC->RobotTar_state_nxt = SSM_st_Free_RobotTar;
      outC->SpeedValue = Speed;
      break;
    case SSM_st_Search_RobotTar :
      /* RobotTar:Search: */
      if (Search_weakb_clock_RobotTar) {
        outC->RobotTar_state_nxt = SSM_st_Search_RobotTar;
        outC->SpeedValue = Speed;
      }
      else {
        if (_L14) {
          outC->RobotTar_state_nxt = SSM_st_Kick_RobotTar;
        }
        else if (outC->_kicks == kcg_lit_int16(0)) {
          outC->RobotTar_state_nxt = SSM_st_Finish_RobotTar;
        }
        else {
          outC->RobotTar_state_nxt = SSM_st_Search_RobotTar;
        }
        /* RobotTar:Search:<2> */
        if (tr_2_clock_Search_RobotTar) {
          outC->SpeedValue = kcg_lit_int16(0);
        }
        else {
          outC->SpeedValue = Speed;
        }
      }
      break;
    case SSM_st_Kick_RobotTar :
      outC->RobotTar_state_nxt = SSM_st_Kick_RobotTar;
      outC->SpeedValue = Speed;
      break;
    case SSM_st_Init_RobotTar :
      outC->RobotTar_state_nxt = SSM_st_Init_RobotTar;
      outC->SpeedValue = Speed;
      break;
    case SSM_st_Count_RobotTar :
      /* RobotTar:Count: */
      if (Count_weakb_clock_RobotTar) {
        outC->RobotTar_state_nxt = SSM_st_Count_RobotTar;
        outC->SpeedValue = Speed;
      }
      else {
        if (inC->Stop) {
          outC->RobotTar_state_nxt = SSM_st_Free_RobotTar;
        }
        else {
          outC->RobotTar_state_nxt = SSM_st_Count_RobotTar;
        }
        /* RobotTar:Count:<1> */
        if (RobotTar_reset_nxt_partial) {
          outC->SpeedValue = kcg_lit_int16(-20);
        }
        else {
          outC->SpeedValue = Speed;
        }
      }
      outC->init = kcg_false;
      break;
    default :
      /* this default branch is unreachable */
      break;
  }
  outC->Speed = outC->SpeedValue;
  outC->Counting = outC->CountValue;
}

#ifndef KCG_USER_DEFINED_INIT
void StateMachine_init(outC_StateMachine *outC)
{
  outC->init = kcg_true;
  outC->CountSM_state_nxt_Count_RobotTar = SSM_st_Wait_CountSM_Count_RobotTar;
  outC->SpeedValue = kcg_lit_int16(0);
  outC->CountValue = kcg_lit_uint32(0);
  outC->Speed = kcg_lit_int16(0);
  outC->_kicks = kcg_lit_int16(0);
  outC->Counting = kcg_lit_uint32(0);
  outC->RobotTar_state_nxt = SSM_st_Init_RobotTar;
}
#endif /* KCG_USER_DEFINED_INIT */


#ifndef KCG_NO_EXTERN_CALL_TO_RESET
void StateMachine_reset(outC_StateMachine *outC)
{
  outC->init = kcg_true;
  outC->Speed = kcg_lit_int16(0);
  outC->_kicks = kcg_lit_int16(0);
  outC->Counting = kcg_lit_uint32(0);
  outC->RobotTar_state_nxt = SSM_st_Init_RobotTar;
}
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */

/*
  Expanded instances for: StateMachine/
  @1: (math::InRangeOutIn#1)
  @2: (math::InRangeInOut#1)
*/

/* $********** SCADE Suite KCG 32-bit 6.6 (build i15) ***********
** StateMachine.c
** Generation date: 2017-09-28T15:51:45
*************************************************************$ */

