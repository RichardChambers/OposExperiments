//*************************************************************************
//** OPOS LineDisplay Constants
//*************************************************************************

typedef [helpstring("OPOS LineDisplay Constants")]
enum
{
    DISP_CB_NOBLINK                           = 0,
    DISP_CB_BLINKALL                          = 1,
    DISP_CB_BLINKEACH                         = 2,
    DISP_CCS_NUMERIC                          = 0,
    DISP_CCS_ALPHA                            = 1,
    DISP_CCS_ASCII                            = 998,
    DISP_CCS_KANA                             = 10,
    DISP_CCS_KANJI                            = 11,
    DISP_CCS_UNICODE                          = 997,
    DISP_CCT_NONE                             = 0x00000000,
    DISP_CCT_FIXED                            = 0x00000001,
    DISP_CCT_BLOCK                            = 0x00000002,
    DISP_CCT_HALFBLOCK                        = 0x00000004,
    DISP_CCT_UNDERLINE                        = 0x00000008,
    DISP_CCT_REVERSE                          = 0x00000010,
    DISP_CCT_OTHER                            = 0x00000020,
    DISP_CCT_BLINK                            = 0x00000040,
    DISP_CRB_NONE                             = 0x00000000,
    DISP_CRB_SINGLE                           = 0x00000001,
    DISP_CR_NONE                              = 0x00000000,
    DISP_CR_REVERSEALL                        = 0x00000001,
    DISP_CR_REVERSEEACH                       = 0x00000002,
    DISP_CS_UNICODE                           = 997,
    DISP_CS_ASCII                             = 998,
    DISP_CS_WINDOWS                           = 999,
    DISP_CS_ANSI                              = 999,
    DISP_CT_NONE                              = 0,
    DISP_CT_FIXED                             = 1,
    DISP_CT_BLOCK                             = 2,
    DISP_CT_HALFBLOCK                         = 3,
    DISP_CT_UNDERLINE                         = 4,
    DISP_CT_REVERSE                           = 5,
    DISP_CT_OTHER                             = 6,
    DISP_CT_BLINK                             = 0x10000000,
    DISP_MT_NONE                              = 0,
    DISP_MT_UP                                = 1,
    DISP_MT_DOWN                              = 2,
    DISP_MT_LEFT                              = 3,
    DISP_MT_RIGHT                             = 4,
    DISP_MT_INIT                              = 5,
    DISP_MF_WALK                              = 0,
    DISP_MF_PLACE                             = 1,
    DISP_GT_SINGLE                            = 1,
    DISP_DT_NORMAL                            = 0,
    DISP_DT_BLINK                             = 1,
    DISP_DT_REVERSE                           = 2,
    DISP_DT_BLINK_REVERSE                     = 3,
    DISP_ST_UP                                = 1,
    DISP_ST_DOWN                              = 2,
    DISP_ST_LEFT                              = 3,
    DISP_ST_RIGHT                             = 4,
    DISP_SD_OFF                               = 0,
    DISP_SD_ON                                = 1,
    DISP_SD_BLINK                             = 2,
    DISP_BM_ASIS                              = -11,
    DISP_BM_LEFT                              = -1,
    DISP_BM_CENTER                            = -2,
    DISP_BM_RIGHT                             = -3,
    DISP_BM_TOP                               = -1,
    DISP_BM_BOTTOM                            = -3,
    OPOS_EDISP_TOOBIG                         = 201,
    OPOS_EDISP_BADFORMAT                      = 202
} OPOSLineDisplayConstants;