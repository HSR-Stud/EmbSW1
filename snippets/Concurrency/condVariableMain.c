enum {maxCount = 10, numThreads = 3, countLimit = 12};
volatile static int count = 0;          // shared resource
static pthread_mutex_t countMutex;      // the mutex
static pthread_cond_t countThresholdCv; // the condition variable
void* incCount(void* t);                // count thread function
void* watchCount(void* t);              // watch thread function

int main(void)
{
  int i;
  long t[numThreads] = {1, 2, 3};
  pthread_t threads[numThreads];

  pthread_mutex_init(&countMutex, 0);       // init mutex
  pthread_cond_init(&countThresholdCv, 0);  // init condition variable
  pthread_create(&threads[0], 0, watchCount, (void*)t[0]);
  pthread_create(&threads[1], 0, incCount, (void*)t[1]);
  pthread_create(&threads[2], 0, incCount, (void*)t[2]);
  for (i = 0; i < numThreads; ++i)
    pthread_join(threads[i], 0);
  pthread_mutex_destroy(&countMutex);       // destroy mutex
  pthread_cond_destroy(&countThresholdCv);  // destroy condition variable
  pthread_exit(0);
}
