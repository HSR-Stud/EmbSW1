namespace csl
{
class Pin{
  public:
    Pin(Id id, Direction dir = in, Mux mux = fun1);
    bool get() const {return HwReg<uint32_t>::areBitsSet(port.dataRegs().dat, bit);}
  private:
    Port port;
    const uint32_t bit;
};
}  // namespace csl
