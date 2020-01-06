namespace csl
{
class Port{
  public:
    struct CtrlRegs{
      volatile uint32_t ctrl;
      volatile uint32_t sel[2];
      volatile uint32_t mux[2];
      volatile uint32_t dir;
      volatile uint32_t pud;};
    struct DataRegs{
      volatile const uint32_t dat;
      volatile uint32_t set;
      volatile uint32_t clear;
      volatile uint32_t toggle;};
    Port(Id id, bool initSamplePeriod = false);
  private:
    enum{addrPortACtrlRegs = 0x00006F80, addrPortBCtrlRegs = 0x00006F90,
         addrPortADataRegs = 0x00006FC0, addrPortBDataRegs = 0x00006FC8};
  ctrlRegs& cRegs;  ///< control registers
  DateRegs& dRegs;  ///< data registers
};
}
