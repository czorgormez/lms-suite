/**
@file	lms7/ADF_module.h
@author	Lime Microsystems
@brief	Header for ADF_module.cpp
*/

#ifndef ADF_MODULE_H
#define ADF_MODULE_H
#include <lms7/Config.h>

class ConnectionManager;

class LMS7_API ADF_module
{
public:
    ADF_module();
    ~ADF_module();

    void SetFrefFvco(double Fref, double Fvco, int &rcount, int &ncount);
    void SetReferenceCounterLatch(int Ldp, int Abw, int refCounter);
    void SetNCounterLatch(int CPgain, int NCounter);
    void SetFunctionLatch(int currentSetting1, int currentSetting2, int timerCounter, int fastLock, int muxoutControl);
    void SetFunctionLatchRgr(int pdPol, int pd1, int pd2, int counterReset, int cpState);
    void SetInitializationLatch(int currentSetting1, int currentSetting2, int timerCounter, int fastLock, int muxoutControl);
    void SetInitializationLatchRgr(int pdPol, int pd1, int pd2, int counterReset, int cpState);

    void SendConfig();
    void SetDefaults();
    void Initialize(ConnectionManager* pSerPort);

    void MakeData();
    void CalculateRN();

    int txtRCnt;
    int cmbABW;
    int cmbLDP;
    int txtNCnt;
    int cmbCPG;
    int rgrCR_i;
    int rgrPD1_i;
    int rgrPD2_i;
    int cmbMOC_i;
    int rgrPDP_i;
    int rgrCPS_i;
    int cmbTC_i;
    int cmbCS1_i;
    int cmbCS2_i;
    int rgrCR_f;
    int rgrPD1_f;
    int rgrPD2_f;
    int cmbMOC_f;
    int rgrPDP_f;
    int rgrCPS_f;
    int cmbTC_f;
    int cmbCS1_f;
    int cmbCS2_f;
    int cmbFL_f;
    int cmbFL_i;
    double txtFref;
    double txtFvco;

    double lblFcomp;
    double lblFvco;

protected:
    ConnectionManager *m_serPort;
    unsigned char m_registers[12];
};

#endif // ADF_MODULE_H
