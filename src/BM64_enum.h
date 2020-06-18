#ifndef BM64_enum_h
#define BM64_enum_h

typedef enum
{
  BM64_MAKE_CALL_CMD = 0x00,
  BM64_MAKE_EXTENSION_CALL_CMD = 0x01,
  BM64_MMI_CMD = 0x02,
  BM64_REPORT_MASK_CMD = 0x03,
  BM64_MUSIC_CONTROL_CMD = 0x04,
  BM64_CHANGE_DEVICE_NAME_CMD = 0x05,
  BM64_CHANGE_PIN_CODE_CMD = 0x06,
  BM64_SET_PAIRING_TIMER_CMD = 0x07,
  BM64_GET_UART_VERSION_CMD = 0x08,
  BM64_GET_PB_BY_AT_CMD = 0x09,
  BM64_VENDOR_AT_CMD = 0x0A,
  BM64_AVRCP_SPEC_CMD = 0x0B,
  BM64_AVRCP_GROUP_NAVIAGE_CMD = 0x0C,
  BM64_READ_LINK_STATUS_CMD = 0x0D,
  BM64_READ_PAIRING_RECORD_CMD = 0x0E,
  BM64_READ_LOCAL_BD_ADDR_CMD = 0x0F,
  BM64_READ_LOCAL_DEVICE_NAME_CMD = 0x10,
  BM64_SET_ACCESS_PB_METHOD_CMD = 0x11, 
  BM64_SEND_SPP_DATA_CMD = 0x12,
  BM64_BTM_UTILITY_FUNCTION_CMD = 0x13,
  BM64_MCU_SEND_EVENT_ACK_CMD = 0x14,
  BM64_ADDITIONAL_PROFILE_LINK_SETUP_CMD = 0x15,
  BM64_READ_LINKED_DEVICE_INFOR_CMD = 0x16,
  BM64_PROFILE_LINK_BACK_CMD = 0x17,
  BM64_DISCONNECT_CMD = 0x18,
  BM64_MCU_STATUS_INDICATION_CMD = 0x19,
  BM64_USER_CONFIRM_SPP_REQ_REPLY_CMD = 0x1A,
  BM64_SET_HF_GAIN_LEVEL_CMD = 0x1B,
  BM64_EQ_MODE_SETTING_CMD = 0x1C,
  BM64_DSP_NR_CTRL_CMD = 0x1D,
  BM64_GPIO_CTRL_CMD = 0x1E,
  BM64_BT_MCU_UART_RX_BUFF_SIZE_CMD = 0x1F,
  BM64_VOICE_PROMPT_CMD = 0x20,
  BM64_MAP_REQUEST_CMD = 0x21,
  BM64_SECURITY_BONDING_REQ_CMD = 0x22,
  BM64_SET_OVERALL_GAIN_CMD = 0x23,
  BM64_LE_SIGNALING_CMD = 0x29,
  BM64_DISCOVERABLE_CMD = 0x33,
  BM64_READ_LINK_MODE_CMD = 0x34
} BM64_cmd;

typedef enum
  {
  BM64_MMI_ADD_REMOVE_SCO_LINK = 0x01,
  BM64_MMI_FORCE_END_CALL = 0x02,
  BM64_MMI_ACCEPT_CALL = 0x04,
  BM64_MMI_REJECT_CALL = 0x05,
  BM64_MMI_ENDCALL_OR_TRANSFER_TO_HEADSET = 0x06,
  BM64_MMI_MIC_MUTE_TOGGLE = 0x07,
  BM64_MMI_MUTE_MIC = 0x08,
  BM64_MMI_UNMUTE_MIC  = 0x09,
  BM64_MMI_VOICE_DIAL  = 0x0A,
  BM64_MMI_CANCLE_VOICE_DAIL = 0x0B,
  BM64_MMI_LAST_NUMBER_REDIAL = 0x0C,
  BM64_MMI_ACTIVE_CALL_HOLD_ACCEPT_HELD_CALL = 0x0D,
  BM64_MMI_VOICE_TRANSFER = 0x0E,
  BM64_MMI_QUERY_CALL_LIST = 0x0F,
  BM64_MMI_THREE_WAY_CALL = 0x10,
  BM64_MMI_RELEASE_CALL = 0x11,
  BM64_MMI_ACCEPT_WAITING_HOLD_CALL_RLS_ACTIVE_CALL = 0x12,
  BM64_MMI_INITIAL_HF_CONNECTION = 0x16,
  BM64_MMI_DISCONNECT_HF_LINK = 0x17,
  BM64_MMI_INC_MIC_GAIN = 0x24,
  BM64_MMI_DEC_MIC_GAIN = 0x25,
  BM64_MMI_SWITCH_PRIMARY_SECONDARY_HF_DEVICE = 0x26,
  BM64_MMI_INC_SPK_GAIN = 0x30,
  BM64_MMI_DEC_SPK_GAIN = 0x31,
  BM64_MMI_INITIAL_A2DP_CONNECT_PLAY_PAUSE = 0x32,
  BM64_MMI_STOP_MEDIA = 0x33,
  BM64_MMI_NEXT_SONG = 0x34,
  BM64_MMI_PREVIOUS_SONG = 0x35,
  BM64_MMI_DISCONNECT_A2DP = 0x3B,
  BM64_MMI_STANDBY_ENTERING_PAIRING = 0x50,
  BM64_MMI_POWERON_BUTTON_PRESS = 0x51,
  BM64_MMI_POWERON_BUTTON_RELEASE = 0x52,
  BM64_MMI_POWEROFF_BUTTON_PRESS = 0x53,
  BM64_MMI_POWEROFF_BUTTON_RELEASE = 0x54,
  BM64_MMI_RESET_EEPROM_SETTING = 0x56,
  BM64_MMI_ANY_MODE_ENTERING_PAIRING = 0x5D,
  BM64_MMI_POWEROFF_BT = 0x5E,
  BM64_MMI_BUZZER_TOGGLE = 0x60,
  BM64_MMI_DISABLE_BUZZER = 0x61,
  BM64_MMI_ENABLE_BUZZER = 0x62,
  BM64_MMI_TONE_CHANGE = 0x63,
  BM64_MMI_RETRIEVE_PHONE_BOOK = 0x64,
  BM64_MMI_RETRIEVE_MISS_CALL_HISTORY = 0x65,
  BM64_MMI_RETRIEVE_RECEIVED_CALL_HISTORY = 0x66,
  BM64_MMI_RETRIEVE_DIALED_CALL_HISTORY = 0x67,
  BM64_MMI_RETRIEVE_ALL_CALL_HISTORY = 0x68,
  BM64_MMI_CANCLE_RETRIEVE = 0x69,
  BM64_MMI_INDICATE_BATTERY_STATUS = 0x6A,
  BM64_MMI_EXIT_PAIRING_MODE = 0x6B,
  BM64_MMI_LINK_BACK_DEVICE = 0x6C,
  BM64_MMI_DISCONNECT_ALL_LINK = 0x6D,
  BM64_MMI_MASTERSPK_ENTER_CSB_PAGE = 0xE0, 
  BM64_MMI_SLAVESPK_ENTER_CSB_PAGESCAN = 0xE1, 
  BM64_MMI_NSPK_ADD_SPEAKER = 0xE2,
  BM64_MMI_MASTERSPK_TERMINAL_CSB = 0xE5, 
  BM64_MMI_MASTERSPK_ENTER_AUXMODE = 0xE7,     
  BM64_MMI_MASTERSPK_EXIT_AUXMODE = 0xE8,   
  BM64_MMI_POWER_OFF_ALL_SPK = 0xED,
  BM64_MMI_MASTERSPK_REPAIR_TO_SLAVE = 0xF0
} BM64_mmi_cmd;

typedef enum            
{
  BM64_EVENT_ACK = 0x00,
  BM64_EVENT_DEVICE_STATE = 0x01,
  BM64_EVENT_CALL_STATUS = 0x02,
  BM64_EVENT_CALL_ID = 0x03,
  BM64_EVENT_SMS_INDICATION = 0x04,
  BM64_EVENT_MISS_CALL_INDICATION = 0x05,
  BM64_EVENT_PHONE_MAX_BATTERY_LEVEL = 0x06,
  BM64_EVENT_PHONE_BATTERY_LEVEL = 0x07,
  BM64_EVENT_PHONE_ROAMING_STATUS = 0x08,
  BM64_EVENT_PHONE_MAX_SIGNAL_STRENGTH = 0x09,
  BM64_EVENT_PHONE_SIGNAL_STRENGTH = 0x0A,
  BM64_EVENT_PHONE_SERVICE_STATUS = 0x0B,
  BM64_EVENT_BATTERY_LEVEL = 0x0C,
  BM64_EVENT_CHARGER_STATUS = 0x0D,
  BM64_EVENT_RESET_TO_DEFAULT = 0x0E,
  BM64_EVENT_VOLUME_LEVEL = 0x0F,
  BM64_EVENT_EQ_MODE = 0x10,
  BM64_EVENT_MISS_CALL_HISTORY = 0x11,
  BM64_EVENT_RECEIVED_CALL_HISTORY = 0x12,
  BM64_EVENT_DIALED_CALL_HISTORY = 0x13,
  BM64_EVENT_COMBINE_CALL_HISTORY = 0x14,
  BM64_EVENT_PHONE_BOOK = 0x15,
  BM64_EVENT_ACCESS_FINISH = 0x16,
  BM64_EVENT_REMOTE_DEVICE_NAME = 0x17,
  BM64_EVENT_UART_VERSION = 0x18,
  BM64_EVENT_CALL_LIST_REPORT = 0x19,
  BM64_EVENT_AVRCP_SPEC_RSP = 0x1A,
  BM64_EVENT_BTM_UTILITY_REQ = 0x1B,
  BM64_EVENT_VENDOR_AT_CMD_RSP = 0x1C,
  BM64_EVENT_UNKNOW_AT_RESULT = 0x1D,
  BM64_EVENT_REPORT_LINK_STATUS = 0x1E,
  BM64_EVENT_REPORT_PAIRING_RECORD = 0x1F,
  BM64_EVENT_REPORT_LOCAL_BD_ADDR = 0x20,
  BM64_EVENT_REPORT_LOCAL_DEVICE_NAME = 0x21,
  BM64_EVENT_REPORT_SPP_DATA = 0x22,
  BM64_EVENT_REPORT_LINK_BACK_STATUS = 0x23,
  BM64_EVENT_RINGTONE_FINISH_INDICATION = 0x24,
  BM64_EVENT_USER_CONFIRM_SSP_REQ = 0x25,
  BM64_EVENT_REPORT_AVRCP_VOL_CTRL = 0x26,
  BM64_EVENT_REPORT_INPUT_SIGNAL_LEVEL = 0x27,
  BM64_EVENT_REPORT_IAP_INFO = 0x28,
  BM64_EVENT_REPORT_AVRCP_ABS_VOL_CTRL = 0x29,
  BM64_EVENT_REPORT_VOICE_PROMPT_STATUS = 0x2A,
  BM64_EVENT_REPORT_MAP_DATA = 0x2B,
  BM64_EVENT_SECURITY_BONDLING_RES = 0x2C,
  BM64_EVENT_REPORT_TYPE_CODEC = 0x2D,
  BM64_EVENT_REPORT_TYPE_BTM_SETTING = 0x2E,
  BM64_EVENT_REPORT_MCU_UPDATE_REPLY = 0x2F,
  BM64_EVENT_REPORT_BTM_INITIAL_STATUS = 0x30,
  BM64_EVENT_REPORT_LE_ANCS_SERVICE = 0x31,
  BM64_EVENT_REPORT_LE_EVENT = 0x32,
  BM64_EVENT_REPORT_nSPK_STATUS = 0x33,
  BM64_EVENT_REPORT_nSPK_VENDOR_EVENT = 0x34,
  BM64_EVENT_REPORT_nSPK_AUDIO_SETTING = 0x35,
  BM64_EVENT_REPORT_SOUND_EFFECT_STATUS = 0x36,
  BM64_EVENT_REPORT_VENDOR_EEPROM_DATA = 0x37,
  BM64_EVENT_REPORT_IC_VERSION_INFO = 0x38,
  BM64_EVENT_REPORT_CUSTOMER_GATT_ATTRIBUTE_DATA = 0x39,
  BM64_EVENT_REPORT_LINK_MODE = 0x3A,
  BM64_EVENT_REPORT_DSP_DEDICATED_EVENT = 0x3B,
  BM64_EVENT_REPORT_nSPK_MISC_EVENT = 0x3C,
  BM64_EVENT_REPORT_nSPK_EXCHANGE_LINK_INFO = 0x3D,
  BM64_EVENT_REPORT_CUSTOMIZED_INFORMATION = 0x3E,
  BM64_EVENT_REPORT_CSB_CLK = 0x3F,
  BM64_EVENT_REPORT_READ_FEATURE_LIST_REPLY = 0x40,
  BM64_EVENT_REPORT_TEST_RESULT_REPLY = 0x41
} BM64_EVENT;

typedef enum{
  MUSIC_CONTROL_PLAY = 0x05,
  MUSIC_CONTROL_PAUSE = 0x06,
  MUSIC_CONTROL_TOGGLE = 0x07,
  MUSIC_CONTROL_STOP = 0x08,
  MUSIC_CONTROL_NEXT = 0x09,
  MUSIC_CONTROL_PREV =0x0A
} BM64_music_control_act;

typedef enum {
  IDLE = 0x00,
  INCOMING_CALL = 0x02,
  OUTGOING_CALL = 0x03,
  CALL_ACTIVE = 0x04,
}BM64_call_status;
#endif