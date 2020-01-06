void* incCount(void* t)
{
  int i;
  long myId = (long)t;
  printf("Starting incCount(): thread %ld\n", myId);

  for (i = 0; i < maxCount; ++i)
  {
    pthread_mutex_lock(&countMutex);    // start of critical section
    ++count;

    // Check the value of count and signal waiting thread when condition is
    // reached. Note that this occurs while mutex is locked.
    if (count == countLimit)
      pthread_cond_signal(&countThresholdCv); // signal waiting thread

    pthread_mutex_unlock(&countMutex);  // end of critical section

    sleep(1);   // Do some work so threads can alternate on mutex lock
  }
  pthread_exit(0);
}
