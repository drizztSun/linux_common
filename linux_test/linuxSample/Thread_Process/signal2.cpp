#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/time.h>

void signal_func(int sig)
{
	switch(sig) {
	case 1:
		printf("signal --- SIGHUP\n");
		break;
	case 2:
		printf("signal --- SIGINT\n");
		break;
	case 3:
		printf("signal --- SIGQUIT\n");
		break;
	default:
		printf("error \n");
		break;
	}
}

void killSignal2() {

	int pid = getpid();

	// send the signals out to the pid's process
	kill(pid, SIGHUP);
	kill(pid, SIGINT);
	kill(pid, SIGQUIT);
}

void signal_route(int no) {
	if (SIGALRM == no) {
		printf("SIG --- ALARM \n");
	}
}

// Use alarm to trigger a singal 'SIGALRM' to current process
void alarm() {

	signal(SIGALRM, signal_route);

	// Trigger the 'SIGALRM' in 5 seconds
	alarm(5);
}

void timerSignal(int signo) {
	switch(signo) {
	case SIGALRM:
		printf("catch a signal ----- SIGALRM \n");
		break;
	case SIGVTALRM:
		printf("catch a vtsignal ----- SIGVALRM \n");
		break;
	}
}
//Use settimer to trigger a signal 'SIGALRM' or 'SIGVALRM' to current process
void setTimerWay() {

	struct itimerval value, ovalue, value2;

	signal(SIGALRM, timerSignal);
	signal(SIGVTALRM, timerSignal);

	value.it_value.tv_sec = 1;
	value.it_value.tv_usec = 0;
	value.it_interval.tv_sec = 1;
	value.it_interval.tv_usec = 0;

	setitimer(ITIMER_REAL, &value, &ovalue);

	value2.it_interval.tv_sec = 0;
	value2.it_interval.tv_usec = 500000;
	value2.it_value.tv_sec = 0;
	value2.it_value.tv_usec = 500000;

	setitimer(ITIMER_VIRTUAL, &value2, &ovalue);

	for(;;);

	return;
}



void testSignal2() {

	printf("test_signal2 %d \n", getpid());

	signal(SIGHUP, signal_func);
	signal(SIGINT, signal_func);
	signal(SIGQUIT, signal_func);

	for(;;)
		//sleep(1);
		// get a signal, then wake
		pause();



	return;
}

