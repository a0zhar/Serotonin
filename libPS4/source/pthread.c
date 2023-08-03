#include "../include/kernel.h"
#include "../include/module.h"
#include "../include/pthread.h"

int libPthread;

int (*scePthreadCreate)(ScePthread *thread, const ScePthreadAttr *attr, void *(*entry)(void *), void *arg, const char *name);
void (*scePthreadExit)(void *value);
int (*scePthreadDetach)(ScePthread thread);
int (*scePthreadJoin)(ScePthread thread, void **value_ptr);
void (*scePthreadYield)(void);
ScePthread (*scePthreadSelf)(void);
int (*scePthreadCancel)(ScePthread thread);

int (*scePthreadMutexInit)(ScePthreadMutex *mutex, const ScePthreadMutexattr *attr, const char *name);
int (*scePthreadMutexDestroy)(ScePthreadMutex *mutex);
int (*scePthreadMutexLock)(ScePthreadMutex *mutex);
int (*scePthreadMutexTrylock)(ScePthreadMutex *mutex);
int (*scePthreadMutexTimedlock)(ScePthreadMutex *mutex, SceKernelUseconds usec);
int (*scePthreadMutexUnlock)(ScePthreadMutex *mutex);

void initPthread(void) {
  if (libPthread) {
    return;
  }

  RESOLVE(libKernelHandle, scePthreadCreate);
  RESOLVE(libKernelHandle, scePthreadExit);
  RESOLVE(libKernelHandle, scePthreadDetach);
  RESOLVE(libKernelHandle, scePthreadJoin);
  RESOLVE(libKernelHandle, scePthreadYield);
  RESOLVE(libKernelHandle, scePthreadSelf);
  RESOLVE(libKernelHandle, scePthreadCancel);

  RESOLVE(libKernelHandle, scePthreadMutexInit);
  RESOLVE(libKernelHandle, scePthreadMutexDestroy);
  RESOLVE(libKernelHandle, scePthreadMutexLock);
  RESOLVE(libKernelHandle, scePthreadMutexTrylock);
  RESOLVE(libKernelHandle, scePthreadMutexTimedlock);
  RESOLVE(libKernelHandle, scePthreadMutexUnlock);

  libPthread = 1;
}
