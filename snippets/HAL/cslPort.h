typedef volatile struct{
  uint32_t ctrl;
  uint32_t sel[2];
  uint32_t mux[2];
  uint32_t dir;
  uint32_t pud;} csl_PortCtrlRegs;

typedef volatile struct{
  const uint32_t dat;
  uint32_t set;
  uint32_t clear;
  uint32_t toggle;} csl_PortDataRegs;

typedef struct{
  csl_PortCtrlRegs* ctrl;
  csl_PortDataRegs* data;} csl_Port;

void csl_PortInit(csl_Port* port, csl_PortId id, bool initSamplePeriod);

enum{
  addrPortACtrlRegs = 0x00006F80,
  addrPortBCtrlRegs = 0x00006F90,
  addrPortADataRegs = 0x00006FC0,
  addrPortBDataRegs = 0x00006FC8
};
