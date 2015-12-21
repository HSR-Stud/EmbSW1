static volatile int val = 0; // shared resource
static pthread_mutex_t valMtx;

int main(void)
{
  pthread_t t;
  pthread_mutex_init(&valMtx, 0); // init mutex
  pthread_create(&t, 0, threadRoutine, 0);
  pthread_join(t, 0);
  pthread_mutex_destroy(&valMtx); // destroy mutex
  return 0;
}

void* threadRoutine(void* arg)
{
  while (1)
  {
    // non critical section
    pthread_mutex_lock(&valMtx); // start of critical section
    // critical section; access shared resource
    pthread_mutex_unlock(&valMtx); // end of critical section
    // non critical section
  }
}