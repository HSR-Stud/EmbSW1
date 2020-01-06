namespace bsl
{
class Led{
  public:
    Led(Id id)  :
        pin(led1 == id ? csl::Pin::pin6 : csl::Pin::pin2, csl::Pin::out) {}
    void off() {pin.clear();}
    void on() {pin.set();}
  private:
    csl::Pin pin;
};
}
