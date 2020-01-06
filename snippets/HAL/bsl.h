typedef struct{
  csl_Pin pin;} bsl_Led;

static inline void bsl_ledOff(bsl_Led* led) {csl_pinClear(&(led->pin));}
