
#ifndef __MAIN_H__
#define __MAIN_H__

#define MAX_VOLT_SCALE (4)
#define MAX_TIME_SCALE (9)

#define OLED_WIDTH      (128)
#define OLED_HEIGHT     (64)

#define SCOPE_STATE_M0_MAIN             (0)
#define SCOPE_STATE_M1_SPECTRUM         (1)
#define SCOPE_STATE_M2_MEASURE_VOLT     (2)
#define SCOPE_STATE_M3_MEASURE_TIME     (3)

#define SCOPE_DISPLAY_RUN               (0)
#define SCOPE_DISPLAY_STOP              (1)

typedef struct{
    uint8_t runState;
    uint8_t runStop;//0:run 1:stop
    uint8_t channelSelect;

    uint8_t voltScaleIdx; //��ѹ����index
    float   voltScale[MAX_VOLT_SCALE]; //��ѹ����
    char    *pVoltName[MAX_VOLT_SCALE];//��ѹ�������֣�������ʾ
    uint32_t voltRawValuePerPixel[MAX_VOLT_SCALE];  //����0-4095ת���ɵ�(pixel)�� adcVal/coef = ʵ�ʵ�λ��
    uint32_t voltRawValuePerGrad[MAX_VOLT_SCALE];   //ÿһ��̶ȶ�Ӧ��rawֵ
    
    uint8_t timeScaleIdx; //ʱ������index
    uint32_t timeScale[MAX_TIME_SCALE]; //ʱ������
    char   *pTimeName[MAX_TIME_SCALE];  //ʱ���������֣�������ʾ
    uint32_t timeDivCoef[MAX_TIME_SCALE]; //����ϵ�����������ò���Ƶ��
    uint32_t sampleRate; //������
    char pFFTSampRate[8]; //������(����)
    char pFFTDiv[8]; //FFTƵ�ʿ̶�(����)
    char pFFTMax[8]; //FFT������̣����֣�
}SCOPE_CTRL, *PSCOPE_CTRL;

extern SCOPE_CTRL g_scopeCtrl;

#endif


