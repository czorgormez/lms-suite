// -----------------------------------------------------------------------------
// FILE: 		ADF_module.h
// DESCRIPTION:	Header for ADF_module.cpp
// DATE:		2013-11-28
// AUTHOR(s):	Lime Microsystems
// REVISIONS:
// -----------------------------------------------------------------------------

#ifndef ADF_MODULE_H
#define ADF_MODULE_H

class ConnectionManager;

class ADF_module
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
