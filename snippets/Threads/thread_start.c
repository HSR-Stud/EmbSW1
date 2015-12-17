#include <pthread.h>

void* threadFunction(void* arg);

int main(void)
{
  int ret;
  pthread_t myT;
  ret = pthread_create(&myT, 0, threadFunction, 0);
  if (ret)
  {  // handle error
    return -1;
  }
  while (1) // endless loop
  {}
  return 0;
}

void* threadFunction(void* arg)
{  // implement this
  return 0;
}