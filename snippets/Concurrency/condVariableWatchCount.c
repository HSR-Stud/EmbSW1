void* watchCount(void* t)
{
  long myId = (long)t;
  printf("Starting watchCount(): thread %ld\n", myId);

  // Note that pthread_cond_wait() will automatically and atomically unlock
  // mutex while it waits. Also, note that if countLimit is reached before this
  // routine is run by the waiting thread, the loop will be skipped to prevent
  // pthread_cond_wait() from never returning.

  pthread_mutex_lock(&countMutex);    // start of critical section
  while (count < countLimit)
  {
    pthread_cond_wait(&countThresholdCv, &countMutex);  // wait on condition
    printf("watchCount(): condition signal received.\n");
    count += 125; // updating the value of count
  }
  pthread_mutex_unlock(&countMutex);  // end of critical section

  pthread_exit(0);
}
