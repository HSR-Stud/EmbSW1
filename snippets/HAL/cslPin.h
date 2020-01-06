typedef struct{
  csl_Port port;
  uint32_t bit;} csl_Pin;

void csl_pinInit(csl_Pin* pin, csl_PinId id, csl_PinMux mux);

static inline bool csl_pinGet(const csl_Pin* pin)
{return csl_hwReg32AreBitsSet(&(pin->port.data->dat), pin->bit);}
